#include <aoc.h>
using namespace std;
using namespace aoc;

class HistorianHysteria {
public:
    HistorianHysteria(string _file, string _extension)
        : datafile(_file, _extension)
    {
        // Parse data
        for (auto elem : datafile.getVectors()) {
            long leftnumber = atol(elem.front().c_str());
            long rightnumber = atol(elem.back().c_str());

            leftset.insert(leftnumber);
            rightset.insert(rightnumber);

            ++leftmap[leftnumber];
            ++rightmap[rightnumber];
        }
    }

    long getResultA()
    {
        long resultA = 0;

        for (auto l = leftset.begin(), r = rightset.begin(); l != leftset.end(); ++l, ++r) {
            resultA += abs(*l - *r);
        }

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = 0;
        for (auto e : leftmap) {
            resultB += e.first * e.second * rightmap[e.first];
        }
        //    resultB += e.getResultB();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    multiset<long> leftset;
    multiset<long> rightset;
    map<long, long> leftmap;
    map<long, long> rightmap;
    aocdatafile datafile;
};

TEST_CASE("Testdata")
{
    HistorianHysteria HistorianHysteriaData(__FILE__, "example");
    REQUIRE(11 == HistorianHysteriaData.getResultA());
    REQUIRE(31 == HistorianHysteriaData.getResultB());
}

TEST_CASE("HistorianHysteria")
{
    HistorianHysteria HistorianHysteriaData(__FILE__, "mydata");
    REQUIRE(2378066 == HistorianHysteriaData.getResultA());
    REQUIRE(18934359 == HistorianHysteriaData.getResultB());
}