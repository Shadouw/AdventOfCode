#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const string enhancementalgorithm = "##.....##.#.#####.#...###...#.##..#....##..#.##.#.#....##.....#.##.##.#.#.#...#.#.#.###.##..#.#.#.#..#.##.#...#..#.#.#..#####.##.#..#..##.#..#.#...#.....#.###..#..#####.##...#..##..##...#.#...##.##..##...##.##.#......#...##.##.#####.#....####....######.#.#.......#.############.###..#..#......####......#..##.####.##....#..#.#.###..#.####.####.#.##.##.##..###.#..#.......#....#..########....##..##.#...#.#.###.###.###..#..#.###..#....#.###..#.##.##..###.#.#####....###.##.###.....#######........#.#.##...##.#....";
const string testalgorithm = "..#.#..#####.#.#.#.###.##.....###.##.#..###.####..#####..#....#..#..##..###..######.###...####..#..#####..##..#.#####...##.#.#..#.##..#.#......#.###.######.###.####...#.##.##..#..#..#####.....#.#....###..#.##......#.....#..#..#..##..#...##.######.####.####.#.#...#.......#..#.#.#...####.##.#......#..#...##.#.##..#...##.#.##..###.#......#.#.......#.#.#.####.###.##...#.....####.#..#..#.##.#....##..#.####....##...##..#...#......#.#.......#.......##..####..#...#.#.#...##..#.#..###..#####........#..####......#..#";
const vector<string> testimage = {
    "#..#.",
    "#....",
    "##..#",
    "..#..",
    "..###"};

