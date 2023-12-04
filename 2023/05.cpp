#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    ""
};

const vector<string> inputData = {
    ""
};

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

private:
    string input;

    friend class problem;
};

class problem {
public:
    problem(const vector<string>& _input)
        : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input)
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
    const vector<string> input;
    vector<item> items;
};

TEST_CASE("Testdata")
{
    problem problemData(inputTestdata);
    REQUIRE(0 == problemData.getResultA());
    REQUIRE(0 == problemData.getResultB());
}

TEST_CASE("Problem")
{
    problem problemData(inputData);
    REQUIRE(0 == problemData.getResultA());
    REQUIRE(0 == problemData.getResultB());
}