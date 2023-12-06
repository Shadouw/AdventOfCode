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
    Boat(const long long _time, const long long _distance)
        : time(_time)
        , distance(_distance)
    {
    }

    long long getNumOfWins()
    {
        long long numOfWins = 0;

        for (long long i = 0; i < time; ++i) {
            if ((time - i) * i > distance)
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
        vector<string> strtime(stringtovector(input[0], ' '));
        // Distance
        vector<string> strdist(stringtovector(input[1], ' '));

        // Parse data
        string stime, sdist;
        for (long long i = 1; i < strdist.size(); ++i) {
            boats.push_back(Boat(stoll(strtime[i]), stoll(strdist[i])));
            stime += strtime[i];
            sdist += strdist[i];
        }

        time = stoll(stime);
        distance = stoll(sdist);
    }

    long long getNumOfWins()
    {
        long long numOfWins = 1;
        for (auto e : boats)
            numOfWins *= e.getNumOfWins();

        cout << "numOfWins: " << numOfWins << endl;
        return numOfWins;
    }

    long long getNumOfWin()
    {
        Boat myboat(time, distance);
        return myboat.getNumOfWins();
    }

private:
    const vector<string> input;
    vector<Boat> boats;

    // For part II
    long long time, distance;
};

TEST_CASE("Testdata")
{
    WaitForIt problemData(inputTestdata);
    REQUIRE(288 == problemData.getNumOfWins());
    REQUIRE(71503 == problemData.getNumOfWin());
}

TEST_CASE("WaitForIt")
{
    WaitForIt problemData(inputData);
    REQUIRE(303600 == problemData.getNumOfWins());
    REQUIRE(23654842 == problemData.getNumOfWin());
}

