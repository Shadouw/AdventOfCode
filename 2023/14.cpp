#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "O....#....",
    "O.OO#....#",
    ".....##...",
    "OO.#O....O",
    ".O.....O#.",
    "O.#..O.#.#",
    "..O..#O..O",
    ".......O..",
    "#....###..",
    "#OO..#...."
};

const vector<string> inputData = {
    ".O..........O.....O.#................#..O#.#......O...O.O...#....#...O.#...#O.O....#.#.........O....",
    "...##OO.#O#......#.#..OO.O....###..#..O..#.O.OO...O.........O......O.O##.O..O.O..#O.#..O...#.OOO.O.O",
    "#.O..OO.O..O.#.#..#.O.O..#..O...........O.OOOO...#..O.......O...O#......O.O..##O...O........#.......",
    "...O...#..O.OO##.O#..O.#O..#....O....#...O.......O.O....#..##.....O.##.#.OOO.......OO......O....O.O.",
    "....O...#..###..O.....O.#O.###..#O..O.....O.#.##OO..OO.O#.OO.#.....O....#.#O##.O.O.O...#O..O.#O.OOOO",
    "#O.........OO....#.....O#..#.##........O..O#........#........O#O.O.O..#..OO.#O.#......O.#O..........",
    "..OOO.O.#.#.O.#...O.#...O..O.O...#O.#O#O.#......OOO.O.#.....OOO.###.....OO#.#OO...##.....#O#....#...",
    ".O...O#.....O..O...#.#.....O.O......#.....O....#.#OOO..#O........O.O...O..O##.O.....#..#.O..#O.#....",
    "#.OO..#.O.......O.O.O##.O.O...................##.......#.........OO#.O....##..O.O..O.#.....O#..#.#..",
    "#OOO..OOO.OO.#....#.O.....##.....O..#.OO#O.#..#..O..#..O.O...O....#..#...O.####..#O#.O....#.O.O.#...",
    "OO..O.#O..O.O#O..#......O.#O...#....O........O....#..O.#O....#....O..#....O..OO##O#......#O.O.O..#O#",
    "..O..##.......O.....##....O#..........#.#.O.##.......#.OO.#.#..O.#...O.....#OO.....O.O.O#........O.O",
    "#..O....#.#..#O...#...#.....OO#..#.#.O..OO....#.#.O...O...O....O..#.#..O.#O.....O..##.O.O..O....#.##",
    "O##.......##.OO..O.#.O..O.O#......O..OOO.....O...OO...O...#.O.O#..O..O.##O.#.....O..O.#O.#...O..O.OO",
    "#O..O....OO.#..#.O...O.O.....O##......O.......O...#.#.....#..O........O.O...O....#O#..O.....#.O....O",
    "O.......#...O...O.O...O....O.......O..#.#.O.##.......O#..O#....O###.O....#...OO...#.#......#........",
    "....O.#.O##...#O..#OO.........O...O#O..O.....#..#...#........#....#..O.##......#.....O.O..OOOO..#...",
    "....#....O#..#..O..........O....OO...O....O.....O.O#..OOO..O.O#..#...O#..#OO.O.O.O.O##.#...##....#..",
    ".#..OO..OO.O#......#OO.O.O.#..O...##.#.....O......#....#..O#OO.#.....#..OO.O#O...#....#...O###O..OO#",
    "#OO..#.O.O##.O......O..O......O.O.....O..O...#.O..O#..OOO.#O#O.#.#.#...##.#.O.O.......O....#..O..#O.",
    "#.#...#....#.#..#.O.####.O...#O#.#....#O..........O.OO...#...........#.#.#..OO.#O..#..#O.O.O..#.O...",
    ".O.##..#...OOO#O#..##.#O....O..#.O.#.#.OO.#..#...O.##...#......O#O#OOO.OO.#...O.O.......#O.O.OOOO##.",
    "......O.........#..O...#...O.#O...#O.O#....#.O..O.OO...OO.O..O#.##...#...#......#.#.O...O#..##.OO.O.",
    "O........O#.O#......O#...#..O#..OO....#.....OOO..O.O...#.O##..#...O..O.....................OOO......",
    "OO...#O....OOO.O.O....#.O..O##OO..O.....#..O#.....#....O.....O..#...OO..#....OO#.#.O.....OOO#..O.OOO",
    ".....#.##..O#O....O#...#.......##.#..O..............#..#...O.OO......#.......O#....#..O.#..#.O..#..#",
    ".#.O.....O##O.#.#.#O.#.....#.......O...O.......#O.O.....O#O#O..#O..#O......OO...O#.O..O....##..O....",
    ".......#.O.O#O#..##..#.OOOO.OO.##.#OO.#O#..O...O..OO.O.#.O#..O#O#O.O....#O.......OO..O...#...O.#....",
    "#O.#...OO#.OO......O.O.O....#O....#O#O....O#..#O#.#....O#.##.#..O.......OO..O..O#OO#O....O#....##..#",
    "..O.OO.O......O.OO....O#...O#O#.O##.....#OO...O....O.##..##..O.O.#..O##O.#O##.#.OOO.#.###..#OO...#O.",
    "O....O..OO#O#...##.....OO....#..O...O.##.......O..#..##OO......#..O.....#..O.#...#.#..O..##O.......O",
    "##.#..#..#..O.....O.#.##.......#.##........#....#.....O.....O.O#O..O.#O.#..#.#O.....O..O..#.O....OOO",
    ".O.#O.#...O..#.......#..#O..#.O.OO...O..O...O.O..O...#..##OO..#......###O#.O..O..#.##........#....#O",
    "..O....##...O#OOO.#O...#..O.O.#.O....##..#.#.O.OO..O#OO....O..OO.OO#......O.O........O.#O.....O#.O..",
    ".OO#...#.OO.OO#.#...OO#.OOOO.O..O.#.OOO....#.OO...O.##..OO#OO.......#O.....O..##....O#.#.OO...O...#.",
    "..#O.OO.O.#O.#...#.....O.#.#..##..O..##...OO#....#.#....O....##..O.........#...OOO..O..#O.....#...#.",
    "#.O.....#..O...OO#....OO....##.....#.........O.O#.O.##.#OO..#.....#O..O............#.....#.......OO.",
    "O..O.#.....O#.O..#O.........##O##..#........#..OO.....#.#...O....O..#.O......#O....OO.........#..OOO",
    "O....#...O...#..........O..O#OO..#O..OO.#OOO....#..####OO#........#O...##.O...#.......OO.O#.....#..#",
    ".#............#.#OOO..O##O...OO..O.#.O...O#O..#.##O..OO.#.O..OOO...#O.#.#O.....#..O...###O..#..#....",
    ".....O.OOOOO..#.#OO...O.O.......#OO...#....OOO#......O...O.....O.#.........OOOO.......O......#.OO...",
    "...#..O...O..O.#O.#O....##OO.O...O....O#....O...O....O#.O..#OO#.......#.O.............#.#O..........",
    "..#.###...O#..O.#.O..#OO.O.OO...#.......O..#...OOO#O.....OO.###...O.#O.OO.O..O#O....O#.#...#...O..O.",
    "..O.#...#...O#.O..#....#.O..O...#O....O.O..#..OO.........O#O.O.#..#O.#..O.O##..O..O......O#...O..#.#",
    "O.O..O..O##.#O##O.#.O..OOO.......#..OO.O.##.#O.OOO.....O.O.O....O..#OO..O.....#O.....#....O..O..O#.O",
    ".#...O.O..O....O...#O#.#O.##...#...#..O.OO#.....#O.O#....O#.##.O.O.O..#OO####......O#O....O......O#O",
    "##.O..#...O....#....#.##.O.........O.##.O..#...#O..#.....O...#.O#........#.O#..OO...#.#OO...#....#..",
    ".O...#O.O...O..#O.O#OO.#.....O.....##O..#.#..OO.O#.##.#.###O...OO....O....#.O.#...O...O....O.#..#..#",
    ".O#....O.#......O...##.O...O.#.O#OO.....O#O.#.O..O.#O..#..#.....O..O.#.O..O..#....O..O#OO...##O.O...",
    ".O.....#O#.......##O.......#O.O........OOO.......#.O#..#.......O....##....#.#O.......O.....O#....#OO",
    "..#.#.OO.#.O.....O#.....#..O...OO.....OO.......O.O##..#.........#........O.O#O.....##...##..........",
    "#O...............O.O.#.....O#O.....O..#.O....OO#O.O...##.....#.O#....O#..OOO.O.#.OO.#..#O#.O.####.#.",
    "O#O.#.O#O...O.....#.O........#..O.....#..O.O..#.#.O.O#....O........O.O...O....O#...#OO#..O.###.O#.O.",
    "..OO......#......#..O...O#O#..#O.#.#.#......#.....#.#..#...O.....#.O#O.OO...#O...#..#..OO.#...O.O#..",
    "..#....O.............O#.#O.....##......O#O.O#.#O##..OO..##O.#O......O#O.O.#O#.#.#.#.#..#....OO.....O",
    "...........#..O.O#.......O...#..O.O#..O.#....#...O...O.#.OO.....#....#..#...#..O...O.#......O#O.O.#.",
    ".O#..O..O#..O.....O.#..#.#...O...O..O.OO.#...O.O......O.......OOO..#.#O..#....O..#O#...#.OO.O...#OO.",
    "O.OO..O.....#.OOO...........O..#...........O........OO.#...O..#.O..O..O....#..##....O#.OO.OOO..##O##",
    "..OOO.#...O#O###.OO...O..#.#.OO..O....O...#..#.#.#...O...##..O..OO##..OO...#....#...#.O.O.O..#......",
    "..O..O.##O#.O..##.O..OO..O....#.#.O..#OO...O..O#.#.........O.......O#.OO........##....O..O#...#...#.",
    "..#...O#O....OO.#...O#......#.O.O#O...#.O.#O.......O....#..O.#.....#...OO.O.#O..#....O..#..O.O#.#..O",
    ".O.......#.OO....O.OO..##.#O#.O.O.#OOO.##.O.O...#.O....O#O#O..#..O.O......O#..O...#....#...#.#.O#...",
    "....O.....O..O...O.#OOO.OO...O...O.O.#.....O#......OOO.OOO.#..##..#..OO............O.O.....O...O....",
    "O#O..O.OOO......O...O...OO.O.....O#.O..#...O##.OOO.#...O.#.O#O....#O.#..#....O.O#....O.O...O.O.O...O",
    "....#.O#.....O.#.#O.........#...#O...O.O#OO...#.......#O...#...........O..O.....O...O#.#O...#..O..O.",
    ".#....#.......#..O#O..O.......O#O....O.O..##.O..O....O#..O.O..O....O#..OOO.O..O.#.#....##.##O.O.O.O.",
    "...O##.OO........OO#.O..O....O.#.O............#....#O#.O#...#..O#####..##.......#.......#...##.O....",
    "#..O...#...O....O.O.##O.#O..O#...O...#..#O.#.O.O.O###...O.....O......#....O#...OO.O...#...#.O...OO..",
    "#.....#.OOO..O....#O##...OO....O.#OO.O..#.#..OO.#.O..##O.###O..##..O...##.....#.OO..O.#.OO.O..#...O.",
    ".#O#...O...OO.O.....#........O##.#.O#O...O..#OO.#.....O....O.O.O..O.#..O..O..O..#..#...#.#OO...O..#O",
    "..#...#......O....OO.O.#..O....O..O...#.......##O#.#OOO..#.##...O..O...O..#......#.O....OO..O.O..O#O",
    "..##.O.........O........O#.#..O.O...O.O##O.....O.OO......O#.....#O.....##OO#O#..O#.O......O....#...O",
    ".O.#...#..........#..##...#.O...#..........#O.#.#....#..O..##..#.O..O.......O......O.#O.#O...#...#..",
    "..O.OO.....O.O.O.OO..O.O#O.OO.........OOO.O..O..OOOO...O....O#...#..O.#.O.O..O..OO...O..OO.O.##..OO#",
    "..O#..#..O..#..OOOO......##.#..#....#...OO.O.O#.#.....O...#OO....O..##..#.#...##.#...O.##O...O......",
    ".....O.O..O....#.O#....#..O.......#......#..##...#...#.....#O..O..OOO.....O.........OO.#O..O..O.#O.#",
    "##.#OO......##..O#..#.OOO..OO.#....OO.#.OO..#..#.......O#...OO.#.O........O.#.O...#O....#....O...O.O",
    "OO.O...#..O..O.O#.#O..........#....O....O.#.....#.O......#....O...O#..OO.#...OO....OO.O...#...OO..##",
    "..O...O...O##..O...O.....##..OO....OO..O.......O.O.#..#.O.O..O..OO#....O..#..#.O......#O#O.O#.O#OO..",
    "...O.OO.....O....#..#....O...#..O.....#OO#O#.#.###...#.O.O.O#.#....#..O...O.....OO..#....OO#...#....",
    ".O.OO....O#.....OO.O#O..#...#....#..O..O....#....O....O.O.#O.##....O........O#.O....O#.O.O#...#O#...",
    "...O.#.#.....OO.OO#.O......#......##...#.#..#O.....#O...O#..#O#O..#..O.....OO##.......O.#.O#....O.#.",
    "..#....O.....##.....O#.O...O.#..#......O....#......OO.O.#....#..............#.....O.......#O.....#.O",
    "..O#...#.O..#.OO..#..O...OOOOOOO.OO#..O........#....O....OO.#OO.......#..O.O...OO.....O.OOOO#O...O..",
    ".O#.#O.#O...#...O#..........O.....O.O.#.....#....O..OO.OOOO......#..O#..#..#....O....O.OO.#....#O.O#",
    "..#OO....O#....O..#....#....O.#...OO#O....OO#.........O..O.O.....#OO....#O##..OOO.#..#O..O..O...O...",
    ".O...#O#..O....OO...O.#...O....#....O...#....#O.#O.O.#O#.O.O#......O............#....#...O.O.#......",
    "#OOO..##....#O.O..OO..O##.......O#.##O..#....#.##.#.#OO........#....#....O...#........O...O..O.O#...",
    "...#.#..#...O...OO.O..#O...O.O......#...OO...OO.#O.....O..O##.##..O.....O......O.OO..#.O....O.#OOO.O",
    "...O.....#........#O.#.OO.#.......O...O....O.#....#.#......O.O..#.#.O.......##......OO.O..O..#OO.O#.",
    "##.O..O#..#...#.#O...O.......#O.OO.....OO...O.OO.....O.......O.....O#....O...O#.O...O..##....#O.O.#.",
    "O.O.#OO.O.#.....#O.O..#O.O...##...#.O......OO.#...#..O.OO.O..........#..OO.....OO..O#.#...#.O..O#O..",
    ".O.#O#O....O...##....O.O.##..........#O.#O#.#..O.#..#O....O..OO......O...#...##O.O.O#.####.OO.O#.O#.",
    ".....OO.#.O..#O###OO#O.O.O.#.......#.#...#.#O....O.O..........#O....O..##.#.....OOO##..O.....#.....#",
    "#....O..O.O.O...O#OO.O...O......O....O#..#....#.O..#..#.O..##O#..OO..O.#.O#..OO.....O.....OO#O....#O",
    ".....OOO...#...#..#.#...O#.O..#.O#O.O##...O.....O...O.#.O..OO......O...O.........#O..#O.#O.....O...O",
    "O........##..O..OO#....#.#O#.O.O..#..OO........OOO..O.OO.#..OO.#..O..##.O...OO.OO....O##.O......O.O.",
    "#O.#.#.O#..O.O........#...O...O.#...##.#..O.#..#..O..#O..O.......O....O.O#O...........O#...#...O#...",
    "...#O..#...#..O###....#O#..O..O...#OO...OO.OO#OO.#...O....O.........#..#O......#..#.......#O#O#..#O.",
    "..O#.....#..##.O#.........#O...#.#.....O..#..#.#OO.#.O.....#O.....O.#.......O....#O..O#..O..O.O...OO"
};

