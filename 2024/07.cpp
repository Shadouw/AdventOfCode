#include <aoc.h>
using namespace std;
using namespace aoc;

class Equation {
public:
    Equation(const string _input)
        : input(_input)
    {
        vector<string> splitinput = stringtovector(_input, ' ');
        testvalue = atol(splitinput[0].c_str());
        for (auto i = 1; i < splitinput.size(); ++i)
            values.push_back(atol(splitinput[i].c_str()));

        for (auto i = 1; i < values.size(); ++i)
            operators.push_back('+');
    }

    long calculate()
    {
        long solution = values[0];
        string val;
        for (auto i = 0; i < operators.size(); ++i) {
            switch (operators[i]) {
            case '+':
                solution += values[i + 1];
                break;
            case '*':
                solution *= values[i + 1];
                break;
            case '|':
                val = to_string(solution);
                val += to_string(values[i + 1]);
                solution = atol(val.c_str());
                break;
            default:
                assert(false);
                break;
            }
        }
        return solution;
    }

    bool findSolution(int iteration = 0)
    {
        if (operators.size() == iteration) {
            if (calculate() == testvalue)
                return true;
            else
                return false;
        } else {
            for (auto i = 0; i < oper.size(); ++i) {
                operators[iteration] = oper[i];
                if (findSolution(iteration + 1))
                    return true;
            }
        }
        return false;
    }

    long getResultA()
    {
        oper = "+*";
        long resultA = 0;

        if (findSolution())
            resultA = calculate();

        return resultA;
    }

    long getResultB()
    {
        oper = "+*|";
        long resultB = 0;

        if (findSolution())
          resultB = calculate();

        return resultB;
    }

    string getString() { return input; }

    friend bool operator<(const Equation& l, const Equation& r)
    {
        return l.input < r.input;
    }

private:
    string input;
    long testvalue = 0;
    vector<long> values;
    vector<char> operators;
    string oper = "+*";

    friend class BridgeRepair;
};

class BridgeRepair {
public:
    BridgeRepair(string _file, string _extension)
    : datafile(_file, _extension)
    {
        // Parse data
        for (auto elem : datafile.getLines())
            Equations.push_back(Equation(elem));
    }

    long getResultA()
    {
        long resultA = 0;
        for (auto e : Equations)
            resultA += e.getResultA();

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = 0;
        for (auto e : Equations)
            resultB += e.getResultB();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    aocdatafile datafile;
    vector<Equation> Equations;
};

TEST_CASE("Testdata")
{
    BridgeRepair BridgeRepairData(__FILE__, "example");
    REQUIRE(3749 == BridgeRepairData.getResultA());
    REQUIRE(11387 == BridgeRepairData.getResultB());
}

TEST_CASE("BridgeRepair")
{
    BridgeRepair BridgeRepairData(__FILE__, "mydata");
    REQUIRE(1038838357795 == BridgeRepairData.getResultA());
    REQUIRE(254136560217241 == BridgeRepairData.getResultB());
}