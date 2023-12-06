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

const vector<string> inputTestdata2 = {
    "Time:      71530",
    "Distance:  940200"
};

const vector<string> inputData = {
    "Time:        38     67     76     73",
    "Distance:   234   1027   1157   1236"
};

const vector<string> inputData2 = {
    "Time:        38677673",
    "Distance:   234102711571236"
};

class Boat {
public:
    Boat(const long long _time, const long long _distance)
        : time(_time), distance(_distance)
    {
    }

    long long getNumOfWins()
    {
        long long numOfWins = 0;

        for ( long long i=0; i<time; ++i)
        {
            if ( (time-i)*i > distance )
                ++numOfWins;
        }

        return numOfWins;
    }

private:
    long long time, distance;

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
        for ( long long i = 1; i<strdist.size(); ++i )
            items.push_back(Boat(stoll(strtime[i]), stoll(strdist[i])));
    }

    long long getNumOfWins()
    {
        long long numOfWins = 1;
        for (auto e : items)
            numOfWins *= e.getNumOfWins();

        cout << "numOfWins: " << numOfWins << endl;
        return numOfWins;
    }

private:
    const vector<string> input;
    vector<Boat> items;
};

TEST_CASE("Testdata")
{
    WaitForIt problemData(inputTestdata);
    REQUIRE(288 == problemData.getNumOfWins());
}

TEST_CASE("Testdata2")
{
    WaitForIt problemData(inputTestdata2);
    REQUIRE(71503 == problemData.getNumOfWins());
}

TEST_CASE("WaitForIt")
{
    WaitForIt problemData(inputData);
    REQUIRE(303600 == problemData.getNumOfWins());
}

TEST_CASE("WaitForIt2")
{
    WaitForIt problemData(inputData2);
    REQUIRE(23654842 == problemData.getNumOfWins());
}