class ParabolicReflectorDish {
public:
    ParabolicReflectorDish(const vector<string>& _input)
        : input(_input)
        , currentstate(_input)
        , rows(input.size())
        , columns(input[0].size())
    {
        cout << "Size of Input: " << rows << " rows, " << columns << " columns " << endl;
    }

    void move(char direction)
    {
        vector<string> tempstate(currentstate);
        switch (direction) {
        case 'N':
            for (int c = 0; c < columns; ++c) {
                int nextpos = 0;
                for (int r = 0; r < rows; ++r)
                    switch (tempstate[r][c]) {
                    case '#':
                        nextpos = r + 1;
                        break;
                    case 'O':
                        tempstate[r][c] = '.';
                        tempstate[nextpos++][c] = 'O';
                        break;
                    default:
                        break;
                    }
            }
            break;
        case 'E':
            for (int r = 0; r < rows; ++r) {
                int nextpos = columns - 1;
                for (int c = columns - 1; c >= 0; --c)
                    switch (tempstate[r][c]) {
                    case '#':
                        nextpos = c - 1;
                        break;
                    case 'O':
                        tempstate[r][c] = '.';
                        tempstate[r][nextpos--] = 'O';
                        break;
                    default:
                        break;
                    }
            }
            break;
        case 'S':
            for (int c = 0; c < columns; ++c) {
                int nextpos = rows - 1;
                for (int r = rows - 1; r >= 0; --r)
                    switch (tempstate[r][c]) {
                    case '#':
                        nextpos = r - 1;
                        break;
                    case 'O':
                        tempstate[r][c] = '.';
                        tempstate[nextpos--][c] = 'O';
                        break;
                    default:
                        break;
                    }
            }
            break;
        case 'W':
            for (int r = 0; r < rows; ++r) {
                int nextpos = 0;
                for (int c = 0; c < columns; ++c)
                    switch (tempstate[r][c]) {
                    case '#':
                        nextpos = c + 1;
                        break;
                    case 'O':
                        tempstate[r][c] = '.';
                        tempstate[r][nextpos++] = 'O';
                        break;
                    default:
                        break;
                    }
            }

            break;
        default:
            break;
        }

        currentstate = tempstate;
    }

