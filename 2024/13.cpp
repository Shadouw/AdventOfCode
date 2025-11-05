#include <aoc.h>
using namespace std;
using namespace aoc;

class ClawMachine {
public:
    ClawMachine(const string _inputA, const string _inputB, const string _inputPrize)
    {
        vector<string> a = stringtovector(_inputA, ' ');
        amove.first = atol(&a[2][2]);
        amove.second = atol(&a[3][2]);

        vector<string> b = stringtovector(_inputB, ' ');
        bmove.first = atol(&b[2][2]);
        bmove.second = atol(&b[3][2]);

        vector<string> p = stringtovector(_inputPrize, ' ');
        prize.first = atol(&p[1][2]);
        prize.second = atol(&p[2][2]);
    }

    long getPrice(pair<long, long> pos)
    {
        // Button A: 3 tokens
        // Button B: 1 token
        return pos.first * 3 + pos.second;
    }

    // This complicated solution is working but not used any longer
    long getCheapestWay()
    {
        long CheapestWay = numeric_limits<long>::max();
        matrix<pair<long, long>> machine(2 + prize.first / min(amove.first, bmove.first), 2 + prize.second / min(amove.second, bmove.second));
        machine[{ 0, 0 }] = { 0, 0 };

        for (int a = 1; a < machine.getX(); ++a) {
            machine[{ a, 0 }] = { machine[{ a - 1, 0 }].first + amove.first, machine[{ a - 1, 0 }].second + amove.second };
            if (machine[{ a, 0 }] == prize && getPrice({ a, 0 }) < CheapestWay)
                CheapestWay = getPrice({ a, 0 });
        }

        for (int b = 1; b < machine.getY(); ++b) {
            auto h1 = machine[{ 0, b - 1 }].first + bmove.first;
            auto h2 = machine[{ 0, b - 1 }].second + bmove.second;
            pair<long, long> h3 = { machine[{ 0, b - 1 }].first + bmove.first, machine[{ 0, b - 1 }].second + bmove.second };
            machine[{ 0, b }] = { 0, 0 };

            machine[{ 0, b }] = { machine[{ 0, b - 1 }].first + bmove.first,
                machine[{ 0, b - 1 }].second + bmove.second };
            if (machine[{ 0, b }] == prize && getPrice({ 0, b }) < CheapestWay)
                CheapestWay = getPrice({ 0, b });
        }

        for (int a = 1; a < machine.getX(); ++a) {
            for (int b = 1; b < machine.getY(); ++b) {
                machine[{ a, b }] = { machine[{ a - 1, b }].first + amove.first, machine[{ a - 1, b }].second + amove.second };
                if (machine[{ a, b }] == prize && getPrice({ a, b }) < CheapestWay)
                    CheapestWay = getPrice({ a, b });
                if (machine[{ a, b }].first >= prize.first || machine[{ a, b }].second >= prize.second)
                    break;
            }
        }

        auto test = getCheapestPrice();
        return (numeric_limits<long>::max() != CheapestWay ? CheapestWay : 0);
    }

    long getCheapestPrice()
    {
        // double b = ((double)prize.second - (double)(prize.first * amove.second) / (double)amove.first) / ((double)bmove.second - (double)(amove.second * bmove.first) / (double)amove.first);
        // double b = (double)(amove.first * prize.second - amove.second * prize.first) / (double)(amove.first * bmove.second - amove.second * bmove.first);
        long bz = amove.first * prize.second - amove.second * prize.first;
        long bn = amove.first * bmove.second - amove.second * bmove.first;
        if (bz % bn)
            return 0;
        long b = bz / bn;
        if (b < 0)
            return 0;

        // double a = ((double)prize.first - (b * (double)bmove.first)) / (double)amove.first;
        long az = prize.first - b * bmove.first;
        long an = amove.first;
        if (az % an)
            return 0;
        long a = az / an;
        if (a < 0)
            return 0;

        return b + 3 * a;
    }

    long getResultB()
    {
        prize.first += 10000000000000;
        prize.second += 10000000000000;

        return getCheapestPrice();
    }

private:
    pair<long, long> amove;
    pair<long, long> bmove;
    pair<long, long> prize;

    friend class ClawContraption;
};

class ClawContraption {
public:
    ClawContraption(string _file, string _extension)
        : datafile(_file, _extension)
    {
        // Parse data
        vector<string> input = datafile.getLines();
        for (auto i = 0; i < input.size(); i += 4)
            ClawMachines.push_back(ClawMachine(input[i], input[i + 1], input[i + 2]));
    }

    long getCheapestWay()
    {
        long CheapestWay = 0;
        for (auto e : ClawMachines)
            CheapestWay += e.getCheapestPrice();

        cout << "CheapestWay: " << CheapestWay << endl;
        return CheapestWay;
    }
    long getResultB()
    {
        long resultB = 0;
        for (auto e : ClawMachines)
            resultB += e.getResultB();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    aocdatafile datafile;
    vector<ClawMachine> ClawMachines;
};

TEST_CASE("Testdata")
{
    ClawContraption ClawContraptionData(__FILE__, "example");
    REQUIRE(480 == ClawContraptionData.getCheapestWay());
}

TEST_CASE("ClawContraption")
{
    ClawContraption ClawContraptionData(__FILE__, "mydata");
    REQUIRE(39996 == ClawContraptionData.getCheapestWay());
    REQUIRE(73267584326867 == ClawContraptionData.getResultB());
}