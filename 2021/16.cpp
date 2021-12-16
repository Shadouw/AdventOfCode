#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;

class packetdecoder
{
public:
    packetdecoder(const string &_input) : inputstring(_input)
    {
        // Make HEX sequency BIN
        for (auto elem : inputstring)
        {
            bitset<4> binary((elem > 60 ? elem - 55 : elem - 48));
            for (int b = 3; b >= 0; --b)
                input.push_back(binary[b]);
        }

        // Store initial BIN string
        stringstream binstream;
        for (auto elem : input)
            binstream << (elem ? '1' : '0');

        binarystring = binstream.str();

        parseInput();
    }
    packetdecoder(const vector<uint8_t> &_input) : input(_input)
    {
        parseInput();
    }

    void parseInput()
    {
        // get Packet Version
        for (int i = 2; i >= 0; --i)
        {
            packetversion *= 2;
            packetversion += popfront();
        }

        // get Packet Type
        for (int i = 2; i >= 0; --i)
        {
            packettype *= 2;
            packettype += popfront();
        }

        if (4 == packettype)
        {
            bool getNextPackage = true;
            while (getNextPackage)
            {
                getNextPackage = popfront();

                for (int i = 3; i >= 0; --i)
                {
                    literal *= 2;
                    literal += popfront();
                }
            }
        }
        else // Operator
        {
            lengthtypeid = (popfront() ? 1 : 0);

            uint8_t lengthtype = 15;
            if (1 == lengthtypeid)
                lengthtype = 11;

            for (int i = 0; i < lengthtype; ++i)
            {
                sublength *= 2;
                sublength += popfront();
            }

            if (0 == lengthtypeid)
            { // Build Subinput
                vector<uint8_t> subinput;
                for (uint64_t i = 0; i < sublength; ++i)
                    subinput.push_back(popfront());

                while (subinput.size() > 0)
                {
                    packetdecoder pd(subinput);
                    subpackages.push_back(pd);

                    while (subinput.size() > pd.getRemainingLength())
                        subinput.erase(subinput.begin());
                }
            }
            else
            {
                for (uint64_t p = 0; p < sublength; ++p)
                {
                    packetdecoder pd(input);
                    subpackages.push_back(pd);

                    while (input.size() > pd.getRemainingLength())
                        input.erase(input.begin());
                }
            }
        }

        return;
    }

    string getBinaryString()
    {
        return binarystring;
    }

    uint8_t getPacketVersion()
    {
        return packetversion;
    }

    uint8_t getPacketType()
    {
        return packettype;
    }

    uint64_t getLiteral()
    {
        return literal;
    }

    uint8_t getLengthTypeId()
    {
        return lengthtypeid;
    }

    uint64_t getSubLength()
    {
        return sublength;
    }

    size_t getRemainingLength()
    {
        return input.size();
    }

    uint64_t getSubVersions()
    {
        uint64_t ret = packetversion;
        for (auto item : subpackages)
            ret += item.getSubVersions();

        return ret;
    }

    uint64_t getValue()
    {
        uint64_t value = 0;
        switch (packettype)
        {
        case 4: // literal
            assert(0 == subpackages.size());
            value = literal;
            break;
        case 0: // sum
            for (auto item : subpackages)
                value += item.getValue();
            break;
        case 1: // prod
            value = 1;
            for (auto item : subpackages)
                value *= item.getValue();
            break;
        case 2: // min
            value = -1;
            for (auto item : subpackages)
                if (item.getValue() < value)
                    value = item.getValue();
            break;
        case 3: // max
            value = 0;
            for (auto item : subpackages)
                if (item.getValue() > value)
                    value = item.getValue();
            break;
        case 5: // greater than
            assert(2 == subpackages.size());
            value = (subpackages[0].getValue() > subpackages[1].getValue());
            break;
        case 6: // less than
            assert(2 == subpackages.size());
            value = (subpackages[0].getValue() < subpackages[1].getValue());
            break;
        case 7: // equal
            assert(2 == subpackages.size());
            value = (subpackages[0].getValue() == subpackages[1].getValue());
            break;
        default:
            cout << ":-o not implemented yet: " << (int)packettype << endl;
            break;
        }

        return value;
    }

private:
    const string inputstring;
    string binarystring;
    vector<uint8_t> input;

    uint8_t packetversion = 0;
    uint8_t packettype = 0;
    uint64_t literal = 0;
    uint8_t lengthtypeid = 0;
    uint64_t sublength = 0;

    vector<packetdecoder> subpackages;

    bool popfront()
    {
        assert(0 != input.size());
        bool retval = input[0];
        input.erase(input.begin());

        return retval;
    }

    bool checkInput()
    {
        for (auto item : input)
            if (item)
                return true;
        false;
    }
};

TEST_CASE("Testdata")
{
    packetdecoder testinstance("D2FE28");
    REQUIRE("110100101111111000101000" == testinstance.getBinaryString());
    REQUIRE(6 == testinstance.getPacketVersion());
    REQUIRE(4 == testinstance.getPacketType());
    REQUIRE(2021 == testinstance.getLiteral());
}

