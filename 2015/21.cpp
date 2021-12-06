#include <iostream>
#include <string>

using namespace std;

const string Weapons[][4] = {
    {"Dagger", "8", "4", "0"},
    {"Shortsword", "10", "5", "0"},
    {"Warhammer", "25", "6", "0"},
    {"Longsword", "40", "7", "0"},
    {"Greataxe", "74", "8", "0"}};

const string Armor[][4] = {
    {"Leather", "13", "0", "1"},
    {"Chainmail", "31", "0", "2"},
    {"Splintmail", "53", "0", "3"},
    {"Bandedmail", "75", "0", "4"},
    {"Platemail", "102", "0", "5"}};

const string Rings[][4] = {
    {"Damage+1", "25", "1", "0"},
    {"Damage+2", "50", "2", "0"},
    {"Damage+3", "100", "3", "0"},
    {"Defense+1", "20", "0", "1"},
    {"Defense+2", "40", "0", "2"},
    {"Defense+3", "80", "0", "3"}};

const int numofWeapons = sizeof(Weapons) / sizeof(Weapons[0]);
const int numofArmor = sizeof(Armor) / sizeof(Armor[0]);
const int numofRings = sizeof(Rings) / sizeof(Rings[0]);

class fighter
{
public:
    fighter() : costs{0}, hitpoints{100}, damage{0}, armor{0} {};
    fighter(int h, int d, int a) : costs{0}, hitpoints{h}, damage{d}, armor{a} {};
    fighter(int w, int a, int r1, int r2) : costs{0}, hitpoints{100}, damage{0}, armor{0}
    {
        items += Weapons[w][0] + " ";
        costs += stoi(Weapons[w][1]);
        damage += stoi(Weapons[w][2]);

        if (-1 < a)
        {
            items += Armor[a][0] + " ";
            costs += stoi(Armor[a][1]);
            armor += stoi(Armor[a][3]);
        }

        if (-1 < r1)
        {
            items += Rings[r1][0] + " ";
            costs += stoi(Rings[r1][1]);
            damage += stoi(Rings[r1][2]);
            armor += stoi(Rings[r1][3]);
        }
        if (-1 < r2)
        {
            items += Rings[r2][0] + " ";
            costs += stoi(Rings[r2][1]);
            damage += stoi(Rings[r2][2]);
            armor += stoi(Rings[r2][3]);
        }
    };

    void print()
    {
        cout << items << costs << " h:" << hitpoints << " d:" << damage << " a:" << armor << endl;
    }

    string items;
    int costs;

    int hitpoints;
    int damage;
    int armor;
};

bool fight(fighter player, fighter boss)
{
    bool playerturn = true;

    while (true)
    {
        if (playerturn)
        {
            int damage = player.damage - boss.armor;
            boss.hitpoints -= damage;
            if (boss.hitpoints <= 0)
                return true;
        }
        else
        {
            int damage = boss.damage - player.armor;
            player.hitpoints -= damage;

            if (player.hitpoints <= 0)
                return false;
        }
        playerturn = !playerturn;
    }
}

int main(int, char **)
{
    int resultA = INT16_MAX;
    int resultB = 0;
    {
        fighter testme(8, 5, 5);
        fighter testboss(12, 7, 2);

        cout << "Fight: " << fight(testme, testboss) << endl;
    }

    fighter boss(103, 9, 2);
    boss.print();

    cout << "numofWeapons: " << numofWeapons << endl;
    cout << "numofArmor: " << numofArmor << endl;
    cout << "numofRings: " << numofRings << endl;

    for (int w = 0; w < numofWeapons; w++)
    {
        for (int a = -1; a < numofArmor; ++a)
        {
            for (int r1 = -1; r1 < numofRings; ++r1)
            {
                for (int r2 = -1; r2 < numofRings; ++r2)
                {
                    if (r1 != r2 || r1 == -1)
                    {
                        fighter me(w, a, r1, r2);
                        if (fight(me, boss))
                        {
                            if (me.costs < resultA)
                                resultA = me.costs;
                        }
                        else
                        {
                            if (me.costs > resultB)
                                resultB = me.costs;
                        }
                    }
                }
            }
        }
    }

    cout << "Result A: " << resultA << endl;
    cout << "Result B: " << resultB << endl;

    return 0;
}
