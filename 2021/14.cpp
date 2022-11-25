#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<pair<string, string>> inputT = {
    {"CH", "B"},
    {"HH", "N"},
    {"CB", "H"},
    {"NH", "C"},
    {"HB", "C"},
    {"HC", "B"},
    {"HN", "C"},
    {"NN", "C"},
    {"BH", "H"},
    {"NC", "B"},
    {"NB", "B"},
    {"BN", "B"},
    {"BB", "N"},
    {"BC", "B"},
    {"CC", "N"},
    {"CN", "C"}};

const vector<pair<string, string>> inputA = {
    {"SO", "F"},
    {"OP", "V"},
    {"NF", "F"},
    {"BO", "V"},
    {"BH", "S"},
    {"VB", "B"},
    {"SV", "B"},
    {"BK", "S"},
    {"KC", "N"},
    {"SP", "O"},
    {"CP", "O"},
    {"VN", "O"},
    {"HO", "S"},
    {"PC", "B"},
    {"CS", "O"},
    {"PO", "K"},
    {"KF", "B"},
    {"BP", "K"},
    {"VO", "O"},
    {"HB", "N"},
    {"PH", "O"},
    {"FF", "O"},
    {"FB", "K"},
    {"CC", "H"},
    {"FK", "F"},
    {"HV", "P"},
    {"CO", "S"},
    {"OC", "N"},
    {"KV", "V"},
    {"SS", "O"},
    {"FC", "O"},
    {"NP", "B"},
    {"OH", "B"},
    {"OF", "K"},
    {"KB", "K"},
    {"BN", "C"},
    {"OK", "C"},
    {"NC", "O"},
    {"NO", "O"},
    {"FS", "C"},
    {"VP", "K"},
    {"KP", "S"},
    {"VS", "B"},
    {"VV", "N"},
    {"NN", "P"},
    {"KH", "P"},
    {"OB", "H"},
    {"HP", "H"},
    {"KK", "H"},
    {"FH", "F"},
    {"KS", "V"},
    {"BS", "V"},
    {"SN", "H"},
    {"CB", "B"},
    {"HN", "K"},
    {"SB", "O"},
    {"OS", "K"},
    {"BC", "H"},
    {"OV", "N"},
    {"PN", "B"},
    {"VH", "N"},
    {"SK", "C"},
    {"PV", "K"},
    {"VC", "N"},
    {"PF", "S"},
    {"NB", "B"},
    {"PP", "S"},
    {"NS", "F"},
    {"PB", "B"},
    {"CV", "C"},
    {"HK", "P"},
    {"PK", "S"},
    {"NH", "B"},
    {"SH", "V"},
    {"KO", "H"},
    {"NV", "B"},
    {"HH", "V"},
    {"FO", "O"},
    {"CK", "O"},
    {"VK", "F"},
    {"HF", "O"},
    {"BF", "C"},
    {"BV", "P"},
    {"KN", "K"},
    {"VF", "C"},
    {"FN", "V"},
    {"ON", "C"},
    {"SF", "F"},
    {"SC", "C"},
    {"OO", "S"},
    {"FP", "K"},
    {"PS", "C"},
    {"NK", "O"},
    {"BB", "V"},
    {"HC", "H"},
    {"FV", "V"},
    {"CH", "N"},
    {"HS", "V"},
    {"CF", "F"},
    {"CN", "S"}};

class problem
{
public:
    problem(const vector<pair<string, string>> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;
        for (auto elem : input)
        {
            if (0 != insertionrules[elem.first].length())
                cout << ":-o" << endl;
            insertionrules[elem.first] = elem.second;
        }
    }

    string expand(const string &seq)
    {
        string retval;

        for (size_t i = 1; i < seq.length(); ++i)
        {
            string sub = seq.substr(i - 1, 2);
            if (0 == retval.length())
                retval += sub.substr(0, 1) + insertionrules[sub] + sub.substr(1, 1);
            else
                retval += insertionrules[sub] + sub.substr(1, 1);
        }

        return retval;
    }

    int getresultA(string seq, int numofiterations)
    {
        for (int i = 0; i < numofiterations; ++i)
        {
            seq = expand(seq);
        }

        map<char, int> letters;

        for (auto elem : seq)
            ++letters[elem];

        size_t mincount = -1;
        size_t maxcount = 0;

        for (auto letter : letters)
        {
            if (letter.second > maxcount)
                maxcount = letter.second;
            else if (letter.second < mincount)
                mincount = letter.second;
        }

        return maxcount - mincount;
    }

    size_t getresultB(string seq, int numofiterations)
    {
        // make a map with the bigrams
        map<string,size_t> bigrams;

        // Init the map
        for (size_t i = 1; i < seq.length(); ++i)
            ++bigrams[seq.substr(i-1,2)];

        for (int i = 0; i < numofiterations; ++i)
        {
            map<string,size_t> oldbigrams(bigrams);
            bigrams.clear();
            
            for ( auto bigram : oldbigrams )
            {
                auto bigram1 = bigram.first;
                auto bigramA = bigram1.substr(0, 1) + insertionrules[bigram1];
                auto bigramB = insertionrules[bigram1] + bigram1.substr(1, 1);

                bigrams[bigramA] += bigram.second;
                bigrams[bigramB] += bigram.second;
            }
        }

        map<char, size_t> letters;
        letters[seq[0]] = 1;
        for (auto elem : bigrams)
        {
            letters[elem.first[1]] += elem.second;
        }

        size_t mincount = -1;
        size_t maxcount = 0;

        for (auto letter : letters)
        {
            if (letter.second > maxcount)
                maxcount = letter.second;
            else if (letter.second < mincount)
                mincount = letter.second;
        }

        return maxcount - mincount;
    }

private:
    const vector<pair<string, string>> input;
    map<string, string> insertionrules;
};

TEST_CASE("Testdata")
{
    problem testproblem(inputT);

    string result = "NNCB";

    result = testproblem.expand(result);
    REQUIRE("NCNBCHB" == result);
    result = testproblem.expand(result);
    REQUIRE("NBCCNBBBCBHCB" == result);
    result = testproblem.expand(result);
    REQUIRE("NBBBCNCCNBBNBNBBCHBHHBCHB" == result);
    result = testproblem.expand(result);
    REQUIRE("NBBNBNBBCCNBCNCCNBBNBBNBBBNBBNBBCBHCBHHNHCBBCBHCB" == result);
    result = testproblem.expand(result);
    REQUIRE(97 == result.length());

    REQUIRE(1588 == testproblem.getresultA("NNCB", 10));
    REQUIRE(1588 == testproblem.getresultB("NNCB", 10));
    REQUIRE(2188189693529 == testproblem.getresultB("NNCB", 40));
}

TEST_CASE("Problem")
{
    problem testproblem(inputA);
    REQUIRE(2587== testproblem.getresultB("VHCKBFOVCHHKOHBPNCKO", 10));
    size_t resultA = testproblem.getresultA("VHCKBFOVCHHKOHBPNCKO", 10);
    cout << "Result A: " << resultA << endl;
    REQUIRE(2587 == resultA);

    size_t resultB = testproblem.getresultB("VHCKBFOVCHHKOHBPNCKO", 40);
    cout << "Result B: " << resultB << endl;
    REQUIRE(3318837563123 == resultB);
}
