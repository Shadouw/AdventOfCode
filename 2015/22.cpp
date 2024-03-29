#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>

#include <catch2/catch_test_macros.hpp>

using namespace std;

struct spell
{
    string name;
    int costs, damage, heal, armor, mana, turns;
};
vector<spell> spells = {
    {"Magic Missile", 53, 4, 0, 0, 0, 0},
    {"Drain", 73, 2, 2, 0, 0, 0},
    {"Shield", 113, 0, 0, 7, 0, 6},
    {"Poison", 173, 3, 0, 0, 0, 6},
    {"Recharge", 229, 0, 0, 0, 101, 5}};

class problem
{
public:
    problem(int phit, int pmana, int bhit, int bdamage) : playerhit(phit), playermana(pmana), bosshit(bhit), bossdamage(bdamage)
    {
        //cout << "Size of Input: " << input.size() << endl;
    }

    void Spellturn()
    {
        for (auto &spellt : spelltimer)
        {
            if (0 != spellt.second)
            {
                --spellt.second;
                for (auto spell : spells)
                {
                    if (spellt.first == spell.name)
                    {
                        bosshit -= spell.damage;
                        playerhit += spell.heal;
                        playermana += spell.mana;
                        break;
                    }
                }
            }
        }
    }

    bool Playerturn(const string _spell)
    {
        for (auto spell : spells)
        {
            if (_spell == spell.name)
            {
                // Enough money?
                if (playermana < spell.costs)
                    return false;

                if (spell.turns > 0)
                {
                    // Add spelltimer
                    if (1 < spelltimer[_spell])
                    //if (0 != spelltimer[_spell])
                    {
                        // oh oh, spell still running
                        return false;
                    }
                    else
                    {
                        Spellturn();
                        spelltimer[spell.name] = spell.turns;
                    }
                }
                else
                {
                    Spellturn();
                    bosshit -= spell.damage;
                    playerhit += spell.heal;
                    playermana += spell.mana;
                }

                playermana -= spell.costs;
                return true;
            }
        }

        return false;
    }

    bool Bossturn()
    {
        Spellturn();

        if (bosshit <= 0)
        {
            // cout << "Boss is dead." << endl;
            return false;
        }

        playerhit -= max(bossdamage - getPlayerArmor(), 1);

        return true;
    }

    int getPlayerArmor()
    {
        int armor = 0;
        // Check active spells
        for (auto spellt : spelltimer)
        {
            if (spellt.second > 0)
            {
                for (auto spell : spells)
                {
                    if (spellt.first == spell.name)
                        armor += spell.armor;
                }
            }
        }
        return armor;
    }

    int checkWinner()
    {
        if (playerhit <= 0)
            return -1;
        if (bosshit <= 0)
            return 1;
        return 0;
    }

    int playerhit, playermana, bosshit, bossdamage;

    map<string, int> spelltimer;
};

int fight(problem currentfight, int spentmana, vector<string> listofspells, bool hardlevel)
{
    //cout << currentfight.playerhit << ":" << currentfight.bosshit << endl;
    static int totalspentmana = INT32_MAX;

    if (0 == spentmana) // New fight.
        totalspentmana = INT32_MAX;
    for (auto spell : spells)
    {
        problem loopcurrentfight(currentfight);
        vector<string> looplistofspells(listofspells);
        int loopspentmana = spentmana;

        if (hardlevel)
        {
            --loopcurrentfight.playerhit;
            if (0 >= loopcurrentfight.playerhit)
            {
                // Lost
                break;
            }
        }

        if (loopcurrentfight.Playerturn(spell.name))
        {
            loopspentmana += spell.costs;
            looplistofspells.push_back(spell.name);
            //cout << "  " << spell.name << endl;

            switch (loopcurrentfight.checkWinner())
            {
            case -1: // Fight lost
                break;
            case 1: // Fight won
                if (loopspentmana < totalspentmana)
                {
                    totalspentmana = loopspentmana;

                    /*
                    for (auto elem : listofspells)
                        cout << elem << " / ";
                    cout << endl;
                    */
                }
                break;
            default: // Still fighting
                loopcurrentfight.Bossturn();
                switch (loopcurrentfight.checkWinner())
                {
                case -1: // Fight lost
                    break;
                case 1: // Fight won
                    if (loopspentmana < totalspentmana)
                    {
                        totalspentmana = loopspentmana;

                        /*
                        for (auto elem : listofspells)
                            cout << elem << " ";
                        cout << endl;
                        */
                    }
                    break;
                default: // Still fighting
                    if (loopspentmana < totalspentmana)
                    {
                        fight(loopcurrentfight, loopspentmana, looplistofspells, hardlevel);
                    }
                    break;
                }
                break;
            }
        }
    }
    return totalspentmana;
}