const vector<string> image = {

    "..##.#.#..#..##.###....######.####.....#.#..##..####......####...##...#.##..##.##.#.####.##.#.##.#.#",
    "#.#####.#.#..#.#...##.......#.#...##.#..#.######....#.#####....####...##..##..#.#####..#.##......##.",
    "....#..#...#...######...#.#.##.##.####..####....####.##.......#..##.#.##..#.#..##..#.##...##...#.#..",
    ".#..#####..#..#..#.#.....#..###.###.##.#..#....#..#...#....#####...###.....#.##.####.#######.##..##.",
    "###.###...###..##.##.######..####.#.###..#....####....#...#.##.#.#....#..#....#.#.#.#.#.......#..###",
    ".#.##.#.#####.....#...##.##..##.##...#####....#.##.###.....##.#..#.######.....###...#.###....#...#.#",
    "##..##.##...#######..#..#.###.##.#.###..##.#.#.#..#..#....##.#..###....#..##.#..#.#....##.##........",
    "#..#......#.###.#####.##..#....#...#.#.#.#.###.##.##..#.#.##.#...#.##..##....#######.######..##.#.#.",
    ".###.....#....###..#.#...##...#.#.####.##.###.#.##..##..###.#.##.####..##.....##....##.......#.#.###",
    "..#.....#####.#.#..##..##..#.###..#.##.#..#.####....##..####.###....##.##.#.#...#..###.##......#####",
    "#..#..####.#.#...#..#...#######.#......#.#.#..#.##.#......#......#.##.####.######....#####..##...###",
    ".###.#...#..####.##...#.#####.##.#...#.#...#...#.#.##.###..#.##.###..#.##...######.#.#.##..#.##..###",
    "####.#.##....#.#..#########.###.#.###.#..#.####.#..##.##..#.#.#....###...#..#..###..##...#..#.....#.",
    "....#####.#..##.....###..#..#.##...#####..##...#...#.##.###....#..####.##.#####.##.#..##..##.#..#.#.",
    "####...#..#####.#..#######.##.#.####...#####.#.#.##....#.###...#.###.##...#...##.##.##.#.#.....##.##",
    "##..##.##.#.#..##..##.#..#.#..#.##.###.#..#..##.#..##..##.##.#......#.##..##.##.##.....##..#.#...###",
    "#..#.#.#.#####..#.##..##....#.##.#.###.#.#...##.###.#..##.##...##..###.##...##.####...##.#..##..##..",
    "####....##.#.#........###..#..####.###..#.#.#....#####.#.#...#.##.####.#..#...#..#.#...#.#...#.##.##",
    "#..#..##.##..#....#...#.#.....#...#...##.....####.#.###.#.#.####.#..#.#.#...#.##.###...##.#.##..##.#",
    "##..##..#.###.####.#####.###..#..#.....####.#..#.##.#####.##.#...##...###.######.#.#...#####.#..#...",
    "#...##.#......#####..##..#.....#..###.#.....##.....#####....#.##.###...##.####.#.#...#.##.######.#..",
    "##.#.###.##.......#.##.####..######...######...####.#..######....##.#.......####...###..##.##...#...",
    "#.....##.#####.####..#.##.#.#.....##.#..#....#.....#.....#.#...#.###.#.....#####.#.###..##..##..###.",
    "#.###..######..#....#...#.#.##..#.....#.###.....#..#.##..#..#.##....#.#..#..#..####.#.##.....#.#.###",
    "#..##..#...##..##........#...#....###.###.#.########.#..#.............#....####..#..##.#.##.#......#",
    ".###..#####........##..##.###.##..#.#.#.####.#..##.##.#...#..####..####..##.##..#.#.#.#......#.##.#.",
    "#.##..##..######....#....##.....#...##..#.#.......#.##.#####.###..##...##.##.#..##.###...##########.",
    ".##.########.##..###....#####.###.###.#.#.##.#.#.#..##.#.#..#.##..#....#.####..###.##..###.....##.#.",
    "..##...#.###.#.#.#...#.##..#.#...#..##..##.##..#.#..##..#.##..##.###.##..##...#.###..##...#..#.#..##",
    ".#.#.####.###.#.##.##.#.###.#.#....##.#........#..##..##..#...##..#.#.###.#.###..#...#.#.##.##..##.#",
    "#.#.####.#.##...###.###.#...#.###.#.#.....#..#.##.#...#.#..#.#.##...###..###.#..#.###.#.####.###.#..",
    "##..####...#.#.####..#..#...###.##.###.##...##.#.#..##..#.###.#.##.##.#..#.###.#..#######.#....#.#..",
    ".#.#.######..##.#..###.##.#....##....#.#..###.....#.##...#..#...#.#.#.#.##....##....####....#......#",
    ".#.#.#.##.###...##.#...###.#....#.#.#....##...#.######.#.#.#####..#..######.#.##.#.##.....##.####.##",
    "..######...##..##..#.#.#.##.......##.#.#...#.#####...######..#######...####..##...#.##.##.#..#...#.#",
    "##..#.#.#..##....#.##....#.....#.#####..#.#.#.#.#.#####....#..###..###.###...#...######...##..#.#..#",
    "####.....##...##....##.##.#...#..##.#..###.#....#...###...#..######...####.###..##......##..###.##..",
    "##.####...#.#.#.#..#..#.#.###..##.#....##.##..#..##........##.##.####.##.#.###.#.#....#####.#.....#.",
    "#...#.....###..#..###..##..#.#..#.###.#..#####.#.###..###..#...##.#..##..#...##...#.#.###.#.#.##.###",
    "##.#...#....##.########..##....##..###.#....###.#.#....#...###.....###.#.##.#..#####......###.#.#.#.",
    "###.###.#...###..#.##....#.#.#.........#.#####.#.#...#######.###.#.#.#..#.#...#..##.#...###.#...##..",
    ".####.###.#..#.###.#.#.######..#####.#...###..#...###..#.########.#.#.#..####..##.###..#..##..##....",
    "#..##.#.#...####.#..#..#..###.##...#####..#.###......#..####.####.##..###.....###..#....#.#######...",
    "###..##.#.#.#..##..##...#..#.#......#..####....#.##..#.##.###...####..##..####...#...###...##..#.#.#",
    "##.##..#....###.##......#.#.##.#.###..##...##.##.#....#.#.#.###....##..#....#.########...#.....##.#.",
    "#.#..###.....#######..#.###....####...##......####..#...##....#..####.#....##.#...#....##.###.##....",
    "#....######..##.##..##.###.....##..#.....#....##...#....###.....##.##...##.#..##.####.#..####.##.#.#",
    ".#.#....#..####..#..#.#...#..#..###..#........###.##...##.##....#.#..#.##..#.##...#####...#..#####..",
    ".##..####..##...##.###.#..####...#....#..#..##.#...##...#.###.....#.#..######.#.#####..#####..######",
    ".#...#.#..##.#.##..#.#.#...###..#..#....###.########..######.#.####...##..#..#...##.####...#.#######",
    ".#####.##.#####.#.#.##.#.#....#..###.#..##......#####..#.##.#########...##..###.######.....#.#.####.",
    "##.#.#.#.##..##.##...#.....#########.##.#.......#..#####.#..#.#.#######...#..##.#..###.#####...##.##",
    "##.##...###.###...#..##.#..#.##.##.....##.#.#.###...##.#.##..#.#.#...####..#..###.####..#...##.##.#.",
    "#...#.#.#..#.##..#..####.#..###.#####...#..#.#..#####.#..#.......#..#.....#.#.#.#.#.##.##.###....#.#",
    "....##..#..####.##..#.#...#####...#...###.##.#.#...##.##.##..######......####.##.#..#.##..##...####.",
    "##...###..#.##..##..#.##...#.#.####.####..#.#.###..#.#..##.#...#.#.####..#.#.##.##.#.###.#.###.#.#..",
    "#.#.#.#..#######.#....#..#.#.####....##...##.###.####.####.#..#..##...##..#..##....#...#..##.####...",
    ".#####.###.##.##..##.##.##.#.##...##..#..##...#.#.##.#...####..#####..#.............###..#..#..#.#..",
    ".##..##..###.##.##.....#...#....#..#..#.#######....#...#......##.###..#....#.#.####.#....###..##..#.",
    ".##.#.###......#.###..#.#..#.##.###.#.#..#.#.##......##.#..##.###..#.###.##...##.#.........###.#.###",
    ".#.#.###......#..#####.###..#..#.##..........#..##.###.#.##.#..#.##.#.###.#.###..#.#...#.###..###...",
    ".###.####.##.##.###..#.#..###..##..##....###.###..#...###...#.##.#...#.#.##..###.##.##..###.##....##",
    "###.########.#.######..#.##.#.#####.###...###.###.#####.###..#...#.###..#...#..#.###.#......#......#",
    ".##....###...##.####....#....#..##...#....###..#..#..#...#...#..##....#####.#..###...##.####....###.",
    ".....#..##...##....####.#..#.#.##..####.#####..###...###.###..##..#...##.....#.#.##...#.....#.####..",
    ".#.###.#.#..#.####....#.#.##..#.####..#...#.#.#.#..#..#.####.###....#####.#..##..#.#..##.#.####.#.#.",
    "#.####.#.....###..###.#..#.####.#..#.#.##.##..##..#.#.#..##...#.####..#.###...#....#.#...#.#..##.#..",
    ".#.####...#.#.#..###.##..#.#...##.##.#.....######...#....#.#.##.....###......##.#...#.###..#....###.",
    "..##.###......#.##...###.#...######..##.#.#.#.#..#####.##...#......#....#.####..#..#..#.#.#.#..#..##",
    "#.##.##.#.##.#.#..#.#.#..###....#####..#.#####.####.##.##.#.##.#..#.#.#.#.###..##.##.#####..##.#####",
    "..#.#..##.#.##.#..###..##.#.#..#.#..#.##....#....##..#.#..#.#.##.##.#.#.#..##..###..##.##.#.###.####",
    "####.####..#..#.#....##.#...##....#.######...#.##.....#.##..#####.#####..##..#.####.#.##......#.#...",
    ".#####..##...#....#.#..#.#.##.#...#.#..#..###.#..#.#..#..##.#.....#.####.#.#...###..#..##.##......##",
    "###.#.....###...###########.##.##..#....##.#.####.#.#.#.....#...###.#.##..#.#.#...###..........###.#",
    "#.#.##.##..#..#.##.#..##.#.#.####..###.#.#..###.#.#.###..###..#.##...#..#..#.#...#...#..##..#..###..",
    "..#.#####.###..#.......#..#.####.#.######....#.##.##.#..#..#####..#...#.##.##.##..#...#####.##..#..#",
    "##..##...##...#.####...#.#....##..#.....##.###.####.##..###..#.##..#..##..####....##.#...#.####.#..#",
    "#.#.##...####..#.##....##...#.###..##....##.#.#.....###...####..###.###..#...##.###.#.#.#.#....#.##.",
    "..####.##..##.#.....##...#.#.##.#.....#.#.##..##.##..#.##...##....#.#...###..####.#.#######..##.#.##",
    "#.....##...#...#...#.##.#.####.###..#.#..###.#.#..#######...#.##.###.#.###.#.##.#.##.....#.#...#.##.",
    "#..#####.....#..#..###.#####..##.##....#.###.##.#.#..##...###...#######.##....#...###...#####..##..#",
    "#..############.##.####..#..#..#..#.####........#.###.###..#.######...##..####..###......##.#.#..#..",
    "##.............###.#.####....##.##....#.#.....#.#.###...##.##.#.#..###.##.##..#.#.#####..#.#.#....##",
    ".####...###.#.###.#..#.#.#.####.#......#..#..#.#...#..#..#....#.##..##.#..##.#..#....#..##.#..##.#.#",
    "###.#..#..###.#...#....###..########....##....#....#.###.#.##...###.#.#.#..##..#.##....#.######.#.#.",
    "#.###....#.##.#.#...#.##.###.##..#..###.##...####..#..#..#.####.#..#..#..#.###....#..#.##...##...###",
    "#..#.##.#.#.#...#.#####.##.#..###.#.#.###........####.#####..#.##..###....#..#.#.#...#.#.#..#.#####.",
    "#..##.##.#####...##...##.##..##.#...#.#..#...#..#..#.....#..####.#...#..#######....########.....#.##",
    "#.....####.#.#.#..#.##..#.#.#####..#.#..######.#.#..#...#..#....#.##.##..##.#.###..#.##...##.#...##.",
    ".###.#..##.##....#.##.#..#.##..####.......##..##.##.#####.###.##.....#.....##.###.#.##.#.#.##..#..##",
    "##....#.#.##.###.#.##.#####.#..#####.#..#####.##.#..#..#..#####.##.###.#..###...#.#...#....######..#",
    "####..#..#..#..######...#####..#..#.#...#.##....###...#...##......#...#####.##.#..#.#.##.#...##.##.#",
    "####...##...#..#..##..#.#....#####...#.#....######.#.#.....#...##..##.##..##...##.###.....##....##.#",
    ".#.####.#..##..####...#.##.##.##..#####..##.#.#..##....#..#.#.####..##.##.#.###.##..####......##.#..",
    "...#..####...##.##.#..#.#....#######.####.#...###....##.#...####.#.###.####.#.#.##.#.......###.####.",
    ".......#..#..#.#..#..#...#.#####.#.#..####..#..#...##..#.#.####.#...#.#.#.#.#.#...#.#.##.#..#.#.####",
    "...###.#...#..#.#.#.....##.##.#.#..##.#......#.#######.....#..###.#####.##..###.#..#.#######.#####.#",
    ".####.#..#.#.###...#..#####...#....##..####..#..#######.###.##.##..######.###..##...#####...#.##.#.#",
    "#..##..####.#.#.#..#.####.###...#..###.#.##.##..####..###.####.....#..#.#.####...#.#.#.##.##..#.#.##",
    "..#.###.#...###..#...###.###.####..##..#.#...##.#...#..#....#####.#####..##.####..##.##.##..#...####"};

