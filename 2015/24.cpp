#include <iostream>
#include <string>
#include <vector>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;

const vector<int> inputT = {1,2,3,4,5,7,8,9,10,11};

const vector<int> inputA = {1,2,3,5,7,13,17,19,23,29,31,37,41,43,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};

class problem
{
public:
    problem(const vector<int> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;
        for ( auto elem : input )
            sumofproblem += elem;
        cout << "Sum of Problem: " << sumofproblem << endl;
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
    const vector<int>  input;
    int sumofproblem = 0;
    int resultA = 0;
    int resultB = 0;
};

TEST_CASE ( "Testdata" )
{
    problem testproblem(inputT);
    REQUIRE ( 0 == testproblem.getresultA() );
    REQUIRE ( 0 == testproblem.getresultB() );
}
