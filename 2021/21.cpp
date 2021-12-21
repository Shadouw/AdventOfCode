#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <math.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;

class DiracDice
{
public:
    DiracDice(uint16_t player1start, uint16_t player2start) : player{player1start, player2start}
    {
    }

    uint16_t getDice()
    {
        if (diracdice > 100)
            diracdice = 1;

        ++rolltime;

        return diracdice++;
    }

    void printGame()
    {
        cout << "Player1 [" << player[0] << "]: " << scores[0] << "   ";
        cout << "Player2 [" << player[1] << "]: " << scores[1] << "   ";
        cout << "Rolled: " << rolltime << "   ";
        cout << endl;
    }

    bool playdirac()
    {
        uint32_t dice = getDice() + getDice() + getDice();

        player[activeplayer] += dice;
        while (player[activeplayer] > 10)
            player[activeplayer] -= 10;

        scores[activeplayer] += player[activeplayer];

        bool won = (scores[activeplayer] >= 1000);

        activeplayer++;
        activeplayer %= 2;

        return won;
    }

    /*
     * 0 no winner
     * 1,2 winner
     */
    uint16_t playquantum(int dice)
    {
        int retval = 0;
        player[activeplayer] += dice;
        while (player[activeplayer] > 10)
            player[activeplayer] -= 10;

        scores[activeplayer] += player[activeplayer];

        if (scores[activeplayer] >= 21)
            retval = activeplayer + 1;

        activeplayer++;
        activeplayer %= 2;

        return retval;
    }

    uint32_t getResultA()
    {
        //cout << "getResultA: " << min(scores[0], scores[1]) << "*" << rolltime << endl;
        return rolltime * min(scores[0], scores[1]);
    }

    friend bool operator<(const DiracDice &l, const DiracDice &r)
    {
        return std::tie(l.player[0], l.player[1], l.scores[0], l.scores[1], l.activeplayer, l.rolltime) < std::tie(r.player[0], r.player[1], r.scores[0], r.scores[1], r.activeplayer, r.rolltime); // keep the same order
    }

private:
    uint16_t player[2] = {0, 0};
    uint16_t scores[2] = {0, 0};
    uint16_t diracdice = 1;
    uint16_t activeplayer = 0;
    uint16_t rolltime = 0;
};

map<DiracDice, uint64_t> universes;

TEST_CASE("Testdata A")
{
    DiracDice testDiracDice(4, 8);

    while (!testDiracDice.playdirac()) {}
        testDiracDice.printGame();

    REQUIRE(739785 == testDiracDice.getResultA());
}

TEST_CASE("Testdata B")
{
    universes[DiracDice(4, 8)] = 1;

    uint64_t won1 = 0, won2 = 0;
    while (universes.size())
    {
        // Make a copy
        map<DiracDice, uint64_t> olduniverses(universes);
        universes.clear();

        for (auto universe : olduniverses)
        {
            for (int d1 = 1; d1 <= 3; ++d1)
            {
                for (int d2 = 1; d2 <= 3; ++d2)
                {
                    for (int d3 = 1; d3 <= 3; ++d3)
                    {
                        DiracDice currentuniverse(universe.first);
                        int winner = currentuniverse.playquantum(d1 + d2 + d3);

                        switch (winner)
                        {
                        case 0:
                            universes[currentuniverse] += universe.second;
                            break;
                        case 1:
                            won1 += universe.second;
                            break;
                        case 2:
                            won2 += universe.second;
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << "Won 1: " << won1 << endl;
    cout << "Won 2: " << won2 << endl;

    REQUIRE(444356092776315 == won1);
    REQUIRE(341960390180808 == won2);
}

TEST_CASE("Problem A")
{
    DiracDice testDiracDice(5, 8);

    while (!testDiracDice.playdirac()) {}
        testDiracDice.printGame();

    uint32_t resultA = testDiracDice.getResultA();
    cout << "Result A: " << resultA << endl;
    REQUIRE(1067724 == resultA);
}


TEST_CASE("Problem B")
{
    universes[DiracDice(5, 8)] = 1;

    uint64_t won1 = 0, won2 = 0;
    while (universes.size())
    {
        // Make a copy
        map<DiracDice, uint64_t> olduniverses(universes);
        universes.clear();

        for (auto universe : olduniverses)
        {
            for (int d1 = 1; d1 <= 3; ++d1)
            {
                for (int d2 = 1; d2 <= 3; ++d2)
                {
                    for (int d3 = 1; d3 <= 3; ++d3)
                    {
                        DiracDice currentuniverse(universe.first);
                        int winner = currentuniverse.playquantum(d1 + d2 + d3);

                        switch (winner)
                        {
                        case 0:
                            universes[currentuniverse] += universe.second;
                            break;
                        case 1:
                            won1 += universe.second;
                            break;
                        case 2:
                            won2 += universe.second;
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << "Won 1: " << won1 << endl;
    cout << "Won 2: " << won2 << endl;

    uint64_t resultB = max(won1, won2);
    cout << "Result B: " << resultB << endl;
    REQUIRE(630947104784464 == resultB);
}