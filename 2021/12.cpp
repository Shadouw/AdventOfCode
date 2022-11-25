#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputT = {
    "start-A",
    "start-b",
    "A-c",
    "A-b",
    "b-d",
    "A-end",
    "b-end"};

const vector<string> inputT2 = {"dc-end",
                                "HN-start",
                                "start-kj",
                                "dc-start",
                                "dc-HN",
                                "LN-dc",
                                "HN-end",
                                "kj-sa",
                                "kj-HN",
                                "kj-dc"};
const vector<string> inputT3 = {"fs-end",
                                "he-DX",
                                "fs-he",
                                "start-DX",
                                "pj-DX",
                                "end-zg",
                                "zg-sl",
                                "zg-pj",
                                "pj-he",
                                "RW-he",
                                "fs-DX",
                                "pj-RW",
                                "zg-RW",
                                "start-pj",
                                "he-WI",
                                "zg-he",
                                "pj-fs",
                                "start-RW"};

const vector<string> inputA = {
    "xx-end",
    "EG-xx",
    "iy-FP",
    "iy-qc",
    "AB-end",
    "yi-KG",
    "KG-xx",
    "start-LS",
    "qe-FP",
    "qc-AB",
    "yi-start",
    "AB-iy",
    "FP-start",
    "iy-LS",
    "yi-LS",
    "xx-AB",
    "end-KG",
    "iy-KG",
    "qc-KG",
    "FP-xx",
    "LS-qc",
    "FP-yi"};

const vector<string> inputB = {
    ""};

class problem
{
public:
    problem(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;
        for (auto elem : input)
        {
            auto pos = elem.find("-");
            string left(elem.substr(0, pos));
            string right(elem.substr(pos + 1));

            if ( "end" != left && "start" != right )
                transitions[left].push_back(right);
            if ( "start" != left && "end" != right)
                transitions[right].push_back(left);
        }
    }

    void listinput()
    {
        for (auto elem : input)
        {
            cout << elem << endl;
        }
    }

    int getresultA()
    {
        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    int getresultB()
    {
        cout << "resultB: " << resultB << endl;
        return resultB;
    }

    int findSolutions(string start, string end, vector<string> path, int maxnumofsmallcage, int numofsmallcage)
    {
        static int numofsolutions = 0;
        //if ( "start" == start )
        if ( path.size() == 0 )
            numofsolutions = 0;

        if (start == end)
        {
            path.push_back(start);
            numofsolutions++;
            /*
            for (auto elem : path)
                cout << elem << " ";
            cout << endl;
            */
            return numofsolutions;
        }

        // Small cage and already visited?
        if (islower(start[0]))
        {
            for (auto elem : path)
            {
                if ( elem == start )
                {
                    ++numofsmallcage;
                    if ( numofsmallcage > maxnumofsmallcage )
                        return numofsolutions;
                }
            }
        }


        path.push_back(start);

        for (auto point : transitions[start])
        {
            findSolutions(point, end, path, maxnumofsmallcage, numofsmallcage);
        }

        return numofsolutions;
    }

private:
    const vector<string> input;
    map<string, vector<string>> transitions;
    //map<string, pair<bool, bool>> points;
    int resultA = 0;
    int resultB = 0;
};

TEST_CASE("Testdata")
{
    problem testproblem(inputT);
    REQUIRE(10 == testproblem.findSolutions("start", "end", vector<string>{},0,0));

    /*
    REQUIRE(0 == testproblem.getresultA());
    REQUIRE(0 == testproblem.getresultB());
    */
}

TEST_CASE("Test2")
{
    problem testproblem(inputT2);
    REQUIRE(19 == testproblem.findSolutions("start", "end", vector<string>{},0,0));
}

TEST_CASE("Test3")
{
    problem testproblem(inputT3);
    REQUIRE(226 == testproblem.findSolutions("start", "end", vector<string>{},0,0));
}

TEST_CASE("Problem")
{
    problem testproblem(inputA);
    int resultA = testproblem.findSolutions("start", "end", vector<string>{},0,0);
    cout << "Result A: " << resultA << endl;
    REQUIRE(4378 == resultA);
}

TEST_CASE("TestdataB")
{
    problem testproblem(inputT);
    REQUIRE(36 == testproblem.findSolutions("start", "end", vector<string>{},1,0));
}

TEST_CASE("Test2B")
{
    problem testproblem(inputT2);
    REQUIRE(103 == testproblem.findSolutions("start", "end", vector<string>{},1,0));
}

TEST_CASE("Test3B")
{
    problem testproblem(inputT3);
    REQUIRE(3509 == testproblem.findSolutions("start", "end", vector<string>{},1,0));
}

TEST_CASE("Problem B")
{
    problem testproblem(inputA);
    int result = testproblem.findSolutions("start", "end", vector<string>{},1,0);
    cout << "Result B: " << result<< endl;
    REQUIRE(133621 == result);
}
