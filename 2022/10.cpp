#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "addx 15",
    "addx -11",
    "addx 6",
    "addx -3",
    "addx 5",
    "addx -1",
    "addx -8",
    "addx 13",
    "addx 4",
    "noop",
    "addx -1",
    "addx 5",
    "addx -1",
    "addx 5",
    "addx -1",
    "addx 5",
    "addx -1",
    "addx 5",
    "addx -1",
    "addx -35",
    "addx 1",
    "addx 24",
    "addx -19",
    "addx 1",
    "addx 16",
    "addx -11",
    "noop",
    "noop",
    "addx 21",
    "addx -15",
    "noop",
    "noop",
    "addx -3",
    "addx 9",
    "addx 1",
    "addx -3",
    "addx 8",
    "addx 1",
    "addx 5",
    "noop",
    "noop",
    "noop",
    "noop",
    "noop",
    "addx -36",
    "noop",
    "addx 1",
    "addx 7",
    "noop",
    "noop",
    "noop",
    "addx 2",
    "addx 6",
    "noop",
    "noop",
    "noop",
    "noop",
    "noop",
    "addx 1",
    "noop",
    "noop",
    "addx 7",
    "addx 1",
    "noop",
    "addx -13",
    "addx 13",
    "addx 7",
    "noop",
    "addx 1",
    "addx -33",
    "noop",
    "noop",
    "noop",
    "addx 2",
    "noop",
    "noop",
    "noop",
    "addx 8",
    "noop",
    "addx -1",
    "addx 2",
    "addx 1",
    "noop",
    "addx 17",
    "addx -9",
    "addx 1",
    "addx 1",
    "addx -3",
    "addx 11",
    "noop",
    "noop",
    "addx 1",
    "noop",
    "addx 1",
    "noop",
    "noop",
    "addx -13",
    "addx -19",
    "addx 1",
    "addx 3",
    "addx 26",
    "addx -30",
    "addx 12",
    "addx -1",
    "addx 3",
    "addx 1",
    "noop",
    "noop",
    "noop",
    "addx -9",
    "addx 18",
    "addx 1",
    "addx 2",
    "noop",
    "noop",
    "addx 9",
    "noop",
    "noop",
    "noop",
    "addx -1",
    "addx 2",
    "addx -37",
    "addx 1",
    "addx 3",
    "noop",
    "addx 15",
    "addx -21",
    "addx 22",
    "addx -6",
    "addx 1",
    "noop",
    "addx 2",
    "addx 1",
    "noop",
    "addx -10",
    "noop",
    "noop",
    "addx 20",
    "addx 1",
    "addx 2",
    "addx 2",
    "addx -6",
    "addx -11",
    "noop",
    "noop",
    "noop"};

const vector<string> inputData = {
    "addx 1",
    "noop",
    "noop",
    "noop",
    "addx 5",
    "addx 5",
    "noop",
    "noop",
    "addx 9",
    "addx -5",
    "addx 1",
    "addx 4",
    "noop",
    "noop",
    "noop",
    "addx 6",
    "addx -1",
    "noop",
    "addx 5",
    "addx -2",
    "addx 7",
    "noop",
    "addx 3",
    "addx -2",
    "addx -38",
    "noop",
    "noop",
    "addx 32",
    "addx -22",
    "noop",
    "addx 2",
    "addx 3",
    "noop",
    "addx 2",
    "addx -2",
    "addx 7",
    "addx -2",
    "noop",
    "addx 3",
    "addx 2",
    "addx 5",
    "addx 2",
    "addx -5",
    "addx 10",
    "noop",
    "addx 3",
    "noop",
    "addx -38",
    "addx 1",
    "addx 27",
    "noop",
    "addx -20",
    "noop",
    "addx 2",
    "addx 27",
    "noop",
    "addx -22",
    "noop",
    "noop",
    "noop",
    "noop",
    "addx 3",
    "addx 5",
    "addx 2",
    "addx -11",
    "addx 16",
    "addx -2",
    "addx -17",
    "addx 24",
    "noop",
    "noop",
    "addx 1",
    "addx -38",
    "addx 15",
    "addx 10",
    "addx -15",
    "noop",
    "addx 2",
    "addx 26",
    "noop",
    "addx -21",
    "addx 19",
    "addx -33",
    "addx 19",
    "noop",
    "addx -6",
    "addx 9",
    "addx 3",
    "addx 4",
    "addx -21",
    "addx 4",
    "addx 20",
    "noop",
    "addx 3",
    "addx -38",
    "addx 28",
    "addx -21",
    "addx 9",
    "addx -8",
    "addx 2",
    "addx 5",
    "addx 2",
    "addx -9",
    "addx 14",
    "addx -2",
    "addx -5",
    "addx 12",
    "addx 3",
    "addx -2",
    "addx 2",
    "addx 7",
    "noop",
    "noop",
    "addx -27",
    "addx 28",
    "addx -36",
    "noop",
    "addx 1",
    "addx 5",
    "addx -1",
    "noop",
    "addx 6",
    "addx -1",
    "addx 5",
    "addx 5",
    "noop",
    "noop",
    "addx -2",
    "addx 20",
    "addx -10",
    "addx -3",
    "addx 1",
    "addx 3",
    "addx 2",
    "addx 4",
    "addx 3",
    "noop",
    "addx -30",
    "noop"};

class CathodeRayTube
{
public:
    CathodeRayTube(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        reset();

        // Parse data
        for (auto elem : input)
            operate(elem);
    }

    void reset()
    {
        X = 1;
        cycle = 0;
        SignalStrength = 0;

        for (int i = 0; i < 40; ++i)
            for (int j = 0; j < 6; ++j)
                crt[i][j] = ' ';
    }

    void operate(const string cmd)
    {
        if ("noop" == cmd)
            drawpixel();
        else if ("addx" == cmd.substr(0, 4))
        {
            drawpixel();
            drawpixel();
        }
        else
            cout << "Unknown command: " << cmd << endl;

        if (cycle >= nextmeasure)
        {
            SignalStrength += nextmeasure * X;
            nextmeasure += 40;
        }

        if ("addx" == cmd.substr(0, 4))
            X += stoi(cmd.substr(5));
    }

    void drawpixel() 
    {
        xpos = cycle % 40;
        ypos = cycle / 40;

        if ( abs(xpos-X) <=1 )
            crt[xpos][ypos] = '#';

        ++cycle;
    }

    int getSignalStrength()
    {
        return SignalStrength;
    }

    bool getResultB()
    {
        int resultB = 0;

        return resultB;
    }

    void printcrt()
    {
        for (int j = 0; j < 6; ++j)
        {
            for (int i = 0; i < 40; ++i)
                cout << crt[i][j];
            cout << endl;
        }
    }

private:
    const vector<string> input;

    int X = 1;
    int cycle = 0;
    int SignalStrength = 0;
    int nextmeasure = 20;

    char crt[40][6];
    int xpos = 0;
    int ypos = 0;
};

TEST_CASE("Testdata")
{
    CathodeRayTube CathodeRayTubeData(inputTestdata);
    REQUIRE(13140 == CathodeRayTubeData.getSignalStrength());
    CathodeRayTubeData.printcrt();
    REQUIRE(0 == CathodeRayTubeData.getResultB());
}

TEST_CASE("CathodeRayTube")
{
    CathodeRayTube CathodeRayTubeData(inputData);
    REQUIRE(11960 == CathodeRayTubeData.getSignalStrength());
    CathodeRayTubeData.printcrt();
    REQUIRE(0 == CathodeRayTubeData.getResultB());
}