#include <iostream>
#include <string>
#include <queue>
#include <aocmd5.h>

#include <catch2/catch_test_macros.hpp>

using namespace std;

class status
{
public:
    status(const string _input, const string _path = "", const int _posx = 0, const int _posy = 0) : input(_input), path(_path), posx(_posx), posy(_posy)
    {
        calcHash();
    }

    void calcHash()
    {
        hash = getmd5hexhash(input + path);
    }

    bool canGo(char direction) const
    {
        switch (direction)
        {
        case 'U':
            if (0 == posy)
                return false;
            return hash[0] > 'a';
            break;
        case 'D':
            if (3 == posy)
                return false;
            return hash[1] > 'a';
            break;
        case 'L':
            if (0 == posx)
                return false;
            return hash[2] > 'a';
            break;
        case 'R':
            if (3 == posx)
                return false;
            return hash[3] > 'a';
            break;
        }
        return false;
    }
    status move(char direction) const
    {
        status newstatus(*this);

        newstatus.path += direction;

        switch (direction)
        {
        case 'U':
            --newstatus.posy;
            break;
        case 'D':
            ++newstatus.posy;
            break;
        case 'L':
            --newstatus.posx;
            break;
        case 'R':
            ++newstatus.posx;
            break;
        }

        newstatus.calcHash();

        return newstatus;
    }

    bool checkFinal()
    {
        return 3 == posx && 3 == posy;
    }

private:
    int posx = 0, posy = 0;
    string input, path;
    string hash;

    friend class TwoStepsForward;
};

class TwoStepsForward
{
public:
    TwoStepsForward(const string &_input) : input(_input)
    {
        statuses.push(input);
    }

    string getResultA()
    {
        long resultA = 0;

        while (statuses.size() > 0)
        {
            const status currentstatus = statuses.front();
            statuses.pop();

            if (currentstatus.canGo('U'))
            {
                status currentstatus2 = currentstatus.move('U');
                if (currentstatus2.checkFinal())
                    return currentstatus2.path;
                statuses.push(currentstatus2);
            }
            if (currentstatus.canGo('D'))
            {
                status currentstatus2 = currentstatus.move('D');
                if (currentstatus2.checkFinal())
                    return currentstatus2.path;
                statuses.push(currentstatus2);
            }
            if (currentstatus.canGo('L'))
            {
                status currentstatus2 = currentstatus.move('L');
                if (currentstatus2.checkFinal())
                    return currentstatus2.path;
                statuses.push(currentstatus2);
            }
            if (currentstatus.canGo('R'))
            {
                status currentstatus2 = currentstatus.move('R');
                if (currentstatus2.checkFinal())
                    return currentstatus2.path;
                statuses.push(currentstatus2);
            }
        }

        cout << "resultA: " << resultA << endl;
        return "";
    }
    long getResultB()
    {
        long resultB = 0;

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const string input;
    queue<status> statuses;
};

TEST_CASE("Testdata")
{
    TwoStepsForward TwoStepsForwardData("hijkl");
    REQUIRE("" == TwoStepsForwardData.getResultA());
    REQUIRE(0 == TwoStepsForwardData.getResultB());
}

TEST_CASE("Testdata2")
{
    TwoStepsForward TwoStepsForwardData("ihgpwlah");
    REQUIRE("DDRRRD" == TwoStepsForwardData.getResultA());
    REQUIRE(0 == TwoStepsForwardData.getResultB());
}

TEST_CASE("Testdata3")
{
    TwoStepsForward TwoStepsForwardData("kglvqrro");
    REQUIRE("DDUDRLRRUDRD" == TwoStepsForwardData.getResultA());
    REQUIRE(0 == TwoStepsForwardData.getResultB());
}

TEST_CASE("Testdata4")
{
    TwoStepsForward TwoStepsForwardData("ulqzkmiv");
    REQUIRE("DRURDRUDDLLDLUURRDULRLDUUDDDRR" == TwoStepsForwardData.getResultA());
    REQUIRE(0 == TwoStepsForwardData.getResultB());
}

TEST_CASE("TwoStepsForward")
{
    TwoStepsForward TwoStepsForwardData("pslxynzg");
    REQUIRE("DDRRUDLRRD" == TwoStepsForwardData.getResultA());
    REQUIRE(0 == TwoStepsForwardData.getResultB());
}