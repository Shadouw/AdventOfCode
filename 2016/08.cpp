#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "rect 3x2",
    "rotate column x=1 by 1",
    "rotate row y=0 by 4",
    "rotate column x=1 by 1"};

const vector<string> inputData = {
    	"rect 1x1",
	"rotate row y=0 by 5",
	"rect 1x1",
	"rotate row y=0 by 5",
	"rect 1x1",
	"rotate row y=0 by 3",
	"rect 1x1",
	"rotate row y=0 by 2",
	"rect 1x1",
	"rotate row y=0 by 3",
	"rect 1x1",
	"rotate row y=0 by 2",
	"rect 1x1",
	"rotate row y=0 by 5",
	"rect 1x1",
	"rotate row y=0 by 5",
	"rect 1x1",
	"rotate row y=0 by 3",
	"rect 1x1",
	"rotate row y=0 by 2",
	"rect 1x1",
	"rotate row y=0 by 3",
	"rect 2x1",
	"rotate row y=0 by 2",
	"rect 1x2",
	"rotate row y=1 by 5",
	"rotate row y=0 by 3",
	"rect 1x2",
	"rotate column x=30 by 1",
	"rotate column x=25 by 1",
	"rotate column x=10 by 1",
	"rotate row y=1 by 5",
	"rotate row y=0 by 2",
	"rect 1x2",
	"rotate row y=0 by 5",
	"rotate column x=0 by 1",
	"rect 4x1",
	"rotate row y=2 by 18",
	"rotate row y=0 by 5",
	"rotate column x=0 by 1",
	"rect 3x1",
	"rotate row y=2 by 12",
	"rotate row y=0 by 5",
	"rotate column x=0 by 1",
	"rect 4x1",
	"rotate column x=20 by 1",
	"rotate row y=2 by 5",
	"rotate row y=0 by 5",
	"rotate column x=0 by 1",
	"rect 4x1",
	"rotate row y=2 by 15",
	"rotate row y=0 by 15",
	"rotate column x=10 by 1",
	"rotate column x=5 by 1",
	"rotate column x=0 by 1",
	"rect 14x1",
	"rotate column x=37 by 1",
	"rotate column x=23 by 1",
	"rotate column x=7 by 2",
	"rotate row y=3 by 20",
	"rotate row y=0 by 5",
	"rotate column x=0 by 1",
	"rect 4x1",
	"rotate row y=3 by 5",
	"rotate row y=2 by 2",
	"rotate row y=1 by 4",
	"rotate row y=0 by 4",
	"rect 1x4",
	"rotate column x=35 by 3",
	"rotate column x=18 by 3",
	"rotate column x=13 by 3",
	"rotate row y=3 by 5",
	"rotate row y=2 by 3",
	"rotate row y=1 by 1",
	"rotate row y=0 by 1",
	"rect 1x5",
	"rotate row y=4 by 20",
	"rotate row y=3 by 10",
	"rotate row y=2 by 13",
	"rotate row y=0 by 10",
	"rotate column x=5 by 1",
	"rotate column x=3 by 3",
	"rotate column x=2 by 1",
	"rotate column x=1 by 1",
	"rotate column x=0 by 1",
	"rect 9x1",
	"rotate row y=4 by 10",
	"rotate row y=3 by 10",
	"rotate row y=1 by 10",
	"rotate row y=0 by 10",
	"rotate column x=7 by 2",
	"rotate column x=5 by 1",
	"rotate column x=2 by 1",
	"rotate column x=1 by 1",
	"rotate column x=0 by 1",
	"rect 9x1",
	"rotate row y=4 by 20",
	"rotate row y=3 by 12",
	"rotate row y=1 by 15",
	"rotate row y=0 by 10",
	"rotate column x=8 by 2",
	"rotate column x=7 by 1",
	"rotate column x=6 by 2",
	"rotate column x=5 by 1",
	"rotate column x=3 by 1",
	"rotate column x=2 by 1",
	"rotate column x=1 by 1",
	"rotate column x=0 by 1",
	"rect 9x1",
	"rotate column x=46 by 2",
	"rotate column x=43 by 2",
	"rotate column x=24 by 2",
	"rotate column x=14 by 3",
	"rotate row y=5 by 15",
	"rotate row y=4 by 10",
	"rotate row y=3 by 3",
	"rotate row y=2 by 37",
	"rotate row y=1 by 10",
	"rotate row y=0 by 5",
	"rotate column x=0 by 3",
	"rect 3x3",
	"rotate row y=5 by 15",
	"rotate row y=3 by 10",
	"rotate row y=2 by 10",
	"rotate row y=0 by 10",
	"rotate column x=7 by 3",
	"rotate column x=6 by 3",
	"rotate column x=5 by 1",
	"rotate column x=3 by 1",
	"rotate column x=2 by 1",
	"rotate column x=1 by 1",
	"rotate column x=0 by 1",
	"rect 9x1",
	"rotate column x=19 by 1",
	"rotate column x=10 by 3",
	"rotate column x=5 by 4",
	"rotate row y=5 by 5",
	"rotate row y=4 by 5",
	"rotate row y=3 by 40",
	"rotate row y=2 by 35",
	"rotate row y=1 by 15",
	"rotate row y=0 by 30",
	"rotate column x=48 by 4",
	"rotate column x=47 by 3",
	"rotate column x=46 by 3",
	"rotate column x=45 by 1",
	"rotate column x=43 by 1",
	"rotate column x=42 by 5",
	"rotate column x=41 by 5",
	"rotate column x=40 by 1",
	"rotate column x=33 by 2",
	"rotate column x=32 by 3",
	"rotate column x=31 by 2",
	"rotate column x=28 by 1",
	"rotate column x=27 by 5",
	"rotate column x=26 by 5",
	"rotate column x=25 by 1",
	"rotate column x=23 by 5",
	"rotate column x=22 by 5",
	"rotate column x=21 by 5",
	"rotate column x=18 by 5",
	"rotate column x=17 by 5",
	"rotate column x=16 by 5",
	"rotate column x=13 by 5",
	"rotate column x=12 by 5",
	"rotate column x=11 by 5",
	"rotate column x=3 by 1",
	"rotate column x=2 by 5",
	"rotate column x=1 by 5",
	"rotate column x=0 by 1"};

