#include <aoc.h>
using namespace std;
using namespace aoc;

class TheTyrannyOfTheRocketEquation {
public:
    TheTyrannyOfTheRocketEquation(string _file, string _extension)
        : datafile(_file, _extension)
    {
        for (auto elem : datafile.getLines())
            input.push_back(atol(elem.c_str()));
    }

    const vector<long> &getInput()
    {
        return input;
    }

private:
    aocdatafile datafile;
    vector<long> input;
};

long calcFuel(const long mass)
{
    return (mass / 3) - 2;
}

long calcRecursiveFuel(long mass)
{
    long ret = 0;

    while (mass > 0) {
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

TEST_CASE("TheTyrannyOfTheRocketEquation A")
{
    TheTyrannyOfTheRocketEquation thetyrannyoftherocketequation(__FILE__, "mydata");

    REQUIRE(3289802 == calcFuel(thetyrannyoftherocketequation.getInput()));
}

TEST_CASE("Testdata Fuel for Fuel")
{
    REQUIRE(2 == calcRecursiveFuel(14));
    REQUIRE(966 == calcRecursiveFuel(1969));
    REQUIRE(50346 == calcRecursiveFuel(100756));
}

TEST_CASE("TheTyrannyOfTheRocketEquation B")
{
    TheTyrannyOfTheRocketEquation thetyrannyoftherocketequation(__FILE__, "mydata");
    REQUIRE(4931831 == calcFuel(thetyrannyoftherocketequation.getInput(), true));
}