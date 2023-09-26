#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>

#include <catch2/catch_test_macros.hpp>

using namespace std;

typedef pair<int, int> POSITION;

class status
{
public:
    status(const POSITION &pos, int _dfn, int _iteration) : position(pos), dfn(_dfn), iteration(_iteration)
    {
    }

    bool getWall(POSITION pos) const
    {
        int x = pos.first;
        int y = pos.second;

        long sum = x * x + 3 * x + 2 * x * y + y + y * y;
        sum += dfn;

        int bits = 0;
        while (sum)
        {
            bits += sum & 1;
            sum >>= 1;
        }

        return bits % 2;
    }

    bool isValid() const
    {
        if (getWall(position))
            return false;

        return position.first >= 0 && position.second >= 0;
    }

    void printMaze(POSITION size)
    {
        for (int y = 0; y <= size.second; ++y)
        {
            for (int x = 0; x <= size.first; ++x)
            {
                cout << (getWall({x, y}) ? "#" : ".");
            }
            cout << endl;
        }
    }

private:
    pair<int, int> position;
    int dfn;
    int iteration;

    friend class AMazeOfTwistyLittleCubicles;
};

class AMazeOfTwistyLittleCubicles
{
public:
    AMazeOfTwistyLittleCubicles(const int _dfn) : dfn(_dfn)
    {
        status init({1, 1}, dfn, 0);
        stati.push(init);

        // test.printMaze({9,6});
    }

    bool checkIfStatusExists(const status &s)
    {
        if ( 1==s.position.first && 1==s.position.second )
            return true;

        int ret = seenstati[s.position];

        if (0 == ret)
            seenstati[s.position] = s.iteration;

        return ret;
    }

    long getToPosition(const POSITION dest)
    {
        long currentIteration = 0;

        while (stati.size() != 0)
        {
            const status currentstatus = stati.front();
            stati.pop();

            if (currentstatus.iteration != currentIteration)
            {
                currentIteration = currentstatus.iteration;
                cout << "Iteration: " << currentIteration << " Size: " << stati.size() << endl;
            }

            for (int _x = -1; _x <= 1; ++_x)
            {
                for (int _y = -1; _y <= 1; ++_y)
                {
                    if ((_x == 0 || _y == 0) && (_x != 0 || _y != 0))
                    {
                        status newstatus({currentstatus.position.first + _x, currentstatus.position.second + _y}, dfn, currentstatus.iteration + 1);

                        if (dest == newstatus.position)
                            return newstatus.iteration;

                        if (newstatus.isValid())
                        {
                            if (!checkIfStatusExists(newstatus))
                            {
                                stati.push(newstatus);
                            }
                        }
                    }
                }
            }
        }

        return 0;
    }

    long getResultB()
    {
        long resultB = 0;

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    queue<status> stati;
    map<POSITION, int> seenstati;

    const int dfn; // designer's favorite number
};

TEST_CASE("Testdata")
{
    AMazeOfTwistyLittleCubicles AMazeOfTwistyLittleCubiclesData(10);
    REQUIRE(11 == AMazeOfTwistyLittleCubiclesData.getToPosition({7, 4}));
    REQUIRE(0 == AMazeOfTwistyLittleCubiclesData.getResultB());
}

TEST_CASE("AMazeOfTwistyLittleCubicles")
{
    AMazeOfTwistyLittleCubicles AMazeOfTwistyLittleCubiclesData(1352);
    REQUIRE(90 == AMazeOfTwistyLittleCubiclesData.getToPosition({31, 39}));
    // REQUIRE(0 == AMazeOfTwistyLittleCubiclesData.getResultB());
}