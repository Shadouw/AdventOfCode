#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputT = {
    " ..##.......",
    "#...#...#..",
    ".#....#..#.",
    "..#.#...#.#",
    ".#...##..#.",
    "..#.##.....",
    ".#.#.#....#",
    ".#........#",
    "#.##...#...",
    "#...##....#",
    ".#..#...#.#"};

const vector<string> inputA = {
    ".............#...#....#.....##.",
    ".#...##.........#.#.........#.#",
    ".....##......#.......#.........",
    ".......#...........#.#.........",
    "#...........#...#..#.#......#..",
    ".........##....#.#...#.........",
    ".....#.........#.#...........#.",
    "....#...............##....##...",
    "#.#.............#..#.......#.#.",
    "...#...........................",
    "......#..#....#.............#..",
    "........#......#.......#.......",
    "....#.....#..#.#...#.........#.",
    "..#.#.......#.##...#....#.....#",
    "...........#.........#..#......",
    "#...........#.#..#...#.#.#....#",
    "........#......................",
    "....#.#.....#....#.......#..#..",
    ".............................#.",
    "....##..........#.....##......#",
    "......#.....................#..",
    "..#.....##.......#.............",
    "....#.#..............#.#.......",
    "..#.#........#.....#..##.......",
    ".....#...##.........##....#.#..",
    ".#....#..#..#...........#......",
    ".............#.....##........#.",
    "..#....#............#.........#",
    "###..........#........#.......#",
    "#...#..#.#.#.........#..#......",
    "..#....#......#.............#..",
    "#...#........#..#...#.....#....",
    ".#..........#.#........#.......",
    "#.....#.........#..#......#....",
    "....#....##........#......#....",
    ".......#....#.....#..#..#.....#",
    ".........#...#.#...#.##........",
    ".##.##...........#..##..#......",
    ".#.##....#........#...#........",
    ".......##.........##.####.....#",
    "....#..##....#.................",
    ".#........#..........#.........",
    "##....##..........##........#..",
    "#......#...........#....#..#...",
    ".......#..#....##..##.....#....",
    ".........#.#.#...#.....#.......",
    "......#...#...#....#......#....",
    "##....#..........#....##....##.",
    "###.........#...#...#..........",
    "#.....##.#........#.......#....",
    "#...............#...##.#......#",
    "..#.....####.###......#......#.",
    "....#.......#..........#.......",
    "....##..............#.#.#......",
    ".......##..#.......#...........",
    "..#.......##....#.......###...#",
    "........#...#.......#.#...#....",
    ".........##....#..#....#.......",
    "............#.#.......#.#......",
    ".....#.....#...#....#.##.......",
    ".......#.........#.......#.....",
    ".#..#...#.....#............#.##",
    ".......#.#......##.............",
    "##.#......#.....#.#............",
    ".#....#.....#............#...#.",
    ".........#.......#.#...........",
    "#............#.##...#..#...#.#.",
    "......#....#.......#....#......",
    "..........#........#..#.#......",
    "#..##.......#.........#..#.....",
    ".........#.....##........#.#..#",
    "..#................#...........",
    "....#..#........##.........#..#",
    "###...#....##.#......##.......#",
    ".......#......##..#.......#....",
    ".......###...#...#..........##.",
    "................#.......#......",
    ".#......##.##........#.........",
    "....##.#.....##.......#........",
    "...........#...........#.....#.",
    "..#........#..#.#...#.#........",
    "#...............#...#.##.##.#.#",
    "................#.......#......",
    ".#..#......#........#.#........",
    "...##..#.......#.......#..#....",
    ".#.....#.#....##..#........#...",
    "........##......#..........#...",
    ".#.......#.......#...#..#......",
    ".#..##.....#....#............#.",
    "...#..........#....#........#..",
    "..#.#..#.......#.#.##..........",
    "#........###.....#.#.......#.##",
    ".....#....##.............#.#..#",
    "..##............#...##.........",
    "...#.........#...........#.....",
    "...#......#.#...#..###.........",
    ".............#...##............",
    ".....##..##.####.#..#......#.#.",
    ".#...#.....#.....#.#.....#.....",
    ".........#.......###.....#..##.",
    ".##.#..#..........#.##.#.#.....",
    ".#...#...#.#.##......#..#......",
    ".............#......#......#...",
    "#.....................#......#.",
    "...#.....#.....#....#........#.",
    "................##..#....#..#..",
    "#.###...#.....................#",
    "...#..#....#.......#.........#.",
    "...........#..#..#...........#.",
    ".......#..#......#....#.#......",
    "..........#......#..#....#.....",
    ".#.#.....#...#.#...#...#.#....#",
    ".....#.......#............#...#",
    "#.#....#......#......#........#",
    ".#.#..#.........##...#.........",
    "#..###..#......................",
    "..#.#..#.......................",
    ".##.....#...#......#..#........",
    "...#...........#...#.......##..",
    "..#...........#........#.......",
    "........#....#.....#.#.........",
    "..........#...........#.....#..",
    "......#...#...##.#.............",
    ".#...#...##....................",
    "............###.........#......",
    ".#.#...................#..#....",
    "....#.#...#.#........#.#.......",
    "....#...#...........#.......#.#",
    "...........#............#...##.",
    ".....####....#.#......#.#......",
    ".##.............#............#.",
    "......#.........#............##",
    "#.#....#...##....#.......#....#",
    ".....#.#....#..#..#...#..#.#..#",
    ".........................#.....",
    "......#.#....###.......#....#..",
    ".....................##.#...#.#",
    "..#.....#.#.#...#...#..........",
    "........#..##........#...#...#.",
    "..........#.#.##....#....##....",
    ".............#..#..............",
    "..#.##..#.......#...#..#..##..#",
    "..#..#....#.#..........#..#....",
    "..........#....#...#......#....",
    ".##...#.......................#",
    ".#.....#....#..........#.......",
    "...........#..#......##.....#..",
    "......###.#..##....#...#.##....",
    ".......#..#.#....#.............",
    "...#..#......##.........###.#..",
    "...........#............##...#.",
    "...#...#...........##.....#....",
    "..................#............",
    ".#.#.#...#..............#..##..",
    "#.#....#........#.........#.##.",
    "#.#.#.......#.....#..........#.",
    "...##.....##.#.....#...........",
    ".#....#..............##...##..#",
    "........##.....................",
    "#..#..#.....###.............#..",
    ".......#...........#...........",
    ".........#.....................",
    ".......#...#...#.....##........",
    "......#.........#........#.....",
    "...#....##..#.####.#.......#.#.",
    ".....#..#......#........#.##..#",
    ".##....#......##......#...###..",
    "..###.#........##.#...#.......#",
    "............#......##....#.#...",
    ".....#....##..##............##.",
    "......##....#.#...#....#.#..#.#",
    ".......#.........#.#.....#.#...",
    ".......#.#....#................",
    ".##...###..#.....#............#",
    "#.#......#.#..#..#.#...#..#..#.",
    "..#.#.#.....#............#...##",
    ".##....###.........#..#........",
    ".#..#.#..#.#....#.........##.#.",
    "....#..#...##.##........#......",
    "........#.#....##....#....#....",
    ".......#..#..#.#..............#",
    "#....#....#.....#....#.........",
    ".#.###...#....#.......#........",
    ".........#.#....##....#...#....",
    "....#.............#.....##.##..",
    ".....#.....#...##..#.#.##...##.",
    ".........#..#................##",
    "...##..##......#.....#........#",
    ".#....#.....#.#......#..###....",
    "#.....#..#.....................",
    "....#.#...#.#.................#",
    ".....##..................#.....",
    "#....##...#.##..###...#........",
    "##.#.........#.......#....#....",
    ".#.#.............##..#.##......",
    "...#.#..............#......#...",
    ".............#.........#.....#.",
    "#.......#........#......#.....#",
    ".....#..............#.##.#.....",
    "#......##...................#..",
    "##.#.....#..........#........#.",
    "#...........##...........#.....",
    ".#...#.....#..#..##....#.......",
    ".....#.........#....##.#.......",
    "#........#......#.............#",
    ".#..................####.#.....",
    "#...#......#....##...#.#..#..#.",
    "............#.#............#...",
    "............#........#.#..###..",
    ".#..#..#..#.#.#.....#.#........",
    "#.....#..#.#...#..#..#........#",
    "#................#....#..#.....",
    "....#..#..#.#......#.#..#.....#",
    ".#..#.......#...##.#.#.....#..#",
    "#.....................#.......#",
    ".............#.......#...#.....",
    "....#......#.........###.##....",
    "....#..#.......#.#........#....",
    "....#...#....#.#....#..........",
    "...#..#......#.............#...",
    ".......###.#.........#....#.#..",
    "..#.....##.....................",
    ".#.#...........#..##....#......",
    "..........##.#....#.#..........",
    "...........#.#..#.#..#.#.......",
    "..........#..#...#.....##......",
    ".....#.........#...#.#..#......",
    "#.#................#..........#",
    "...#.....##.#..#...#.##.......#",
    ".....##...........#............",
    ".....#...#...#...#.#.....#.....",
    "...........##..................",
    ".........#................#....",
    "......#.....#.#...#.......#....",
    "...#...#........#...#...#.#.#..",
    "...............##..#....##...#.",
    "...#.#...........##.......##..#",
    "...........#............#......",
    ".#....#.#.......##.#.#.#.......",
    ".....#.#..#.#.#................",
    ".#............#...#.#..........",
    ".....#.......#.#.......#.....#.",
    "#....#...........#...#....##...",
    "..#...#..##.....#....#..#......",
    "#.#.........#..#.#..#.#......#.",
    "................#......##......",
    "#........#..............#....#.",
    "........#..#.#........#..#..#..",
    "#..........#......#............",
    "..##.......#..#.......#....#...",
    ".#........#..#..#.#.......##...",
    "................#..............",
    "#.................#...........#",
    "##..#...................#....##",
    "#..#....#.....#.#..#.#.#......#",
    "#................#.#.#...#.....",
    ".............#..#...#..##...#.#",
    "#..................#...........",
    "..............#..#.....##.....#",
    "..#...............#.#..........",
    ".....#......#....#..#...#......",
    ".#......#...##.....###.....#...",
    "...##...##.##....#.#.#..#......",
    "....#.#.......#..##....#.##....",
    "...#.........#.#.....#...#...##",
    ".##.#.........##..#.##..#......",
    ".#...#......#......#.........#.",
    ".............#.................",
    "..........#..............#.....",
    "##...........#...#...###....#..",
    "....#...............#..........",
    ".......####.....#......#.......",
    "........#..........#..#........",
    "..#.......#..#.................",
    "......#.#..##...##....#........",
    ".##...#........#...#....#...#..",
    ".......................#.......",
    ".........##..#..#...#....##...#",
    "..#..#...#.....#.........#..#..",
    ".......#....#.........#...#..#.",
    ".............#.................",
    ".....##..#.....###....##.#.....",
    "....#.#..#..#.#.....##....#..#.",
    "......#..#..............#.##..#",
    "..#..#......#.#.........#..#...",
    "..........#.#..#....#.....#....",
    ".....................#.........",
    "...#.....#.......##..#.#.......",
    ".....#...#..........###....#.#.",
    "......#.....##............#...#",
    ".......#..........#.#..#...#..#",
    "#...#..#...........#..##..#....",
    ".#......#.......##.....#..#....",
    "...#..#....#.......##......#...",
    "........#.......##...#.......#.",
    ".....#........#................",
    "......#........#....#..........",
    "...#....#....###.........#.#...",
    "##..............#......#..#.#..",
    ".........##....#........#..#.#.",
    ".......#.##.#........#........#",
    ".....###..#..#...........#....#",
    ".......#....##.......#.#...#...",
    "#..............#.#....#..#...#.",
    "#..#....#..#.#............#..#.",
    ".#...##.#..................#...",
    "...#...............##.........#",
    "###..............#.#..#.#.#....",
    ".#......#.#.....##.......#.....",
    "...#.................#.#.......",
    ".#...#....#...#..#......#...#..",
    "...##....#........#.#.#..#.....",
    "..#.....#........#....#.#......",
    "...........#.#...#.............",
    "......#.....#.....#.........#..",
    ".#.##.###...#.##.......#.......",
    ".............#....#.......#....",
    "..............#...........#....",
    ".............#..#.#.....#....#.",
    ".......#........##...##..##....",
    "..##...#............#..#......#",
    ".............#...##.....#......",
    ".#...##..##.#.........#.##...#."};

