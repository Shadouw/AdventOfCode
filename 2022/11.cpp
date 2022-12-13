#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "Monkey 0:",
    "  Starting items: 79, 98",
    "  Operation: new = old * 19",
    "  Test: divisible by 23",
    "    If true: throw to monkey 2",
    "    If false: throw to monkey 3",
    "",
    "Monkey 1:",
    "  Starting items: 54, 65, 75, 74",
    "  Operation: new = old + 6",
    "  Test: divisible by 19",
    "    If true: throw to monkey 2",
    "    If false: throw to monkey 0",
    "",
    "Monkey 2:",
    "  Starting items: 79, 60, 97",
    "  Operation: new = old * old",
    "  Test: divisible by 13",
    "    If true: throw to monkey 1",
    "    If false: throw to monkey 3",
    "",
    "Monkey 3:",
    "  Starting items: 74",
    "  Operation: new = old + 3",
    "  Test: divisible by 17",
    "    If true: throw to monkey 0",
    "    If false: throw to monkey 1"};

const vector<string> inputData = {
    "Monkey 0:",
    "  Starting items: 74, 73, 57, 77, 74",
    "  Operation: new = old * 11",
    "  Test: divisible by 19",
    "    If true: throw to monkey 6",
    "    If false: throw to monkey 7",
    "",
    "Monkey 1:",
    "  Starting items: 99, 77, 79",
    "  Operation: new = old + 8",
    "  Test: divisible by 2",
    "    If true: throw to monkey 6",
    "    If false: throw to monkey 0",
    "",
    "Monkey 2:",
    "  Starting items: 64, 67, 50, 96, 89, 82, 82",
    "  Operation: new = old + 1",
    "  Test: divisible by 3",
    "    If true: throw to monkey 5",
    "    If false: throw to monkey 3",
    "",
    "Monkey 3:",
    "  Starting items: 88",
    "  Operation: new = old * 7",
    "  Test: divisible by 17",
    "    If true: throw to monkey 5",
    "    If false: throw to monkey 4",
    "",
    "Monkey 4:",
    "  Starting items: 80, 66, 98, 83, 70, 63, 57, 66",
    "  Operation: new = old + 4",
    "  Test: divisible by 13",
    "    If true: throw to monkey 0",
    "    If false: throw to monkey 1",
    "",
    "Monkey 5:",
    "  Starting items: 81, 93, 90, 61, 62, 64",
    "  Operation: new = old + 7",
    "  Test: divisible by 7",
    "    If true: throw to monkey 1",
    "    If false: throw to monkey 4",
    "",
    "Monkey 6:",
    "  Starting items: 69, 97, 88, 93",
    "  Operation: new = old * old",
    "  Test: divisible by 5",
    "    If true: throw to monkey 7",
    "    If false: throw to monkey 2",
    "",
    "Monkey 7:",
    "  Starting items: 59, 80",
    "  Operation: new = old + 6",
    "  Test: divisible by 11",
    "    If true: throw to monkey 2",
    "    If false: throw to monkey 3"};

class Monkey
{
public:
    Monkey(unsigned long long _worrylevelreducer) : worrylevelreducer(_worrylevelreducer)
    {
    }

    void parseLine(string line)
    {
        if ("Monkey " == line.substr(0, 7))
            name = line;
        else if ("  Starting items: " == line.substr(0, 18))
        {
            string itemstring = line.substr(18);
            auto pos = itemstring.find(',');
            while (string::npos != pos)
            {
                Items.push_back(stoi(itemstring));
                itemstring = itemstring.substr(pos + 1);
                pos = itemstring.find(',');
            }
            Items.push_back(stoi(itemstring));
        }
        else if ("  Operation: new = " == line.substr(0, 19))
        {
            string opline = line.substr(19);
            auto oppos = opline.find('+');
            if (string::npos != oppos)
            {
                op = '+';
            }
            else
            {
                oppos = opline.find('*');
                op = '*';
            }
            if (opline.substr(0, 3) == "old")
                op1 = -1;
            else
                op1 = stoi(opline);
            if (opline.substr(oppos + 2) == "old")
                op2 = -1;
            else
                op2 = stoi(opline.substr(oppos + 1));
        }
        else if ("  Test: divisible by " == line.substr(0, 21))
        {
            divisibleby = stoi(line.substr(21));
        }
        else if ("    If true: throw to monkey " == line.substr(0, 29))
        {
            truemonkey = stoi(line.substr(29));
        }
        else if ("    If false: throw to monkey " == line.substr(0, 30))
        {
            falsemonkey = stoi(line.substr(30));
        }
        else
            cout << "Unknown: " << line << endl;
    }

    void clear()
    {
        name = "";
        Items.clear();
        divisibleby = 1;
        truemonkey = -1;
        falsemonkey = -1;
        op = ' ';
        op1 = 0;
        op2 = 0;
        inspectcount = 0;
    }

