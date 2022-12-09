#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    ""};

const vector<string> inputData = {
    ""};

class item
{
public:
    item(const string _input) : input(_input)
    {
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

    string getString()
    {
        return input;
    }

private:
    string input;
};

class RopeBridge
{
public:
    RopeBridge(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input)
            items.push_back(item(elem));
    }

    int getResultA()
    {
        int resultA = 0;
        for (auto e : items)
            resultA += e.getResultA();

        cout << "result A: " << resultA << endl;
        return resultA;
    }
    int getResultB()
    {
        int resultB = 0;
        for (auto e : items)
            resultB += e.getResultB();

        cout << "result B: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string>  input;
    vector<item> items;
};

TEST_CASE ( "Testdata" )
{
    RopeBridge RopeBridgeData(inputTestdata);
    REQUIRE(0 == RopeBridgeData.getResultA());
    REQUIRE(0 == RopeBridgeData.getResultB());
}

TEST_CASE("RopeBridge")
{
    RopeBridge RopeBridgeData(inputData);
    REQUIRE(0 == RopeBridgeData.getResultA());
    REQUIRE(0 == RopeBridgeData.getResultB());
}