#include <aoc.h>
using namespace std;
using namespace aoc;

class MullItOver {
public:
    MullItOver(string _file, string _extension)
    : datafile(_file, _extension)
    {
        // Parse data
        for (auto elem : datafile.getLines())
            Memory += elem;
    }

    static long getMult(const string _Memory)
    {
        regex mul_regex("mul\\(([0-9]+),([0-9]+)\\)");
        long Mult = 0;

        auto mul_begin = sregex_iterator(_Memory.begin(), _Memory.end(), mul_regex);
        auto mul_end = sregex_iterator();

        for (auto i = mul_begin; i != mul_end; ++i) {
            smatch match = *i;
            string match_str = match.str();
            Mult += atol(((string)match[1]).c_str()) * atol(((string)match[2]).c_str());
        }

        return Mult;
    }

    long getMult()
    {
        long Mult = getMult(Memory);
        cout << "Mult: " << Mult << endl;
        return Mult;
    }

    long getMultFixed()
    {
        string _Memory(Memory);

        auto posdont = _Memory.find("don't()");
        auto posdo = _Memory.find("do()");

        while (posdo != string::npos || posdont != string::npos) {
            if (posdont < posdo)
                _Memory = _Memory.replace(posdont, posdo + 4 - posdont, "");
            else if (posdo < posdont) // Just remove do()
                _Memory = _Memory.replace(posdo, 4, "");
            else
                cout << "Special case: " << posdont << "/" << posdo << endl;

            posdont = _Memory.find("don't()");
            posdo = _Memory.find("do()");
        };

        long MultFixed = getMult(_Memory);

        cout << "MultFixed: " << MultFixed << endl;
        return MultFixed;
    }

private:
    aocdatafile datafile;
    string Memory;
};

TEST_CASE("Testdata")
{
    MullItOver MullItOverData(__FILE__, "example");
    REQUIRE(161 == MullItOverData.getMult());
    REQUIRE(48 == MullItOverData.getMultFixed());
}

TEST_CASE("MullItOver")
{
    MullItOver MullItOverData(__FILE__, "mydata");
    REQUIRE(166630675 == MullItOverData.getMult());
    REQUIRE(93465710 == MullItOverData.getMultFixed());
}
