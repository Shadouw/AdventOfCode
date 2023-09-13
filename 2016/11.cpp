#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "The first floor contains a hydrogen-compatible microchip and a lithium-compatible microchip.",
    "The second floor contains a hydrogen generator.",
    "The third floor contains a lithium generator.",
    "The fourth floor contains nothing relevant."};

const vector<string> inputData = {
    "The first floor contains a polonium generator, a thulium generator, a thulium-compatible microchip, a promethium generator, a ruthenium generator, a ruthenium-compatible microchip, a cobalt generator, and a cobalt-compatible microchip.",
    "The second floor contains a polonium-compatible microchip and a promethium-compatible microchip.",
    "The third floor contains nothing relevant.",
    "The fourth floor contains nothing relevant."};

class status
{
public:
    status(int _iteration) : iteration(_iteration)
    {
    }

    void parseline(string line)
    {
        int floor = 0;
        if ("The first floor contains" == line.substr(0, 24))
        {
            floor = 1;
            line = line.substr(24);
        }
        else if ("The second floor contains" == line.substr(0, 25))
        {
            floor = 2;
            line = line.substr(25);
        }
        else if ("The third floor contains" == line.substr(0, 24))
        {
            floor = 3;
            line = line.substr(24);
        }
        else if ("The fourth floor contains" == line.substr(0, 25))
        {
            floor = 4;
            line = line.substr(25);
        }
        else
            cout << "Unknown line: '" << line << "'" << endl;

        auto pos = line.find(" a ");
        while (string::npos != pos)
        {
            auto pos2 = line.find_first_of("- ", pos + 3);
            if (string::npos == pos2)
                cout << "Unexpected end of line: '" << line << "'";

            string element = line.substr(pos + 3, pos2 - (pos + 3));

            if ('-' == line[pos2])
                microchips[element] = floor;
            else
                generators[element] = floor;

            pos = line.find(" a ", pos2);
        }
    }

private:
    map<string, int> generators;
    map<string, int> microchips;

    int iteration;

    friend class RadioisotopeThermoelectricGenerators;
};

class RadioisotopeThermoelectricGenerators
{
public:
    RadioisotopeThermoelectricGenerators(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        status initstatus(0);

        // Parse data
        for (auto elem : input)
            initstatus.parseline(elem);

        statuss.push_back(initstatus);
    }

    long getResultA()
    {
        long resultA = 0;
        // for (auto e : statuss)
        //     resultA += e.getResultA();

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = 0;
        // for (auto e : statuss)
        //     resultB += e.getResultB();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    vector<status> statuss;
};

TEST_CASE("Testdata")
{
    RadioisotopeThermoelectricGenerators RadioisotopeThermoelectricGeneratorsData(inputTestdata);
    REQUIRE(11 == RadioisotopeThermoelectricGeneratorsData.getResultA());
    REQUIRE(0 == RadioisotopeThermoelectricGeneratorsData.getResultB());
}

TEST_CASE("RadioisotopeThermoelectricGenerators")
{
    RadioisotopeThermoelectricGenerators RadioisotopeThermoelectricGeneratorsData(inputData);
    REQUIRE(0 == RadioisotopeThermoelectricGeneratorsData.getResultA());
    REQUIRE(0 == RadioisotopeThermoelectricGeneratorsData.getResultB());
}