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
    problem(const vector<string> &_input) : input(_input), resulta(0), resultb(0)
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

    int getResultA(){
        cout << "ResultA: " << resulta << endl;
        return resulta;
    }
    int getResultB(){
        cout << "ResultB: " << resultb << endl;
        return resultb;
    }
private:
    const vector<string>  input;
    int resulta;
    int resultb;
};

TEST_CASE ( "Testdata" )
{
    problem testproblem(inputT);
    REQUIRE ( 0 == testproblem.getResultA() );
    REQUIRE ( 0 == testproblem.getResultB() );
}
