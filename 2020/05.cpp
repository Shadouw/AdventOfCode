#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputT = {
    ""};

const vector<string> inputA = {
    ""};

const vector<string> inputB = {
    ""};

class item
{
public:
    item(const string _input) : input(_input)
    {
    }

    string getString()
    {
        return input;
    }

private:
    string input;
};

class BinaryBoarding
{
public:
    BinaryBoarding(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input)
            items.push_back(item(elem));
    }

    void listinput()
    {
        for (auto elem : input)
        {
            cout << elem << endl;
        }
    }

    int getresultA(){
        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    int getresultB(){
        cout << "resultB: " << resultB << endl;
        return resultB;
    }
private:
    const vector<string>  input;
    vector<item> items;
    int resultA = 0;
    int resultB = 0;
};

TEST_CASE ( "Testdata" )
{
    BinaryBoarding testBinaryBoarding(inputT);
    REQUIRE ( 0 == testBinaryBoarding.getresultA() );
    REQUIRE ( 0 == testBinaryBoarding.getresultB() );
}
