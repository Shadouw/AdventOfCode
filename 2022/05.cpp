#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "ZN",
    "MCD",
    "P",
    "",
    "move 1 from 2 to 1",
    "move 3 from 1 to 3",
    "move 2 from 2 to 1",
    "move 1 from 1 to 2"};

const vector<string> inputData = {
    "NCRTMZP",
    "DNTSBZ",
    "MHQRFCTG",
    "GRZ",
    "ZNRH",
    "FHSWPZLD",
    "WDZRCGM",
    "SJFLHWZQ",
    "SQPWN",
    "",
    "move 7 from 6 to 8",
    "move 5 from 2 to 6",
    "move 2 from 4 to 1",
    "move 1 from 4 to 5",
    "move 5 from 7 to 6",
    "move 7 from 6 to 3",
    "move 5 from 9 to 2",
    "move 6 from 2 to 3",
    "move 2 from 7 to 9",
    "move 20 from 3 to 1",
    "move 11 from 1 to 6",
    "move 1 from 9 to 8",
    "move 3 from 8 to 2",
    "move 8 from 1 to 5",
    "move 10 from 8 to 4",
    "move 7 from 6 to 4",
    "move 1 from 8 to 3",
    "move 8 from 1 to 7",
    "move 16 from 4 to 8",
    "move 1 from 9 to 8",
    "move 1 from 5 to 2",
    "move 4 from 7 to 4",
    "move 5 from 6 to 7",
    "move 1 from 6 to 1",
    "move 8 from 7 to 4",
    "move 1 from 6 to 9",
    "move 12 from 4 to 5",
    "move 3 from 2 to 5",
    "move 1 from 6 to 2",
    "move 1 from 3 to 7",
    "move 1 from 3 to 2",
    "move 1 from 9 to 3",
    "move 1 from 7 to 8",
    "move 1 from 7 to 5",
    "move 1 from 3 to 2",
    "move 4 from 5 to 7",
    "move 5 from 5 to 7",
    "move 1 from 4 to 3",
    "move 1 from 3 to 9",
    "move 3 from 1 to 8",
    "move 1 from 9 to 1",
    "move 2 from 2 to 1",
    "move 2 from 2 to 7",
    "move 8 from 8 to 1",
    "move 3 from 5 to 2",
    "move 8 from 7 to 5",
    "move 7 from 1 to 3",
    "move 3 from 1 to 7",
    "move 1 from 1 to 5",
    "move 1 from 3 to 7",
    "move 7 from 5 to 8",
    "move 2 from 2 to 8",
    "move 1 from 3 to 2",
    "move 1 from 2 to 4",
    "move 1 from 4 to 8",
    "move 13 from 8 to 1",
    "move 13 from 5 to 9",
    "move 2 from 5 to 2",
    "move 7 from 9 to 3",
    "move 12 from 8 to 3",
    "move 4 from 9 to 3",
    "move 1 from 3 to 4",
    "move 2 from 2 to 3",
    "move 1 from 1 to 6",
    "move 1 from 2 to 3",
    "move 1 from 5 to 9",
    "move 7 from 7 to 4",
    "move 10 from 1 to 8",
    "move 1 from 1 to 4",
    "move 1 from 9 to 5",
    "move 2 from 5 to 1",
    "move 1 from 6 to 5",
    "move 3 from 8 to 9",
    "move 5 from 4 to 3",
    "move 4 from 4 to 1",
    "move 7 from 1 to 6",
    "move 2 from 5 to 7",
    "move 35 from 3 to 4",
    "move 4 from 9 to 1",
    "move 19 from 4 to 8",
    "move 1 from 7 to 6",
    "move 1 from 9 to 2",
    "move 10 from 4 to 5",
    "move 2 from 4 to 7",
    "move 3 from 4 to 3",
    "move 1 from 2 to 8",
    "move 1 from 1 to 9",
    "move 3 from 3 to 6",
    "move 4 from 8 to 6",
    "move 4 from 5 to 2",
    "move 2 from 8 to 3",
    "move 3 from 5 to 9",
    "move 12 from 6 to 1",
    "move 8 from 8 to 6",
    "move 2 from 9 to 1",
    "move 1 from 4 to 1",
    "move 1 from 3 to 8",
    "move 3 from 7 to 8",
    "move 2 from 9 to 7",
    "move 1 from 6 to 7",
    "move 10 from 6 to 8",
    "move 4 from 2 to 5",
    "move 1 from 3 to 7",
    "move 7 from 5 to 7",
    "move 13 from 8 to 1",
    "move 29 from 1 to 4",
    "move 8 from 7 to 8",
    "move 1 from 1 to 3",
    "move 3 from 7 to 6",
    "move 1 from 1 to 9",
    "move 15 from 4 to 1",
    "move 1 from 3 to 6",
    "move 10 from 1 to 6",
    "move 10 from 6 to 7",
    "move 1 from 4 to 9",
    "move 1 from 9 to 1",
    "move 1 from 9 to 7",
    "move 6 from 7 to 8",
    "move 1 from 1 to 6",
    "move 5 from 6 to 5",
    "move 21 from 8 to 9",
    "move 5 from 1 to 9",
    "move 2 from 9 to 5",
    "move 3 from 5 to 6",
    "move 3 from 7 to 9",
    "move 4 from 4 to 6",
    "move 6 from 8 to 7",
    "move 6 from 6 to 3",
    "move 2 from 7 to 9",
    "move 1 from 7 to 2",
    "move 6 from 3 to 2",
    "move 1 from 6 to 4",
    "move 4 from 5 to 9",
    "move 1 from 4 to 5",
    "move 9 from 4 to 6",
    "move 7 from 6 to 4",
    "move 10 from 9 to 2",
    "move 5 from 7 to 5",
    "move 10 from 2 to 7",
    "move 2 from 5 to 4",
    "move 2 from 5 to 9",
    "move 4 from 9 to 4",
    "move 1 from 8 to 6",
    "move 7 from 7 to 2",
    "move 1 from 5 to 4",
    "move 2 from 7 to 1",
    "move 1 from 5 to 7",
    "move 3 from 6 to 2",
    "move 4 from 4 to 5",
    "move 1 from 2 to 7",
    "move 10 from 4 to 7",
    "move 3 from 7 to 3",
    "move 17 from 9 to 4",
    "move 1 from 1 to 4",
    "move 1 from 1 to 5",
    "move 5 from 2 to 7",
    "move 1 from 9 to 2",
    "move 5 from 4 to 8",
    "move 2 from 9 to 7",
    "move 4 from 8 to 1",
    "move 3 from 4 to 8",
    "move 1 from 2 to 5",
    "move 1 from 9 to 2",
    "move 6 from 4 to 8",
    "move 3 from 7 to 5",
    "move 1 from 4 to 9",
    "move 1 from 9 to 1",
    "move 3 from 1 to 9",
    "move 4 from 8 to 5",
    "move 2 from 9 to 8",
    "move 4 from 2 to 5",
    "move 8 from 7 to 2",
    "move 5 from 8 to 5",
    "move 2 from 7 to 8",
    "move 1 from 3 to 5",
    "move 1 from 1 to 2",
    "move 1 from 1 to 6",
    "move 2 from 3 to 6",
    "move 5 from 2 to 8",
    "move 4 from 7 to 1",
    "move 7 from 8 to 5",
    "move 1 from 1 to 5",
    "move 3 from 8 to 3",
    "move 1 from 9 to 3",
    "move 7 from 2 to 3",
    "move 2 from 2 to 8",
    "move 2 from 4 to 8",
    "move 1 from 8 to 5",
    "move 1 from 1 to 4",
    "move 2 from 4 to 7",
    "move 2 from 7 to 1",
    "move 3 from 2 to 3",
    "move 3 from 5 to 2",
    "move 1 from 8 to 3",
    "move 3 from 3 to 2",
    "move 5 from 2 to 1",
    "move 17 from 5 to 8",
    "move 9 from 8 to 1",
    "move 11 from 3 to 5",
    "move 8 from 8 to 5",
    "move 2 from 8 to 5",
    "move 16 from 1 to 4",
    "move 13 from 4 to 7",
    "move 6 from 5 to 2",
    "move 2 from 4 to 8",
    "move 5 from 7 to 9",
    "move 2 from 1 to 2",
    "move 7 from 7 to 1",
    "move 1 from 1 to 4",
    "move 1 from 9 to 8",
    "move 7 from 2 to 8",
    "move 1 from 4 to 7",
    "move 2 from 9 to 4",
    "move 1 from 4 to 1",
    "move 1 from 3 to 5",
    "move 2 from 9 to 8",
    "move 11 from 8 to 7",
    "move 2 from 6 to 5",
    "move 1 from 6 to 9",
    "move 1 from 1 to 9",
    "move 1 from 9 to 1",
    "move 4 from 1 to 4",
    "move 2 from 1 to 8",
    "move 1 from 1 to 2",
    "move 1 from 9 to 5",
    "move 2 from 4 to 3",
    "move 2 from 2 to 7",
    "move 2 from 3 to 9",
    "move 1 from 9 to 1",
    "move 1 from 9 to 1",
    "move 5 from 5 to 1",
    "move 19 from 5 to 6",
    "move 5 from 1 to 4",
    "move 1 from 2 to 9",
    "move 1 from 1 to 3",
    "move 7 from 5 to 8",
    "move 1 from 3 to 6",
    "move 8 from 7 to 3",
    "move 7 from 4 to 8",
    "move 3 from 8 to 5",
    "move 1 from 4 to 1",
    "move 1 from 9 to 4",
    "move 1 from 4 to 9",
    "move 1 from 5 to 2",
    "move 2 from 5 to 6",
    "move 2 from 8 to 2",
    "move 7 from 8 to 1",
    "move 1 from 1 to 7",
    "move 3 from 6 to 9",
    "move 2 from 3 to 2",
    "move 1 from 2 to 1",
    "move 1 from 8 to 7",
    "move 2 from 9 to 6",
    "move 2 from 9 to 5",
    "move 1 from 5 to 6",
    "move 1 from 2 to 8",
    "move 2 from 1 to 7",
    "move 1 from 4 to 3",
    "move 3 from 2 to 5",
    "move 7 from 1 to 3",
    "move 10 from 3 to 4",
    "move 3 from 5 to 4",
    "move 1 from 3 to 8",
    "move 3 from 3 to 2",
    "move 1 from 8 to 1",
    "move 1 from 1 to 3",
    "move 3 from 8 to 3",
    "move 5 from 4 to 6",
    "move 1 from 2 to 3",
    "move 4 from 6 to 4",
    "move 1 from 5 to 7",
    "move 4 from 3 to 4",
    "move 1 from 2 to 8",
    "move 12 from 7 to 6",
    "move 1 from 8 to 2",
    "move 2 from 2 to 7",
    "move 1 from 8 to 4",
    "move 23 from 6 to 3",
    "move 14 from 3 to 6",
    "move 15 from 4 to 6",
    "move 1 from 8 to 6",
    "move 10 from 3 to 7",
    "move 2 from 4 to 2",
    "move 11 from 7 to 8",
    "move 2 from 2 to 6",
    "move 44 from 6 to 9",
    "move 21 from 9 to 3",
    "move 12 from 3 to 6",
    "move 1 from 7 to 4",
    "move 1 from 4 to 7",
    "move 9 from 3 to 2",
    "move 2 from 8 to 6",
    "move 3 from 2 to 4",
    "move 17 from 9 to 1",
    "move 3 from 4 to 6",
    "move 2 from 2 to 9",
    "move 4 from 9 to 2",
    "move 10 from 6 to 9",
    "move 1 from 7 to 6",
    "move 4 from 9 to 5",
    "move 4 from 2 to 4",
    "move 14 from 1 to 5",
    "move 4 from 4 to 3",
    "move 3 from 2 to 9",
    "move 9 from 9 to 7",
    "move 1 from 2 to 5",
    "move 9 from 8 to 5",
    "move 8 from 7 to 2",
    "move 4 from 3 to 8",
    "move 5 from 6 to 2",
    "move 3 from 1 to 6",
    "move 1 from 7 to 1",
    "move 4 from 2 to 4",
    "move 3 from 6 to 4",
    "move 3 from 8 to 3",
    "move 13 from 5 to 2",
    "move 2 from 3 to 5",
    "move 12 from 5 to 9",
    "move 1 from 3 to 5",
    "move 1 from 5 to 9",
    "move 1 from 8 to 3",
    "move 4 from 9 to 5",
    "move 6 from 4 to 5",
    "move 12 from 9 to 7",
    "move 1 from 9 to 3",
    "move 1 from 3 to 2",
    "move 12 from 5 to 6",
    "move 12 from 7 to 2",
    "move 1 from 3 to 7",
    "move 1 from 4 to 8",
    "move 33 from 2 to 8",
    "move 1 from 7 to 5",
    "move 1 from 1 to 2",
    "move 4 from 5 to 4",
    "move 3 from 2 to 5",
    "move 34 from 8 to 6",
    "move 1 from 4 to 3",
    "move 1 from 5 to 7",
    "move 1 from 7 to 5",
    "move 3 from 4 to 9",
    "move 2 from 9 to 7",
    "move 1 from 9 to 4",
    "move 1 from 3 to 7",
    "move 1 from 5 to 8",
    "move 1 from 5 to 1",
    "move 1 from 5 to 7",
    "move 1 from 4 to 8",
    "move 1 from 1 to 4",
    "move 1 from 4 to 2",
    "move 3 from 7 to 5",
    "move 2 from 8 to 5",
    "move 1 from 2 to 8",
    "move 4 from 6 to 2",
    "move 1 from 8 to 6",
    "move 1 from 7 to 9",
    "move 29 from 6 to 7",
    "move 4 from 2 to 3",
    "move 2 from 5 to 8",
    "move 1 from 9 to 5",
    "move 2 from 8 to 1",
    "move 23 from 7 to 5",
    "move 2 from 6 to 1",
    "move 23 from 5 to 6",
    "move 1 from 3 to 6",
    "move 4 from 5 to 9",
    "move 2 from 1 to 3",
    "move 5 from 3 to 8",
    "move 2 from 6 to 5",
    "move 2 from 1 to 4",
    "move 1 from 9 to 8",
    "move 1 from 9 to 1",
    "move 1 from 4 to 6",
    "move 2 from 5 to 6",
    "move 6 from 7 to 8",
    "move 2 from 9 to 2",
    "move 18 from 6 to 5",
    "move 21 from 6 to 4",
    "move 1 from 1 to 6",
    "move 2 from 6 to 7",
    "move 2 from 7 to 9",
    "move 2 from 2 to 8",
    "move 7 from 4 to 3",
    "move 12 from 5 to 3",
    "move 1 from 9 to 5",
    "move 1 from 9 to 4",
    "move 6 from 5 to 2",
    "move 17 from 3 to 4",
    "move 3 from 4 to 3",
    "move 1 from 2 to 4",
    "move 5 from 2 to 8",
    "move 1 from 5 to 8",
    "move 19 from 8 to 7",
    "move 1 from 3 to 6",
    "move 1 from 8 to 4",
    "move 1 from 6 to 1",
    "move 15 from 4 to 6",
    "move 1 from 1 to 4",
    "move 3 from 3 to 5",
    "move 4 from 6 to 7",
    "move 1 from 4 to 7",
    "move 10 from 6 to 7",
    "move 16 from 4 to 5",
    "move 24 from 7 to 2",
    "move 8 from 7 to 8",
    "move 1 from 4 to 2",
    "move 6 from 8 to 7",
    "move 1 from 8 to 7",
    "move 1 from 6 to 9",
    "move 14 from 5 to 4",
    "move 9 from 7 to 8",
    "move 4 from 5 to 1",
    "move 2 from 1 to 5",
    "move 3 from 8 to 6",
    "move 2 from 6 to 9",
    "move 2 from 2 to 8",
    "move 6 from 2 to 7",
    "move 3 from 4 to 6",
    "move 1 from 3 to 4",
    "move 3 from 5 to 7",
    "move 1 from 6 to 9",
    "move 5 from 7 to 2",
    "move 4 from 9 to 1",
    "move 1 from 7 to 9",
    "move 9 from 8 to 4",
    "move 5 from 1 to 2",
    "move 2 from 6 to 1",
    "move 6 from 4 to 7",
    "move 1 from 7 to 3",
    "move 1 from 3 to 9",
    "move 1 from 9 to 7",
    "move 1 from 6 to 7",
    "move 9 from 4 to 5",
    "move 7 from 7 to 9",
    "move 3 from 7 to 5",
    "move 1 from 9 to 2",
    "move 6 from 9 to 8",
    "move 4 from 4 to 5",
    "move 1 from 4 to 2",
    "move 1 from 4 to 2",
    "move 2 from 1 to 2",
    "move 1 from 9 to 8",
    "move 10 from 2 to 4",
    "move 8 from 2 to 7",
    "move 12 from 2 to 9",
    "move 6 from 7 to 4",
    "move 1 from 1 to 2",
    "move 8 from 9 to 8",
    "move 7 from 5 to 1",
    "move 9 from 4 to 3",
    "move 14 from 8 to 4",
    "move 1 from 8 to 4",
    "move 1 from 1 to 5",
    "move 1 from 5 to 2",
    "move 3 from 2 to 4",
    "move 1 from 7 to 1",
    "move 1 from 7 to 3",
    "move 2 from 1 to 7",
    "move 3 from 5 to 7",
    "move 2 from 7 to 6",
    "move 1 from 6 to 5",
    "move 3 from 7 to 1",
    "move 1 from 6 to 8",
    "move 1 from 8 to 7",
    "move 1 from 3 to 6",
    "move 1 from 7 to 1",
    "move 4 from 1 to 4",
    "move 6 from 3 to 2",
    "move 3 from 1 to 2",
    "move 3 from 3 to 6",
    "move 3 from 2 to 6",
    "move 6 from 6 to 5",
    "move 1 from 1 to 4",
    "move 1 from 9 to 6",
    "move 5 from 2 to 1",
    "move 3 from 1 to 2",
    "move 2 from 9 to 8",
    "move 3 from 1 to 5",
    "move 1 from 9 to 7",
    "move 25 from 4 to 1",
    "move 1 from 1 to 7",
    "move 2 from 8 to 3",
    "move 13 from 1 to 9",
    "move 2 from 3 to 5",
    "move 8 from 5 to 9",
    "move 4 from 2 to 1",
    "move 2 from 6 to 7",
    "move 10 from 5 to 9",
    "move 4 from 7 to 2",
    "move 2 from 2 to 3",
    "move 9 from 9 to 2",
    "move 4 from 4 to 5",
    "move 4 from 5 to 4",
    "move 5 from 1 to 4",
    "move 10 from 4 to 5",
    "move 22 from 9 to 1",
    "move 2 from 2 to 7",
    "move 3 from 2 to 1",
    "move 6 from 2 to 6",
    "move 1 from 7 to 1",
    "move 10 from 5 to 7",
    "move 15 from 1 to 4",
    "move 13 from 1 to 5",
    "move 3 from 6 to 8",
    "move 1 from 8 to 9"};

