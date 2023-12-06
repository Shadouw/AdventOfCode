#include <iostream>
#include <string>
#include <vector>

#include <stringtovector.h>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "Time:      7  15   30",
    "Distance:  9  40  200"
};

const vector<string> inputData = {
    "Time:        38     67     76     73",
    "Distance:   234   1027   1157   1236"
};

class Boat {
public:
    Boat(const long _time, const long _distance)
        : time(_time), distance(_distance)
    {
    }

    long getNumOfWins()
    {
        long numOfWins = 0;

        for ( long i=0; i<time; ++i)
        {
            if ( (time-i)*i > distance )
                ++numOfWins;
        }

        return numOfWins;
    }

    long getResultB()
    {
        long resultB = 0;

        return resultB;
    }

private:
    long time, distance;

    friend class WaitForIt;
};

class WaitForIt {
public:
    WaitForIt(const vector<string>& _input)
        : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Time
        vector<string> strtime ( stringtovector(input[0], ' '));
        // Distance
        vector<string> strdist ( stringtovector(input[1], ' '));

        // Parse data
        for ( long i = 1; i<strdist.size(); ++i )
            items.push_back(Boat(stoi(strtime[i]), stoi(strdist[i])));
    }

    long getNumOfWins()
    {
        long numOfWins = 1;
        for (auto e : items)
            numOfWins *= e.getNumOfWins();

        cout << "numOfWins: " << numOfWins << endl;
        return numOfWins;
    }
    long getResultB()
    {
        long resultB = 0;
        for (auto e : items)
            resultB += e.getResultB();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    vector<Boat> items;
};

TEST_CASE("Testdata")
{
    WaitForIt problemData(inputTestdata);
    REQUIRE(288 == problemData.getNumOfWins());
    REQUIRE(0 == problemData.getResultB());
}

TEST_CASE("WaitForIt")
{
    WaitForIt problemData(inputData);
    REQUIRE(303600 == problemData.getNumOfWins());
    REQUIRE(0 == problemData.getResultB());
}
