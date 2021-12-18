#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;

const vector<string> inputT = {
    ""};

const vector<string> inputA = {
    ""};

class snailfishnumber
{
public:
    snailfishnumber(const string &_input) : input(_input)
    {
        //cout << "Size of Input: " << input.size() << endl;
        parse();
    }

    ~snailfishnumber()
    {
        if (subfish[0])
            delete subfish[0];
        if (subfish[1])
            delete subfish[1];
    }

    void parse()
    {
        assert('[' == input[0]);
        assert(']' == input[input.size() - 1]);
        string subinput(input.substr(1, input.size() - 2));

        // Find ,
        int c = 0;
        size_t pos = 0;
        for (auto item : subinput)
        {

            if (',' == item && 0 == c)
                break;
            else if ('[' == item)
                ++c;
            else if (']' == item)
                --c;
            pos++;
        }

        string part[2] = {subinput.substr(0, pos), subinput.substr(pos + 1)};
        for (int p = 0; p < 2; ++p)
        {
            if (string::npos != part[p].find('['))
            {
                subfish[p] = new snailfishnumber(part[p]);
            }
            else
            {
                number[p] = stoi(part[p]);
            }
        }
    }

    const string getText() const
    {
        stringstream ret;
        ret << "[";
        if (-1 == number[0])
            ret << subfish[0]->getText();
        else
            ret << number[0];
        ret << ",";
        if (-1 == number[1])
            ret << subfish[1]->getText();
        else
            ret << number[1];
        ret << "]";
        return ret.str();
    }

    int explode(int level = -1)
    {
        static int rightnumber = -1;
        int leftnumber = -1;
        static bool finished = false;

        if ( -1 == level)
        {
            rightnumber = -1;
            leftnumber = -1;
            level = 0;
            finished = false;
        }

        if (4 == level)
        {
            if ( finished )
                return leftnumber;
            assert(nullptr == subfish[0]);
            assert(nullptr == subfish[1]);
            assert(-1 != number[0]);
            assert(-1 != number[1]);
            exploded = true;
            cout << "Explode: " << number[0] << "," << number[1] << endl;
            rightnumber = number[1];
            finished = true;
            return number[0];
        }

        for (int p = 0; p < 2; ++p)
            if (-1 == number[p])
            {
                leftnumber = subfish[p]->explode(level + 1);
                if (-1 != leftnumber)
                {
                    if (subfish[p]->exploded)
                    {
                        delete subfish[p];
                        subfish[p] = nullptr;
                        number[p] = 0;
                    }

                    // Right number to add?
                    if (1 == p)
                    {
                        if (number[0] != -1)
                        {
                            number[0] += leftnumber;
                            leftnumber = -1;
                        }
                    }
                }
            }
            else
            {
                if (-1 != rightnumber)
                {
                    number[p] += rightnumber;
                    rightnumber = -1;
                }
            }

        return leftnumber;
    }

    friend snailfishnumber operator+(snailfishnumber const &, snailfishnumber const &);

private:
    const string input;

    int number[2] = {-1, -1};
    snailfishnumber *subfish[2] = {nullptr, nullptr};
    bool exploded = false;
};

snailfishnumber operator+(snailfishnumber const &l, snailfishnumber const &r)
{
    string resfishtext = "[" + l.getText() + "," + r.getText() + "]";
    snailfishnumber resfish(resfishtext);
    return resfish;
}

TEST_CASE("AddFish")
{
    snailfishnumber f1("[1,2]"),
        f2("[[3,4],5]");

    snailfishnumber f3 = f1 + f2;

    REQUIRE("[[1,2],[[3,4],5]]" == f3.getText());
}

TEST_CASE("Explode")
{
    snailfishnumber test1("[[[[[9,8],1],2],3],4]");
    test1.explode();
    REQUIRE("[[[[0,9],2],3],4]" == test1.getText());

    snailfishnumber test2("[7,[6,[5,[4,[3,2]]]]]");
    test2.explode();
    REQUIRE("[7,[6,[5,[7,0]]]]" == test2.getText());

    snailfishnumber test3("[[6,[5,[4,[3,2]]]],1]");
    test3.explode();
    REQUIRE("[[6,[5,[7,0]]],3]" == test3.getText());

    snailfishnumber test4("[[3,[2,[1,[7,3]]]],[6,[5,[4,[3,2]]]]]");
    test4.explode();
    REQUIRE("[[3,[2,[8,0]]],[9,[5,[4,[3,2]]]]]" == test4.getText());

    snailfishnumber test5("[[3,[2,[8,0]]],[9,[5,[4,[3,2]]]]]");
    test5.explode();
    REQUIRE("[[3,[2,[8,0]]],[9,[5,[7,0]]]]" == test5.getText());
}
