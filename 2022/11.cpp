#include <iostream>
#include <string>
#include <vector>

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
    Monkey()
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
                itemstring = itemstring.substr(pos+1);
                pos = itemstring.find(',');
            }
            Items.push_back(stoi(itemstring));
        }
        else if ("  Operation: new = " == line.substr(0, 19))
        {
            string opline = line.substr(19);
            auto oppos = opline.find('+');
            if ( string::npos != oppos)
            {
                op = '+';
            } else {
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

    int getResultA()
    {
        int resultA = 0;

        return resultA;
    }

    bool getResultB()
    {
        int resultB = 0;

        return resultB;
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
    }

private:
    string name;

    vector<int> Items;
    int divisibleby = 1;
    int truemonkey = -1;
    int falsemonkey = -1;

    char op = ' ';
    int op1 = 0;
    int op2 = 0;
};

class MonkeyInTheMiddle
{
public:
    MonkeyInTheMiddle(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        Monkey monkey;

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
    }

    int getResultA()
    {
        int resultA = 0;
        for (auto e : Monkeys)
            resultA += e.getResultA();

        cout << "result A: " << resultA << endl;
        return resultA;
    }
    int getResultB()
    {
        int resultB = 0;
        for (auto e : Monkeys)
            resultB += e.getResultB();

        cout << "result B: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    vector<Monkey> Monkeys;
};

TEST_CASE("Testdata")
{
    MonkeyInTheMiddle MonkeyInTheMiddleData(inputTestdata);
    REQUIRE(0 == MonkeyInTheMiddleData.getResultA());
    REQUIRE(0 == MonkeyInTheMiddleData.getResultB());
}

TEST_CASE("MonkeyInTheMiddle")
{
    MonkeyInTheMiddle MonkeyInTheMiddleData(inputData);
    REQUIRE(0 == MonkeyInTheMiddleData.getResultA());
    REQUIRE(0 == MonkeyInTheMiddleData.getResultB());
}