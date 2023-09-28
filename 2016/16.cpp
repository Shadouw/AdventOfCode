#include <iostream>
#include <string>
#include <algorithm>

#include <catch2/catch_test_macros.hpp>

using namespace std;

string Dragon(string a)
{
    string b(a);
    reverse(b.begin(), b.end());

    for (auto &c : b)
        c = ('0' == c ? '1' : '0');

    return a + "0" + b;
}

string Checksum(string inp)
{
    string chksm;
    while (chksm.size() % 2 == 0)
    {
        chksm.clear();
        for (int i = 0; i < inp.size() / 2; ++i)
            chksm += (inp[2 * i] == inp[2 * i + 1] ? "1" : "0");

        inp = chksm;
    }
    return chksm;
}

string fillDisk(string inp, long length)
{
    while (inp.size() < length)
        inp = Dragon(inp);

    inp = inp.substr(0, length);
    return inp;
}

TEST_CASE("Dragon")
{
    REQUIRE("100" == Dragon("1"));
    REQUIRE("001" == Dragon("0"));
    REQUIRE("11111000000" == Dragon("11111"));
    REQUIRE("1111000010100101011110000" == Dragon("111100001010"));
}

TEST_CASE("Checksum")
{
    REQUIRE("100" == Checksum("110010110100"));
}

TEST_CASE("FillDisk")
{
    REQUIRE("10000011110010000111" == fillDisk("10000", 20));
    REQUIRE("01100" == Checksum(fillDisk("10000", 20)));
}

TEST_CASE("DragonChecksum")
{
    REQUIRE("00000100100001100" == Checksum(fillDisk("11011110011011101", 272)));
    REQUIRE("00011010100010010" == Checksum(fillDisk("11011110011011101", 35651584)));
}