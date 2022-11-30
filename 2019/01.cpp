#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<long> inputA = {
    83285,
    96868,
    121640,
    51455,
    128067,
    128390,
    141809,
    52325,
    68310,
    140707,
    124520,
    149678,
    87961,
    52040,
    133133,
    52203,
    117483,
    85643,
    84414,
    86558,
    65402,
    122692,
    88565,
    61895,
    126271,
    128802,
    140363,
    109764,
    53600,
    114391,
    98973,
    124467,
    99574,
    69140,
    144856,
    56809,
    149944,
    138738,
    128823,
    82776,
    77557,
    51994,
    74322,
    64716,
    114506,
    124074,
    73096,
    97066,
    96731,
    149307,
    135626,
    121413,
    69575,
    98581,
    50570,
    60754,
    94843,
    72165,
    146504,
    53290,
    63491,
    50936,
    79644,
    119081,
    70218,
    85849,
    133228,
    114550,
    131943,
    67288,
    68499,
    80512,
    148872,
    99264,
    119723,
    68295,
    90348,
    146534,
    52661,
    99146,
    95993,
    130363,
    78956,
    126736,
    82065,
    77227,
    129950,
    97946,
    132345,
    107137,
    79623,
    148477,
    88928,
    118911,
    75277,
    97162,
    80664,
    149742,
    88983,
    74518};

class problem
{
public:
    problem(const vector<long> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;
    }

    void listinput()
    {
        for (auto elem : input)
        {
            cout << elem << endl;
        }
    }

    int getresultA()
    {
        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    int getresultB()
    {
        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<long> input;
    int resultA = 0;
    int resultB = 0;
};

long calcFuel(const long mass)
{
    return (mass / 3) - 2;
}

long calcRecursiveFuel(long mass)
{
    long ret = 0;

    while (mass > 0)
    {
        mass = calcFuel(mass);
        if (mass > 0)
            ret += mass;
    }

    return ret;
}

long calcFuel(const vector<long> input, bool recursive = false)
{
    long retval = 0;
    for (auto e : input)
        if (!recursive)
            retval += calcFuel(e);
        else
            retval += calcRecursiveFuel(e);

    return retval;
}

TEST_CASE("Testdata")
{
    REQUIRE(2 == calcFuel(12));
    REQUIRE(2 == calcFuel(14));
    REQUIRE(654 == calcFuel(1969));
    REQUIRE(33583 == calcFuel(100756));
}

TEST_CASE("Problem A")
{
    REQUIRE(3289802 == calcFuel(inputA));
}

TEST_CASE("Testdata Fuel for Fuel")
{
    REQUIRE(2 == calcRecursiveFuel(14));
    REQUIRE(966 == calcRecursiveFuel(1969));
    REQUIRE(50346 == calcRecursiveFuel(100756));
}

TEST_CASE("Problem B")
{
    REQUIRE(4931831 == calcFuel(inputA, true));
}