class TwoFactorAuthentication
{
public:
    TwoFactorAuthentication(const vector<string> &_input, unsigned int _x, unsigned int _y) : input(_input), maxx(_x), maxy(_y)
    {
        cout << "Size of Input: " << input.size() << endl;

        screen = new bool*[maxx+1];
        for ( unsigned int x = 0; x<=maxx; ++x )
            screen[x] = new bool[maxy+1];

        for ( unsigned int x = 0; x<maxx; ++x )
            for (unsigned int y =0; y<maxy; ++y )
                screen[x][y] = false;

        // Parse data
        for (auto elem : input)
        {
            if ( elem.substr(0, 5) == "rect " )
            {
                int xval = 0, yval = 0;
                sscanf(elem.c_str(), "rect %dx%d", &xval, &yval);

                for ( unsigned int x = 0; x<xval; ++x )
                    for (unsigned int y = 0; y<yval; ++y )
                        screen[x][y] = true;

            } 
            else if ( elem.substr(0, 16) == "rotate column x=" )
            {
                int xcol = 0, yrot = 0;
                sscanf(elem.c_str(), "rotate column x=%d by %d", &xcol, &yrot);

                // Backup column 
                for (unsigned int y = 0; y<maxy; ++y )
                    screen[maxx][y] = screen[xcol][y];

                // Rotate
                for (unsigned int y = 0; y<maxy; ++y )
                {
                    screen[xcol][(y+yrot) % maxy] = screen[maxx][y];
                }
            } 
            else if ( elem.substr(0, 13) == "rotate row y=" )
            {
                int xrot = 0, yrow = 0;
                sscanf(elem.c_str(), "rotate row y=%d by %d", &yrow, &xrot);

                // Backup row 
                for (unsigned int x = 0; x<maxx; ++x )
                    screen[x][maxy] = screen[x][yrow];

                // Rotate
                for (unsigned int x = 0; x<maxx; ++x )
                {
                    screen[(x+xrot) % maxx][yrow] = screen[x][maxy];
                }
            } 
            else 
            {
                cerr << "Unknown command: '" << elem << "'" << endl;
            }

            //cout << elem << endl;
            //printscreen();
        }
    }

    ~TwoFactorAuthentication()
    {
        for ( unsigned int x = 0; x<=maxx; ++x )
            delete[] screen[x];

        delete[] screen;
    }

    long getLitPixels()
    {
        long LitPixels = 0;
        for ( unsigned int x = 0; x<maxx; ++x )
            for (unsigned int y =0; y<maxy; ++y )
                if ( screen[x][y] )
                    ++LitPixels;

        cout << "LitPixels: " << LitPixels << endl;
        return LitPixels;
    }

    void printscreen()
    {
        for (unsigned int y =0; y<maxy; ++y )
        {
            for ( unsigned int x = 0; x<maxx; ++x )
                cout << ( screen[x][y] ? '#' : ' ' );

            cout << endl;
        }
    }

private:
    const vector<string> input;
    const unsigned int maxx=0, maxy=0;

    bool **screen = 0;
};

TEST_CASE("Testdata")
{
    TwoFactorAuthentication TwoFactorAuthenticationData(inputTestdata, 7, 3);
    REQUIRE(6 == TwoFactorAuthenticationData.getLitPixels());

    TwoFactorAuthenticationData.printscreen();
}

TEST_CASE("Problem")
{
    TwoFactorAuthentication TwoFactorAuthenticationData(inputData, 50, 6);
    REQUIRE(106 == TwoFactorAuthenticationData.getLitPixels());

    TwoFactorAuthenticationData.printscreen(); // Must be: CFLELOYFCS
}