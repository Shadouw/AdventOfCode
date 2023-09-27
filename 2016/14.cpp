#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <set>

#include <catch2/catch_test_macros.hpp>

#include <aocmd5.h>

using namespace std;

class OneTimePad
{
public:
    OneTimePad(const string &_salt) : salt(_salt)
    {
        cout << "Size of salt: " << salt.size() << endl;
    }

    void getFive()
    {
        while (true)
        {
            string md5hex(salt + to_string(counter++));
            string md5hexresult = getmd5hexhash(md5hex);

            for (int i = 0; i < md5hexresult.size() - 3; ++i)
                if (md5hexresult[i] == md5hexresult[i + 1] && md5hexresult[i] == md5hexresult[i + 2])
                    keythree[md5hexresult[i]].insert(counter - 1);

            for (int i = 0; i < md5hexresult.size() - 5; ++i)
                if (md5hexresult[i] == md5hexresult[i + 1] &&
                    md5hexresult[i] == md5hexresult[i + 2] &&
                    md5hexresult[i] == md5hexresult[i + 3] &&
                    md5hexresult[i] == md5hexresult[i + 4])
                {
                    keyfive[md5hexresult[i]].insert(counter - 1);
                    return;
                }
        }
    }

    void confirmKeys()
    {
        for (const auto &key : keythree)
            for (const auto &index : key.second)
            {
                auto &key5 = keyfive[key.first];

                for (auto &index2 : key5)
                    if (index < index2 && index + 1000 > index2)
                        keys[index] = true;
            }
    }

    long getResultA()
    {
        while (keys.size() < 64)
        {
            getFive();
            confirmKeys();
        }

        long resultA = keys.rbegin()->first;

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = 0;

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const string salt;
    unsigned long counter = 0;
    map<char, set<unsigned long>> keythree;
    map<char, set<unsigned long>> keyfive;
    map<unsigned long, bool> keys;
};

TEST_CASE("Testdata")
{
    OneTimePad OneTimePadData("abc");
    REQUIRE(22728 == OneTimePadData.getResultA());
    REQUIRE(0 == OneTimePadData.getResultB());
}

TEST_CASE("OneTimePad")
{
    OneTimePad OneTimePadData("ahsbgdzn");
    REQUIRE(24438 > OneTimePadData.getResultA());
    REQUIRE(0 == OneTimePadData.getResultA());
    REQUIRE(0 == OneTimePadData.getResultB());
}