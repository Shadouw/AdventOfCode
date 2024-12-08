#include <aoc.h>
using namespace std;

const vector<string> inputTestdata = {
    "............",
    "........0...",
    ".....0......",
    ".......0....",
    "....0.......",
    "......A.....",
    "............",
    "............",
    "........A...",
    ".........A..",
    "............",
    "............"
};

const vector<string> inputData = {
    ".............4....O..........w....R...............",
    ".................................f................",
    "..............4...j......NW0......................",
    "....................R..W..........................",
    "...............R..................................",
    "..................................................",
    "v.......................f.......0W................",
    ".....9L............l...N.........w................",
    "....L....9.......ON........8......................",
    ".1.........49L........f..0..N.....................",
    "..........................V...l...................",
    "..........4.......................................",
    ".....................j...................3.....U..",
    "....O.....U.......................................",
    "........J......................l..................",
    ".O....s.Q.......j.....l.....w..........F...q......",
    "..................................................",
    ".U.......................j..8.....................",
    "................U...............................3.",
    "2.............................J............3......",
    "..............................F...................",
    ".....s...R...........J..................F.........",
    ".s......................x..........F.....q........",
    ".......2.....Q........3........x..................",
    "...........v......................u...............",
    "..............v...........n......8............q...",
    ".......f..................8........i..............",
    ".5..................1n..............P.....i.......",
    "............7............Q..................X.....",
    "......5...p....................V..................",
    ".................J..........nx............q.......",
    ".......p............W...........................0.",
    "......2.............p.5.....1....P................",
    "......I.................7.X....i...P..............",
    "............s.....r...w................V..........",
    "...............or...6.................V...........",
    "............................PS.7..................",
    "..........o...........................S...........",
    "...........5..............o..1.......n............",
    "...........I.........r.......7.......6............",
    ".................o.r...........X..................",
    "................................x.........u.......",
    ".........p..Q....2................................",
    ".........v.................S.....................u",
    "I...........................S.....6...............",
    "..................................................",
    ".......I..........................................",
    "..................................................",
    ".......................................6..........",
    ".................................X................"
};

class ResonantCollinearity {
public:
    ResonantCollinearity(const vector<string>& _input)
        : input(_input)
        , roof(_input)
    {
        cout << "Size of Input: " << roof.getX() << "/" << roof.getY() << endl;
    }

    position getDiff(position a, position b)
    {
        return { a.first - b.first, a.second - b.second };
    }

    pair<position, position> antinodes(position a, position b)
    {
        position antinode1;
        position antinode2;

        position diff = getDiff(a, b);

        if (b == pair<long, long>(a.first + diff.first, a.second + diff.second)) {
            antinode1 = { a.first - diff.first, a.second - diff.second };
            antinode2 = { b.first + diff.first, b.second + diff.second };
        } else {
            antinode1 = { a.first + diff.first, a.second + diff.second };
            antinode2 = { b.first - diff.first, b.second - diff.second };
        }

        return { antinode1, antinode2 };
    }

    long getResultA()
    {
        auto roof2 = roof;
        string frequencies = roof.getChars();
        for (auto c : frequencies) {
            auto allpositions = roof.findAllChars(c);

            for (auto p1 = allpositions.begin(); p1 != allpositions.end(); ++p1) {
                for (auto p2 = p1 + 1; p2 != allpositions.end(); ++p2) {
                    auto a = antinodes(*p1, *p2);
                    roof2.setPosition(a.first, '#');
                    roof2.setPosition(a.second, '#');
                }
            }
        }

        long resultA = roof2.findAllChars('#').size();

        cout << "resultA: " << resultA << endl;
        return resultA;
    }

    long getResultB()
    {
        auto roof2 = roof;
        string frequencies = roof.getChars();
        for (auto c : frequencies) {
            auto allpositions = roof.findAllChars(c);

            for (auto p1 = allpositions.begin(); p1 != allpositions.end(); ++p1) {
                for (auto p2 = p1 + 1; p2 != allpositions.end(); ++p2) {
                    auto diff = getDiff(*p2, *p1);
                    long i = 0;
                    while (roof2.setPosition({ (*p1).first + diff.first * i, (*p1).second + diff.second * i }, '#'))
                    {
                      ++i;
                    }
                    i = 0;
                    while (roof2.setPosition({ (*p1).first - diff.first * i, (*p1).second - diff.second * i }, '#')) {
                        ++i;
                    }
                }
            }
        }

        long resultB = roof2.findAllChars('#').size();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    aocmap roof;
};

TEST_CASE("Testdata")
{
    ResonantCollinearity ResonantCollinearityData(inputTestdata);
    REQUIRE(14 == ResonantCollinearityData.getResultA());
    REQUIRE(34 == ResonantCollinearityData.getResultB());
}

TEST_CASE("ResonantCollinearity")
{
    ResonantCollinearity ResonantCollinearityData(inputData);
    REQUIRE(252 == ResonantCollinearityData.getResultA());
    REQUIRE(839 == ResonantCollinearityData.getResultB());
}