#include <aoc.h>
using namespace std;
using namespace aoc;

class item {
public:
    item(const string _input)
        : input(_input)
    {
    }

    long getResultA()
    {
        long resultA = 0;

        return resultA;
    }

    long getResultB()
    {
        long resultB = 0;

        return resultB;
    }

    string getString() { return input; }

    friend bool operator<(const item& l, const item& r)
    {
        return l.input < r.input;
    }

private:
    string input;

    friend class problem;
};

class problem {
public:
    problem(string _file, string _extension)
        : datafile(_file, _extension)
    {
        // Parse data
        for (auto elem : datafile.getLines())
            items.push_back(item(elem));
    }

    long getResultA()
    {
        long resultA = 0;
        for (auto e : items)
            resultA += e.getResultA();

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = 0;
        for (auto e : items)
            resultB += e.getResultB();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    aocdatafile datafile;
    vector<item> items;
};

TEST_CASE("Testdata")
{
    problem problemData(__FILE__, "example");
    REQUIRE(0 == problemData.getResultA());
    REQUIRE(0 == problemData.getResultB());
}

TEST_CASE("Problem")
{
    problem problemData(__FILE__, "mydata");
    REQUIRE(0 == problemData.getResultA());
    REQUIRE(0 == problemData.getResultB());
}