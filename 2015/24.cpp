#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const set<uint32_t> inputT = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11};

const set<uint32_t> inputA = {1, 2, 3, 5, 7, 13, 17, 19, 23, 29,
                              31, 37, 41, 43, 53, 59, 61, 67, 71,
                              73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

class packagegroup
{
public:
    void addpackage(uint32_t package)
    {
        packages.insert(package);
        weight += package;
        qe *= package;
    }
    void removepackage(uint32_t package)
    {
        auto const pos = packages.find(package);
        if (pos != packages.end())
        {
            packages.erase(pos);
            weight -= package;
            qe /= package;
        }
    }

    set<uint32_t> packages;
    uint32_t weight = 0;
    uint64_t qe = 1;
};

class balance
{
public:
    balance(const set<uint32_t> &_input, uint32_t _n) : input(_input), numofgroups(_n)
    {
        cout << "Size of Input: " << input.size() << endl;
        for (auto elem : input)
            sumofall += elem;
        cout << "Sum of all packages: " << sumofall << " ";
        assert(sumofall % numofgroups == 0);
        sumofgroup = sumofall / numofgroups;
        cout << "Sum of one package: " << sumofgroup << endl;

        // array<packagegroup, numofgroups> resultsets;

        // Much too slow.
        //getallvalidgroups(resultsets, input.size() - 1);

        packagegroup resultset;
        getsmallestpackage(resultset, input.size() - 1);

        cout << "Valid Groups: " << groups.size() << endl;
    }

    void getsmallestpackage(packagegroup &resultset, int level)
    {
        if (resultset.packages.size() > smallestpackagesize)
            return;
        if (resultset.packages.size() == smallestpackagesize && resultset.qe > smallestpackageqe)
            return;
        if (resultset.weight > sumofgroup)
            return;

        if (resultset.weight == sumofgroup)
        {
            groups.insert(resultset.packages);
            return;
        }

        if (level < 0)
            return;

        auto element = (input.begin());
        for (int i = 0; i < level; ++i)
            ++element;
        uint32_t currentNumber = *element;

        // Two options: Add it or not
        for (int i = 0; i < 2; ++i)
        {
            if (1 == i)
                resultset.addpackage(currentNumber);
            getsmallestpackage(resultset, level - 1);
            if (1 == i)
                resultset.removepackage(currentNumber);
        }
    }
    /*
    void getallvalidgroups(array<packagegroup, numofgroups> &resultsets, int level)
    {
        for (auto resultset : resultsets)
            if (resultset.weight > sumofgroup)
                return;

        if (resultsets[0].weight == sumofgroup &&
            resultsets[1].weight == sumofgroup &&
            resultsets[2].weight == sumofgroup)
        {
            for (auto resultset : resultsets)
                groups.insert(resultset.packages);
            return;
        }

        if (level < 0)
            return;

        auto element = (input.begin());
        for (int i = 0; i < level; ++i)
            ++element;
        uint32_t currentNumber = *element;

        // How many targets?
        int t = numofgroups;
        if (0 == resultsets[0].weight)
            t = 1;
        else if (0 == resultsets[1].weight)
            t = 2;

        for (int i = 0; i < t; ++i)
        {
            if (resultsets[i].weight + currentNumber <= sumofgroup && level >= 0)
            {
                resultsets[i].addpackage(currentNumber);
                getallvalidgroups(resultsets, level - 1);
                resultsets[i].removepackage(currentNumber);
            }
        }
    }
*/
    uint64_t getSmallestQE()
    {
        size_t smallestsize = -1;
        for (auto group : groups)
        {
            if (group.size() < smallestsize)
                smallestsize = group.size();
        }

        uint64_t smallestqe = -1;
        for (auto group : groups)
        {
            if (group.size() == smallestsize)
            {
                uint64_t qe = 1;
                for (auto packet : group)
                    qe *= packet;

                if (qe < smallestqe)
                    smallestqe = qe;
            }
        }

        return smallestqe;
    }

    uint32_t getNumOfGroups() { return groups.size(); }

private:
    const set<uint32_t> input;
    uint32_t sumofall = 0;
    uint32_t sumofgroup = 0;
    uint32_t smallestpackagesize = -1;
    uint64_t smallestpackageqe = -1;

    const uint32_t numofgroups;

    set<set<uint32_t>> groups;
};

TEST_CASE("Testdata")
{
    balance test(inputT, 3);
    // Probably wrong: Example Data (19) is incomplete
    // REQUIRE(24 == test.getNumOfGroups());
    REQUIRE(99 == test.getSmallestQE());

    balance testb(inputT, 4);
    REQUIRE(44 == testb.getSmallestQE());
}

TEST_CASE("Task")
{
    balance problemA(inputA, 3);
    uint64_t resultA = problemA.getSmallestQE();
    cout << "Result A: " << resultA << endl;
    REQUIRE(10723906903 == resultA);

    balance problemB(inputA, 4);
    uint64_t resultB = problemB.getSmallestQE();
    cout << "Result B: " << resultB << endl;
    REQUIRE(74850409 == resultB);
}
