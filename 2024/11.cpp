#include <aoc.h>
using namespace std;

const string inputData = {
    "5 62914 65 972 0 805922 6521 1639064"
};

class Stone {
public:
    Stone() { }
    Stone(const string _input)
        : input(_input)
    {
    }

    string blink()
    {
        long number = atol(input.c_str());
        string s2;
        if (0 == number)
            input = "1";
        else if (input.size() % 2 == 0) {
            s2 = input.substr(0, input.size() / 2);
            input = to_string(atol(input.substr(input.size() / 2).c_str()));
        } else {
            input = to_string(number * 2024);
        }

        return s2;
    }

    string getString() { return input; }

    friend bool operator<(const Stone& l, const Stone& r)
    {
        return l.input < r.input;
    }

private:
    string input;

    friend class PlutonianPebbles;
};

class PlutonianPebbles {
public:
    PlutonianPebbles(const string& _input)
        : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : stringtovector(input, ' '))
            Stones.push_back(Stone(elem));
    }

    void blink()
    {
        /*
        for (vector<Stone>::size_type s = 0; s < Stones.size(); ++s) {
            auto s2 = Stones[s].blink();

            if ("" != s2) {
                Stones.insert(Stones.begin()+s, { s2 });
                s++;
            }
        }
        */

        vector<Stone> tempStones;
        // for (auto s : Stones) {
        while (Stones.size()) {
            auto s = Stones.front();
            Stones.erase(Stones.begin());

            auto s2 = s.blink();
            if ("" != s2) {
                tempStones.push_back({ s2 });
                Stoned.insert(s2);
            }
            tempStones.push_back(s);
            Stoned.insert(s.input);
        }
        // Stones.clear();
        Stones = tempStones;
    }

    void blink(long i)
    {
        for (auto j = 0; j < i; ++j) {
            blink();
            cout << j << "/" << Stoned.size() << ": " << Stones.size() << endl;
        }
    }

    string getString()
    {
        string ret;

        for (auto s : Stones) {
            ret += s.input + " ";
        }

        return ret;
    }

    long getNumberofStones() { return Stones.size(); }

private:
    const string input;
    vector<Stone> Stones;

    // How many different values do actually exist?
    // I wonder if I can save lot of memory if I check, if something already exists and build kind of tree.
    set<string> Stoned;
};

TEST_CASE("Test1")
{
    PlutonianPebbles problemData("0 1 10 99 999");
    problemData.blink(1);
    REQUIRE("1 2024 1 0 9 9 2021976 " == problemData.getString());
}

TEST_CASE("Test2")
{
    PlutonianPebbles problemData("125 17");
    problemData.blink();
    REQUIRE("253000 1 7 " == problemData.getString());

    problemData.blink();
    REQUIRE("253 0 2024 14168 " == problemData.getString());
    problemData.blink();
    REQUIRE("512072 1 20 24 28676032 " == problemData.getString());
    problemData.blink();
    REQUIRE("512 72 2024 2 0 2 4 2867 6032 " == problemData.getString());
    problemData.blink();
    REQUIRE("1036288 7 2 20 24 4048 1 4048 8096 28 67 60 32 " == problemData.getString());
    problemData.blink();
    REQUIRE("2097446912 14168 4048 2 0 2 4 40 48 2024 40 48 80 96 2 8 6 7 6 0 3 2 " == problemData.getString());

    REQUIRE(22 == problemData.getNumberofStones());

    problemData.blink(19);
    REQUIRE(55312 == problemData.getNumberofStones());
}

TEST_CASE("PlutonianPebbles")
{
    PlutonianPebbles problemData(inputData);
    problemData.blink(25);
    REQUIRE(199753 == problemData.getNumberofStones());
    problemData.blink(50);
    REQUIRE(-1 == problemData.getNumberofStones());
}