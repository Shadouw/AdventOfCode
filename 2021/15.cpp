#include <iostream>
#include <string>
#include <vector>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;

const vector<vector<uint32_t>> inputT = {
    {1, 1, 6, 3, 7, 5, 1, 7, 4, 2},
    {1, 3, 8, 1, 3, 7, 3, 6, 7, 2},
    {2, 1, 3, 6, 5, 1, 1, 3, 2, 8},
    {3, 6, 9, 4, 9, 3, 1, 5, 6, 9},
    {7, 4, 6, 3, 4, 1, 7, 1, 1, 1},
    {1, 3, 1, 9, 1, 2, 8, 1, 3, 7},
    {1, 3, 5, 9, 9, 1, 2, 4, 2, 1},
    {3, 1, 2, 5, 4, 2, 1, 6, 3, 9},
    {1, 2, 9, 3, 1, 3, 8, 5, 2, 1},
    {2, 3, 1, 1, 9, 4, 4, 5, 8, 1}};

const vector<vector<uint32_t>> inputA = {
    {8, 8, 9, 7, 9, 8, 9, 1, 5, 8, 7, 7, 3, 7, 6, 9, 9, 8, 6, 6, 8, 3, 3, 1, 7, 1, 2, 6, 9, 4, 9, 8, 9, 5, 8, 4, 4, 7, 8, 9, 8, 9, 8, 9, 1, 9, 9, 8, 8, 9, 8, 2, 8, 4, 6, 9, 7, 6, 8, 5, 4, 8, 8, 7, 6, 9, 8, 8, 5, 9, 7, 2, 1, 8, 7, 9, 9, 9, 7, 6, 8, 7, 9, 5, 5, 7, 1, 9, 1, 1, 1, 5, 9, 8, 9, 9, 8, 3, 2, 7},
    {9, 6, 4, 9, 3, 6, 9, 1, 1, 7, 5, 9, 9, 5, 9, 8, 1, 9, 7, 9, 3, 9, 4, 8, 2, 9, 9, 4, 9, 1, 9, 8, 7, 9, 9, 9, 8, 7, 5, 8, 8, 8, 4, 9, 4, 1, 9, 2, 5, 9, 9, 9, 9, 3, 7, 5, 8, 9, 2, 8, 3, 6, 3, 8, 7, 9, 9, 9, 9, 3, 4, 8, 4, 8, 7, 2, 9, 1, 7, 9, 9, 7, 8, 9, 7, 8, 9, 5, 7, 3, 9, 9, 8, 9, 5, 7, 9, 1, 9, 1},
    {7, 9, 9, 7, 3, 2, 9, 9, 8, 4, 9, 9, 7, 9, 9, 3, 9, 8, 3, 9, 9, 8, 6, 9, 2, 5, 5, 8, 6, 8, 3, 9, 9, 7, 8, 7, 4, 5, 4, 1, 9, 2, 2, 6, 9, 9, 3, 8, 9, 4, 2, 3, 7, 6, 3, 9, 4, 3, 1, 6, 9, 8, 7, 7, 2, 9, 6, 1, 2, 9, 7, 4, 1, 9, 9, 8, 9, 9, 9, 8, 8, 1, 9, 3, 9, 9, 9, 8, 2, 5, 6, 8, 5, 8, 9, 7, 1, 8, 9, 9},
    {3, 9, 6, 1, 9, 8, 3, 5, 7, 8, 8, 8, 9, 6, 8, 5, 9, 8, 7, 6, 9, 8, 8, 9, 9, 2, 7, 1, 9, 6, 4, 4, 2, 8, 5, 2, 9, 3, 6, 3, 9, 9, 8, 1, 8, 9, 6, 3, 9, 1, 4, 5, 3, 4, 8, 9, 7, 7, 9, 4, 9, 9, 4, 4, 5, 2, 4, 4, 5, 9, 5, 9, 3, 6, 4, 2, 2, 8, 5, 9, 9, 1, 7, 9, 8, 6, 8, 8, 2, 9, 9, 9, 9, 6, 7, 9, 4, 3, 8, 6},
    {9, 6, 3, 7, 6, 9, 4, 7, 9, 6, 7, 9, 2, 8, 4, 8, 6, 9, 8, 5, 8, 5, 4, 3, 6, 7, 6, 6, 6, 9, 3, 8, 7, 8, 1, 1, 6, 8, 1, 1, 5, 7, 4, 5, 4, 5, 9, 9, 6, 9, 1, 7, 9, 8, 8, 8, 4, 9, 6, 7, 8, 5, 5, 9, 8, 8, 9, 8, 7, 1, 3, 4, 5, 9, 6, 4, 7, 9, 6, 7, 7, 9, 6, 5, 7, 5, 6, 8, 6, 7, 6, 7, 8, 1, 9, 8, 6, 6, 7, 9},
    {7, 1, 6, 9, 7, 8, 8, 8, 7, 9, 7, 9, 1, 1, 9, 3, 2, 8, 7, 8, 6, 9, 5, 9, 6, 8, 2, 1, 7, 9, 5, 9, 9, 6, 8, 6, 8, 6, 2, 9, 8, 9, 2, 9, 6, 7, 9, 6, 9, 9, 9, 9, 9, 5, 1, 7, 1, 9, 9, 7, 3, 7, 5, 7, 9, 7, 8, 7, 9, 1, 8, 1, 5, 5, 8, 9, 7, 1, 7, 8, 2, 9, 3, 7, 9, 4, 6, 5, 2, 9, 8, 1, 7, 5, 5, 3, 1, 9, 9, 5},
    {8, 9, 1, 1, 7, 8, 7, 9, 4, 9, 4, 8, 8, 6, 3, 1, 7, 9, 9, 1, 9, 2, 2, 9, 7, 9, 1, 7, 3, 5, 1, 7, 9, 9, 9, 6, 3, 9, 8, 1, 9, 1, 2, 8, 8, 9, 7, 3, 5, 7, 9, 1, 8, 9, 1, 5, 4, 1, 8, 6, 9, 9, 9, 9, 4, 7, 2, 9, 9, 8, 4, 6, 4, 9, 9, 9, 6, 9, 1, 4, 8, 9, 6, 9, 8, 9, 8, 7, 8, 5, 9, 9, 2, 7, 8, 8, 9, 8, 9, 8},
    {4, 1, 2, 8, 9, 4, 8, 5, 9, 4, 1, 4, 3, 9, 7, 2, 3, 7, 5, 9, 9, 6, 7, 9, 8, 8, 8, 7, 3, 9, 9, 8, 9, 4, 7, 5, 2, 9, 9, 6, 9, 9, 6, 9, 8, 7, 9, 8, 8, 9, 7, 8, 9, 1, 8, 5, 7, 7, 2, 9, 8, 9, 6, 9, 7, 4, 4, 4, 6, 9, 4, 9, 6, 4, 6, 1, 5, 3, 7, 6, 7, 8, 9, 9, 6, 5, 7, 9, 5, 7, 9, 8, 8, 2, 5, 9, 5, 2, 1, 7},
    {5, 9, 6, 5, 8, 1, 7, 1, 1, 9, 7, 3, 5, 7, 9, 9, 9, 2, 7, 8, 8, 4, 8, 9, 6, 7, 8, 7, 8, 7, 6, 4, 8, 6, 3, 9, 3, 6, 9, 7, 7, 4, 2, 8, 9, 4, 6, 6, 8, 9, 8, 9, 9, 2, 9, 4, 8, 7, 1, 1, 7, 7, 6, 8, 3, 5, 9, 5, 6, 5, 3, 8, 8, 1, 8, 9, 5, 1, 8, 9, 7, 6, 7, 7, 7, 9, 1, 7, 5, 5, 9, 9, 9, 2, 1, 7, 2, 8, 4, 7},
    {2, 9, 8, 9, 8, 8, 5, 7, 7, 1, 1, 9, 9, 6, 2, 1, 1, 7, 9, 9, 5, 8, 1, 9, 9, 1, 1, 5, 6, 1, 2, 9, 1, 8, 6, 2, 4, 4, 8, 8, 1, 9, 6, 9, 3, 9, 3, 4, 9, 6, 7, 2, 4, 6, 4, 5, 7, 6, 9, 8, 9, 5, 5, 5, 8, 2, 5, 9, 9, 9, 7, 8, 8, 5, 9, 9, 8, 3, 7, 8, 7, 9, 4, 3, 8, 9, 3, 6, 6, 1, 1, 4, 4, 7, 9, 9, 9, 8, 3, 9},
    {6, 2, 7, 9, 8, 9, 7, 8, 2, 4, 9, 2, 5, 9, 3, 6, 9, 5, 6, 4, 9, 7, 3, 4, 2, 9, 3, 9, 3, 7, 8, 9, 2, 7, 5, 9, 7, 7, 7, 6, 8, 9, 8, 6, 7, 6, 8, 4, 3, 6, 9, 5, 6, 6, 9, 6, 5, 8, 9, 8, 9, 6, 7, 8, 8, 8, 1, 9, 9, 3, 7, 2, 5, 3, 5, 2, 5, 7, 9, 7, 9, 7, 5, 4, 8, 2, 2, 1, 8, 5, 8, 5, 4, 7, 7, 1, 5, 9, 4, 9},
    {5, 9, 8, 9, 2, 9, 6, 8, 9, 9, 7, 1, 4, 1, 8, 7, 6, 6, 3, 8, 9, 9, 1, 6, 6, 2, 9, 9, 6, 4, 3, 9, 9, 9, 5, 8, 8, 5, 9, 9, 1, 8, 9, 3, 2, 9, 5, 9, 6, 9, 9, 2, 7, 9, 1, 7, 6, 4, 9, 1, 9, 9, 8, 9, 7, 7, 9, 7, 9, 1, 9, 9, 9, 7, 9, 9, 2, 4, 5, 5, 9, 2, 5, 9, 9, 7, 9, 5, 5, 7, 7, 9, 9, 1, 7, 6, 9, 9, 8, 7},
    {9, 9, 6, 2, 6, 5, 5, 5, 8, 6, 3, 9, 7, 4, 5, 7, 6, 4, 4, 4, 8, 9, 8, 4, 9, 6, 9, 8, 9, 9, 6, 9, 3, 8, 7, 5, 8, 3, 3, 5, 4, 7, 9, 8, 4, 8, 9, 3, 9, 7, 8, 9, 6, 6, 6, 9, 9, 9, 1, 8, 7, 9, 1, 9, 9, 5, 6, 9, 8, 8, 5, 9, 4, 7, 6, 2, 9, 3, 9, 6, 1, 7, 8, 8, 3, 6, 6, 9, 8, 7, 9, 1, 4, 2, 6, 1, 5, 8, 7, 6},
    {1, 7, 7, 6, 5, 3, 5, 9, 5, 8, 8, 8, 8, 4, 8, 9, 9, 9, 9, 8, 6, 8, 8, 8, 9, 9, 3, 5, 8, 7, 6, 8, 9, 1, 9, 9, 5, 9, 1, 7, 8, 5, 8, 5, 7, 3, 8, 8, 8, 1, 4, 1, 9, 3, 2, 8, 9, 2, 8, 7, 1, 9, 2, 9, 7, 5, 9, 6, 8, 5, 6, 3, 3, 9, 9, 9, 9, 9, 8, 7, 8, 3, 5, 6, 5, 9, 9, 9, 6, 6, 4, 8, 9, 8, 4, 4, 5, 8, 9, 9},
    {1, 3, 8, 9, 5, 8, 8, 5, 3, 9, 8, 7, 9, 9, 9, 4, 9, 1, 8, 9, 6, 6, 6, 3, 9, 9, 7, 9, 2, 4, 8, 9, 2, 5, 1, 6, 4, 7, 6, 6, 8, 6, 1, 1, 1, 9, 9, 3, 2, 3, 9, 7, 8, 8, 4, 8, 3, 6, 7, 2, 8, 5, 7, 4, 9, 1, 4, 8, 8, 9, 6, 9, 8, 6, 7, 8, 7, 4, 8, 1, 5, 9, 7, 8, 6, 6, 6, 6, 5, 2, 6, 9, 7, 7, 9, 3, 7, 8, 7, 3},
    {2, 9, 6, 5, 9, 8, 7, 1, 9, 2, 8, 9, 9, 9, 7, 5, 7, 8, 1, 5, 7, 4, 9, 6, 7, 9, 9, 2, 7, 4, 4, 9, 9, 9, 9, 8, 9, 7, 8, 4, 9, 8, 1, 3, 4, 9, 6, 8, 9, 9, 9, 9, 2, 3, 1, 8, 8, 6, 8, 6, 4, 8, 6, 8, 5, 4, 8, 8, 2, 7, 8, 5, 9, 7, 7, 6, 4, 7, 8, 1, 2, 3, 7, 4, 4, 9, 7, 7, 9, 1, 1, 3, 9, 9, 7, 8, 9, 7, 8, 1},
    {2, 8, 6, 4, 8, 3, 8, 5, 7, 1, 8, 3, 9, 3, 8, 7, 5, 3, 7, 6, 6, 9, 6, 5, 1, 1, 7, 9, 7, 9, 1, 6, 4, 9, 9, 1, 7, 9, 7, 9, 9, 9, 4, 2, 9, 8, 8, 9, 1, 6, 8, 9, 8, 1, 5, 7, 3, 5, 2, 8, 9, 4, 5, 8, 7, 9, 9, 7, 8, 8, 1, 3, 8, 8, 9, 2, 1, 7, 6, 7, 9, 5, 9, 9, 9, 3, 7, 9, 9, 8, 6, 9, 7, 5, 9, 6, 5, 6, 3, 9},
    {9, 8, 4, 9, 9, 6, 4, 7, 4, 7, 7, 7, 2, 9, 9, 9, 9, 5, 5, 1, 5, 5, 2, 9, 1, 7, 9, 6, 9, 8, 5, 9, 9, 9, 6, 5, 6, 5, 3, 7, 9, 8, 9, 9, 9, 5, 9, 9, 3, 8, 5, 1, 8, 6, 9, 2, 8, 8, 8, 9, 8, 6, 8, 9, 9, 7, 4, 9, 8, 9, 8, 6, 8, 9, 4, 9, 6, 7, 9, 5, 3, 8, 9, 6, 1, 5, 5, 5, 9, 9, 7, 8, 1, 9, 9, 3, 9, 8, 8, 9},
    {4, 9, 9, 4, 7, 7, 3, 4, 5, 8, 1, 8, 6, 7, 9, 6, 3, 1, 6, 2, 5, 1, 9, 9, 8, 9, 9, 8, 8, 7, 8, 9, 2, 9, 1, 7, 1, 6, 8, 5, 8, 9, 7, 8, 1, 8, 6, 8, 5, 4, 7, 4, 9, 8, 9, 2, 6, 9, 9, 8, 8, 8, 9, 9, 9, 9, 5, 1, 3, 3, 1, 9, 6, 6, 1, 7, 7, 3, 8, 9, 5, 9, 5, 9, 9, 5, 9, 6, 8, 6, 5, 2, 3, 7, 4, 3, 9, 1, 9, 5},
    {5, 8, 9, 8, 9, 9, 4, 6, 8, 6, 6, 6, 6, 8, 8, 7, 8, 7, 8, 6, 9, 7, 9, 6, 9, 4, 9, 3, 7, 7, 2, 4, 7, 9, 3, 6, 8, 5, 4, 5, 9, 1, 1, 2, 8, 6, 5, 9, 5, 6, 8, 7, 9, 5, 6, 6, 5, 1, 9, 4, 5, 4, 9, 4, 8, 6, 8, 6, 7, 4, 9, 1, 9, 6, 7, 9, 8, 8, 5, 4, 7, 7, 7, 7, 8, 9, 6, 4, 9, 4, 4, 9, 4, 9, 6, 4, 8, 9, 9, 3},
    {2, 9, 6, 8, 9, 5, 8, 6, 1, 9, 9, 8, 6, 5, 5, 9, 9, 7, 8, 9, 7, 8, 7, 7, 8, 9, 7, 3, 8, 6, 7, 6, 4, 6, 9, 4, 9, 3, 8, 9, 8, 4, 9, 2, 3, 9, 8, 6, 5, 9, 2, 5, 9, 9, 1, 5, 1, 5, 9, 9, 7, 6, 7, 7, 9, 8, 9, 9, 4, 5, 6, 9, 4, 1, 8, 4, 5, 3, 7, 4, 6, 9, 9, 7, 8, 3, 4, 9, 8, 6, 8, 1, 9, 9, 9, 6, 6, 2, 5, 8},
    {9, 3, 9, 8, 8, 7, 6, 8, 4, 9, 7, 9, 5, 4, 6, 7, 9, 6, 8, 5, 4, 5, 4, 9, 4, 5, 4, 6, 5, 7, 8, 8, 1, 9, 7, 9, 6, 3, 7, 9, 8, 6, 9, 9, 1, 7, 1, 9, 9, 9, 4, 1, 6, 9, 7, 7, 6, 2, 2, 5, 3, 9, 9, 9, 8, 4, 2, 8, 8, 9, 8, 9, 3, 1, 8, 6, 4, 9, 3, 8, 3, 8, 7, 5, 5, 8, 3, 1, 6, 9, 5, 1, 9, 4, 7, 6, 9, 7, 7, 9},
    {6, 8, 3, 8, 9, 8, 5, 7, 6, 9, 8, 6, 9, 6, 9, 6, 9, 8, 3, 8, 9, 8, 9, 1, 7, 6, 4, 5, 9, 3, 8, 9, 9, 8, 1, 8, 4, 1, 9, 6, 8, 3, 4, 5, 9, 8, 3, 8, 8, 8, 9, 7, 5, 8, 8, 9, 4, 2, 9, 2, 3, 8, 5, 7, 9, 5, 9, 2, 8, 1, 9, 2, 8, 9, 7, 8, 9, 8, 2, 1, 9, 5, 4, 9, 9, 9, 8, 2, 7, 3, 9, 6, 9, 6, 2, 6, 6, 8, 8, 9},
    {3, 9, 8, 7, 6, 9, 3, 9, 5, 9, 9, 9, 7, 5, 9, 2, 7, 9, 9, 8, 8, 9, 5, 9, 9, 8, 2, 9, 9, 9, 7, 5, 8, 9, 8, 8, 9, 4, 2, 2, 9, 9, 1, 9, 7, 9, 9, 1, 6, 9, 7, 4, 7, 4, 6, 9, 6, 8, 7, 9, 1, 9, 7, 9, 4, 6, 4, 5, 6, 8, 3, 1, 2, 4, 3, 7, 8, 8, 5, 9, 7, 2, 8, 1, 6, 2, 5, 9, 8, 7, 9, 4, 1, 6, 5, 9, 9, 8, 1, 3},
    {5, 3, 8, 8, 5, 9, 1, 4, 7, 3, 4, 7, 7, 7, 9, 5, 9, 4, 9, 1, 7, 9, 8, 9, 9, 7, 9, 8, 5, 9, 4, 6, 4, 2, 3, 7, 6, 4, 9, 9, 9, 7, 9, 7, 4, 3, 8, 9, 5, 9, 6, 1, 1, 3, 9, 6, 7, 5, 5, 9, 9, 7, 2, 8, 5, 7, 2, 9, 7, 4, 3, 5, 6, 8, 7, 9, 5, 3, 6, 7, 4, 7, 9, 7, 7, 2, 8, 1, 9, 7, 5, 6, 9, 9, 3, 9, 5, 9, 3, 9},
    {8, 8, 2, 2, 9, 9, 5, 1, 9, 6, 9, 8, 7, 8, 9, 6, 4, 7, 8, 5, 9, 1, 7, 7, 7, 9, 8, 6, 7, 1, 8, 9, 7, 8, 9, 6, 6, 9, 3, 2, 9, 4, 9, 9, 8, 9, 7, 5, 3, 5, 8, 6, 9, 8, 6, 2, 2, 1, 9, 8, 7, 8, 4, 3, 6, 9, 3, 5, 6, 8, 6, 7, 7, 9, 8, 9, 6, 6, 6, 9, 9, 3, 5, 7, 8, 8, 8, 3, 7, 8, 8, 5, 5, 7, 5, 9, 4, 6, 9, 6},
    {9, 5, 9, 7, 2, 9, 8, 4, 8, 9, 9, 6, 9, 8, 9, 7, 1, 7, 5, 8, 8, 9, 6, 9, 6, 6, 9, 9, 8, 1, 8, 8, 9, 8, 7, 7, 8, 9, 6, 5, 9, 9, 9, 9, 5, 7, 4, 5, 2, 6, 9, 8, 7, 6, 2, 9, 9, 8, 4, 3, 7, 4, 9, 8, 9, 5, 9, 8, 9, 9, 7, 7, 6, 2, 4, 8, 9, 9, 7, 9, 7, 9, 9, 8, 9, 9, 9, 4, 6, 9, 6, 9, 8, 8, 7, 9, 5, 3, 9, 6},
    {7, 9, 9, 9, 1, 8, 7, 1, 5, 8, 9, 6, 7, 6, 8, 8, 9, 4, 4, 7, 5, 2, 9, 6, 7, 3, 8, 8, 3, 9, 9, 9, 7, 1, 9, 7, 5, 8, 5, 7, 9, 5, 8, 9, 9, 9, 9, 9, 2, 6, 8, 6, 4, 7, 9, 4, 8, 9, 9, 9, 7, 8, 9, 3, 9, 8, 9, 9, 9, 5, 9, 2, 9, 5, 9, 5, 4, 9, 9, 1, 9, 9, 4, 7, 7, 8, 9, 1, 9, 7, 2, 2, 6, 8, 4, 8, 4, 5, 2, 9},
    {1, 5, 5, 3, 4, 9, 8, 9, 8, 5, 4, 8, 9, 8, 6, 5, 9, 6, 7, 9, 2, 4, 9, 5, 8, 1, 1, 9, 4, 5, 8, 2, 9, 6, 8, 8, 3, 2, 3, 9, 4, 6, 3, 2, 7, 9, 6, 2, 4, 9, 3, 6, 4, 9, 8, 8, 7, 1, 6, 9, 9, 9, 6, 8, 9, 9, 7, 9, 7, 3, 8, 5, 7, 1, 7, 7, 7, 8, 4, 9, 7, 1, 9, 8, 7, 9, 3, 9, 9, 1, 5, 9, 9, 9, 4, 1, 4, 6, 7, 8},
    {8, 3, 9, 3, 2, 6, 9, 4, 4, 6, 3, 5, 7, 2, 8, 3, 2, 9, 9, 2, 5, 8, 6, 6, 1, 8, 8, 7, 8, 9, 9, 9, 3, 3, 9, 2, 9, 2, 7, 6, 7, 1, 9, 6, 8, 9, 4, 5, 9, 4, 7, 9, 6, 7, 7, 9, 8, 9, 9, 8, 2, 8, 6, 9, 9, 9, 1, 7, 9, 3, 9, 9, 7, 9, 9, 3, 3, 3, 8, 9, 6, 9, 9, 9, 4, 1, 6, 8, 3, 2, 9, 7, 9, 9, 4, 1, 9, 1, 8, 9},
    {7, 8, 8, 9, 9, 5, 9, 6, 2, 7, 6, 7, 9, 8, 9, 2, 7, 6, 5, 4, 9, 6, 7, 8, 6, 4, 7, 6, 9, 6, 9, 1, 4, 6, 9, 9, 9, 8, 9, 9, 6, 6, 6, 9, 5, 8, 8, 9, 6, 8, 8, 7, 7, 1, 5, 8, 1, 6, 7, 9, 7, 9, 1, 9, 3, 9, 1, 9, 5, 3, 3, 5, 8, 8, 9, 9, 8, 7, 7, 7, 7, 3, 8, 8, 2, 7, 4, 2, 8, 2, 9, 9, 8, 9, 7, 9, 7, 6, 4, 9},
    {9, 4, 6, 7, 8, 6, 8, 8, 2, 7, 8, 4, 9, 1, 5, 2, 7, 2, 3, 8, 9, 7, 1, 6, 9, 5, 5, 1, 8, 9, 6, 4, 2, 1, 1, 9, 8, 9, 8, 6, 8, 8, 9, 9, 9, 7, 3, 9, 7, 8, 9, 9, 5, 6, 3, 5, 8, 3, 9, 9, 7, 9, 9, 5, 9, 7, 1, 9, 1, 8, 8, 3, 9, 9, 9, 6, 5, 2, 6, 1, 3, 9, 3, 4, 2, 7, 4, 2, 6, 2, 7, 9, 6, 9, 1, 7, 8, 8, 3, 5},
    {4, 3, 7, 8, 9, 9, 2, 9, 6, 5, 7, 9, 7, 9, 4, 7, 9, 9, 1, 9, 3, 3, 9, 8, 8, 9, 2, 2, 9, 1, 1, 8, 8, 9, 4, 4, 9, 7, 9, 1, 6, 7, 9, 7, 8, 4, 9, 7, 9, 8, 2, 3, 6, 9, 8, 1, 9, 5, 9, 9, 6, 7, 8, 1, 2, 6, 9, 6, 4, 7, 8, 1, 5, 1, 6, 9, 6, 7, 1, 9, 1, 4, 7, 8, 7, 8, 9, 1, 9, 6, 7, 9, 8, 7, 5, 9, 7, 7, 9, 7},
    {7, 7, 6, 4, 4, 2, 7, 5, 8, 7, 7, 2, 9, 7, 7, 7, 9, 2, 4, 9, 8, 4, 1, 1, 8, 5, 1, 3, 3, 8, 5, 7, 7, 2, 4, 9, 7, 9, 9, 4, 5, 9, 8, 3, 9, 8, 3, 9, 9, 9, 9, 9, 5, 3, 5, 6, 8, 9, 9, 9, 7, 5, 9, 6, 4, 8, 7, 9, 8, 9, 4, 8, 8, 8, 7, 8, 3, 7, 9, 7, 7, 6, 8, 7, 9, 8, 9, 8, 2, 4, 1, 1, 9, 8, 1, 2, 6, 9, 8, 4},
    {9, 7, 2, 8, 8, 9, 5, 5, 7, 1, 7, 5, 9, 1, 9, 5, 2, 8, 4, 3, 8, 9, 8, 9, 9, 7, 9, 7, 6, 6, 9, 6, 7, 2, 6, 9, 9, 1, 9, 8, 8, 9, 8, 8, 2, 9, 9, 8, 9, 8, 9, 5, 7, 9, 5, 7, 1, 3, 6, 7, 8, 1, 9, 8, 7, 1, 6, 3, 1, 9, 8, 1, 8, 8, 9, 7, 8, 8, 5, 9, 7, 9, 9, 3, 8, 9, 6, 2, 9, 3, 9, 7, 4, 9, 7, 6, 1, 8, 9, 1},
    {6, 1, 8, 9, 7, 2, 7, 1, 6, 7, 8, 9, 7, 9, 1, 9, 8, 9, 6, 8, 4, 9, 7, 9, 8, 1, 2, 9, 9, 6, 5, 9, 9, 7, 2, 9, 4, 7, 6, 7, 9, 5, 3, 6, 9, 5, 1, 9, 8, 2, 3, 1, 8, 8, 7, 3, 9, 8, 3, 8, 6, 8, 1, 8, 1, 1, 8, 9, 8, 3, 6, 9, 9, 8, 6, 6, 5, 9, 9, 9, 3, 9, 8, 7, 2, 9, 8, 4, 5, 8, 5, 5, 9, 5, 6, 3, 9, 9, 5, 5},
    {9, 5, 9, 9, 6, 9, 5, 9, 5, 1, 7, 5, 5, 1, 6, 6, 9, 2, 6, 7, 2, 9, 2, 9, 9, 7, 7, 1, 9, 9, 4, 9, 1, 9, 2, 2, 4, 3, 9, 6, 7, 6, 9, 5, 9, 9, 6, 8, 7, 1, 1, 8, 4, 9, 6, 9, 8, 3, 3, 8, 7, 2, 8, 4, 9, 5, 6, 4, 1, 9, 8, 9, 6, 8, 5, 4, 9, 9, 8, 1, 5, 7, 9, 9, 2, 9, 1, 8, 4, 6, 3, 4, 8, 6, 9, 1, 9, 7, 8, 7},
    {9, 9, 1, 5, 6, 9, 8, 2, 9, 8, 7, 7, 2, 9, 8, 4, 8, 7, 7, 9, 4, 7, 5, 2, 7, 9, 8, 3, 2, 5, 7, 2, 6, 3, 8, 4, 9, 9, 4, 7, 1, 9, 8, 6, 9, 1, 7, 3, 6, 7, 3, 7, 8, 8, 4, 8, 1, 2, 8, 1, 9, 5, 6, 9, 9, 4, 9, 9, 4, 1, 5, 8, 9, 3, 7, 9, 9, 9, 9, 6, 6, 4, 9, 9, 9, 8, 2, 7, 3, 6, 9, 9, 6, 6, 6, 6, 6, 7, 2, 8},
    {9, 9, 3, 9, 5, 5, 7, 8, 8, 9, 7, 6, 8, 7, 1, 9, 8, 9, 4, 7, 2, 9, 4, 4, 9, 7, 9, 2, 2, 9, 8, 9, 9, 8, 9, 9, 4, 8, 8, 7, 8, 5, 7, 7, 1, 1, 8, 6, 6, 5, 9, 3, 9, 9, 1, 9, 8, 6, 3, 4, 9, 9, 3, 5, 2, 9, 9, 1, 6, 6, 9, 9, 9, 5, 9, 8, 9, 9, 1, 7, 7, 7, 9, 5, 8, 4, 9, 7, 8, 9, 9, 3, 9, 9, 8, 9, 9, 5, 7, 4},
    {9, 8, 1, 5, 6, 9, 9, 7, 2, 7, 6, 4, 9, 5, 2, 6, 9, 4, 9, 9, 5, 8, 9, 8, 8, 5, 9, 9, 9, 8, 8, 8, 7, 8, 3, 8, 8, 6, 9, 1, 7, 7, 8, 7, 6, 9, 9, 7, 9, 1, 2, 1, 6, 6, 5, 1, 8, 4, 9, 6, 7, 7, 3, 5, 5, 7, 9, 8, 9, 9, 8, 5, 8, 9, 2, 1, 9, 5, 8, 9, 5, 6, 7, 6, 4, 7, 9, 8, 3, 4, 8, 1, 7, 9, 9, 7, 9, 2, 9, 8},
    {8, 8, 9, 4, 9, 9, 7, 9, 4, 5, 9, 3, 5, 9, 5, 3, 2, 9, 8, 7, 5, 8, 8, 9, 9, 8, 9, 9, 8, 7, 3, 9, 3, 1, 9, 9, 2, 3, 6, 1, 4, 3, 9, 6, 5, 7, 5, 8, 9, 7, 4, 2, 7, 9, 7, 6, 9, 7, 5, 9, 8, 8, 3, 4, 6, 3, 3, 7, 1, 7, 5, 9, 2, 5, 5, 7, 1, 8, 6, 8, 9, 2, 6, 4, 8, 7, 6, 6, 5, 1, 4, 5, 1, 8, 3, 9, 2, 3, 7, 9},
    {7, 8, 8, 8, 9, 8, 4, 9, 5, 6, 7, 1, 8, 6, 7, 4, 6, 3, 9, 9, 7, 9, 3, 8, 3, 9, 9, 9, 9, 9, 1, 4, 4, 9, 6, 4, 8, 3, 8, 9, 6, 5, 9, 4, 7, 7, 3, 8, 9, 5, 9, 4, 9, 8, 7, 9, 9, 1, 2, 7, 3, 9, 6, 3, 9, 8, 8, 6, 9, 7, 9, 8, 3, 8, 6, 8, 4, 5, 6, 1, 4, 7, 6, 8, 8, 5, 8, 1, 3, 9, 2, 7, 9, 8, 8, 3, 9, 9, 4, 5},
    {6, 9, 1, 6, 7, 7, 8, 5, 9, 9, 1, 8, 9, 6, 8, 9, 5, 5, 7, 9, 8, 6, 5, 9, 2, 5, 9, 8, 8, 2, 1, 9, 5, 7, 8, 6, 6, 8, 6, 9, 8, 1, 9, 9, 9, 6, 8, 9, 3, 4, 2, 9, 4, 6, 4, 9, 7, 7, 9, 8, 7, 8, 8, 8, 4, 3, 9, 1, 1, 6, 2, 8, 9, 4, 5, 9, 6, 9, 9, 1, 7, 7, 7, 4, 8, 9, 1, 6, 9, 7, 1, 2, 7, 9, 3, 6, 8, 6, 5, 4},
    {9, 9, 7, 4, 1, 9, 9, 1, 6, 8, 4, 4, 9, 6, 1, 5, 6, 9, 3, 7, 7, 6, 3, 5, 9, 9, 2, 5, 8, 6, 9, 3, 6, 5, 8, 4, 1, 9, 7, 4, 2, 9, 4, 9, 8, 9, 6, 1, 3, 5, 2, 1, 7, 9, 9, 6, 4, 7, 4, 3, 8, 8, 9, 3, 7, 1, 9, 9, 4, 5, 9, 2, 3, 9, 7, 4, 2, 1, 1, 7, 7, 4, 9, 5, 8, 6, 4, 4, 9, 9, 6, 5, 8, 7, 9, 9, 7, 7, 1, 7},
    {7, 3, 9, 7, 9, 2, 9, 7, 6, 1, 6, 1, 8, 4, 1, 1, 6, 7, 9, 4, 1, 7, 3, 2, 9, 8, 5, 5, 6, 8, 8, 9, 1, 4, 9, 8, 6, 9, 5, 8, 9, 7, 8, 9, 5, 9, 6, 6, 9, 2, 9, 9, 8, 1, 5, 9, 7, 7, 9, 8, 2, 3, 9, 4, 7, 7, 9, 4, 6, 9, 5, 9, 5, 8, 9, 2, 1, 9, 7, 5, 7, 1, 2, 8, 8, 9, 7, 3, 5, 9, 9, 3, 7, 9, 7, 7, 2, 9, 8, 4},
    {3, 8, 7, 6, 9, 9, 9, 7, 2, 7, 5, 8, 4, 8, 8, 2, 1, 9, 8, 1, 9, 9, 1, 9, 5, 9, 8, 8, 8, 9, 3, 8, 8, 8, 9, 4, 9, 8, 9, 9, 7, 1, 8, 1, 7, 8, 2, 1, 9, 8, 9, 6, 1, 9, 9, 9, 1, 8, 9, 9, 9, 9, 9, 1, 9, 9, 9, 2, 9, 4, 9, 6, 9, 9, 9, 1, 7, 5, 9, 4, 8, 8, 1, 9, 9, 9, 7, 9, 1, 4, 8, 9, 8, 9, 4, 7, 9, 3, 8, 6},
    {7, 4, 8, 8, 9, 8, 8, 4, 7, 4, 9, 6, 9, 8, 8, 9, 4, 9, 5, 6, 1, 8, 8, 7, 8, 6, 9, 6, 7, 2, 5, 4, 5, 9, 7, 9, 7, 8, 4, 6, 5, 7, 2, 1, 9, 6, 8, 3, 6, 4, 7, 8, 5, 7, 4, 3, 7, 9, 7, 1, 3, 9, 7, 1, 7, 9, 9, 5, 9, 7, 9, 9, 9, 5, 9, 7, 8, 4, 5, 8, 7, 2, 1, 8, 9, 7, 8, 8, 9, 7, 8, 9, 9, 2, 1, 4, 9, 5, 6, 7},
    {9, 5, 5, 7, 9, 9, 9, 9, 7, 5, 9, 9, 7, 6, 9, 9, 4, 9, 7, 9, 2, 7, 6, 5, 8, 8, 4, 7, 9, 9, 1, 1, 9, 7, 1, 5, 6, 9, 5, 9, 9, 8, 7, 6, 9, 9, 5, 8, 8, 2, 6, 6, 8, 8, 6, 9, 2, 1, 9, 3, 8, 4, 4, 2, 8, 4, 7, 2, 5, 7, 1, 5, 9, 7, 9, 9, 9, 9, 9, 1, 9, 7, 9, 4, 9, 8, 9, 9, 8, 9, 8, 1, 5, 8, 9, 4, 7, 7, 1, 4},
    {5, 5, 9, 6, 8, 9, 8, 8, 7, 8, 8, 6, 3, 8, 3, 2, 8, 7, 1, 4, 1, 3, 5, 8, 1, 9, 8, 8, 7, 9, 9, 6, 8, 9, 4, 1, 9, 7, 7, 1, 9, 8, 2, 7, 8, 9, 7, 8, 9, 9, 9, 1, 8, 9, 8, 9, 7, 9, 8, 9, 8, 9, 9, 2, 5, 9, 9, 9, 5, 9, 9, 3, 6, 8, 6, 6, 9, 9, 9, 5, 9, 6, 2, 9, 9, 7, 4, 6, 6, 6, 1, 1, 9, 3, 9, 9, 8, 9, 7, 9},
    {9, 9, 2, 6, 8, 1, 9, 9, 7, 9, 3, 1, 5, 6, 9, 8, 2, 4, 1, 3, 9, 8, 9, 9, 4, 9, 9, 6, 9, 9, 9, 8, 8, 9, 8, 2, 1, 9, 8, 2, 7, 5, 9, 4, 6, 1, 7, 2, 3, 2, 8, 2, 1, 8, 7, 9, 3, 1, 9, 9, 3, 9, 7, 9, 9, 3, 6, 9, 7, 4, 7, 9, 6, 1, 9, 9, 3, 8, 2, 6, 1, 5, 5, 8, 5, 9, 9, 6, 9, 6, 9, 6, 4, 1, 9, 4, 7, 3, 8, 2},
    {1, 5, 4, 6, 8, 6, 8, 9, 1, 8, 6, 9, 4, 4, 7, 4, 7, 9, 6, 9, 9, 9, 1, 2, 9, 9, 4, 9, 7, 5, 1, 9, 8, 5, 8, 1, 9, 8, 1, 8, 9, 9, 9, 8, 8, 8, 7, 9, 4, 9, 9, 3, 9, 6, 7, 1, 2, 8, 2, 1, 5, 7, 8, 7, 8, 3, 9, 7, 2, 9, 8, 3, 9, 8, 4, 7, 7, 9, 9, 5, 3, 9, 8, 5, 5, 9, 8, 1, 8, 5, 6, 7, 1, 3, 2, 9, 7, 7, 9, 9},
    {4, 4, 9, 5, 4, 2, 7, 9, 8, 7, 9, 3, 6, 7, 1, 7, 5, 1, 6, 5, 6, 6, 7, 2, 2, 1, 4, 6, 6, 3, 9, 7, 3, 9, 6, 6, 7, 2, 6, 3, 9, 7, 9, 9, 8, 9, 4, 5, 8, 9, 8, 6, 9, 9, 4, 9, 9, 6, 8, 7, 9, 9, 2, 4, 4, 7, 3, 1, 6, 8, 7, 5, 8, 8, 7, 9, 7, 2, 7, 8, 9, 9, 8, 7, 9, 7, 7, 6, 7, 1, 8, 5, 4, 4, 5, 9, 3, 9, 6, 9},
    {2, 8, 9, 9, 6, 9, 9, 2, 3, 4, 8, 4, 4, 9, 8, 6, 3, 1, 4, 9, 7, 5, 2, 5, 4, 8, 8, 2, 3, 9, 9, 5, 8, 2, 9, 9, 6, 9, 3, 8, 9, 9, 7, 3, 8, 8, 6, 8, 4, 7, 1, 4, 2, 9, 5, 9, 9, 9, 9, 7, 1, 8, 7, 1, 9, 9, 9, 8, 8, 3, 3, 9, 7, 6, 2, 9, 8, 9, 7, 6, 1, 6, 8, 3, 8, 9, 9, 8, 3, 4, 1, 1, 5, 8, 2, 6, 6, 9, 1, 9},
    {2, 3, 2, 9, 8, 1, 8, 9, 7, 7, 5, 8, 6, 8, 8, 6, 7, 5, 2, 6, 4, 9, 9, 3, 4, 7, 2, 9, 5, 8, 8, 6, 3, 5, 5, 1, 9, 4, 4, 7, 7, 8, 7, 8, 8, 6, 8, 8, 9, 2, 9, 2, 3, 3, 8, 9, 9, 9, 7, 3, 6, 5, 7, 9, 9, 8, 8, 3, 9, 9, 1, 6, 6, 5, 7, 9, 6, 8, 2, 5, 1, 9, 7, 9, 8, 9, 8, 5, 6, 1, 9, 2, 1, 4, 3, 8, 7, 7, 8, 1},
    {9, 4, 9, 1, 2, 9, 9, 9, 8, 7, 9, 7, 8, 8, 9, 5, 5, 5, 9, 9, 5, 6, 9, 1, 9, 9, 8, 7, 3, 1, 9, 9, 7, 9, 9, 6, 8, 9, 1, 6, 2, 9, 9, 4, 7, 1, 3, 4, 7, 9, 8, 8, 5, 6, 8, 6, 7, 8, 5, 7, 1, 7, 8, 9, 4, 6, 9, 1, 8, 1, 8, 4, 5, 6, 4, 1, 8, 7, 9, 6, 2, 1, 5, 7, 4, 7, 4, 6, 7, 9, 9, 8, 5, 9, 7, 8, 9, 6, 2, 9},
    {3, 9, 9, 9, 7, 3, 6, 6, 3, 2, 5, 6, 9, 9, 4, 7, 1, 7, 6, 8, 1, 5, 9, 1, 9, 4, 9, 7, 5, 4, 6, 8, 9, 8, 9, 4, 9, 9, 7, 9, 9, 8, 6, 9, 5, 4, 8, 4, 1, 5, 9, 9, 5, 4, 1, 8, 9, 5, 8, 9, 9, 7, 5, 1, 7, 9, 3, 6, 9, 8, 8, 3, 5, 7, 3, 1, 8, 7, 7, 7, 4, 3, 1, 8, 6, 9, 8, 3, 9, 9, 6, 9, 8, 4, 2, 2, 4, 9, 8, 5},
    {3, 7, 4, 3, 3, 1, 3, 6, 8, 8, 5, 9, 7, 2, 6, 3, 2, 7, 9, 6, 8, 8, 8, 6, 6, 9, 8, 9, 2, 6, 9, 1, 9, 9, 8, 8, 6, 3, 2, 1, 9, 9, 5, 8, 6, 6, 9, 9, 5, 9, 9, 5, 5, 8, 9, 8, 5, 8, 7, 5, 9, 1, 8, 8, 6, 8, 8, 9, 9, 9, 1, 7, 6, 5, 8, 9, 9, 6, 7, 1, 8, 4, 9, 8, 9, 6, 8, 8, 9, 5, 7, 6, 7, 9, 5, 3, 9, 4, 9, 7},
    {9, 9, 7, 2, 9, 9, 8, 9, 8, 4, 9, 9, 7, 3, 6, 4, 7, 9, 6, 6, 1, 7, 4, 3, 7, 9, 4, 9, 1, 2, 6, 3, 9, 9, 6, 1, 9, 9, 9, 6, 3, 9, 2, 9, 7, 8, 4, 7, 8, 8, 9, 8, 3, 9, 8, 4, 6, 8, 9, 8, 6, 9, 2, 7, 4, 7, 8, 7, 5, 4, 9, 5, 8, 6, 9, 8, 9, 7, 8, 9, 8, 6, 6, 8, 9, 8, 9, 8, 9, 3, 7, 1, 9, 2, 3, 9, 9, 8, 5, 8},
    {8, 9, 9, 8, 7, 9, 3, 7, 8, 1, 6, 6, 8, 9, 6, 5, 9, 5, 9, 9, 3, 9, 7, 5, 3, 3, 9, 2, 8, 2, 8, 8, 9, 7, 9, 1, 8, 9, 3, 6, 5, 4, 2, 8, 9, 4, 3, 7, 1, 9, 3, 9, 6, 7, 7, 8, 8, 3, 6, 9, 2, 3, 2, 8, 7, 5, 4, 9, 9, 8, 2, 9, 3, 6, 2, 6, 1, 9, 2, 3, 2, 5, 8, 9, 8, 9, 9, 6, 5, 2, 6, 8, 9, 9, 6, 8, 7, 9, 9, 4},
    {3, 1, 5, 7, 9, 8, 8, 8, 8, 6, 1, 1, 5, 9, 8, 9, 8, 7, 1, 1, 5, 8, 9, 1, 8, 7, 8, 9, 7, 2, 5, 6, 8, 4, 9, 8, 3, 9, 6, 8, 8, 9, 9, 5, 9, 8, 7, 8, 8, 9, 3, 1, 4, 6, 7, 6, 5, 9, 6, 9, 8, 9, 4, 9, 8, 1, 7, 2, 7, 9, 6, 9, 9, 7, 9, 2, 9, 7, 9, 4, 9, 7, 8, 9, 9, 9, 8, 7, 7, 1, 4, 9, 9, 9, 7, 8, 8, 7, 6, 4},
    {8, 9, 9, 3, 8, 9, 2, 6, 9, 8, 3, 9, 9, 7, 9, 1, 1, 6, 9, 4, 3, 7, 1, 3, 8, 8, 9, 3, 4, 3, 3, 5, 4, 5, 8, 8, 9, 7, 9, 9, 1, 1, 9, 2, 4, 9, 7, 5, 8, 7, 4, 9, 7, 9, 1, 9, 8, 6, 9, 6, 2, 9, 2, 9, 8, 9, 6, 9, 1, 8, 6, 9, 6, 8, 9, 1, 7, 8, 7, 1, 5, 9, 7, 8, 9, 9, 7, 7, 7, 8, 5, 4, 1, 6, 9, 9, 9, 8, 5, 6},
    {5, 5, 2, 1, 4, 5, 9, 8, 1, 6, 8, 5, 3, 9, 9, 9, 7, 9, 6, 8, 8, 1, 7, 8, 4, 8, 9, 8, 6, 9, 6, 9, 5, 9, 7, 5, 1, 3, 3, 9, 9, 9, 6, 6, 1, 2, 9, 4, 6, 7, 8, 9, 9, 1, 1, 9, 7, 9, 8, 3, 6, 6, 6, 9, 9, 8, 6, 7, 3, 7, 2, 6, 9, 6, 8, 1, 1, 5, 1, 7, 7, 8, 2, 6, 9, 9, 7, 7, 2, 2, 1, 7, 3, 9, 4, 7, 9, 8, 1, 7},
    {4, 9, 8, 7, 6, 1, 9, 6, 6, 6, 7, 1, 4, 7, 9, 9, 9, 9, 8, 3, 7, 1, 8, 7, 1, 9, 7, 9, 2, 9, 9, 9, 9, 7, 8, 9, 9, 7, 9, 9, 9, 2, 8, 9, 9, 9, 5, 1, 2, 4, 3, 6, 6, 8, 2, 2, 9, 8, 4, 2, 8, 9, 7, 9, 9, 1, 9, 5, 7, 9, 7, 7, 9, 8, 6, 2, 9, 2, 9, 6, 7, 6, 9, 1, 7, 2, 9, 8, 9, 8, 9, 1, 2, 9, 9, 9, 5, 7, 9, 7},
    {4, 9, 2, 4, 7, 6, 1, 9, 2, 4, 7, 6, 5, 9, 8, 9, 7, 3, 1, 9, 7, 6, 6, 9, 7, 7, 9, 8, 3, 5, 9, 9, 9, 4, 9, 1, 9, 4, 4, 7, 9, 5, 8, 7, 4, 3, 7, 3, 9, 5, 7, 7, 5, 7, 9, 8, 9, 7, 6, 2, 9, 9, 8, 9, 9, 9, 6, 7, 9, 7, 3, 7, 7, 8, 8, 5, 9, 7, 3, 8, 5, 8, 3, 9, 1, 6, 6, 9, 8, 7, 7, 9, 1, 3, 7, 9, 2, 8, 9, 9},
    {9, 9, 8, 3, 5, 7, 2, 5, 9, 8, 6, 5, 9, 7, 6, 9, 9, 1, 8, 9, 8, 8, 8, 9, 6, 9, 5, 5, 3, 8, 7, 4, 8, 4, 7, 5, 7, 5, 8, 8, 2, 8, 5, 5, 8, 8, 9, 7, 6, 9, 6, 8, 1, 9, 1, 9, 7, 6, 3, 7, 9, 4, 1, 8, 8, 4, 8, 2, 4, 2, 6, 3, 9, 3, 9, 6, 1, 8, 9, 6, 6, 9, 9, 6, 1, 9, 8, 9, 5, 2, 8, 9, 6, 9, 9, 9, 8, 4, 8, 8},
    {4, 1, 1, 2, 1, 5, 4, 2, 9, 8, 9, 5, 9, 6, 9, 5, 7, 5, 8, 8, 8, 6, 3, 9, 8, 9, 7, 9, 1, 9, 4, 9, 8, 7, 9, 1, 1, 7, 3, 1, 9, 6, 8, 9, 9, 9, 5, 9, 8, 3, 4, 8, 9, 9, 5, 3, 4, 7, 7, 7, 9, 9, 9, 2, 7, 3, 7, 7, 1, 6, 9, 9, 1, 9, 9, 9, 4, 9, 4, 9, 8, 8, 8, 3, 4, 6, 7, 9, 8, 6, 1, 5, 9, 5, 1, 7, 5, 9, 9, 4},
    {8, 3, 5, 3, 7, 6, 9, 6, 1, 9, 9, 9, 1, 4, 9, 5, 4, 8, 1, 9, 6, 3, 9, 8, 8, 9, 6, 9, 8, 7, 5, 7, 1, 2, 9, 7, 1, 5, 8, 2, 7, 9, 7, 2, 7, 9, 4, 5, 9, 8, 7, 9, 7, 3, 1, 8, 4, 5, 4, 8, 2, 8, 1, 8, 8, 9, 8, 4, 1, 2, 8, 9, 7, 1, 9, 6, 9, 4, 7, 9, 5, 9, 5, 8, 6, 9, 9, 9, 3, 9, 7, 5, 7, 5, 8, 5, 6, 8, 3, 9},
    {9, 3, 8, 7, 8, 5, 9, 3, 4, 9, 2, 4, 9, 9, 9, 9, 1, 9, 5, 9, 9, 7, 3, 9, 9, 8, 2, 1, 8, 3, 6, 3, 9, 9, 5, 6, 8, 2, 1, 8, 9, 8, 2, 5, 7, 1, 7, 1, 9, 4, 3, 9, 9, 8, 1, 5, 5, 5, 9, 5, 8, 9, 8, 8, 5, 6, 8, 8, 7, 6, 7, 7, 9, 6, 4, 2, 1, 2, 4, 1, 8, 1, 9, 9, 9, 1, 9, 9, 6, 1, 9, 9, 2, 6, 6, 9, 8, 9, 5, 3},
    {9, 3, 9, 5, 9, 9, 7, 8, 6, 5, 2, 9, 8, 1, 9, 8, 3, 9, 5, 9, 4, 9, 8, 8, 8, 7, 8, 8, 4, 9, 7, 5, 3, 8, 7, 8, 5, 8, 9, 3, 3, 9, 9, 5, 6, 6, 9, 9, 4, 3, 2, 4, 8, 9, 9, 9, 8, 9, 9, 9, 9, 7, 8, 7, 4, 9, 8, 1, 9, 2, 9, 1, 7, 9, 6, 3, 9, 5, 7, 9, 2, 9, 9, 9, 9, 9, 9, 7, 8, 9, 7, 6, 7, 8, 3, 7, 8, 2, 4, 8},
    {6, 6, 3, 6, 9, 7, 3, 1, 9, 8, 9, 9, 9, 8, 9, 3, 9, 9, 3, 9, 7, 7, 1, 6, 9, 9, 9, 8, 5, 9, 8, 6, 9, 9, 4, 6, 5, 4, 2, 4, 9, 5, 6, 3, 2, 5, 4, 4, 8, 9, 9, 7, 6, 1, 9, 6, 9, 3, 8, 8, 9, 4, 6, 8, 8, 6, 4, 8, 7, 8, 2, 8, 5, 9, 9, 2, 9, 9, 5, 9, 9, 7, 6, 8, 1, 9, 9, 8, 7, 1, 8, 6, 6, 1, 5, 8, 9, 2, 9, 4},
    {1, 5, 3, 2, 7, 6, 6, 9, 9, 7, 9, 6, 8, 7, 3, 8, 5, 9, 3, 6, 9, 7, 1, 8, 9, 8, 4, 7, 9, 5, 5, 9, 5, 6, 9, 4, 5, 7, 9, 5, 4, 6, 3, 1, 7, 5, 1, 7, 4, 9, 9, 9, 9, 9, 1, 4, 7, 4, 7, 8, 9, 8, 9, 6, 3, 9, 3, 8, 8, 8, 6, 9, 3, 7, 1, 8, 9, 9, 4, 2, 9, 2, 6, 9, 3, 8, 9, 6, 9, 1, 9, 7, 5, 1, 8, 6, 9, 9, 7, 7},
    {4, 9, 8, 7, 9, 8, 4, 4, 2, 1, 6, 5, 8, 7, 9, 6, 9, 9, 9, 7, 5, 5, 5, 3, 7, 2, 6, 3, 8, 9, 9, 5, 3, 7, 9, 7, 9, 7, 7, 6, 2, 6, 9, 9, 5, 9, 2, 5, 9, 9, 9, 3, 8, 7, 7, 6, 8, 9, 2, 6, 1, 3, 3, 9, 9, 5, 8, 5, 9, 2, 2, 4, 8, 2, 7, 7, 4, 6, 9, 2, 9, 7, 9, 1, 5, 2, 8, 3, 4, 8, 7, 9, 3, 9, 8, 9, 9, 8, 9, 7},
    {1, 7, 7, 6, 3, 9, 8, 7, 3, 9, 7, 9, 1, 9, 9, 8, 7, 9, 6, 9, 7, 6, 3, 8, 7, 5, 8, 1, 9, 6, 9, 9, 7, 7, 8, 3, 9, 8, 9, 7, 5, 4, 9, 9, 9, 9, 1, 4, 9, 3, 9, 6, 8, 7, 6, 1, 9, 5, 3, 9, 8, 9, 2, 1, 5, 7, 4, 8, 1, 9, 8, 6, 4, 1, 5, 9, 7, 6, 8, 1, 2, 5, 9, 9, 9, 1, 7, 6, 9, 6, 6, 4, 2, 4, 6, 9, 4, 6, 7, 5},
    {6, 3, 8, 9, 6, 7, 1, 5, 9, 8, 4, 9, 8, 6, 9, 6, 9, 8, 8, 6, 6, 4, 8, 4, 8, 8, 4, 6, 6, 8, 8, 8, 9, 8, 9, 4, 8, 5, 5, 6, 9, 2, 1, 5, 9, 1, 7, 9, 9, 9, 5, 9, 6, 7, 6, 7, 8, 9, 2, 9, 9, 4, 8, 4, 1, 9, 6, 8, 5, 8, 5, 6, 5, 9, 7, 8, 9, 8, 5, 6, 1, 7, 6, 9, 9, 7, 1, 8, 9, 8, 8, 9, 6, 4, 8, 7, 4, 4, 3, 1},
    {7, 7, 1, 9, 5, 6, 7, 5, 6, 1, 9, 9, 1, 8, 9, 6, 9, 6, 4, 9, 9, 9, 2, 4, 7, 3, 6, 8, 1, 9, 1, 7, 4, 4, 7, 9, 6, 3, 7, 9, 4, 8, 9, 9, 8, 3, 5, 9, 1, 8, 7, 2, 8, 2, 9, 7, 1, 1, 9, 2, 7, 9, 5, 9, 9, 3, 2, 7, 6, 9, 6, 8, 8, 1, 9, 8, 9, 9, 8, 9, 9, 8, 9, 7, 4, 9, 1, 8, 5, 9, 1, 3, 9, 1, 9, 7, 1, 9, 5, 9},
    {3, 9, 7, 3, 9, 6, 9, 5, 5, 6, 5, 5, 9, 6, 8, 2, 5, 4, 7, 7, 3, 7, 9, 9, 4, 7, 6, 8, 9, 9, 9, 1, 9, 6, 7, 8, 9, 3, 9, 6, 9, 9, 8, 7, 1, 8, 9, 7, 1, 3, 5, 3, 8, 1, 4, 3, 9, 9, 5, 3, 4, 3, 7, 4, 9, 8, 9, 2, 9, 7, 9, 8, 8, 7, 8, 1, 2, 4, 3, 8, 9, 6, 2, 8, 9, 2, 9, 5, 6, 9, 8, 9, 2, 8, 8, 2, 8, 2, 8, 9},
    {7, 9, 9, 1, 9, 3, 8, 8, 2, 7, 7, 9, 8, 2, 5, 8, 9, 9, 8, 8, 8, 9, 6, 9, 8, 6, 6, 9, 2, 4, 9, 1, 4, 1, 2, 9, 6, 9, 9, 9, 7, 2, 7, 7, 6, 7, 8, 9, 5, 9, 4, 2, 7, 3, 6, 5, 8, 9, 7, 9, 4, 3, 6, 8, 6, 1, 9, 9, 4, 8, 6, 4, 7, 9, 7, 7, 7, 2, 1, 5, 6, 6, 8, 5, 6, 2, 5, 9, 8, 9, 1, 8, 3, 7, 9, 9, 2, 9, 9, 9},
    {9, 3, 4, 7, 4, 1, 9, 9, 9, 9, 8, 7, 9, 4, 9, 8, 8, 9, 3, 9, 8, 8, 8, 1, 2, 7, 1, 8, 4, 9, 1, 9, 8, 6, 8, 5, 9, 5, 6, 9, 7, 9, 7, 8, 2, 7, 9, 7, 1, 8, 9, 9, 9, 8, 8, 5, 1, 9, 9, 8, 8, 7, 9, 9, 4, 9, 9, 8, 9, 9, 9, 5, 9, 1, 9, 9, 8, 7, 4, 9, 2, 2, 4, 6, 9, 9, 4, 9, 1, 9, 7, 3, 9, 9, 8, 8, 7, 8, 6, 7},
    {5, 2, 8, 5, 6, 8, 5, 3, 9, 9, 5, 8, 9, 8, 1, 8, 5, 7, 7, 3, 2, 8, 7, 2, 8, 9, 9, 4, 8, 1, 6, 8, 5, 9, 9, 4, 4, 7, 7, 9, 4, 7, 9, 5, 4, 8, 4, 8, 6, 6, 1, 8, 8, 8, 5, 6, 3, 9, 2, 4, 8, 5, 8, 5, 1, 4, 3, 8, 9, 9, 2, 1, 8, 9, 9, 8, 9, 9, 1, 7, 4, 5, 9, 6, 6, 9, 6, 7, 5, 5, 6, 7, 4, 3, 7, 9, 9, 6, 6, 3},
    {9, 3, 9, 5, 8, 5, 4, 8, 9, 6, 9, 2, 7, 7, 9, 8, 1, 6, 1, 9, 7, 8, 6, 7, 9, 8, 9, 4, 1, 7, 2, 9, 9, 1, 3, 4, 1, 6, 3, 3, 5, 5, 8, 8, 6, 8, 9, 9, 7, 6, 8, 1, 8, 5, 4, 9, 9, 9, 1, 7, 8, 3, 9, 8, 9, 9, 6, 7, 4, 2, 7, 9, 8, 5, 5, 9, 8, 1, 8, 6, 1, 8, 8, 1, 3, 1, 6, 6, 5, 9, 7, 7, 7, 4, 9, 8, 9, 9, 8, 9},
    {6, 6, 3, 8, 7, 4, 4, 7, 9, 2, 5, 5, 7, 9, 7, 9, 4, 9, 8, 5, 9, 9, 8, 1, 8, 8, 4, 6, 1, 6, 8, 6, 9, 9, 9, 2, 1, 2, 5, 9, 9, 1, 9, 8, 7, 5, 7, 6, 9, 9, 6, 1, 6, 8, 7, 4, 4, 2, 9, 7, 9, 5, 1, 1, 2, 7, 7, 7, 5, 5, 5, 9, 2, 8, 6, 9, 1, 9, 9, 4, 4, 8, 6, 7, 1, 5, 9, 9, 8, 5, 9, 9, 3, 4, 5, 5, 5, 8, 1, 6},
    {7, 8, 5, 9, 8, 9, 9, 9, 9, 9, 5, 8, 1, 9, 8, 1, 9, 3, 8, 3, 9, 6, 9, 4, 9, 1, 8, 8, 7, 7, 8, 9, 1, 3, 6, 1, 8, 9, 3, 8, 9, 9, 9, 8, 9, 5, 9, 3, 9, 9, 4, 9, 9, 1, 4, 3, 5, 8, 9, 6, 4, 8, 3, 9, 2, 1, 9, 3, 9, 8, 7, 8, 9, 2, 3, 4, 4, 8, 8, 8, 2, 1, 9, 8, 1, 9, 6, 9, 9, 6, 5, 8, 7, 9, 5, 7, 1, 1, 9, 9},
    {5, 7, 6, 8, 2, 9, 8, 6, 8, 5, 5, 9, 1, 9, 9, 3, 9, 5, 6, 3, 9, 9, 6, 6, 9, 1, 9, 9, 4, 6, 9, 7, 1, 3, 9, 8, 8, 3, 8, 9, 4, 6, 9, 6, 5, 8, 9, 1, 6, 8, 5, 9, 4, 8, 1, 7, 1, 8, 6, 6, 5, 1, 5, 8, 8, 9, 7, 8, 8, 7, 5, 9, 3, 5, 1, 8, 9, 8, 6, 8, 7, 4, 8, 9, 7, 6, 6, 5, 7, 6, 3, 8, 9, 5, 4, 9, 6, 9, 7, 8},
    {7, 3, 8, 9, 9, 6, 7, 2, 8, 7, 9, 4, 5, 1, 7, 1, 6, 4, 9, 2, 2, 8, 4, 1, 1, 1, 8, 2, 1, 9, 9, 8, 7, 9, 9, 7, 7, 9, 9, 5, 4, 5, 7, 4, 9, 4, 9, 2, 7, 2, 9, 7, 2, 7, 8, 5, 5, 1, 6, 8, 7, 4, 6, 8, 4, 7, 9, 5, 5, 5, 2, 7, 3, 5, 9, 5, 1, 9, 1, 9, 5, 8, 7, 9, 8, 1, 9, 7, 8, 8, 8, 9, 7, 8, 5, 5, 2, 8, 1, 9},
    {1, 9, 8, 6, 9, 6, 8, 9, 9, 8, 7, 1, 9, 3, 9, 5, 2, 9, 9, 9, 7, 3, 6, 5, 9, 1, 1, 1, 8, 4, 9, 1, 9, 6, 9, 9, 6, 1, 4, 7, 9, 2, 7, 1, 9, 1, 8, 1, 7, 8, 7, 6, 6, 1, 8, 5, 4, 4, 7, 4, 9, 9, 4, 3, 9, 5, 8, 5, 9, 8, 5, 6, 9, 8, 8, 9, 3, 8, 1, 9, 8, 7, 8, 9, 7, 1, 2, 8, 8, 9, 8, 9, 4, 1, 8, 6, 7, 5, 1, 2},
    {9, 9, 2, 8, 4, 9, 9, 1, 9, 7, 4, 4, 4, 4, 9, 7, 9, 9, 9, 9, 7, 8, 9, 1, 4, 5, 1, 9, 9, 9, 9, 6, 5, 9, 1, 2, 7, 4, 5, 9, 9, 9, 2, 9, 7, 9, 2, 7, 5, 1, 9, 8, 8, 9, 2, 1, 5, 9, 1, 1, 3, 9, 3, 1, 9, 4, 9, 6, 9, 9, 9, 7, 9, 5, 1, 4, 8, 9, 7, 5, 8, 9, 2, 7, 7, 8, 6, 9, 5, 8, 2, 1, 7, 4, 8, 4, 9, 7, 9, 3},
    {4, 3, 4, 8, 7, 6, 2, 1, 9, 1, 9, 9, 9, 3, 6, 2, 9, 9, 6, 4, 8, 7, 9, 6, 9, 8, 5, 6, 3, 9, 9, 9, 6, 4, 9, 9, 4, 1, 9, 9, 7, 8, 8, 8, 8, 9, 9, 7, 5, 6, 5, 7, 7, 9, 1, 4, 3, 2, 7, 7, 7, 3, 7, 7, 1, 1, 9, 8, 8, 6, 9, 2, 5, 9, 9, 5, 6, 6, 9, 9, 8, 9, 4, 9, 9, 9, 7, 9, 4, 8, 9, 6, 2, 9, 7, 8, 2, 3, 8, 1},
    {9, 9, 8, 6, 6, 9, 4, 9, 9, 9, 8, 2, 4, 1, 8, 7, 6, 7, 9, 9, 2, 9, 4, 1, 8, 5, 5, 8, 5, 7, 8, 8, 9, 1, 1, 9, 9, 5, 6, 1, 9, 9, 9, 7, 8, 4, 4, 1, 9, 4, 6, 3, 5, 8, 7, 8, 1, 9, 5, 7, 2, 2, 9, 9, 6, 9, 8, 9, 9, 8, 1, 5, 9, 5, 5, 9, 9, 9, 7, 7, 9, 1, 8, 1, 5, 8, 9, 9, 5, 7, 4, 3, 1, 8, 6, 9, 5, 8, 8, 8},
    {1, 6, 9, 3, 3, 9, 1, 9, 1, 6, 9, 5, 7, 2, 1, 3, 9, 9, 2, 1, 9, 7, 9, 1, 5, 8, 1, 4, 2, 6, 7, 9, 4, 1, 9, 3, 9, 2, 6, 7, 6, 9, 9, 7, 8, 7, 9, 9, 8, 9, 9, 6, 3, 4, 9, 8, 5, 9, 8, 8, 7, 4, 2, 8, 3, 9, 6, 9, 9, 6, 9, 5, 2, 9, 5, 8, 9, 6, 6, 8, 9, 9, 3, 8, 9, 2, 6, 9, 7, 6, 9, 9, 9, 9, 7, 1, 8, 5, 8, 9},
    {8, 7, 9, 9, 2, 8, 5, 2, 9, 1, 9, 1, 7, 9, 9, 8, 1, 6, 8, 9, 3, 8, 6, 9, 4, 7, 8, 5, 2, 5, 8, 9, 7, 1, 2, 4, 9, 3, 5, 2, 8, 4, 6, 6, 6, 6, 7, 2, 3, 3, 9, 9, 5, 6, 4, 9, 6, 7, 8, 3, 1, 9, 8, 2, 7, 4, 6, 4, 4, 8, 3, 8, 7, 6, 7, 7, 9, 7, 4, 9, 3, 9, 9, 8, 9, 3, 9, 9, 3, 6, 6, 8, 9, 6, 8, 9, 4, 9, 8, 1},
    {9, 1, 9, 4, 4, 3, 3, 9, 1, 7, 4, 7, 7, 9, 9, 7, 1, 4, 9, 9, 6, 8, 3, 8, 8, 1, 9, 7, 8, 1, 8, 1, 4, 9, 6, 9, 9, 4, 7, 1, 3, 7, 9, 9, 9, 6, 2, 2, 9, 9, 9, 9, 1, 4, 9, 4, 4, 8, 7, 6, 9, 9, 9, 5, 3, 9, 7, 9, 7, 1, 4, 1, 6, 9, 6, 2, 8, 9, 5, 4, 1, 9, 9, 8, 4, 9, 9, 8, 1, 6, 5, 9, 5, 9, 9, 6, 9, 5, 8, 9},
    {9, 9, 9, 7, 9, 2, 5, 5, 8, 4, 4, 9, 9, 3, 9, 7, 9, 5, 7, 6, 6, 7, 1, 5, 7, 7, 1, 8, 1, 7, 8, 9, 8, 5, 5, 9, 9, 9, 5, 9, 6, 1, 5, 9, 6, 9, 5, 1, 6, 6, 9, 7, 3, 8, 9, 7, 7, 7, 7, 3, 9, 9, 6, 7, 2, 8, 5, 9, 9, 9, 4, 8, 5, 2, 9, 9, 8, 9, 9, 7, 8, 8, 3, 5, 9, 7, 8, 9, 8, 9, 5, 7, 7, 1, 7, 9, 9, 9, 2, 2},
    {3, 1, 6, 9, 8, 8, 7, 4, 9, 7, 2, 6, 7, 8, 6, 6, 9, 9, 7, 5, 1, 3, 7, 3, 7, 7, 9, 3, 7, 2, 7, 4, 3, 5, 8, 6, 9, 8, 2, 1, 9, 8, 9, 6, 9, 9, 9, 6, 5, 9, 6, 7, 6, 7, 8, 2, 5, 7, 4, 7, 3, 8, 2, 6, 9, 1, 9, 8, 7, 8, 2, 7, 9, 4, 5, 9, 7, 9, 6, 1, 3, 9, 8, 8, 3, 8, 5, 6, 5, 8, 7, 9, 4, 1, 6, 8, 9, 7, 1, 7},
    {2, 2, 6, 2, 5, 9, 6, 4, 3, 9, 8, 4, 8, 1, 9, 9, 8, 9, 8, 7, 3, 2, 9, 5, 7, 6, 9, 8, 5, 8, 7, 5, 7, 9, 9, 1, 9, 1, 5, 9, 9, 4, 7, 9, 2, 7, 8, 3, 9, 6, 8, 2, 9, 7, 9, 9, 9, 8, 9, 7, 9, 4, 9, 8, 9, 1, 8, 9, 9, 9, 9, 8, 5, 4, 6, 8, 8, 6, 9, 5, 1, 9, 7, 9, 9, 8, 8, 8, 9, 7, 4, 8, 8, 6, 8, 9, 4, 6, 9, 9},
    {9, 2, 9, 9, 8, 1, 3, 4, 7, 8, 8, 7, 1, 6, 2, 8, 6, 7, 8, 8, 2, 9, 9, 9, 9, 8, 8, 6, 9, 9, 3, 4, 6, 9, 9, 3, 9, 6, 5, 4, 8, 6, 8, 1, 2, 1, 6, 7, 3, 6, 9, 9, 8, 9, 9, 7, 9, 8, 7, 3, 7, 3, 1, 9, 6, 9, 7, 8, 7, 8, 8, 9, 5, 9, 9, 7, 4, 8, 8, 9, 1, 7, 9, 6, 2, 1, 3, 9, 1, 9, 9, 7, 5, 9, 1, 8, 4, 6, 4, 2},
    {6, 8, 9, 2, 9, 8, 7, 4, 9, 2, 1, 3, 8, 2, 5, 3, 3, 9, 9, 6, 9, 8, 1, 6, 7, 9, 2, 7, 7, 7, 7, 7, 8, 2, 8, 9, 6, 7, 8, 9, 9, 1, 8, 9, 9, 8, 9, 1, 2, 9, 7, 9, 5, 6, 3, 6, 6, 3, 3, 8, 1, 9, 2, 6, 8, 9, 9, 9, 8, 1, 9, 9, 8, 8, 9, 8, 1, 2, 6, 9, 7, 9, 8, 9, 4, 7, 6, 7, 1, 9, 5, 7, 1, 4, 9, 8, 3, 1, 7, 9},
    {9, 8, 4, 9, 1, 6, 3, 8, 9, 5, 4, 9, 9, 9, 4, 6, 3, 9, 4, 7, 8, 8, 8, 1, 5, 9, 7, 7, 8, 1, 9, 8, 3, 4, 7, 9, 9, 3, 6, 9, 8, 6, 4, 9, 7, 8, 6, 6, 8, 5, 8, 1, 5, 9, 3, 3, 4, 7, 3, 6, 7, 8, 9, 4, 1, 9, 9, 7, 8, 6, 9, 1, 3, 2, 7, 8, 6, 9, 8, 3, 9, 1, 9, 8, 4, 8, 8, 7, 3, 5, 8, 7, 8, 9, 3, 9, 8, 9, 5, 9},
    {8, 1, 7, 2, 7, 9, 1, 1, 9, 8, 9, 3, 9, 8, 9, 9, 1, 6, 9, 9, 9, 8, 7, 5, 1, 1, 9, 7, 6, 1, 7, 8, 8, 7, 5, 9, 8, 9, 5, 9, 9, 7, 1, 6, 8, 3, 6, 8, 8, 9, 5, 5, 9, 4, 9, 6, 9, 9, 2, 1, 4, 3, 4, 9, 8, 9, 7, 8, 9, 4, 8, 7, 9, 8, 9, 6, 8, 9, 4, 9, 7, 9, 1, 3, 2, 2, 7, 2, 8, 4, 2, 9, 7, 6, 3, 3, 4, 2, 9, 9},
    {7, 3, 5, 5, 7, 5, 1, 2, 7, 4, 7, 8, 6, 5, 2, 8, 9, 6, 9, 7, 9, 5, 8, 9, 3, 5, 5, 9, 8, 7, 7, 7, 9, 9, 8, 9, 9, 9, 1, 9, 9, 1, 6, 3, 7, 5, 1, 9, 9, 8, 4, 2, 9, 6, 6, 1, 6, 3, 7, 1, 8, 8, 9, 3, 9, 9, 3, 8, 9, 3, 8, 9, 7, 7, 3, 9, 9, 4, 7, 6, 9, 8, 9, 8, 1, 1, 1, 3, 9, 8, 6, 6, 9, 5, 1, 9, 6, 9, 1, 8},
    {6, 2, 3, 7, 2, 9, 9, 1, 9, 6, 7, 9, 7, 8, 9, 5, 1, 9, 9, 5, 1, 4, 9, 4, 9, 6, 7, 8, 9, 8, 2, 9, 5, 9, 6, 9, 1, 4, 9, 7, 5, 7, 9, 8, 9, 1, 7, 3, 5, 6, 4, 5, 6, 9, 7, 9, 9, 2, 1, 9, 7, 4, 9, 8, 8, 7, 7, 4, 4, 9, 2, 7, 4, 9, 9, 9, 6, 8, 3, 8, 8, 7, 6, 7, 6, 5, 8, 1, 9, 6, 6, 5, 7, 9, 3, 1, 7, 6, 7, 9}};