class stackofcrates
{
public:
    stackofcrates(const string _input) : input(_input)
    {
        for (auto e : input)
            crates.push_back(e);
    }

    int getTopWord()
    {
        int resultA = 0;

        return resultA;
    }

    string poptop(int n = 1)
    {
        string lastelems;
        for (int i = 0; i < n; ++i)
        {
            lastelems = crates.back() + lastelems;
            crates.pop_back();
        }

        return lastelems;
    }

    char gettop()
    {
        return crates.back();
    }

    void push(string inputstring)
    {
        for (auto elem : inputstring)
            crates.push_back(elem);
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
    vector<char> crates;
};

class SupplyStacks
{
public:
    SupplyStacks(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;
        parseData();
    }

    void parseData()
    {
        moves.clear();
        stackofcratess.clear();
        // Parse data
        bool addmoves = false;
        for (auto elem : input)
        {
            if ("" == elem)
                addmoves = true;
            else if (addmoves)
                moves.push_back(elem);
            else
                stackofcratess.push_back(stackofcrates(elem));
        }
    }

    void moveCrateMover9000()
    {
        parseData();
        for (auto elem : moves)
        {
            auto posfrom = elem.find("from");
            auto posto = elem.find("to");

            int number = stoi(elem.substr(5));
            int from = stoi(elem.substr(posfrom + 5));
            int to = stoi(elem.substr(posto + 3));

            for (int i = 0; i < number; ++i)
            {
                stackofcratess[to - 1].push(stackofcratess[from - 1].poptop());
            }
        }
    }