    void play(vector<Monkey> &Monkeys)
    {
        for (auto item : Items)
        {
            // Inspect Item
            unsigned long long worrylevel = item;
            unsigned long long _op1 = (-1 == op1 ? worrylevel : op1);
            unsigned long long _op2 = (-1 == op2 ? worrylevel : op2);
            if ('+' == op)
                worrylevel = _op1 + _op2;
            if ('*' == op)
                worrylevel = _op1 * _op2;
            ++inspectcount;

            // Monkey gets bored
            if (1 != worrylevelreducer)
                worrylevel /= worrylevelreducer;
            else
                worrylevel %= monkeymodulo;

            // Test
            if (0 == worrylevel % divisibleby)
                Monkeys[truemonkey].catchItem(worrylevel);
            else
                Monkeys[falsemonkey].catchItem(worrylevel);
        }

        Items.clear();
    }
    void catchItem(unsigned long long worrylevel)
    {
        Items.push_back(worrylevel);
    }

    unsigned long long getInspectCount()
    {
        return inspectcount;
    }

    void print()
    {
        cout << name;
        for (auto elem : Items)
            cout << elem << " ";
        cout << endl;
    }

    unsigned long long getMonkeyModulo()
    {
        return divisibleby;
    }

    void setMonkeyModulo(unsigned long long _monkeymodulo)
    {
        monkeymodulo = _monkeymodulo;
    }

private:
    string name;

    vector<unsigned long long> Items;
    unsigned long long divisibleby = 1;
    int truemonkey = -1;
    int falsemonkey = -1;

    char op = ' ';
    unsigned long long op1 = 0;
    unsigned long long op2 = 0;

    unsigned long long inspectcount = 0;

    unsigned long long worrylevelreducer = 1;

    unsigned long long monkeymodulo = 1;
};

class MonkeyInTheMiddle
{
public:
    MonkeyInTheMiddle(const vector<string> &_input, unsigned long long _worrylevelreducer) : input(_input), worrylevelreducer(_worrylevelreducer)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        Monkey monkey(worrylevelreducer);

        for (auto elem : input)
            if ("" != elem)
                monkey.parseLine(elem);
            else
            {
                Monkeys.push_back(monkey);
                monkey.clear();
            }

        // Push the last monkey on the list
        Monkeys.push_back(monkey);

        // Trick with Modulo Monkey
        for (auto &elem : Monkeys)
            elem.setMonkeyModulo(getMonkeyModulo());
    }

    void playRound(int rounds)
    {
        for (int r = 0; r < rounds; ++r)
            for (auto &monkey : Monkeys)
                monkey.play(Monkeys);
    }

    unsigned long long getLevelOfMonkeyBusiness(unsigned long long num)
    {
        unsigned long long LevelOfMonkeyBusiness = 1;
        std::multiset<unsigned long long> mostactivemonkeys;
        for (auto e : Monkeys)
            mostactivemonkeys.insert(e.getInspectCount());

        unsigned long long c = 0;
        for (auto it = mostactivemonkeys.rbegin(); it != mostactivemonkeys.rend(); ++it)
        {
            LevelOfMonkeyBusiness *= *it;
            if (++c >= num)
                break;
        }

        return LevelOfMonkeyBusiness;
    }

    void print()
    {
        for (auto el : Monkeys)
            el.print();
    }

    unsigned long long getMonkeyModulo()
    {
        int MonkeyModulo = 1;

        for (auto &elem : Monkeys)
            MonkeyModulo *= elem.getMonkeyModulo();

        return MonkeyModulo;
    }

private:
    const vector<string> input;
    vector<Monkey> Monkeys;
    unsigned long long worrylevelreducer = 1;
};

TEST_CASE("Testdata A")
{
    MonkeyInTheMiddle MonkeyInTheMiddleData(inputTestdata, 3);
    MonkeyInTheMiddleData.playRound(20);
    REQUIRE(10605 == MonkeyInTheMiddleData.getLevelOfMonkeyBusiness(2));
}

TEST_CASE("Testdata B")
{
    MonkeyInTheMiddle MonkeyInTheMiddleData(inputTestdata, 1);
    MonkeyInTheMiddleData.playRound(1);
    REQUIRE(6 * 4 == MonkeyInTheMiddleData.getLevelOfMonkeyBusiness(2));

    MonkeyInTheMiddleData.playRound(20 - 1);
    REQUIRE(103 * 99 == MonkeyInTheMiddleData.getLevelOfMonkeyBusiness(2));

    MonkeyInTheMiddleData.playRound(1000 - 20);
    REQUIRE(5204 * 5192 == MonkeyInTheMiddleData.getLevelOfMonkeyBusiness(2));

    MonkeyInTheMiddleData.playRound(2000 - 1000);
    REQUIRE(10419 * 10391 == MonkeyInTheMiddleData.getLevelOfMonkeyBusiness(2));

    MonkeyInTheMiddleData.playRound(10000 - 2000);
    REQUIRE(2713310158 == MonkeyInTheMiddleData.getLevelOfMonkeyBusiness(2));
}

TEST_CASE("MonkeyInTheMiddle A")
{
    MonkeyInTheMiddle MonkeyInTheMiddleData(inputData, 3);
    MonkeyInTheMiddleData.playRound(20);
    REQUIRE(69918 == MonkeyInTheMiddleData.getLevelOfMonkeyBusiness(2));
}

TEST_CASE("MonkeyInTheMiddle B")
{
    MonkeyInTheMiddle MonkeyInTheMiddleData(inputData, 1);
    MonkeyInTheMiddleData.playRound(10000);
    REQUIRE(19573408701 == MonkeyInTheMiddleData.getLevelOfMonkeyBusiness(2));
}