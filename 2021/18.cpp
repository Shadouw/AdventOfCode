#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;

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

    snailfishnumber(int l, int r)
    {
        number[0] = l;
        number[1] = r;
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
        static bool exploded = false;

        if (-1 == level)
        {
            rightnumber = -1;
            level = 0;
            exploded = false;
        }

        if (4 == level)
        {
            if (!exploded)
            {
                assert(nullptr == subfish[0]);
                assert(nullptr == subfish[1]);
                assert(-1 != number[0]);
                assert(-1 != number[1]);
                explodednode = true;
                cout << "Explode: " << number[0] << "," << number[1] << endl;
                leftnumber = number[0];
                rightnumber = number[1];
                exploded = true;
                return leftnumber;
            }
        }

        for (int p = 0; p < 2; ++p)
            if (-1 == number[p])
            {
                leftnumber = subfish[p]->explode(level + 1);
                if (-1 != leftnumber)
                {
                    if (subfish[p]->explodednode)
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

    bool split(int level = -1)
    {
        static bool splitted = false;

        if (-1 == level)
        {
            splitted = false;
            level = 0;
        }

        for (int p = 0; p < 2; ++p)
        {
            if (9 < number[p] && !splitted)
            {
                assert(nullptr == subfish[p]);
                subfish[p] = new snailfishnumber(number[p] / 2, number[p] / 2 + number[p] % 2);
                number[p] = -1;
                splitted = true;
            }
            if (-1 == number[p])
                subfish[p]->split(level + 1);
        }

        return splitted;
    }

    void optimize()
    {
        string oldstring;

        while (oldstring != getText())
        {
            oldstring = getText();
            //cout << oldstring << endl;

            explode();
            if (oldstring == getText())
                split();
        }
    }

    snailfishnumber &operator=(const snailfishnumber &b)
    {
        this->input = b.getText();
        for (int i = 0; i < 2; ++i)
        {
            this->number[i] = -1;
            if (this->subfish[i])
                delete this->subfish[i];
        }
        this->parse();
        return *this;
    }

    friend snailfishnumber operator+(snailfishnumber const &, snailfishnumber const &);

private:
    string input;

    int number[2] = {-1, -1};
    snailfishnumber *subfish[2] = {nullptr, nullptr};
    bool explodednode = false;
};

snailfishnumber operator+(snailfishnumber const &l, snailfishnumber const &r)
{
    string resfishtext = "[" + l.getText() + "," + r.getText() + "]";
    snailfishnumber resfish(resfishtext);
    resfish.optimize();
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

TEST_CASE("Split")
{
    snailfishnumber test1("[[[[0,7],4],[15,[0,13]]],[1,1]]");
    test1.split();
    REQUIRE("[[[[0,7],4],[[7,8],[0,13]]],[1,1]]" == test1.getText());

    test1.split();
    REQUIRE("[[[[0,7],4],[[7,8],[0,[6,7]]]],[1,1]]" == test1.getText());

    snailfishnumber test2("[[[[0,7],4],[16,[0,13]]],[1,1]]");
    test2.split();
    REQUIRE("[[[[0,7],4],[[8,8],[0,13]]],[1,1]]" == test2.getText());
}

TEST_CASE("Add")
{
    snailfishnumber f1("[[[[4,3],4],4],[7,[[8,4],9]]]");
    snailfishnumber f2("[1,1]");

    snailfishnumber f3(f1 + f2);
    f3.optimize();
    REQUIRE("[[[[0,7],4],[[7,8],[6,0]]],[8,1]]" == f3.getText());
}

TEST_CASE("Sum")
{
    const vector<string> inputT = {"[1,1]", "[2,2]", "[3,3]", "[4,4]"};
    snailfishnumber test(inputT[0]);
    for (size_t t = 1; t < inputT.size(); ++t)
        test = test + snailfishnumber(inputT[t]);

    REQUIRE("[[[[1,1],[2,2]],[3,3]],[4,4]]" == test.getText());
}

TEST_CASE("Sum2Simple")
{
    snailfishnumber test(snailfishnumber("[[[[1,1],[2,2]],[3,3]],[4,4]]") + snailfishnumber("[5,5]"));

    REQUIRE("[[[[3,0],[5,3]],[4,4]],[5,5]]" == test.getText());
}

TEST_CASE("Sum2")
{
    const vector<string> inputT = {"[1,1]", "[2,2]", "[3,3]", "[4,4]", "[5,5]"};
    snailfishnumber test(inputT[0]);
    for (size_t t = 1; t < inputT.size(); ++t)
        test = test + snailfishnumber(inputT[t]);

    REQUIRE("[[[[3,0],[5,3]],[4,4]],[5,5]]" == test.getText());
}

TEST_CASE("Sum3")
{
    const vector<string> inputT = {"[1,1]", "[2,2]", "[3,3]", "[4,4]", "[5,5]", "[6,6]"};
    snailfishnumber test(inputT[0]);
    for (size_t t = 1; t < inputT.size(); ++t)
        test = test + snailfishnumber(inputT[t]);

    REQUIRE("[[[[5,0],[7,4]],[5,5]],[6,6]]" == test.getText());
}

TEST_CASE("SumLarge")
{
    const vector<string> inputT = {"[[[0,[4,5]],[0,0]],[[[4,5],[2,6]],[9,5]]]",
                                   "[7,[[[3,7],[4,3]],[[6,3],[8,8]]]]",
                                   "[[2,[[0,8],[3,4]]],[[[6,7],1],[7,[1,6]]]]",
                                   "[[[[2,4],7],[6,[0,5]]],[[[6,8],[2,8]],[[2,1],[4,5]]]]",
                                   "[7,[5,[[3,8],[1,4]]]]",
                                   "[[2,[2,2]],[8,[8,1]]]",
                                   "[2,9]",
                                   "[1,[[[9,3],9],[[9,0],[0,7]]]]",
                                   "[[[5,[7,4]],7],1]",
                                   "[[[[4,2],2],6],[8,7]]"};

    const vector<string> results = {"",
                                    "[[[[4,0],[5,4]],[[7,7],[6,0]]],[[8,[7,7]],[[7,9],[5,0]]]]",
                                    "[[[[6,7],[6,7]],[[7,7],[0,7]]],[[[8,7],[7,7]],[[8,8],[8,0]]]]",
                                    "[[[[7,0],[7,7]],[[7,7],[7,8]]],[[[7,7],[8,8]],[[7,7],[8,7]]]]",
                                    "[[[[7,7],[7,8]],[[9,5],[8,7]]],[[[6,8],[0,8]],[[9,9],[9,0]]]]",
                                    "[[[[6,6],[6,6]],[[6,0],[6,7]]],[[[7,7],[8,9]],[8,[8,1]]]]",
                                    "[[[[6,6],[7,7]],[[0,7],[7,7]]],[[[5,5],[5,6]],9]]",
                                    "[[[[7,8],[6,7]],[[6,8],[0,8]]],[[[7,7],[5,0]],[[5,5],[5,6]]]]",
                                    "[[[[7,7],[7,7]],[[8,7],[8,7]]],[[[7,0],[7,7]],9]]",
                                    "[[[[8,7],[7,7]],[[8,6],[7,7]]],[[[0,7],[6,6]],[8,7]]]"};

    snailfishnumber test(inputT[0]);
    for (size_t t = 1; t < inputT.size(); ++t)
    {
        test = test + snailfishnumber(inputT[t]);
        REQUIRE(results[t] == test.getText());
    }

    REQUIRE("[[[[8,7],[7,7]],[[8,6],[7,7]]],[[[0,7],[6,6]],[8,7]]]" == test.getText());
}