    void moveCrateMover9001()
    {
        parseData();
        for (auto elem : moves)
        {
            auto posfrom = elem.find("from");
            auto posto = elem.find("to");

            int number = stoi(elem.substr(5));
            int from = stoi(elem.substr(posfrom + 5));
            int to = stoi(elem.substr(posto + 3));

            stackofcratess[to - 1].push(stackofcratess[from - 1].poptop(number));
        }
    }

    string getTopWord()
    {
        string resultA;
        for (auto e : stackofcratess)
            resultA += e.gettop();

        return resultA;
    }

private:
    const vector<string> input;
    vector<string> moves;
    vector<stackofcrates> stackofcratess;
};

TEST_CASE("Testdata")
{
    SupplyStacks SupplyStacksData(inputTestdata);
    SupplyStacksData.moveCrateMover9000();
    REQUIRE("CMZ" == SupplyStacksData.getTopWord());
    SupplyStacksData.moveCrateMover9000();
    REQUIRE("CMZ" == SupplyStacksData.getTopWord());
    SupplyStacksData.moveCrateMover9001();
    REQUIRE("MCD" == SupplyStacksData.getTopWord());
}

TEST_CASE("SupplyStacks")
{
    SupplyStacks SupplyStacksData(inputData);
    SupplyStacksData.moveCrateMover9000();
    REQUIRE("RTGWZTHLD" == SupplyStacksData.getTopWord());
    SupplyStacksData.moveCrateMover9001();
    REQUIRE("STHGRZZFR" == SupplyStacksData.getTopWord());
}