class imageenhancment
{
public:
    imageenhancment(const vector<string> &_image, const string &_algorithm, bool ai = true) : image(_image), algorithm(_algorithm), autoincrease(ai)
    {
        xmax = image[0].size();
        ymax = image.size();
        cout << "Size of image: " << image[0].size() << "-" << image.size() << endl;

        for (int y = ymin; y < ymax; ++y)
        {
            for (int x = xmin; x < xmax; ++x)
            {
                pixels[make_pair(x, y)] = (image[x][y] == '#');
            }
        }
    }

    void mapincrease(uint32_t addsize)
    {
        xmin -= addsize;
        ymin -= addsize;
        xmax += addsize;
        ymax += addsize;
    }

    void applyalgorithm()
    {
        map<pair<int, int>, bool> oldpixels(pixels);
        pixels.clear();
        if (autoincrease)
        {
            static bool fillblack = false;
            if ( !fillblack)
            mapincrease(2);/*            
            // Fill the "border"
            if (fillblack)
            {
                for (int x = xmin; x < xmax; ++x)
                {
                    oldpixels[make_pair(x, ymin)] = (algorithm[0] == '#');
                    oldpixels[make_pair(x, ymax - 1)] = (algorithm[0] == '#');
                }
                for (int y = ymin; y < ymax; ++y)
                {
                    oldpixels[make_pair(xmin, y)] = (algorithm[0] == '#');
                    oldpixels[make_pair(xmax - 1, y)] = (algorithm[0] == '#');
                }
            }
            fillblack = !fillblack;*/
        }

        for (int x = xmin; x < xmax; ++x)
        {
            for (int y = ymin; y < ymax; ++y)
            {
                int bin = 0;
                for (int x2 = x - 1; x2 <= x + 1; ++x2)
                {
                    for (int y2 = y - 1; y2 <= y + 1; ++y2)
                    {
                        bin *= 2;
                        bin += (oldpixels[make_pair(x2, y2)] ? 1 : 0);
                    }
                }
                bool wtf = ('#' == algorithm[bin]);
                pixels[make_pair(x, y)] = wtf;
            }
        }
    }