TEST_CASE("LengthTypeId0")
{
    packetdecoder testinstance("38006F45291200");
    REQUIRE("00111000000000000110111101000101001010010001001000000000" == testinstance.getBinaryString());
    REQUIRE(1 == testinstance.getPacketVersion());
    REQUIRE(6 == testinstance.getPacketType());
    REQUIRE(0 == testinstance.getLengthTypeId());
    REQUIRE(27 == testinstance.getSubLength());
}

TEST_CASE("LengthTypeId1")
{
    packetdecoder testinstance("EE00D40C823060");
    REQUIRE("11101110000000001101010000001100100000100011000001100000" == testinstance.getBinaryString());
    REQUIRE(7 == testinstance.getPacketVersion());
    REQUIRE(3 == testinstance.getPacketType());
    REQUIRE(1 == testinstance.getLengthTypeId());
    REQUIRE(3 == testinstance.getSubLength());
}

TEST_CASE("SubVersion1")
{
    packetdecoder testinstance("8A004A801A8002F478");
    REQUIRE(16 == testinstance.getSubVersions());

    packetdecoder testinstance2("620080001611562C8802118E34");
    REQUIRE(12 == testinstance2.getSubVersions());

    packetdecoder testinstance3("C0015000016115A2E0802F182340");
    REQUIRE(23 == testinstance3.getSubVersions());

    packetdecoder testinstance4("A0016C880162017C3686B18A3D4780");
    REQUIRE(31 == testinstance4.getSubVersions());
}

TEST_CASE("ValueTest")
{
    packetdecoder test1("C200B40A82");
    REQUIRE(3 == test1.getValue());

    packetdecoder test8("04005AC33890");
    REQUIRE(54 == test8.getValue());

    packetdecoder test2("880086C3E88112");
    REQUIRE(7 == test2.getValue());

    packetdecoder test3("CE00C43D881120");
    REQUIRE(9 == test3.getValue());

    packetdecoder test4("D8005AC2A8F0");
    REQUIRE(1 == test4.getValue());

    packetdecoder test5("F600BC2D8F");
    REQUIRE(0 == test5.getValue());

    packetdecoder test6("9C005AC2F8F0");
    REQUIRE(0 == test6.getValue());

    packetdecoder test7("9C0141080250320F1802104A08");
    REQUIRE(1 == test7.getValue());
}

TEST_CASE("Problem A ")
{
    packetdecoder problem("8054F9C95F9C1C973D000D0A79F6635986270B054AE9EE51F8001D395CCFE21042497E4A2F6200E1803B0C20846820043630C1F8A840087C6C8BB1688018395559A30997A8AE60064D17980291734016100622F41F8DC200F4118D3175400E896C068E98016E00790169A600590141EE0062801E8041E800F1A0036C28010402CD3801A60053007928018CA8014400EF2801D359FFA732A000D2623CADE7C907C2C96F5F6992AC440157F002032CE92CE9352AF9F4C0119BDEE93E6F9C55D004E66A8B335445009E1CCCEAFD299AA4C066AB1BD4C5804149C1193EE1967AB7F214CF74752B1E5CEDC02297838C649F6F9138300424B9C34B004A63CCF238A56B71520142A5A7FC672E5E00B080350663B44F1006A2047B8C51CC80286C0055253951F98469F1D86D3C1E600F80021118A124261006E23C7E8260008641A8D51F0C01299EC3F4B6A37CABD80252211221A600BC930D0057B2FAA31CDCEF6B76DADF1666FE2E000FA4905CB7239AFAC0660114B39C9BA492D4EBB180252E472AD6C00BF48C350F9F47D2012B6C014000436284628BE00087C5D8671F27F0C480259C9FE16D1F4B224942B6F39CAF767931CFC36BC800EA4FF9CE0CCE4FCA4600ACCC690DE738D39D006A000087C2A89D0DC401987B136259006AFA00ACA7DBA53EDB31F9F3DBF31900559C00BCCC4936473A639A559BC433EB625404300564D67001F59C8E3172892F498C802B1B0052690A69024F3C95554C0129484C370010196269D071003A079802DE0084E4A53E8CCDC2CA7350ED6549CEC4AC00404D3C30044D1BA78F25EF2CFF28A60084967D9C975003992DF8C240923C45300BE7DAA540E6936194E311802D800D2CB8FC9FA388A84DEFB1CB2CBCBDE9E9C8803A6B00526359F734673F28C367D2DE2F3005256B532D004C40198DF152130803D11211C7550056706E6F3E9D24B0");

    uint64_t resulta = problem.getSubVersions();
    cout << "Problem A: " << resulta << endl;
    REQUIRE(1007 == resulta);

    uint64_t resultb = problem.getValue();
    cout << "Problem B: " << resultb << endl;
    REQUIRE(834151779165 == resultb);
}
