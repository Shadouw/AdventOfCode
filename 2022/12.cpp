#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iomanip>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "Sabqponm",
    "abcryxxl",
    "accszExk",
    "acctuvwj",
    "abdefghi"};

const vector<string> inputData = {
    "abcccccccaaaaaaaaccccccccccaaaaaaccccccaccaaaaaaaccccccaacccccccccaaaaaaaaaaccccccccccccccccccccccccccccccccaaaaa",
    "abcccccccaaaaaaaaacccccccccaaaaaacccccaaacaaaaaaaaaaaccaacccccccccccaaaaaaccccccccccccccccccccccccccccccccccaaaaa",
    "abcccccccaaaaaaaaaaccccccccaaaaaacaaacaaaaaaaaaaaaaaaaaaccccccccccccaaaaaaccccccccccccccaaacccccccccccccccccaaaaa",
    "abaaacccccccaaaaaaacccccccccaaacccaaaaaaaaaaaaaaaaaaaaaaaaacccccccccaaaaaaccccccccccccccaaacccccccccccccccccaaaaa",
    "abaaaaccccccaaaccccccccccccccccccccaaaaaaaaacaaaacacaaaaaacccccccccaaaaaaaacccccccccccccaaaaccaaacccccccccccaccaa",
    "abaaaaccccccaaccccaaccccccccccccccccaaaaaaacaaaaccccaaaaaccccccccccccccccacccccccccccccccaaaaaaaaacccccccccccccca",
    "abaaaaccccccccccccaaaacccccccccaacaaaaaaaacccaaacccaaacaacccccccccccccccccccccccccccciiiiaaaaaaaacccccccccccccccc",
    "abaaacccccccccccaaaaaacccccccccaaaaaaaaaaacccaaacccccccaacccccccccccaacccccccccccccciiiiiiijaaaaccccccccaaccccccc",
    "abaaaccccccccccccaaaacccccccccaaaaaaaacaaacccaaaccccccccccccccccccccaaacaaacccccccciiiiiiiijjjacccccccccaaacccccc",
    "abcccccaacaacccccaaaaaccccccccaaaaaacccccacaacccccccccccccccccccccccaaaaaaaccccccciiiinnnoijjjjjjjjkkkaaaaaaacccc",
    "abcccccaaaaacccccaacaaccccccccccaaaacccaaaaaaccccccccccccccccccccccccaaaaaaccccccciiinnnnooojjjjjjjkkkkaaaaaacccc",
    "abccccaaaaacccccccccccccccccccccaccccccaaaaaaaccccccccccccccccccccaaaaaaaaccccccchhinnnnnoooojjooopkkkkkaaaaccccc",
    "abccccaaaaaaccccccccccccccccccccccccccccaaaaaaacccccccccccccccccccaaaaaaaaacccccchhhnnntttuooooooopppkkkaaaaccccc",
    "abccccccaaaaccccccccccacccccccccccccccccaaaaaaacccaaccccccccccccccaaaaaaaaaaccccchhhnnttttuuoooooppppkkkaaaaccccc",
    "abccccccaccccccccccccaaaacaaaccccccccccaaaaaacaaccaacccaaccccccccccccaaacaaacccchhhnnnttttuuuuuuuuupppkkccaaccccc",
    "abccccccccccccccaaccccaaaaaaaccccccccccaaaaaacaaaaaacccaaaaaaccccccccaaacccccccchhhnnntttxxxuuuuuuupppkkccccccccc",
    "abcccccccccccccaaaacccaaaaaaacccaccccccccccaaccaaaaaaacaaaaaaccccccccaacccaaccchhhhnnnttxxxxuuyyyuupppkkccccccccc",
    "abcccccccccccccaaaaccaaaaaaaaacaaacccccccccccccaaaaaaaaaaaaaccccccccccccccaaachhhhmnnnttxxxxxxyyyuvppkkkccccccccc",
    "abcccccccccccccaaaacaaaaaaaaaaaaaaccccccccccccaaaaaacaaaaaaaccccccccccccccaaaghhhmmmttttxxxxxyyyyvvpplllccccccccc",
    "abccacccccccccccccccaaaaaaaaaaaaaaccccccccccccaaaaaacccaaaaaacccaacaacccaaaaagggmmmttttxxxxxyyyyvvppplllccccccccc",
    "SbaaaccccccccccccccccccaaacaaaaaaaacccccccccccccccaacccaaccaacccaaaaacccaaaagggmmmsttxxxEzzzzyyvvvppplllccccccccc",
    "abaaaccccccccccccccccccaaaaaaaaaaaaacaaccccccccccccccccaaccccccccaaaaaccccaagggmmmsssxxxxxyyyyyyvvvqqqlllcccccccc",
    "abaaacccccccccccccccccccaaaaaaaaaaaaaaaaacccccccccccccccccccccccaaaaaaccccaagggmmmsssxxxwywyyyyyyvvvqqlllcccccccc",
    "abaaaaacccccccccccccccccccaacaaaccaaaaaaacccccccccccccccccccccccaaaaccccccaagggmmmssswwwwwyyyyyyyvvvqqqllcccccccc",
    "abaaaaaccccccccccccccccccccccaaaccccaaaacccccccccccccccccaaccaacccaaccccccccgggmmmmssssswwyywwvvvvvvqqqlllccccccc",
    "abaaaaacccccccccccccaccacccccaaaccccaaaacccccccccccccccccaaaaaacccccccccccaaggggmllllsssswwywwwvvvvqqqqlllccccccc",
    "abaaccccccccccccccccaaaaccccccccccccaccaccccccccccccccccccaaaaacccccccccccaaagggglllllssswwwwwrrqqqqqqmmllccccccc",
    "abaaccccccccccccccccaaaaaccccccaaccaaccccccccccccccccccccaaaaaaccaacccccccaaaaggfffllllsswwwwrrrrqqqqqmmmcccccccc",
    "abacaaaccccccccccccaaaaaaccccccaaaaaaccccccaacccccccccccaaaaaaaacaaacaaccccaaaaffffflllsrrwwwrrrmmmmmmmmmcccccccc",
    "abaaaaaccccccccccccaaaaaaccccccaaaaaccccccaaaaccccccccccaaaaaaaacaaaaaaccccaaaaccfffflllrrrrrrkkmmmmmmmccccaccccc",
    "abaaaacccccccccccccccaaccccccccaaaaaacccccaaaacccccccccccccaaccaaaaaaaccccccccccccffflllrrrrrkkkmmmmmccccccaccccc",
    "abaaacccccccccccccccccccccccccaaaaaaaaccccaaaacccccccccccccaaccaaaaaaacccccccccccccfffllkrrrkkkkmddddcccccaaacccc",
    "abaaacccccccccccccccccccccccccaaaaaaaacccccccccccccccccccccccccccaaaaaaccccccccccccfffllkkkkkkkdddddddcaaaaaacccc",
    "abaaaacccccccccccccccccccccccccccaaccccccccccccccccccccccccccccccaacaaacccccccccccccfeekkkkkkkddddddcccaaaccccccc",
    "abcaaacccccccccccaaaccccccccaacccaaccccaaaaaccccaaaccccccccccccccaaccccccccccccccccceeeeekkkkdddddccccccaaccccccc",
    "abccccccccccccccaaaaaaccccccaaacaaccacaaaaaaaccaaaaccccccccccaccaaccccccccccccccccccceeeeeeeedddacccccccccccccccc",
    "abccccccccccccccaaaaaacccccccaaaaacaaaaaccaaaaaaaacccccccccccaaaaacccccccccccccccccccceeeeeeedaaacccccccccccccaaa",
    "abccccccaaacccccaaaaacccccccaaaaaacaaaaaaaaaaaaaaaccccccccccccaaaaaccccccccccccccccccccceeeeecaaacccccccccccccaaa",
    "abccccccaaaccccccaaaaacccccaaaaaaaaccaaaaacaaaaaaccccccccccccaaaaaacccccccccccccccccccccaaaccccaccccccccccccccaaa",
    "abccccaacaaaaacccaaaaacccccaaaaaaaacaaaaaaaaaaaaaaaccccaaaaccaaaacccccccccccccccccccccccaccccccccccccccccccaaaaaa",
    "abccccaaaaaaaaccccccccccccccccaaccccaacaaaaaaaaaaaaaaccaaaaccccaaacccccccccccccccccccccccccccccccccccccccccaaaaaa"};

