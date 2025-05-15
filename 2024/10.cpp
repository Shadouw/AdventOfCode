#include <aoc.h>
using namespace std;
using namespace aoc;

class HoofIt {
public:
    HoofIt(string _file, string _extension)
    : datafile(_file, _extension)
        , mymap(datafile.getAOCMap())
    {
        string s = mymap.getString();

        trails = mymap.findTrails('0', '9');
    }

    long getTrailHeadScores(){
        map<position,set<position>> trailHeads;

        for ( auto t : trails )
            trailHeads[t.front()].insert(t.back());

        long score = 0;
        for ( auto th : trailHeads )
            score += th.second.size();

        return score;
    }

    long getResultA()
    {
        long resultA = getTrailHeadScores();

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = trails.size();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    aocdatafile datafile;
    aocmap mymap;
    vector<vector<position>> trails;
};

TEST_CASE("Testdata")
{
    HoofIt HoofItData(__FILE__, "example");
    REQUIRE(36 == HoofItData.getResultA());
    REQUIRE(81 == HoofItData.getResultB());
}

TEST_CASE("HoofIt")
{
    HoofIt HoofItData(__FILE__, "mydata");
    REQUIRE(587 == HoofItData.getResultA());
    REQUIRE(1340 == HoofItData.getResultB());
}