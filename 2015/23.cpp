#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputT = {
    "inc a",
    "jio a, +2",
    "tpl a",
    "inc a"};

const vector<string> inputA = {
    "jio a, +16",
    "inc a",
    "inc a",
    "tpl a",
    "tpl a",
    "tpl a",
    "inc a",
    "inc a",
    "tpl a",
    "inc a",
    "inc a",
    "tpl a",
    "tpl a",
    "tpl a",
    "inc a",
    "jmp +23",
    "tpl a",
    "inc a",
    "inc a",
    "tpl a",
    "inc a",
    "inc a",
    "tpl a",
    "tpl a",
    "inc a",
    "inc a",
    "tpl a",
    "inc a",
    "tpl a",
    "inc a",
    "tpl a",
    "inc a",
    "inc a",
    "tpl a",
    "inc a",
    "tpl a",
    "tpl a",
    "inc a",
    "jio a, +8",
    "inc b",
    "jie a, +4",
    "tpl a",
    "inc a",
    "jmp +2",
    "hlf a",
    "jmp -7"};

class problem
{
public:
    problem(const vector<string> &_input, int _a = 0, int _b = 0) : input(_input), a(_a), b(_b)
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

    void processInput()
    {
        for (auto inst = input.begin(); inst != input.end(); ++inst)
        {
            if (inst->substr(0, 3) == "hlf")
            {
                //cout << "hlf " << (*inst)[4] << ": ";
                switch ((*inst)[4])
                {
                case 'a':
                    a /= 2;
                    //cout << a;
                    break;
                case 'b':
                    b /= 2;
                    //cout << b;
                    break;
                default:
                    break;
                }

                //cout << endl;
            }
            else if (inst->substr(0, 3) == "tpl")
            {
                //cout << "tpl " << (*inst)[4] << ": ";
                switch ((*inst)[4])
                {
                case 'a':
                    a *= 3;
                    //cout << a;
                    break;
                case 'b':
                    b *= 3;
                    //cout << b;
                    break;
                default:
                    break;
                }

                //cout << endl;
            }
            else if (inst->substr(0, 3) == "inc")
            {
                //cout << "inc " << (*inst)[4] << ": ";
                switch ((*inst)[4])
                {
                case 'a':
                    ++a;
                    //cout << a;
                    break;
                case 'b':
                    ++b;
                    //cout << b;
                    break;
                default:
                    break;
                }

                //cout << endl;
            }
            else if (inst->substr(0, 3) == "jmp")
            {
                string soffset(inst->substr(4));
                int offset = stoi(soffset);
                //cout << "jmp " << "(" << offset << ")";
                inst += offset - 1; // -1 because there is a ++ in the for loop

                //cout << endl;
            }
            else if (inst->substr(0, 3) == "jie")
            {
                int offset = stoi(inst->substr(7));
                //cout << "jie " << (*inst)[4] << "(" << offset << ")";
                bool jump = true;
                switch ((*inst)[4])
                {
                case 'a':
                    jump = !(a % 2);
                    break;
                case 'b':
                    jump = !(b % 2);
                    break;
                default:
                    break;
                }
                if (jump)
                {
                    //cout << '/';
                    inst += offset - 1; // -1 because there is a ++ in the for loop
                }
                else
                {
                    //cout << 'x';
                }

                //cout << endl;
            }
            else if (inst->substr(0, 3) == "jio")
            {
                int offset = stoi(inst->substr(7));
                //cout << "jio " << (*inst)[4] << "(" << offset << ")";
                bool jump = true;
                switch ((*inst)[4])
                {
                case 'a':
                    jump = (a == 1);
                    break;
                case 'b':
                    jump = (b == 1);
                    break;
                default:
                    break;
                }
                if (jump)
                {
                    //cout << '/';
                    inst += offset - 1; // -1 because there is a ++ in the for loop
                }
                else
                {
                    //cout << 'x';
                }
                //cout << endl;
            }
        }
    }
    int geta() { return a; };
    int getb() { return b; };

private:
    const vector<string> input;
    uint32_t a, b;
};

TEST_CASE("Testdata")
{
    problem testproblem(inputT);

    testproblem.processInput();
    REQUIRE(2 == testproblem.geta());
}

TEST_CASE("RunA")
{
    problem testproblem(inputA);

    testproblem.processInput();
    int resultA = testproblem.getb();

    REQUIRE(170 == resultA);
    cout << "Result A: " << resultA << endl;
}

TEST_CASE("RunB")
{
    problem testproblem(inputA, 1, 0);

    testproblem.processInput();
    int resultB = testproblem.getb();

    REQUIRE(247 == resultB);
    cout << "Result B: " << resultB << endl;
}