    void cycle(long c)
    {
        for (long i = 0; i < c; ++i) {
            if (!(i % 1000000))
                cout << i << endl;
            move('N');
            move('W');
            move('S');
            move('E');

            if (currentstate == periodicstate) {
                cout << "Found at i = " << i << endl;
                long diff = i-100;
                
                // Jump forward
                i += ((c-i)/diff)*diff;
            }

            // Assumption: After at least 100 iterations it is periodic
            if (100 == i)
                periodicstate = currentstate;
        }
    }

    long getLoad()
    {
        int rowload = rows;
        long load = 0;
        for (auto row : currentstate) {
            for (auto c : row)
                load += ('O' == c ? rowload : 0);
            --rowload;
        }

        return load;
    }

    long getResultA()
    {
        move('N');

        long resultA = getLoad();

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        currentstate = input;
        cycle(1000000000);
        long resultB = getLoad();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    const long rows, columns;

    vector<string> currentstate;
    vector<string> periodicstate;
};

TEST_CASE("Testdata")
{
    ParabolicReflectorDish ParabolicReflectorDishData(inputTestdata);
    REQUIRE(136 == ParabolicReflectorDishData.getResultA());
    REQUIRE(64 == ParabolicReflectorDishData.getResultB());
}

TEST_CASE("ParabolicReflectorDish")
{
    ParabolicReflectorDish ParabolicReflectorDishData(inputData);
    REQUIRE(108826 == ParabolicReflectorDishData.getResultA());
    REQUIRE(99291 == ParabolicReflectorDishData.getResultB());
}