    void printimage()
    {
        for (int x = xmin; x < xmax; ++x)
        {
            for (int y = ymin; y < ymax; ++y)
            {

                if (pixels[make_pair(x, y)])
                    cout << "*";
                else
                    cout << " ";
            }

            cout << endl;
        }
        cout << endl;
    }

    uint32_t countlit(int ignorframe = 1)
    {
        uint32_t lit = 0;

        for (int x = xmin + ignorframe; x < xmax - ignorframe; ++x)
        {
            for (int y = ymin + ignorframe; y < ymax - ignorframe; ++y)
            {
                if (pixels[make_pair(x, y)])
                    ++lit;
            }
        }
        return lit;
    }

    //private:
    const vector<string> image;
    const string algorithm;
    int xmin = 0, xmax = 0, ymin = 0, ymax = 0;
    map<pair<int, int>, bool> pixels;
    bool autoincrease = true;
};

TEST_CASE("Testdata")
{
    imageenhancment testimageenhancment(testimage, testalgorithm);

    //testimageenhancment.mapincrease(20);
    testimageenhancment.printimage();
    testimageenhancment.applyalgorithm();
    testimageenhancment.printimage();

    testimageenhancment.applyalgorithm();
    testimageenhancment.printimage();

    REQUIRE(35 == testimageenhancment.countlit(0));
}

