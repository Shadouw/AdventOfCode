#include <iostream>
#include <string>
#include <vector>

#include <cstdio>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "Disc #1 has 5 positions; at time=0, it is at position 4.",
    "Disc #2 has 2 positions; at time=0, it is at position 1."};

const vector<string> inputData = {
    "Disc #1 has 13 positions; at time=0, it is at position 11.",
    "Disc #2 has 5 positions; at time=0, it is at position 0.",
    "Disc #3 has 17 positions; at time=0, it is at position 11.",
    "Disc #4 has 3 positions; at time=0, it is at position 0.",
    "Disc #5 has 7 positions; at time=0, it is at position 2.",
    "Disc #6 has 19 positions; at time=0, it is at position 17."};

class disc
{
public:
    disc(const string _input) : input(_input)
    {
        sscanf(input.c_str(), "Disc #%d has %d positions; at time=0, it is at position %d.", &discnumber, &positions, &pos0);
    }

    // This function returns if disc is free on time t 
    bool capsuleFalls(unsigned long t)
    {
        int currentposition = (pos0 + t) % positions;

        return (0 == currentposition);
    }

    // This function returns if disc is free on time t but includes the disc position
    bool getStartButton(unsigned long t)
    {
        return capsuleFalls(t+discnumber);
    }

    string getString() { return input; }

private:
    string input;
    int discnumber = 0, positions = 0, pos0 = 0;

    friend class TimingIsEverything;
};

class TimingIsEverything
{
public:
    TimingIsEverything(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input)
            discs.push_back(disc(elem));
    }

    void addDisc(string d)
    {
        discs.push_back(d);
    }

    unsigned long getStartButton()
    {
        unsigned long StartButton = 0;

        bool testing = true;
        while (testing)
        {
            testing = false;
            for ( auto  d : discs )
                if ( !d.getStartButton(StartButton) )
                    testing = true;
            
            if ( testing )
                ++StartButton;
        }

        cout << "StartButton: " << StartButton << endl;
        return StartButton;
    }

private:
    const vector<string> input;
    vector<disc> discs;
};

TEST_CASE("Testdata")
{
    TimingIsEverything TimingIsEverythingData(inputTestdata);
    REQUIRE(5 == TimingIsEverythingData.getStartButton());
}

TEST_CASE("TimingIsEverything")
{
    TimingIsEverything TimingIsEverythingData(inputData);
    REQUIRE(122318 == TimingIsEverythingData.getStartButton());
}

TEST_CASE("TimingIsEverythingB")
{
    TimingIsEverything TimingIsEverythingData(inputData);
    TimingIsEverythingData.addDisc("Disc #7 has 11 positions; at time=0, it is at position 0.");

    REQUIRE(3208583 == TimingIsEverythingData.getStartButton());
}