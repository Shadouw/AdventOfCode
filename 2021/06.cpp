#include <iostream>
#include <string>
#include <array>

using namespace std;

const short inputT[] = {3, 4, 3, 1, 2};

const short inputA[] = {4, 5, 3, 2, 3, 3, 2, 4, 2, 1, 2, 4, 5, 2, 2, 2, 4, 1, 1, 1, 5, 1, 1, 2, 5, 2, 1, 1, 4, 4, 5, 5, 1, 2, 1, 1, 5, 3, 5, 2, 4, 3, 2, 4, 5, 3, 2, 1, 4, 1, 3, 1, 2, 4, 1, 1, 4, 1, 4, 2, 5, 1, 4, 3, 5, 2, 4, 5, 4, 2, 2, 5, 1, 1, 2, 4, 1, 4, 4, 1, 1, 3, 1, 2, 3, 2, 5, 5, 1, 1, 5, 2, 4, 2, 2, 4, 1, 1, 1, 4, 2, 2, 3, 1, 2, 4, 5, 4, 5, 4, 2, 3, 1, 4, 1, 3, 1, 2, 3, 3, 2, 4, 3, 3, 3, 1, 4, 2, 3, 4, 2, 1, 5, 4, 2, 4, 4, 3, 2, 1, 5, 3, 1, 4, 1, 1, 5, 4, 2, 4, 2, 2, 4, 4, 4, 1, 4, 2, 4, 1, 1, 3, 5, 1, 5, 5, 1, 3, 2, 2, 3, 5, 3, 1, 1, 4, 4, 1, 3, 3, 3, 5, 1, 1, 2, 5, 5, 5, 2, 4, 1, 5, 1, 2, 1, 1, 1, 4, 3, 1, 5, 2, 3, 1, 3, 1, 4, 1, 3, 5, 4, 5, 1, 3, 4, 2, 1, 5, 1, 3, 4, 5, 5, 2, 1, 2, 1, 1, 1, 4, 3, 1, 4, 2, 3, 1, 3, 5, 1, 4, 5, 3, 1, 3, 3, 2, 2, 1, 5, 5, 4, 3, 2, 1, 5, 1, 3, 1, 3, 5, 1, 1, 2, 1, 1, 1, 5, 2, 1, 1, 3, 2, 1, 5, 5, 5, 1, 1, 5, 1, 4, 1, 5, 4, 2, 4, 5, 2, 4, 3, 2, 5, 4, 1, 1, 2, 4, 3, 2, 1};

auto &input = inputA;
auto sizeofinput = sizeof(input) / sizeof(input[0]);

void printfishes(const array<long, 9> &fishes)
{
    for (auto fish : fishes)
        cout << fish << " ";

    cout << endl;
}

void initfishes(array<long, 9> &fishes, const short input[], const int size)
{
    for (int i = 0; i < 9; ++i)
        fishes[i] = 0;

    for (int i = 0; i < size; ++i)
        ++fishes[input[i]];
}

array<long, 9> fishesnewday(array<long, 9> fishes)
{
    array<long, 9> retfishes;

    for (int i = 0; i < 9; ++i)
        retfishes[i] = fishes[i + 1];

    retfishes[6] += fishes[0];
    retfishes[8] = fishes[0];

    //printfishes ( retfishes );

    return retfishes;
}

long getnumoffishes(const array<long, 9> fishes)
{
    long retval = 0;

    for (auto fish : fishes)
        retval += fish;

    return retval;
}

int main(int, char **)
{

    int resultA = 0;
    unsigned long long resultB = 0;

    array<long, 9> fishes;
    initfishes(fishes, input, sizeofinput);

    printfishes(fishes);

    for (int i = 0; i < 80; ++i)
        fishes = fishesnewday(fishes);

    resultA = getnumoffishes(fishes);

    cout << "Result A: " << resultA << endl;

    // B
    initfishes(fishes, input, sizeofinput);

    for (int i = 0; i < 256; ++i)
    {
        fishes = fishesnewday(fishes);
    }

    resultB = getnumoffishes(fishes);

    cout << "Result B: " << resultB << endl;

    return 0;
}
