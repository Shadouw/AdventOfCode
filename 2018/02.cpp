#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "abcdef",
    "bababc",
    "abbcde",
    "abcccd",
    "aabcdd",
    "abcdee",
    "ababab"};

const vector<string> inputTestdata2 = {
    "abcde",
    "fghij",
    "klmno",
    "pqrst",
    "fguij",
    "axcye",
    "wvxyz"};

const vector<string> inputData = {
    "xrysntkqrduheficajodiglvzw",
    "xzymntkqrbuhefmcajodiflvzw",
    "xpysetkyrbuhefmcajodiglvgw",
    "xtysnykqrbuhefmczjodiglvzw",
    "xpysntkqyvuhefmjajodiglvzw",
    "xpysntkqrbuqjfmcajodiglvzu",
    "xpysntkqrbuhefmvaoodimlvzw",
    "xplsntkqrbuhefmcajohimlvzw",
    "cpysntkqrbuhefmcajodiglpmw",
    "xpysndkqrbuhefmcajzdiglmzw",
    "xpysntkqrbuhsfmctjoqiglvzw",
    "xpysztkkrbuhewmcajodiglvzw",
    "xpysntkguzuhefmcajodiglvzw",
    "xpysnbkvrbuhyfmcajodiglvzw",
    "xpgsntkqrbphefmcajodzglvzw",
    "xpysntkqrbdhefmcajodvgqvzw",
    "xpmsntkqrbuhedmcajodiglvnw",
    "wpysntkqmbuheemcajodiglvzw",
    "xpysntdvrbuhdfmcajodiglvzw",
    "xpbsetkqrbuhefmcayodiglvzw",
    "xpasntkqrbuhefmcajydigovzw",
    "xpylntkqrbuhefmcajudiglnzw",
    "xpysqtkqrbuoefmcrjodiglvzw",
    "xlysntkqrbuhefmuejodiglvzw",
    "xpysntkqrzuhewmcajodaglvzw",
    "xpysotkqrbuhefmxajowiglvzw",
    "xpysntkqrbuhefmcajodinlyza",
    "xpysntkqrbuhemmmajofiglvzw",
    "xpysntkqcbuhezmcyjodiglvzw",
    "xpysntyqrbuhefmcajodiglvfn",
    "xpysntkqrbudefmcarodcglvzw",
    "xpysntkqrjuhefkcajodiglvzg",
    "xpysntkqrbuhefmcahooiglvow",
    "xpysntkqrqfhevmcajodiglvzw",
    "xpysntlqrbuhefmcajodivlvzu",
    "xpyjotkqrbuhefmcavodiglvzw",
    "xpysntqqrbuhebmcgjodiglvzw",
    "xpjsnikqbbuhefmcajodiglvzw",
    "xpysntkqrbuhefmcalodeflvzw",
    "xpysntktrbuhefmcaqoviglvzw",
    "xpysntkqrbuhefmcrjogiglvzk",
    "xpysntkqrjuhekmcajodixlvzw",
    "xpypntyqrbuhefmcajodigzvzw",
    "cpysnwkqrbuhefmcajodiglvww",
    "xpysntkqqbuqefmcajodiglvlw",
    "xpysntkqrbuhvfmcajldiglvzh",
    "xpysntkqrbuhefmzmjodislvzw",
    "xpysnnkqrbuhefmcajodjplyzw",
    "xpysntdqobuhefmcajbdiglvzw",
    "xpyzntknrbuhefmcajodigtvzw",
    "xpysntkqbbohefmcajodialvzw",
    "xpysntkqryuhefmcayoxiglvzw",
    "xxysntkqrbuhefmcajodiglgzl",
    "jzysntkqrbuhmfmcajodiglvzw",
    "xpysntocrbuhefmcakodiglvzw",
    "xpysntkqrbuheomrgjodiglvzw",
    "xpysntkerbuhefmxajoduglvzw",
    "xpysntkqobuhefpcajodiglvzd",
    "xpysntkqrbvhefmcajopislvzw",
    "xpysntkqrbuhefucqjodiglvqw",
    "xpysvtkqrbuhdfmcajokiglvzw",
    "xqysnjkqrbuhemmcajodiglvzw",
    "xpysnteqxbuhefmcajodiglvdw",
    "xpysntkqrbuhefzcajodignvzc",
    "xpysntkqrbuledmcajoyiglvzw",
    "xpysntkqrbuhofmcajkdigpvzw",
    "xpysmtkqrbuhefmcajodaglvze",
    "xlysntiqrbuhefmqajodiglvzw",
    "xpysntvqrbugefmcajodiglizw",
    "xpysntkqrbuhefmuwjndiglvzw",
    "ypysntkqrbuhefmbajodislvzw",
    "xpycntkqrbuhemmcaqodiglvzw",
    "xpysntkqrbuhefmcajobivdvzw",
    "xpysnfkprbuhefmcajodiglvkw",
    "xtysntkwrjuhefmcajodiglvzw",
    "xpysntkqrbqhefmcaxodiulvzw",
    "xpysntkqrbuhefmcajsdigkvkw",
    "xpysnekqrbugefmcajwdiglvzw",
    "xpysntkqjbuhefmcajoduglbzw",
    "xpysntkqrbohlfmcajodiggvzw",
    "xpysntkqrbfhefmcajodiglhnw",
    "xpmsntkirbusefmcajodiglvzw",
    "xpnsntkqrbehefmcajodigrvzw",
    "xpytntgqrbuhefmcajodigllzw",
    "xpysntkqrbuhefmcejodiglvvm",
    "xpyvntkqrbuhefmmajodiglmzw",
    "rpysntkirbuhefmcajodiglyzw",
    "xpysntkqrbuhefmcajoznglvzz",
    "xpysntkqrbmhefmcafodigwvzw",
    "xpysntkqrbuhetmcarodiglvzx",
    "xpysntnqrbuhefmcajogiglfzw",
    "xpysutkqjbuheomcajodiglvzw",
    "xpysnqkprbuhefkcajodiglvzw",
    "xpysntuqrbuhemmcajodyglvzw",
    "spysntkqrbupefmcajodigpvzw",
    "qpygntkqrbuhefmcajodqglvzw",
    "xpysnteqrbuhefmcatodiylvzw",
    "xpysntkqrbusefsckjodiglvzw",
    "xpysntkqrbubeflcajodiglvcw",
    "xpysntwqrbuhefmcajodigekzw",
    "xpysntkqrbuhefmcnjodiguvtw",
    "xpysntkqrbqhefmkasodiglvzw",
    "xmysntkqrbuhefmkcjodiglvzw",
    "xpysntkqrquhefmcajodiouvzw",
    "xpysnnkqrbuhefmcajodiplyzw",
    "xpysntkorbuhefaqajodiglvzw",
    "npysntkqobuhefmcajodiglvfw",
    "xlysntkqrbuhefmcazbdiglvzw",
    "xpysftkqrbihefmcajodiglezw",
    "xpysolqqrbuhefmcajodiglvzw",
    "xpysntkqrwuheixcajodiglvzw",
    "xoysntkqibuhefmcqjodiglvzw",
    "xpysntkqrbupefmcajodtulvzw",
    "xpyentkqrbuhvfmcajudiglvzw",
    "xpysntksrbuhefmgajodqglvzw",
    "xpysntkqrbuhcfmcvjodigldzw",
    "gpyrntdqrbuhefmcajodiglvzw",
    "vpysntvqrbuhefmcajndiglvzw",
    "xpvsntkqrbuhefvcajhdiglvzw",
    "xpysntkqrbubefmcajowiglvzl",
    "xpysndkqibuhefmcajodiblvzw",
    "xpysntkqrbuhefmldjodjglvzw",
    "xpysntzqrbuhefmcyjomiglvzw",
    "xpysntkqrbuhefmedjodiwlvzw",
    "xpysntklrbuhefmcyjodiglvjw",
    "xpypnlkqrbehefmcajodiglvzw",
    "xpysntkqrbuhefycacodiglvzz",
    "ypysntkqrbuhefmcajadiglvew",
    "xpysntkqobuhefmcajadiglhzw",
    "xpysbtxlrbuhefmcajodiglvzw",
    "xpysntkqrbuhefdcajoviglvww",
    "xpysntkqrbuhefmcaaodiblvzc",
    "wpysntkqrbuhefmcajddiglvbw",
    "wpysntmqrbuhefmcajodiglvza",
    "epysntkqrbuhemmcajoniglvzw",
    "vpysntkqrbuhejmcajodiglvzo",
    "xpysntkqrbuhebmmajodiglazw",
    "lpysntkqrguhtfmcajodiglvzw",
    "xpksndkqpbuhefmcajodiglvzw",
    "xpydnukqrbuhefmcajmdiglvzw",
    "xpysnmkqrbuhefioajodiglvzw",
    "xpysntkqruuhefmcajodyglvzx",
    "xpysntkqrmuhefmcmjidiglvzw",
    "xpysntksrbupefmcajodiplvzw",
    "xpykntkqrbuhefmmajodiglxzw",
    "xpssntkqrbuhefmzajodiglvgw",
    "xpysntkqrbuhefmcrjodigovzd",
    "xpysntkqrbuhefmpajodirlvqw",
    "xpysnskqrruhefmtajodiglvzw",
    "xpysnzkqrbuhezmcajodiglvzj",
    "xpysntkcrburefmckjodiglvzw",
    "xpysntkqrbuhefecpoodiglvzw",
    "xpysnjkqrbuhexmcajodigrvzw",
    "xpysztkqhbuhefmcanodiglvzw",
    "xpysntkqrbuhefmcajozyelvzw",
    "xpyuntkmrbuhefmcajodigcvzw",
    "xpysnykmrbuhefmaajodiglvzw",
    "jpysntkqrbuhefmcajodigumzw",
    "xtysntkqhbuhefmcajodiglvzz",
    "xpysntkqrbqhefmcxjouiglvzw",
    "xpysntkqreujefmmajodiglvzw",
    "xnysntzqrbuhefacajodiglvzw",
    "xpysntkqriuhefmcajkdiqlvzw",
    "xposntkqrbuheffcajodihlvzw",
    "xpysntkqpquhefmcajodrglvzw",
    "xpysjtkqrbudefmcajouiglvzw",
    "xpysnxkqrbulefmcacodiglvzw",
    "xpygntkqrbuhefmfajzdiglvzw",
    "xpysntkqrbuhefmuayodiglyzw",
    "xpysnbksrbuhefmcajediglvzw",
    "xkyzntkqrbuhefmcajodiglvzz",
    "xpysntkqrbehlxmcajodiglvzw",
    "xpysntkqryuhefmcaxodiklvzw",
    "xpysntdqrbuhefmcjjodiglvzt",
    "xpysntkqrbuhefmcauodigqvzy",
    "xpysftkqrbuhefmcajodrgvvzw",
    "xpysntkqrbuhefmczjodiglivw",
    "xpysatkorbuhefmcyjodiglvzw",
    "xhysntkqrbthefmcajodxglvzw",
    "xpysnpkqrbuhefmcajoqyglvzw",
    "xpyyntkqrbuhefmcjjodxglvzw",
    "xpysntkqrozhefhcajodiglvzw",
    "xpymftkqrbuhefmcajodiglvzo",
    "xpysntkqrbuhvfmcajodiyllzw",
    "xpysatsqrbuhefmcajodiglvzo",
    "cpysntkqqbuhefmcajodlglvzw",
    "xpysntkyrblhefmcajodiglvzz",
    "xpysntkfrbuhefbcajodiglbzw",
    "upysotkqrbuhpfmcajodiglvzw",
    "xpysdokqrbuheflcajodiglvzw",
    "xrysntkqrbuhefpcanodiglvzw",
    "xdysntkqrbuhefpcajodiglmzw",
    "xpyynteqrbjhefmcajodiglvzw",
    "xpysntkqrbuhefkcajodielvhw",
    "xplsktkqrbuhefmcajodtglvzw",
    "xpysrtkqrbuhefmcdjodiglvzx",
    "upysntkmrbuhefmcajodiglvzt",
    "xnysnpkqrbusefmcajodiglvzw",
    "xtysntnqrbuhexmcajodiglvzw",
    "xpysngkmrbfhefmcajodiglvzw",
    "xpysnhkhrbuhefmcajodiplvzw",
    "xpysntvqrbuhefmcaoodsglvzw",
    "xpyzntkqrbuhefmcajlviglvzw",
    "xpysndkqrbuievmcajodiglvzw",
    "xpysntkqrsuhcfzcajodiglvzw",
    "xpysntkqlbuhefmcajjdlglvzw",
    "xpysntkqrbuhifmcajoliylvzw",
    "xpysntkqxbphefmcajodialvzw",
    "bnyswtkqrbuhefmcajodiglvzw",
    "upysatkqrbuhefmcajodvglvzw",
    "xpysntkqqbuhefmcajodxglzzw",
    "xpysntkqryuhefmcafodinlvzw",
    "xpzsntkqrcuhefmcajokiglvzw",
    "xpynntkqrbuheimccjodiglvzw",
    "xpysnfkqduuhefmcajodiglvzw",
    "xpywntkqrbuhefmcajodigllzz",
    "xpysftkqrbahefmcajsdiglvzw",
    "xpysntkkrbutefmcljodiglvzw",
    "xfysntkqrbbhkfmcajodiglvzw",
    "xpysgtksrbuhefkcajodiglvzw",
    "xpysntyqrbuhefmcajodijlvzg",
    "xpysnpkqobuhefmcljodiglvzw",
    "xvysntkqrbuhefmcsjodiclvzw",
    "xpysntkqrtuhwfmcajodillvzw",
    "xpysntkprbuhejmcajouiglvzw",
    "apysntkqrbuhefmcaboviglvzw",
    "xpysqykqrbuhefmcajodirlvzw",
    "xpysntkqrluhefmcajowiglvzf",
    "dpysnokqrbuhefmcajoaiglvzw",
    "xppsntkqmbuheumcajodiglvzw",
    "xpysntkqrbuhlymcaoodiglvzw",
    "dpysntkqrbuhmfmcajodiglvzt",
    "xpysltbqrbuhefmcajoliglvzw",
    "xpysntpqrbuhefmcnjoniglvzw",
    "xpysntpqrbuhektcajodiglvzw",
    "xpysntkhrbshefmqajodiglvzw",
    "zpysntuqrbuhefmcajmdiglvzw",
    "xpysxtdqrbuhefmcajoyiglvzw",
    "xpysntkubbumefmcajodiglvzw",
    "xpysntkqzouhefmcajsdiglvzw",
    "xpysntkqrbuhefmcojoziglvyw",
    "jpysntkqrmuhefmcajodidlvzw",
    "xpmsttkqrhuhefmcajodiglvzw",
    "xpysntkqlbuhefmcajgdiflvzw",
    "xpysntxkrbuhefmcauodiglvzw",
    "xpysotkqubuhefscajodiglvzw",
    "xjysntkqrbvheemcajodiglvzw",
    "xpykntkqrbuhefmcpjodiglvow",
    "xplsntkqrbuvefmcajediglvzw",
    "upysntwqrbuhefmfajodiglvzw"};

