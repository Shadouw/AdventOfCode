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

class problem
{
public:
    problem(const vector<string> &_input) : input(_input), resultA(0), resultB(0)
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
    int resultA;
    int resultB;
};

TEST_CASE ( "Testdata" )
{
    problem testproblem(inputT);
    REQUIRE ( 0 == testproblem.getresultA() );
    REQUIRE ( 0 == testproblem.getresultB() );
}
