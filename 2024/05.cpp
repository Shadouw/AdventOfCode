#include <aoc.h>
using namespace std;
using namespace aoc;

class PageOrderRule {
public:
    PageOrderRule(const string _input)
        : input(_input)
    {
        vector<string> _rule = stringtovector(_input, '|');
        rule = pair<long, long>(atol(_rule[0].c_str()), atol(_rule[1].c_str()));
        assert(rule.first != rule.second);
    }

    bool checkUpdate(const vector<long> update)
    {
        auto pos1 = find(update.begin(), update.end(), rule.first);
        auto pos2 = find(update.begin(), update.end(), rule.second);

        if (update.end() == pos1 || update.end() == pos2)
            return true;

        return (pos1 < pos2);
    }

    string getString() { return input; }

    friend bool operator<(const PageOrderRule& l, const PageOrderRule& r)
    {
        return l.input < r.input;
    }

private:
    string input;
    pair<long, long> rule;

    friend class PrintQueue;
    friend class Update;
};

class Update {
public:
    Update(const string _input)
        : input(_input)
    {
        vector<string> _update = stringtovector(_input, ',');
        for (auto elem : _update)
            update.push_back(atol(elem.c_str()));

        for (auto i = 0; i < update.size() - 2; ++i)
            for (auto j = i + 1; j < update.size() - 1; ++j) {
                assert(update[i] != update[j]);
                assert(update.size() % 2 == 1);
            }
    }

    bool checkPageOrderRule(const vector<PageOrderRule> PageOrderRules)
    {
        for (auto rule : PageOrderRules) {
            if (!rule.checkUpdate(update)) {
                failedrule = rule.rule;
                return false;
            }
        }
        return true;
    }

    long getMiddleNumber()
    {
        auto x = update.size();
        long MiddleNumber = update[(update.size() + 1) / 2 - 1];

        return MiddleNumber;
    }

    long getMiddleNumberFixed(const vector<PageOrderRule> PageOrderRules)
    {
        // Fix the order
        failedrule.first = 0;
        failedrule.second = 0;

        while (!checkPageOrderRule(PageOrderRules)) {
            // Just swap the two positions.
            auto pos1 = find(update.begin(), update.end(), failedrule.first);
            auto pos2 = find(update.begin(), update.end(), failedrule.second);

            iter_swap(pos1, pos2);
        }

        return getMiddleNumber();
    }

    string getString() { return input; }

    friend bool operator<(const Update& l, const Update& r)
    {
        return l.input < r.input;
    }

private:
    const string input;
    vector<long> update;
    pair<long, long> failedrule;

    friend class PrintQueue;
};

class PrintQueue {
public:
    PrintQueue(string _file, string _extension)
    : datafile(_file, _extension)
    {
        bool parsePageOrderRules = true;

        // Parse data
        for (auto elem : datafile.getLines()) {
            if ("" == elem)
                parsePageOrderRules = false;
            else if (parsePageOrderRules)
                PageOrderRules.push_back(PageOrderRule(elem));
            else
                Updates.push_back(Update(elem));
        }
        cout << PageOrderRules.size() << " PageOrderRules" << endl;
        cout << Updates.size() << " Updates" << endl;
    }

    long getMiddleNumbers()
    {
        long MiddleNumbers = 0;
        for (auto e : Updates) {
            if (e.checkPageOrderRule(PageOrderRules))
                MiddleNumbers += e.getMiddleNumber();
        }

        cout << "MiddleNumbers: " << MiddleNumbers << endl;
        return MiddleNumbers;
    }

    long getMiddleNumbersFixed()
    {
        long MiddleNumbersFixed = 0;
        for (auto e : Updates) {
            if (!e.checkPageOrderRule(PageOrderRules))
                MiddleNumbersFixed += e.getMiddleNumberFixed(PageOrderRules);
        }

        cout << "MiddleNumbersFixed: " << MiddleNumbersFixed << endl;
        return MiddleNumbersFixed;
    }

private:
    aocdatafile datafile;
    vector<Update> Updates;
    vector<PageOrderRule> PageOrderRules;
};

TEST_CASE("Testdata")
{
    PrintQueue PrintQueueData(__FILE__, "example");
    REQUIRE(143 == PrintQueueData.getMiddleNumbers());
    REQUIRE(123 == PrintQueueData.getMiddleNumbersFixed());
}

TEST_CASE("PrintQueue")
{
    PrintQueue PrintQueueData(__FILE__, "mydata");
    REQUIRE(4905 == PrintQueueData.getMiddleNumbers());
    REQUIRE(6204 == PrintQueueData.getMiddleNumbersFixed());
}