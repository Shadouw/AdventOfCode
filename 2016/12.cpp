#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
	"cpy 41 a",
	"inc a",
	"inc a",
	"dec a",
	"jnz a 2",
	"dec a"};

const vector<string> inputData = {
	"cpy 1 a",
	"cpy 1 b",
	"cpy 26 d",
	"jnz c 2",
	"jnz 1 5",
	"cpy 7 c",
	"inc d",
	"dec c",
	"jnz c -2",
	"cpy a c",
	"inc a",
	"dec b",
	"jnz b -2",
	"cpy c b",
	"dec d",
	"jnz d -6",
	"cpy 14 c",
	"cpy 14 d",
	"inc a",
	"dec d",
	"jnz d -2",
	"dec c",
	"jnz c -5"};

class LeonardosMonorail
{
public:
    LeonardosMonorail(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;
    }

    void runProgram()
    {
        while (PC<input.size())
            runInstruction(input[PC]);
    }

    void runInstruction(string instruction)
    {
        // tokenize instruction
        string inst = instruction.substr(0,3);
        string token1 = instruction.substr(4), token2;

        const auto pos = token1.find(' ');
        if ( string::npos != pos )
        {
            token2 = token1.substr(pos+1);
            token1 = token1.substr(0,pos);
        }

        switch (inst[0])
        {
            case 'c': // "cpy"
                reg[token2] = getValue(token1);
                ++PC;
                break;
            case 'i': // "inc"
                ++reg[token1];
                ++PC;   
                break;
            case 'd': // "dec"
                --reg[token1];
                ++PC;
                break;
            case 'j': // "jnz"
                if ( 0 != getValue(token1) )
                    PC+=getValue(token2);
                else
                    ++PC;
                break;
            default:
                cout << "Unknown instruction: " << inst << endl;
        }
    }

    long getValue(string token)
    {
        if ( 'a' <= token[0] && token[0] <= 'z' )
            return reg[token];

        return stoi(token);
    }

    void reset()
    {
        PC = 0;
        reg.clear();
    }


    long getResultA()
    {
        runProgram();
        long resultA = reg["a"];

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        reset();
        reg["c"]=1;
        runProgram();
        long resultB = reg["a"];

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;

    long PC = 0; // program counter.
    map<string, long> reg;
};

TEST_CASE("Testdata")
{
    LeonardosMonorail LeonardosMonorailData(inputTestdata);
    REQUIRE(42 == LeonardosMonorailData.getResultA());
}

TEST_CASE("LeonardosMonorail")
{
    LeonardosMonorail LeonardosMonorailData(inputData);
    REQUIRE(318007 == LeonardosMonorailData.getResultA());
    REQUIRE(9227661 == LeonardosMonorailData.getResultB());
}