class TobogganTrajectory
{
public:
    TobogganTrajectory(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;
    }

    void listinput()
    {
        for (auto elem : input)
        {
            cout << elem << endl;
        }
    }

    unsigned int getTreesOnFly(unsigned int right, unsigned int down)
    {
        size_t posx = 0;
        size_t posy = 0;
        unsigned int retval = 0;

        for (auto e : input)
        {
            if (0 == posy)
            {
                if ('#' == e[posx])
                    ++retval;
                posx += right;
                if (posx >= e.length())
                    posx -= e.length();
            }
            ++posy;
            if (posy == down)
                posy = 0;
        }

        return retval;
    }
private:
    const vector<string> input;
    int resultA = 0;
    int resultB = 0;
};

TEST_CASE("Testdata")
{
    TobogganTrajectory testTobogganTrajectory(inputT);

    REQUIRE(2 == testTobogganTrajectory.getTreesOnFly(1, 1));
    REQUIRE(7 == testTobogganTrajectory.getTreesOnFly(3, 1));
    REQUIRE(3 == testTobogganTrajectory.getTreesOnFly(5, 1));
    REQUIRE(4 == testTobogganTrajectory.getTreesOnFly(7, 1));
    REQUIRE(2 == testTobogganTrajectory.getTreesOnFly(1, 2));

    REQUIRE(336 == testTobogganTrajectory.getTreesOnFly(1, 1) *
                   testTobogganTrajectory.getTreesOnFly(3, 1) *
                   testTobogganTrajectory.getTreesOnFly(5, 1) *
                   testTobogganTrajectory.getTreesOnFly(7, 1) *
                   testTobogganTrajectory.getTreesOnFly(1, 2));
}

TEST_CASE("Problem")
{
    TobogganTrajectory testTobogganTrajectory(inputA);
    REQUIRE(167 == testTobogganTrajectory.getTreesOnFly(3, 1));
    REQUIRE(736527114 == testTobogganTrajectory.getTreesOnFly(1, 1) *
                         testTobogganTrajectory.getTreesOnFly(3, 1) *
                         testTobogganTrajectory.getTreesOnFly(5, 1) *
                         testTobogganTrajectory.getTreesOnFly(7, 1) *
                         testTobogganTrajectory.getTreesOnFly(1, 2));    
}
