#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

class trickshot
{
public:
    trickshot(int _x1, int _x2, int _y1, int _y2) : x1(_x1), x2(_x2), y1(_y1), y2(_y2)
    {
        //cout << "Size of Input: " << input.size() << endl;
    }

    int step()
    {
        int retval = 0;
        // 0: no hit
        // 1: hit
        // -1: hit impossible

        int oldx = x, oldy = y;

        x += vx;
        y += vy;
        if (vx > 0)
            --vx;
        if (vx < 0)
            ++vx;
        --vy;

        // Check hit
        if (x1 <= x && x <= x2 && y1 <= y && y <= y2)
            retval = 1;

        if (x > x2)
            retval = -1;
        if (y < y1 && vy < 0)
            retval = -1;

        // cout << "(" << oldx << "/" << oldy << ") " << retval << " (" << x << "/" << y << ") " << endl;

        return retval;
    }

    void resetPosition(int _vx, int _vy)
    {
        x = 0;
        y = 0;
        vx = _vx;
        vy = _vy;
    }

    int posx() { return x; }
    int posy() { return y; }

    int findYMax()
    {
        int ymax = 0;
        for (int xvel = 0; xvel <= x2; ++xvel)
        {
            for (int yvel = 0; yvel <= 1000; ++yvel)
            {
                int tempymax = ymax;
                resetPosition(xvel, yvel);

                int result = step();
                while (-1 != result)
                {
                    if (posy() > tempymax)
                        tempymax = posy();

                    if (1 == result)
                        ymax = tempymax;

                    result = step();
                }
            }
        }

        return ymax;
    }

    int findInitialPositions()
    {
        int num = 0;
        for (int xvel = 0; xvel <= x2; ++xvel)
        {
            for (int yvel = -1000; yvel <= 1000; ++yvel)
            {
                resetPosition(xvel, yvel);

                int result = step();
                while (-1 != result)
                {
                    if (1 == result)
                    {
                        ++num;
                        //cout << xvel << ","<< yvel << endl;
                        break;
                    }

                    result = step();
                }
            }
        }

        return num;
    }

private:
    int x1, x2, y1, y2;
    int x = 0, y = 0;
    int vx = 0, vy = 0;
};

TEST_CASE("Testdata")
{
    trickshot test(20, 30, -10, -5);
    test.resetPosition(7, 2);
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());

    REQUIRE(1 == test.step());

    REQUIRE(-1 == test.step());

    test.resetPosition(6, 3);
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(1 == test.step());
    REQUIRE(-1 == test.step());

    test.resetPosition(9, 0);
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(0 == test.step());
    REQUIRE(1 == test.step());
    REQUIRE(-1 == test.step());

    test.resetPosition(17, -4);
    REQUIRE(0 == test.step());
    REQUIRE(-1 == test.step());
    REQUIRE(-1 == test.step());

    REQUIRE(45 == test.findYMax());

    REQUIRE(112 == test.findInitialPositions());
}

TEST_CASE("trickshot")
{
    trickshot problem(257, 286, -101, -57);

    int resultA = problem.findYMax();
    cout << "Result A: " << resultA << endl;
    REQUIRE(5050 == resultA);

    int resultB = problem.findInitialPositions();
    cout << "Result B: " << resultB << endl;
    REQUIRE(2223 == resultB);

}