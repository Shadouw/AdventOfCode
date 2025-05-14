#include <aoc.h>
using namespace std;
using namespace aoc;

class report {
public:
    report(const string _input)
        : input(_input)
    {
        vector<string> _values = stringtovector(_input, ' ');
        for (auto _value : _values)
            values.push_back(atol(_value.c_str()));
    }

    bool getIsSafe() { return getIsSafe(values); }

    bool getIsSafe(vector<long> _values)
    {
        long Counter = 0;
        for (auto i = 0; i < _values.size() - 1; ++i) {
            if (_values[i] > _values[i + 1] && _values[i] - _values[i + 1] <= 3)
                --Counter;
            else if (_values[i] < _values[i + 1] && _values[i + 1] - _values[i] <= 3)
                ++Counter;
        }

        isIncreasing = (Counter > 0);

        return abs(Counter) == _values.size() - 1;
    }

    bool getIsSafeWithASingleBad()
    {
        if (getIsSafe())
            return true;

        for (auto i = 0; i < values.size(); ++i) {
            vector<long> temp(values);
            temp.erase(temp.begin() + i);
            if (getIsSafe(temp))
                return true;
        }

        return false;
    }

    string getString() { return input; }

    friend bool operator<(const report& l, const report& r)
    {
        return l.input < r.input;
    }

private:
    string input;
    vector<long> values;

    bool isIncreasing;

    friend class RedNosedReports;
};

class RedNosedReports {
public:
    RedNosedReports(string _file, string _extension)
    : datafile(_file, _extension)
    {
        // Parse data
        for (auto elem : datafile.getLines() )
            reports.push_back(report(elem));
    }

    long getIsSafe()
    {
        long IsSafe = 0;
        for (auto e : reports)
            IsSafe += e.getIsSafe();

        cout << "IsSafe: " << IsSafe << endl;
        return IsSafe;
    }
    long getIsSafeWithASingleBad()
    {
        long IsSafeWithASingleBad = 0;
        for (auto e : reports)
            IsSafeWithASingleBad += e.getIsSafeWithASingleBad();

        cout << "IsSafeWithASingleBad: " << IsSafeWithASingleBad << endl;
        return IsSafeWithASingleBad;
    }

private:
    aocdatafile datafile;
    vector<report> reports;
};

TEST_CASE("Testdata")
{
    RedNosedReports RedNosedReportsData(__FILE__, "example");
    REQUIRE(2 == RedNosedReportsData.getIsSafe());
    REQUIRE(4 == RedNosedReportsData.getIsSafeWithASingleBad());
}

TEST_CASE("RedNosedReports")
{
    RedNosedReports RedNosedReportsData(__FILE__, "mydata");
    REQUIRE(639 == RedNosedReportsData.getIsSafe());
    REQUIRE(674 == RedNosedReportsData.getIsSafeWithASingleBad());
}