class HillClimbingAlgorithm
{
public:
    HillClimbingAlgorithm(const vector<string> &_input) : input(_input), X(input[0].size()), Y(input.size())
    {
        cout << "Size of Input: " << X << "x" << Y << endl;

        // Initialize height matrix
        height = new int *[X];
        height[0] = new int[X * Y];
        for (int x = 0; x < X; ++x)
            height[x] = height[0] + Y * x;
        for (int x = 0; x < X; ++x)
            for (int y = 0; y < Y; ++y)
            {
                switch (input[y][x])
                {
                case 'S':
                    S = {x, y};
                    height[x][y] = 0;
                    break;
                case 'E':
                    E = {x, y};
                    height[x][y] = 'z' - 'a';
                    break;
                default:
                    height[x][y] = input[y][x] - 'a';
                    break;
                }
            }

        // Initialize costs matrix
        costs = new unsigned int *[X];
        costs[0] = new unsigned int[X * Y];
        for (int x = 0; x < X; ++x)
            costs[x] = costs[0] + Y * x;
        for (int xy = 0; xy < X * Y; ++xy)
            costs[0][xy] = -100;

        costs[E.first][E.second] = 0;

        findPath();
    }

    void printheightmatrix()
    {
        for (int y = 0; y < Y; ++y)
        {
            for (int x = 0; x < X; ++x)
            {
                cout << setw(3) << height[x][y];
            }
            cout << endl;
        }
    }

