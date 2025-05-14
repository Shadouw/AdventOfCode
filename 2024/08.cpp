#include <aoc.h>
using namespace std;
using namespace aoc;

class ResonantCollinearity {
public:
    ResonantCollinearity(string _file, string _extension)
    : datafile(_file, _extension)
        , roof(datafile.getAOCMap())
    {
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
    aocdatafile datafile;
    aocmap roof;
};

TEST_CASE("Testdata")
{
    ResonantCollinearity ResonantCollinearityData(__FILE__, "example");
    REQUIRE(14 == ResonantCollinearityData.getResultA());
    REQUIRE(34 == ResonantCollinearityData.getResultB());
}

TEST_CASE("ResonantCollinearity")
{
    ResonantCollinearity ResonantCollinearityData(__FILE__, "mydata");
    REQUIRE(252 == ResonantCollinearityData.getResultA());
    REQUIRE(839 == ResonantCollinearityData.getResultB());
}