class item
{
public:
    item(const string _input) : input(_input)
    {
        for ( auto c : input )
            ++counter[c];
    }

    bool checkRudimentaryChecksum(unsigned int count)
    {
        for ( auto c: counter )
            if (count == c.second)
                return true;

        return false;
    }

    string getString() { return input; }

private:
    string input;
    map<char, unsigned int> counter;

    friend class InventoryManagementSystem;
};

class InventoryManagementSystem
{
public:
    InventoryManagementSystem(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input)
            items.push_back(item(elem));
    }

    long getRudimentaryChecksum()
    {
        long RudimentaryChecksum = 0;
        long RudimentaryChecksum2 = 0;
        long RudimentaryChecksum3 = 0;

        for (auto e : items)
        {
            if (e.checkRudimentaryChecksum(2))
                ++RudimentaryChecksum2;

            if (e.checkRudimentaryChecksum(3))
                ++RudimentaryChecksum3;
        }

        RudimentaryChecksum = RudimentaryChecksum2 * RudimentaryChecksum3;
        cout << "RudimentaryChecksum: " << RudimentaryChecksum << endl;
        return RudimentaryChecksum;
    }
    string getCommonLetters()
    {
        string CommonLetters;
        for (auto e1 : items)
            for (auto e2 : items)
                if ( e1.input != e2.input )
                {
                    assert(e1.input.size() == e2.input.size());

                    unsigned int counter = 0;
                    for ( int i=0; i<e1.input.size(); ++i )
                        if (e1.input[i] != e2.input[i])
                            ++counter;

                    if ( 1 == counter && 0==CommonLetters.size() )
                        for ( int i=0; i<e1.input.size(); ++i )
                            if (e1.input[i] == e2.input[i])
                                CommonLetters += e1.input[i];


                }

        cout << "CommonLetters: " << CommonLetters << endl;
        return CommonLetters;
    }

private:
    const vector<string> input;
    vector<item> items;
};

TEST_CASE("Testdata")
{
    InventoryManagementSystem InventoryManagementSystemData(inputTestdata);
    REQUIRE(12 == InventoryManagementSystemData.getRudimentaryChecksum());
}

TEST_CASE("Testdata1")
{
    InventoryManagementSystem InventoryManagementSystemData(inputTestdata2);
    REQUIRE("fgij" == InventoryManagementSystemData.getCommonLetters());
}

TEST_CASE("InventoryManagementSystem")
{
    InventoryManagementSystem InventoryManagementSystemData(inputData);
    REQUIRE(6200 == InventoryManagementSystemData.getRudimentaryChecksum());
    REQUIRE("xpysnnkqrbuhefmcajodplyzw" == InventoryManagementSystemData.getCommonLetters());
}