TEST_CASE("Testdata B")
{
    imageenhancment testimageenhancment(testimage, testalgorithm);

    //testimageenhancment.mapincrease(100);

    for (int i = 0; i < 50; ++i)
        testimageenhancment.applyalgorithm();

    REQUIRE(3351 == testimageenhancment.countlit(0));
}

TEST_CASE("Problem A")
{
    imageenhancment testimageenhancment(image, enhancementalgorithm,false);
    testimageenhancment.mapincrease(3);
    //testimageenhancment.printimage();
    testimageenhancment.applyalgorithm();
    //testimageenhancment.printimage();

    testimageenhancment.applyalgorithm();
    //testimageenhancment.printimage();

    uint32_t resulta = testimageenhancment.countlit(1);
    cout << "Result A: " << resulta << endl;
    REQUIRE(5275 == resulta);
}

TEST_CASE("Problem B")
{
    imageenhancment testimageenhancment(image, enhancementalgorithm,false);
    testimageenhancment.mapincrease(99);

    for (int i = 0; i < 50; ++i)
    {
        //if ( 10 == i )
            //testimageenhancment.printimage();
        testimageenhancment.applyalgorithm();
    }

    uint32_t resultb = testimageenhancment.countlit(49);

    //testimageenhancment.printimage();
    cout << "Result B: " << resultb << endl;
    REQUIRE(16482 == resultb);
}

TEST_CASE("Test B")
{
    imageenhancment testimageenhancment(image, enhancementalgorithm);
    //testimageenhancment.mapincrease(2);

    for (int i = 0; i < 50; ++i)
    {
        testimageenhancment.applyalgorithm();
        testimageenhancment.printimage();
    }

    uint32_t resultb = testimageenhancment.countlit();

    cout << "Result B: " << resultb << endl;
    REQUIRE(16482 == resultb);
}