    void printcostmatrix()
    {
        for (int y = 0; y < Y; ++y)
        {
            for (int x = 0; x < X; ++x)
            {
                cout << setw(11) << costs[x][y];
            }
            cout << endl;
        }
    }

    bool updatePoint(int x, int y)
    {
        bool changed = false;
        if (x > 0)
            if (height[x - 1][y] - 1 <= height[x][y] && costs[x - 1][y] + 1 < costs[x][y])
            {
                changed = true;
                costs[x][y] = costs[x - 1][y] + 1;
            }

        if (x < X - 1)
            if (height[x + 1][y] - 1 <= height[x][y] && costs[x + 1][y] + 1 < costs[x][y])
            {
                changed = true;
                costs[x][y] = costs[x + 1][y] + 1;
            }

        if (y > 0)
            if (height[x][y - 1] - 1 <= height[x][y] && costs[x][y - 1] + 1 < costs[x][y])
            {
                changed = true;
                costs[x][y] = costs[x][y - 1] + 1;
            }

        if (y < Y - 1)
            if (height[x][y + 1] - 1 <= height[x][y] && costs[x][y + 1] + 1 < costs[x][y])
            {
                changed = true;
                costs[x][y] = costs[x][y + 1] + 1;
            }

        return changed;
    }

    bool updateAllPoints()
    {
        bool changed = false;

        for (int y = 0; y < Y; ++y)
            for (int x = 0; x < X; ++x)
                changed |= updatePoint(x, y);

        return changed;
    }

    void findPath()
    {
        while (updateAllPoints())
            ;
    }

    int getSteps()
    {
        int Steps = costs[S.first][S.second];

        cout << "result A: " << Steps << endl;
        return Steps;
    }
    int getMinimalStepsFromA()
    {
        unsigned int MinimalStepsFromA = -1;

        for (int y = 0; y < Y; ++y)
            for (int x = 0; x < X; ++x)
                if (0 == height[x][y] && costs[x][y] < MinimalStepsFromA)
                    MinimalStepsFromA = costs[x][y];

        cout << "result B: " << MinimalStepsFromA << endl;
        return MinimalStepsFromA;
    }

private:
    const vector<string> input;
    int X = 0;
    int Y = 0;
    int **height = nullptr;
    unsigned int **costs = nullptr;

    pair<int, int> S;
    pair<int, int> E;
};

TEST_CASE("Testdata")
{
    HillClimbingAlgorithm HillClimbingAlgorithmData(inputTestdata);
    HillClimbingAlgorithmData.printcostmatrix();
    REQUIRE(31 == HillClimbingAlgorithmData.getSteps());
    REQUIRE(29 == HillClimbingAlgorithmData.getMinimalStepsFromA());
}

TEST_CASE("HillClimbingAlgorithm")
{
    HillClimbingAlgorithm HillClimbingAlgorithmData(inputData);
    REQUIRE(380 == HillClimbingAlgorithmData.getSteps());
    REQUIRE(375 == HillClimbingAlgorithmData.getMinimalStepsFromA());
}