TEST_CASE("Test1")
{
    problem testproblem(10, 250, 13, 8);

    /* Player turn */

    REQUIRE(10 == testproblem.playerhit);
    REQUIRE(0 == testproblem.getPlayerArmor());
    REQUIRE(250 == testproblem.playermana);
    REQUIRE(13 == testproblem.bosshit);

    REQUIRE(true == testproblem.Playerturn("Poison"));
    REQUIRE(0 == testproblem.checkWinner());

    /* Boss turn */

    REQUIRE(10 == testproblem.playerhit);
    REQUIRE(0 == testproblem.getPlayerArmor());
    REQUIRE(77 == testproblem.playermana);
    REQUIRE(13 == testproblem.bosshit);

    REQUIRE(true == testproblem.Bossturn());
    REQUIRE(0 == testproblem.checkWinner());

    /* Player turn */

    REQUIRE(2 == testproblem.playerhit);
    REQUIRE(0 == testproblem.getPlayerArmor());
    REQUIRE(77 == testproblem.playermana);
    REQUIRE(10 == testproblem.bosshit);

    REQUIRE(true == testproblem.Playerturn("Magic Missile"));
    REQUIRE(0 == testproblem.checkWinner());

    /* Boss turn */

    REQUIRE(2 == testproblem.playerhit);
    REQUIRE(0 == testproblem.getPlayerArmor());
    REQUIRE(24 == testproblem.playermana);
    REQUIRE(3 == testproblem.bosshit);

    REQUIRE(false == testproblem.Bossturn());
    REQUIRE(1 == testproblem.checkWinner());
}

TEST_CASE("Test2")
{
    problem testproblem(10, 250, 14, 8);

    /* Player turn */

    REQUIRE(10 == testproblem.playerhit);
    REQUIRE(0 == testproblem.getPlayerArmor());
    REQUIRE(250 == testproblem.playermana);
    REQUIRE(14 == testproblem.bosshit);

    REQUIRE(true == testproblem.Playerturn("Recharge"));
    REQUIRE(0 == testproblem.checkWinner());

    /* Boss turn */

    REQUIRE(10 == testproblem.playerhit);
    REQUIRE(0 == testproblem.getPlayerArmor());
    REQUIRE(21 == testproblem.playermana);
    REQUIRE(14 == testproblem.bosshit);

    REQUIRE(true == testproblem.Bossturn());
    REQUIRE(0 == testproblem.checkWinner());

    /* Player turn */

    REQUIRE(2 == testproblem.playerhit);
    REQUIRE(0 == testproblem.getPlayerArmor());
    REQUIRE(122 == testproblem.playermana);
    REQUIRE(14 == testproblem.bosshit);

    REQUIRE(true == testproblem.Playerturn("Shield"));
    REQUIRE(0 == testproblem.checkWinner());
    /* Boss turn */

    REQUIRE(2 == testproblem.playerhit);
    REQUIRE(7 == testproblem.getPlayerArmor());
    REQUIRE(110 == testproblem.playermana);
    REQUIRE(14 == testproblem.bosshit);

    REQUIRE(true == testproblem.Bossturn());
    REQUIRE(0 == testproblem.checkWinner());
    /* Player turn */

    REQUIRE(1 == testproblem.playerhit);
    REQUIRE(7 == testproblem.getPlayerArmor());
    REQUIRE(211 == testproblem.playermana);
    REQUIRE(14 == testproblem.bosshit);

    REQUIRE(true == testproblem.Playerturn("Drain"));
    REQUIRE(0 == testproblem.checkWinner());
    /* Boss turn */

    REQUIRE(3 == testproblem.playerhit);
    REQUIRE(7 == testproblem.getPlayerArmor());
    REQUIRE(239 == testproblem.playermana);
    REQUIRE(12 == testproblem.bosshit);

    REQUIRE(true == testproblem.Bossturn());
    REQUIRE(0 == testproblem.checkWinner());
    /* Player turn */

    REQUIRE(2 == testproblem.playerhit);
    REQUIRE(7 == testproblem.getPlayerArmor());
    REQUIRE(340 == testproblem.playermana);
    REQUIRE(12 == testproblem.bosshit);

    REQUIRE(true == testproblem.Playerturn("Poison"));
    REQUIRE(0 == testproblem.checkWinner());
    /* Boss turn */

    REQUIRE(2 == testproblem.playerhit);
    REQUIRE(7 == testproblem.getPlayerArmor());
    REQUIRE(167 == testproblem.playermana);
    REQUIRE(12 == testproblem.bosshit);

    REQUIRE(true == testproblem.Bossturn());
    REQUIRE(0 == testproblem.checkWinner());
    /* Player turn */

    REQUIRE(1 == testproblem.playerhit);
    REQUIRE(7 == testproblem.getPlayerArmor());
    REQUIRE(167 == testproblem.playermana);
    REQUIRE(9 == testproblem.bosshit);

    REQUIRE(true == testproblem.Playerturn("Magic Missile"));
    REQUIRE(0 == testproblem.checkWinner());
    /* Boss turn */

    REQUIRE(1 == testproblem.playerhit);
    REQUIRE(0 == testproblem.getPlayerArmor());
    REQUIRE(114 == testproblem.playermana);
    REQUIRE(2 == testproblem.bosshit);

    REQUIRE(false == testproblem.Bossturn());
    REQUIRE(1 == testproblem.checkWinner());
}

TEST_CASE("Testfight")
{
    problem testproblem(10, 250, 13, 8);
    REQUIRE(226 >= fight(testproblem, 0, vector<string>({}), false));
}

TEST_CASE("Testfight2")
{
    problem testproblem(10, 250, 14, 8);
    REQUIRE(641 == fight(testproblem, 0, vector<string>({}), false));
}

TEST_CASE("FightA")
{
    problem testproblem(50, 500, 55, 8);
    int resultA = fight(testproblem, 0, vector<string>({}), false);
    cout << "ResultA: " << resultA << endl;

    REQUIRE(953 == resultA);
}

TEST_CASE("FightB")
{
    problem testproblem(50, 500, 55, 8);
    int resultB = fight(testproblem, 0, vector<string>({}), true);
    cout << "ResultB: " << resultB << endl;

    REQUIRE(1289 == resultB);
}