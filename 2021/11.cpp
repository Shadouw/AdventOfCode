#include <iostream>
#include <string>
#include <vector>
#include <array>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputT = {
    "5483143223",
    "2745854711",
    "5264556173",
    "6141336146",
    "6357385478",
    "4167524645",
    "2176841721",
    "6882881134",
    "4846848554",
    "5283751526"};

const vector<string> inputA = {
    "8448854321",
    "4447645251",
    "6542573645",
    "4725275268",
    "6442514153",
    "4515734868",
    "5513676158",
    "3257376185",
    "2172424467",
    "6775163586"};

const vector<string> inputB = {
    ""};

class problem
{
public:
    problem(const vector<string> &_input) : input(_input), 
                                            sizex(input.size()), sizey(input[0].length())
    {
        cout << "Size of Input: " << sizex << endl;
        cout << "Welcome to the first line: " << sizey << endl;

        octopus = new int *[sizex];
        for (int x = 0; x < sizex; ++x)
        {
            octopus[x] = new int[sizey];
            for (int y = 0; y < sizey; ++y)
            {
                octopus[x][y] = input[x][y] - '0';
            }
        }
    }

    ~problem()
    {
        for (int x = 0; x < sizex; ++x)
            delete[] octopus[x];

        delete[] octopus;
    }

    void listinput()
    {
        for (auto elem : input)
        {
            cout << elem << endl;
        }
    }

    int flashstep(int _n)
    {
        int oldflashcount = flashcount;
        for (int n = 0; n < _n; ++n)
        {
            // Increase Octopus Engery Level
            for (int x = 0; x < sizex; ++x)
                for (int y = 0; y < sizey; ++y)
                    ++octopus[x][y];

            // Flash Octopus
            bool flashed = true;
            while (flashed)
            {
                flashed = false;
                for (int x = 0; x < sizex; ++x)
                    for (int y = 0; y < sizey; ++y)
                    {
                        if (9 < octopus[x][y])
                        {
                            // Set flashed Octopus to 0
                            octopus[x][y] = 0;
                            ++flashcount;
                            flashed = true;

                            // Increase neighbour octopus;
                            for (int x1 = max(0, x - 1); x1 <= min(sizex - 1, x + 1); ++x1)
                                for (int y1 = max(0, y - 1); y1 <= min(sizey - 1, y + 1); ++y1)
                                    if (0 != octopus[x1][y1])
                                        ++octopus[x1][y1];
                        }
                    }
            }
        }

        return flashcount - oldflashcount;
    }

    int getresultA()
    {
        cout << "resultA: " << flashcount << endl;
        return flashcount;
    }
    int getresultB()
    {
        int n=1;
        while (sizex*sizey != flashstep(1))
        ++n;
        
        cout << "resultB: " << n << endl;
        return n;
    }

private:
    const vector<string> input;
    const int sizex, sizey;

    int **octopus;

    int flashcount = 0;
};

TEST_CASE("Test A")
{
    problem testproblem(inputT);
    REQUIRE(1656 == testproblem.flashstep(100));

    REQUIRE(1656 == testproblem.getresultA());
}

TEST_CASE("Test B")
{
    problem testproblem(inputT);
    REQUIRE(195 == testproblem.getresultB());
}


TEST_CASE("Problem A")
{
    problem testproblem(inputA);
    REQUIRE(1546 == testproblem.flashstep(100));

    REQUIRE(1546 == testproblem.getresultA());
}

TEST_CASE("Problem B")
{
    problem testproblem(inputA);
    REQUIRE(471 == testproblem.getresultB());
}