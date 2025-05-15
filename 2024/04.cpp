#include <aoc.h>
using namespace std;
using namespace aoc;

class CeresSearch {
public:
    CeresSearch(string _file, string _extension)
    : datafile(_file, _extension)
    {
        ysize = datafile.getYSize();
        xsize = datafile.getXSize();

        // Parse data
        // for (auto elem : input)
        //    items.push_back(item(elem));
    }

    char getLetter(size_t x, size_t y)
    {
        if (x < 0 || x >= xsize || y < 0 || y >= ysize)
            return '.';

        return datafile.getLines()[y][x];
    }

    long getXMAS()
    {
        long XMAS = 0;
        // Find all 'X'
        for (size_t x = 0; x < xsize; x++) {
            for (size_t y = 0; y < ysize; y++) {
                if ('X' == getLetter(x, y)) {
                    if ('M' == getLetter(x, y + 1) && 'A' == getLetter(x, y + 2) && 'S' == getLetter(x, y + 3)) // N
                        ++XMAS;
                    if ('M' == getLetter(x + 1, y + 1) && 'A' == getLetter(x + 2, y + 2) && 'S' == getLetter(x + 3, y + 3)) // NE
                        ++XMAS;
                    if ('M' == getLetter(x + 1, y) && 'A' == getLetter(x + 2, y) && 'S' == getLetter(x + 3, y)) // E
                        ++XMAS;
                    if ('M' == getLetter(x + 1, y - 1) && 'A' == getLetter(x + 2, y - 2) && 'S' == getLetter(x + 3, y - 3)) // SE
                        ++XMAS;
                    if ('M' == getLetter(x, y - 1) && 'A' == getLetter(x, y - 2) && 'S' == getLetter(x, y - 3)) // S
                        ++XMAS;
                    if ('M' == getLetter(x - 1, y - 1) && 'A' == getLetter(x - 2, y - 2) && 'S' == getLetter(x - 3, y - 3)) // SW
                        ++XMAS;
                    if ('M' == getLetter(x - 1, y) && 'A' == getLetter(x - 2, y) && 'S' == getLetter(x - 3, y)) // W
                        ++XMAS;
                    if ('M' == getLetter(x - 1, y + 1) && 'A' == getLetter(x - 2, y + 2) && 'S' == getLetter(x - 3, y + 3)) // NW
                        ++XMAS;
                }
            }
        }

        cout << "XMAS: " << XMAS << endl;
        return XMAS;
    }
    long getX_MAS()
    {
        long X_MAS = 0;
        // Find all 'A'
        for (size_t x = 0; x < xsize; x++) {
            for (size_t y = 0; y < ysize; y++) {
                if ('A' == getLetter(x, y)) {
                    if ('M' == getLetter(x + 1, y + 1) && 'S' == getLetter(x - 1, y - 1) || 'S' == getLetter(x + 1, y + 1) && 'M' == getLetter(x - 1, y - 1))
                        if ('M' == getLetter(x + 1, y - 1) && 'S' == getLetter(x - 1, y + 1) || 'S' == getLetter(x + 1, y - 1) && 'M' == getLetter(x - 1, y + 1))
                            ++X_MAS;
                }
            }
        }

        cout << "X_MAS: " << X_MAS << endl;
        return X_MAS;
    }

private:
    aocdatafile datafile;
    size_t xsize;
    size_t ysize;
};

TEST_CASE("Testdata")
{
    CeresSearch CeresSearchData(__FILE__, "example");
    REQUIRE(18 == CeresSearchData.getXMAS());
    REQUIRE(9 == CeresSearchData.getX_MAS());
}

TEST_CASE("CeresSearch")
{
    CeresSearch CeresSearchData(__FILE__, "mydata");
    REQUIRE(2483 == CeresSearchData.getXMAS());
    REQUIRE(1925 == CeresSearchData.getX_MAS());
}