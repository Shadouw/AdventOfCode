#include <iostream>
#include <string>
#include <vector>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;

const vector<string> inputT = {
    ""};

const vector<string> inputA = {
    ""};

const vector<string> inputB = {
    ""};

class snailfish
{
public:
    snailfish(const string &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;
    }

    void listinput()
    {
        for (auto elem : input)
        {
            cout << elem << endl;
        }
    }

private:
    const string  input;
};

TEST_CASE ( "Testdata" )
{
    snailfish testproblem("[[[[[9,8],1],2],3],4]");
}