class problem
{
public:
    problem(const vector<vector<uint32_t>> &_input, int scale) : originalinput(_input),
                                                                 xsize(_input[0].size() * scale), ysize(_input.size() * scale),
                                                                 input(ysize, std::vector<uint32_t>(xsize))
    {
        cout << "Size of Input: " << input.size() << endl;

        uint32_t originalxsize = _input[0].size(), originalysize = _input.size();

        for (int y = 0; y < ysize; ++y)
        {
            for (int x = 0; x < xsize; ++x)
            {
                input[y][x] = originalinput[y % originalysize][x % originalxsize] + (y / originalysize) + (x / originalxsize);

                while (9 < input[y][x])
                    input[y][x] -= 9;
            }
        }
        /*
        if (5 == scale)
            for (int y = 0; y < ysize; ++y)
            {
                for (int x = 0; x < xsize; ++x)
                {
                    cout << input[y][x];
                }
                cout << endl;
            }
        */
    }

    uint32_t getRisk()
    {
        vector<vector<uint32_t>> RiskMatrix(ysize, std::vector<uint32_t>(xsize));

        RiskMatrix[0][0] = 0; //input[0][0];

        // Set border of RiskMatrix
        for (size_t y = 1; y < ysize; ++y)
            RiskMatrix[y][0] = RiskMatrix[y - 1][0] + input[y][0];

        for (size_t x = 1; x < xsize; ++x)
            RiskMatrix[0][x] = RiskMatrix[0][x - 1] + input[0][x];

        // Now calculate the RiskMatrix
        for (size_t y = 1; y < ysize; ++y)
        {
            for (size_t x = 1; x < xsize; ++x)
            {
                uint32_t distmin = RiskMatrix[y - 1][x];
                if (RiskMatrix[y][x - 1] < distmin)
                    distmin = RiskMatrix[y][x - 1];

                RiskMatrix[y][x] = distmin + input[y][x];
            }
        }

        bool foundoptimization = true;
        while (foundoptimization)
        {
            foundoptimization = false;

            for (size_t y = 0; y < ysize; ++y)
            {
                for (size_t x = 0; x < xsize; ++x)
                {
                    uint32_t distmin = -1;

                    if (0 < y)
                        distmin = RiskMatrix[y - 1][x];

                    if (0 < x)
                        if (RiskMatrix[y][x - 1] < distmin)
                            distmin = RiskMatrix[y][x - 1];

                    if (ysize - 1 > y)
                        if (RiskMatrix[y + 1][x] < distmin)
                            distmin = RiskMatrix[y + 1][x];

                    if (xsize - 1 > x)
                        if (RiskMatrix[y][x + 1] < distmin)
                            distmin = RiskMatrix[y][x + 1];

                    if (RiskMatrix[y][x] > distmin + input[y][x])
                    {
                        foundoptimization = true;
                        RiskMatrix[y][x] = distmin + input[y][x];
                    }
                }
            }
        }

        return RiskMatrix[ysize - 1][xsize - 1];
    }

private:
    const vector<vector<uint32_t>> originalinput;
    const uint32_t xsize;
    const uint32_t ysize;
    int resultA = 0;
    int resultB = 0;
    vector<vector<uint32_t>> input;
};

TEST_CASE("Testdata")
{
    problem testproblem(inputT, 1);
    REQUIRE(40 == testproblem.getRisk());
}

TEST_CASE("Testdata5")
{
    problem testproblem(inputT, 5);
    REQUIRE(315 == testproblem.getRisk());
}

TEST_CASE("Problem A")
{
    problem testproblem(inputA, 1);

    uint32_t result = testproblem.getRisk();
    cout << "Result A: " << result << endl;
    REQUIRE(811 == result);
}

TEST_CASE("Problem B")
{
    problem testproblem(inputA, 5);

    uint32_t result = testproblem.getRisk();
    cout << "Result B: " << result << endl;
    REQUIRE(3012 == result);
}