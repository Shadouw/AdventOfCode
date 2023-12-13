#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "#.##..##.",
    "..#.##.#.",
    "##......#",
    "##......#",
    "..#.##.#.",
    "..##..##.",
    "#.#.##.#.",
    "",
    "#...##..#",
    "#....#..#",
    "..##..###",
    "#####.##.",
    "#####.##.",
    "..##..###",
    "#....#..#"
};

const vector<string> inputData = {
    "#..#...#.#..#",
    "#..#####.####",
    "#..######....",
    ".##...####.#.",
    ".##.##.#.####",
    "#..#.###.##.#",
    ".....###.#.#.",
    ".##..##..##..",
    "....#.#####..",
    "....###..##.#",
    "....####.##.#",
    "",
    "..#.#......#.",
    "###.#.####.#.",
    "##.##.#..#.##",
    "##..#.####.#.",
    "...###.##.###",
    "###.##.##.##.",
    "###..##..#...",
    "###..##..##..",
    "####.#.##.#.#",
    "",
    ".#.####.#.#",
    "...####....",
    "....##....#",
    ".#.####.#.#",
    ".#..##..#.#",
    "##......#.#",
    ".#..##..#.#",
    "####..####.",
    ".########..",
    ".#..##..#.#",
    "..######..#",
    "##.####.###",
    "##.####.###",
    "",
    ".##.##.",
    "#...##.",
    ".######",
    "#..#..#",
    "#..#..#",
    ".######",
    "#...##.",
    ".##.##.",
    ".#..#..",
    ".#.....",
    "##.....",
    "#.#####",
    "#..####",
    "##.#..#",
    "#.#####",
    "",
    "###....#####.",
    ".########.##.",
    "#.#.#..#.##..",
    "..######...#.",
    "#.##..##.##.#",
    "#...##...#.#.",
    "#..####..#.##",
    ".#.####.#.##.",
    "..........#..",
    "..........#..",
    ".#.####.#.##.",
    "",
    "#....###.",
    "......##.",
    "......#.#",
    ".#..#....",
    "..##....#",
    "########.",
    "#.##.#.#.",
    "######.##",
    ".#..#..#.",
    "..##.....",
    "..##.....",
    ".####.##.",
    ".####.###",
    "",
    ".....##",
    "####...",
    "....#..",
    "....#..",
    "####...",
    ".....##",
    ".##...#",
    "#..###.",
    "#..#.#.",
    "#.##.##",
    ".##.#.#",
    "",
    "...##...#.#..#..#",
    "...##...#.#..#..#",
    "#..####...###....",
    "...#.#.##.#...##.",
    ".###.#..##.###..#",
    ".####..##....####",
    "....##....##.####",
    ".#...#..#.#######",
    "..##..#....#.#..#",
    "##..#.#.#########",
    "#....#...#..##..#",
    "#..###.###..#.##.",
    "...#..#...####...",
    "",
    "###..##.......#",
    "###.###.......#",
    "#.#..#..###..#.",
    ".##.#..###..#.#",
    ".##.#..###..#.#",
    "#.#..#..###..#.",
    "###.###.......#",
    "###..##.......#",
    ".##.#####..#.##",
    "#...#.#.#..#..#",
    "..##.#.##.##...",
    ".###.##..####.#",
    ".###..##.#...#.",
    ".####.####.##..",
    ".##.#...#..####",
    "",
    ".###..#..###.",
    "...#....#....",
    "...#....#....",
    ".###..#..###.",
    "#.#..#..#...#",
    "##.###....##.",
    ".#.###.###..#",
    "...#####.###.",
    "##.#..####...",
    "..#.#.......#",
    ".###..#######",
    "#####.#.###..",
    "#####.#.###..",
    ".###..#######",
    "..#.#.......#",
    "#..#..####...",
    "...#####.###.",
    "",
    ".##.#..",
    "####.##",
    ".....##",
    "#####..",
    "####...",
    ".##.###",
    "#..##..",
    "#..#...",
    "####.##",
    ".##..##",
    "#..##..",
    "#..##..",
    "....###",
    "####...",
    ".##.#..",
    "#..#.##",
    ".#..#..",
    "",
    "######.",
    ".#..###",
    "..###.#",
    "####.##",
    "####.##",
    "..###.#",
    ".#..###",
    "######.",
    ".#####.",
    ".#.#..#",
    "..##...",
    "..#.###",
    "..#.###",
    "..#....",
    ".#.#..#",
    "",
    ".#..#.#.##..#",
    "#.####..#####",
    "..##.###.#..#",
    ".#.####.#.##.",
    ".#.####.#.##.",
    "..##.###.#..#",
    "#.####..#####",
    ".##.#.#.##..#",
    "#..#.###.####",
    "#..#.###..##.",
    "#..#..#.#....",
    "",
    ".#....#..",
    ".##.###..",
    "##.##.###",
    "##.##.###",
    ".#.##.#..",
    ".#....#..",
    "#.#..#.##",
    "##.##.###",
    "#......##",
    "###..####",
    "#..##..##",
    "",
    "#.#..#.#..#.#",
    "#.####.####.#",
    ".#....#.##.#.",
    ".#.##.#.##.#.",
    ".##..##....##",
    "##.##.######.",
    "..#..#......#",
    "#..###.#..#.#",
    "#..##..#..#..",
    "########..###",
    ".######....##",
    "",
    "..##....##...",
    "########.....",
    "#####..##....",
    "##..#..#.####",
    "#..#...###...",
    "####.#..##...",
    "....#.##.#...",
    "....#.##.#...",
    "######..##...",
    "#..#...###...",
    "##..#..#.####",
    "",
    "#.#.##.##",
    "..###.##.",
    "..###.##.",
    "#.#.##.##",
    "..#..##.#",
    "....####.",
    "#.###.#..",
    ".#.###.##",
    ".#.###.##",
    "#.#.#.#..",
    "....####.",
    "..#..##.#",
    "#.#.##.##",
    "",
    "#....#......#..",
    "......######...",
    "#.##.########.#",
    "##..##......##.",
    ".####........##",
    ".......#..#....",
    "#.##.##....#..#",
    "..##....##....#",
    ".####..#..#..##",
    "",
    "#.#....##..####",
    ".#..###........",
    "###...###..#..#",
    "###.#.###..#..#",
    ".#..###........",
    "#.#....##..####",
    "##.#.....#.####",
    "##.##.....##..#",
    "..##..#....#..#",
    "",
    "####......#..##.#",
    "...#.###.##.#####",
    "...#.###.##.#####",
    "####......#..##.#",
    "##.######...##.#.",
    "##.###..#.......#",
    ".#####...###..#..",
    "###.###..#.#..#..",
    ".#.#######.##...#",
    ".#.#######.##...#",
    "###.###..###..#..",
    ".#####...###..#..",
    "##.###..#.......#",
    "##.######...##.#.",
    "####......#..##.#",
    "",
    "###.##.##..##",
    "###.##.##..##",
    ".#..#...#.#..",
    "...####.###..",
    "#.#..##.##...",
    "#..#.#..#.###",
    "#...#.##....#",
    "",
    "....##...#.##",
    ".##.####.#..#",
    "#..###.....##",
    "####..##.#.##",
    "####.##..#...",
    ".##.##..####.",
    "#..##...##.##",
    "######.###..#",
    ".##.###...#..",
    "#..######...#",
    "#..######....",
    "",
    "...#.#..#..",
    "..#..##...#",
    "..#..##...#",
    "...#.#..#..",
    "##.#..#..##",
    ".######.#.#",
    "###.#..##..",
    "###.#..##.#",
    ".######.#.#",
    "",
    "##.##.##...#..##.",
    "#########..#...##",
    ".#.##.#.##.#...#.",
    ".#.##.#.##.#...#.",
    "#########.##...##",
    "##.##.##...#..##.",
    "##.##.#####.....#",
    "..####..#....#.#.",
    "#.####.#...###..#",
    "##....##.#......#",
    "##....###...####.",
    "##########.#.####",
    "#......#....#...#",
    "",
    "#....##..##..",
    "#....#....#..",
    "#.##.#.##.#.#",
    ".#..#.#.##.#.",
    ".#..#.#..#.#.",
    "......####...",
    ".......##....",
    "##..########.",
    "#.##.#.##.#.#",
    "######.##.###",
    "#....##..##..",
    "",
    "##..####.",
    "#.#......",
    "....#.##.",
    "##..####.",
    "####.##.#",
    "..#......",
    "##.#....#",
    "###.####.",
    "..#.#..#.",
    "..#......",
    ".#.#.##.#",
    "..#..##..",
    "..#..##..",
    "",
    "...#.#...#..##..#",
    "##.#.#.###......#",
    "##.###.###.#..#.#",
    "..#...#.#..#..#..",
    ".#.#.######.##.##",
    "..##..##.###..###",
    "####.##.#########",
    "...###..#..####..",
    "......###...##...",
    "...##..###..##..#",
    "...###.#...####..",
    "...###....#....#.",
    "..#......##....##",
    ".....##.####..###",
    "..#...#.....##...",
    "...#..#...#.##.#.",
    "####.....#......#",
    "",
    "###..###.##.#.##.",
    "...##...###.#..##",
    "........#..###..#",
    ".#....#.#######..",
    "###..####.##...##",
    "###..###..#..#.##",
    "...........###..#",
    "#########....#..#",
    "..#..#...####..#.",
    "##.##.####..#....",
    "............##.##",
    "########..##.#.#.",
    ".........#..##...",
    "##....####.....#.",
    "...##...#..#.###.",
    "",
    "###..#####.##",
    "##....####.#.",
    "...##...####.",
    "..####.......",
    "#......###.##",
    "########.###.",
    "..####....###",
    ".........##..",
    "...##....##..",
    "",
    "####...##..##..##",
    "....#...##..##.##",
    ".##.#.##......#..",
    "####.####..#...##",
    ".##.#.#.###.#....",
    ".##.#.#.###.#....",
    "####.####..#...##",
    ".##.#.##......#..",
    "....#...##..##.##",
    "####...##..##..##",
    ".....##..#.#....#",
    "..#..#####.##.##.",
    ".##.##....##..#.#",
    "#..##.##...#####.",
    "######..#.#......",
    "",
    ".###.###.##",
    "..#.#.##..#",
    ".##.....###",
    ".##.#...###",
    "..#.#.##..#",
    ".###.###.##",
    "#....###.#.",
    "#....###.#.",
    ".###.###.##",
    "",
    "...#.......#.####",
    "#..####..########",
    "..######..######.",
    "...#..#.......#.#",
    "#.######.#####.##",
    "...#..#...#...#..",
    "....##....##...##",
    "##..##..###..##..",
    "...#..#....#.#.#.",
    "....##....###.#..",
    "###.##.####.##.#.",
    "##.####.###....##",
    "##.####.###....##",
    "###.##.####.##.#.",
    "....##....###.#..",
    "",
    "#.##.##",
    ".#.####",
    ".#.....",
    ".#.....",
    ".#.####",
    "#.#####",
    "####.#.",
    "#..###.",
    "##..#..",
    "#####..",
    "######.",
    "..##...",
    "..##...",
    "",
    "...##....##....##",
    ".#..#.##.#..#.#.#",
    "...##....##...###",
    "#..##.##.##..####",
    "##.#.####.#.##...",
    "##.########.#####",
    "...#.####.#......",
    "##....##....##.##",
    "#.##.####.##.#...",
    "#.#...##...#.##..",
    "....##..##.......",
    "..#.######.#.....",
    ".#...####...#....",
    "",
    "#.##.###..#..",
    "#.##.###..#..",
    "#..#####..##.",
    "##..#.##.#.#.",
    "..###.....###",
    "####.######.#",
    "#.#.##......#",
    "#.#.##......#",
    "####.######.#",
    "...##.....###",
    "##..#.##.#.#.",
    "#..#####..##.",
    "#.##.###..#..",
    "",
    "#......##.###.#",
    "########...####",
    "#......##.#.##.",
    "...##....#.....",
    "#.####.#.###...",
    "#..##..##..#.#.",
    ".#....#.##.#..#",
    "..#..#..#.....#",
    "#..##..###...#.",
    "#..##..###..##.",
    "..#..#..#.....#",
    ".#....#.##.#..#",
    "#..##..##..#.#.",
    "#.####.#.###...",
    "...##....#.....",
    "",
    "##.#.###.##....#.",
    "###...#...#...#..",
    "###...#...#...#..",
    "##.#.###.##....#.",
    "#..#.#..###.###..",
    "###.####.#...#...",
    "...#.#.##.##.####",
    "##..####.####.###",
    "###.###.##..###.#",
    "..#..#.#...#.#..#",
    "...###.#.....#...",
    "..#.######.#..#.#",
    "..###.#.....##.##",
    "##.#.#..#.##..###",
    "...#.#.#.#.###.#.",
    ".......##..####..",
    "##....###..##..#.",
    "",
    "##.##.....#.###",
    ".#.##.###..#...",
    ".#.##.###..#...",
    "##.##.....#.###",
    "#....#...###...",
    "..#..#.#..#....",
    ".#.##.##...#.##",
    "..######.#.#...",
    "..###...###.###",
    "##....#..######",
    ".#..##.###.####",
    "##..##..##.#...",
    ".##..#.###..#.#",
    "",
    ".#.#.###.",
    "#.#.####.",
    ".....###.",
    "......##.",
    "#.#.####.",
    ".#.#.###.",
    "#...#...#",
    ".....#.#.",
    ".#..#.##.",
    "##..#....",
    "##..#....",
    "",
    "#......",
    "..####.",
    ".##..##",
    "#.##.#.",
    "#.####.",
    "##.##.#",
    "##.##.#",
    "",
    "#...###.#..#.",
    "..###...####.",
    "###.#..######",
    ".##.#..######",
    "..###...####.",
    "#...###.#..#.",
    "#.##.....##..",
    "",
    ".#..####..####..#",
    ".#..####..####..#",
    ".#..####..#####.#",
    ".#######..#######",
    "#####.######.####",
    ".....##....##....",
    "#..###.####.###..",
    "..##..........##.",
    "..######..######.",
    "",
    "#..##..####",
    ".....##.#.#",
    ".....##.#.#",
    "#..###.####",
    "####.#.#...",
    ".##.##....#",
    "#..##....##",
    "####...#...",
    "#####..#.##",
    "########..#",
    "#..#.#.#.##",
    "######.#.##",
    "#..#.##.#..",
    "......##.##",
    "#..##.##..#",
    "#..#...#.##",
    "########...",
    "",
    ".##.#.#####.#..##",
    "..###.#.#...###.#",
    ".##...#.#....#.#.",
    "..##.#..##....##.",
    "#..##...#...#.##.",
    "#..##...#...#.##.",
    "..##.#..##....##.",
    ".##...#.#....#.#.",
    "..###.#.#...###.#",
    ".##.#.#####.#..##",
    "###......#.##....",
    "###......#.##....",
    ".##.#..####.#..##",
    "",
    "....###..",
    "..#######",
    "#..######",
    "##...##..",
    ".##.####.",
    "###......",
    "###......",
    ".##.####.",
    "##...##..",
    "#..######",
    "..#######",
    "",
    "#.##.###.##.###",
    ".#.##..........",
    ".####...#..#...",
    ".#.#.###....###",
    "..#..###....###",
    "#######.####.##",
    ".#..#...####...",
    "......##....##.",
    "#.###...#..#...",
    ".###.....##....",
    "...#.##.####.##",
    "",
    "#...##..##...##",
    "#.###.##.###.##",
    "#.###.##.###.##",
    "#...##..##...##",
    ".#####..#####.#",
    "#...#.##.#...##",
    "..#.######.#..#",
    "..##......##...",
    "##..........##.",
    ".....####.....#",
    "##..##..##..##.",
    "#....####....##",
    "####.####.##.#.",
    ".####....####..",
    ".##.######.##..",
    ".....####.....#",
    "#.####..####.##",
    "",
    "..#.######.##",
    "..#.###.##.##",
    "##.#.#...#..#",
    "..####.#.##..",
    "...##..###...",
    ".....#....###",
    "##.###...#..#",
    "",
    "#..##.####.",
    "#..##.####.",
    "........#..",
    "...###.###.",
    ".###..#...#",
    "##.#####.#.",
    "#.##.#.#...",
    "#.##.#.....",
    "##.#####.#.",
    ".###..#...#",
    "...###.###.",
    "",
    "#..#.#.#.#..#.#",
    "......####..###",
    "#..###...#..#..",
    ".##.......##...",
    ".##.##.#####.##",
    "####.##...##...",
    ".....#..##..##.",
    "....##..##..##.",
    "......####..###",
    "#####.#..####..",
    ".....#.###..###",
    "####.#.##....##",
    "#..#.....####..",
    "",
    "...#....#....##",
    "#..........#...",
    "...######...#..",
    ".#.##..##.#.###",
    "##.#....#.##.##",
    "..#.####.#...##",
    ".....##........",
    "#.#.####.#.##..",
    "..##....##...##",
    "#..##..##..##..",
    "..#..##..#..#..",
    "#.#......#.#.##",
    "#.#......#.##..",
    "#.##....##.#...",
    "#..##..##..##..",
    "#..##..##..#...",
    ".#.##..##......",
    "",
    ".#..#..",
    "#.#.###",
    "#.#.#.#",
    ".##.##.",
    ".#..##.",
    "....#.#",
    "#.##.##",
    "....###",
    "..#.###",
    "..#.###",
    "....###",
    "#.##.##",
    "....#.#",
    ".#..##.",
    ".##.##.",
    "",
    "....####....###",
    ".....##......##",
    "#..######..#.#.",
    ".###.##.###...#",
    "...##..##......",
    "###.####.###.##",
    "###.####.###.#.",
    "",
    "####.######.####.",
    "####.######.####.",
    "###.#..##..#.###.",
    "#.....#..#.....#.",
    ".#..#..##..#..#..",
    ".##########.###.#",
    "#....#.##.#....#.",
    "",
    ".#...##..",
    "##.......",
    "###.##.#.",
    ".##......",
    "..###..##",
    "#.#######",
    "..###..##",
    "..#.#..#.",
    "..##.##.#",
    "..##.##.#",
    "..##.##.#",
    "",
    ".#.....",
    "#.##.##",
    "##..###",
    "..##...",
    ".#..#..",
    "#.##.##",
    "##..###",
    "#....##",
    ".#..#..",
    "#....##",
    "#.##.##",
    "",
    ".#..##..#.#..",
    "##########.##",
    "###....###...",
    "...#..#...##.",
    "..#....#...#.",
    "##.####.#####",
    "..######.....",
    "####..#####..",
    "##.####.##.#.",
    "###.##.######",
    "..#.##.#..###",
    "",
    ".#.#....#",
    ".#.#....#",
    ".#..####.",
    "###.#..#.",
    ".#.#.##.#",
    "#....##..",
    "#.##.##.#",
    "##.#....#",
    "#.#.#..#.",
    "...#....#",
    "..###..##",
    "##...##..",
    "####.##.#",
    "..#..##..",
    "..#.####.",
    "##.##..##",
    ".###..#.#",
    "",
    "#.##..#.######.",
    "#.#.####.####.#",
    "#..##.###.##.##",
    ".##.###########",
    ".#..#..#######.",
    "...##..#......#",
    "##..###.######.",
    "#..#..#########",
    "#...####..##..#",
    "##.####.######.",
    "##.####.######.",
    "#...####..##..#",
    "#..#..#########",
    "",
    "#.##...#..#",
    "#...##.####",
    ".####.#.##.",
    "##.###..##.",
    ".....#.....",
    "#...#...##.",
    ".#.#.#..##.",
    ".#...#..##.",
    "#...#...##.",
    "",
    "#....#.##...##.##",
    "#.##.##.###.##...",
    "#######.###.##...",
    "#....#.##...##.##",
    "##..##.###....#..",
    "#.##.#...######..",
    "...............##",
    "#....##.#.#.##.##",
    "#....##.#...#...#",
    ".####..#.#.#.....",
    ".#..#............",
    "",
    "..#....#..###",
    "...#..#......",
    "...#..#.....#",
    "##.####.#####",
    ".###..###....",
    "...#..#......",
    ".##.##.##.#..",
    "...####....##",
    "##.####.###..",
    ".#.####.#....",
    ".#......#....",
    "...#..#......",
    "#.######.####",
    "",
    "#....##.#..##.###",
    "..##...#..##.##.#",
    "..##..###.##..###",
    ".......#.#......#",
    "..##..#.....##...",
    ".####..#..#....##",
    ".#..#..#.#..#####",
    "#.##.#.....###.##",
    "..##...#...#.#.##",
    "##..#####.#..#.#.",
    "..##..#..#.##.#.#",
    "..##..#####..####",
    "..##..#####..####",
    "..##..#..#.##.#.#",
    "##..#####.##.#.#.",
    "",
    "#.#..#.##",
    "###..##..",
    "##....###",
    "...##...#",
    "...##...#",
    "##....###",
    "###..##..",
    "#.#..#.#.",
    "#.#..#.#.",
    "###..##..",
    "##....###",
    "",
    "..####.##.#",
    "#.#.###..##",
    "#..#..####.",
    "......####.",
    "##.##.#..#.",
    "##....####.",
    "..##.......",
    ".######..##",
    ".#.#.##..##",
    ".#.#.##..##",
    ".######..##",
    "..##.......",
    "##....####.",
    "##.##.#..#.",
    "...#..####.",
    "",
    "..##....##....#",
    "#..#....##....#",
    "#..............",
    "####.##.##.##.#",
    "#.#############",
    "###.#..#..#..#.",
    "..##.##.##.##.#",
    "##..#........#.",
    ".##############",
    ".#.............",
    ".#...##....##..",
    "##..####..####.",
    "..#.####..####.",
    "..#..##....##..",
    "#...#..#..#..#.",
    "#..............",
    "###............",
    "",
    "...###..#..",
    ".######...#",
    "#.#.#.....#",
    ".#.#....#.#",
    ".#.#....#.#",
    "#.#.#.....#",
    ".######...#",
    "...###..#..",
    ".#.###.####",
    "...#...##.#",
    ".....#...##",
    ".####..###.",
    ".####..#.#.",
    "",
    "..##..##.",
    "####..###",
    "..#.##.#.",
    "...#..#..",
    "..######.",
    "..#.##.#.",
    "###....##",
    "..##...#.",
    "###....##",
    "",
    "##.##.####.##",
    "##.....###...",
    ".##.##.#.....",
    "##....#.#.#..",
    "#.....#.#.#..",
    ".##.##.#.....",
    "##.....###...",
    "##.##.####.##",
    "..#..##...#..",
    ".###.##..##..",
    "...##.#..##..",
    ".##..##....##",
    "##.#..####...",
    "",
    "#....##...##.",
    "..###.##.#..#",
    ".#.###.......",
    ".#.###.......",
    "..###.##.#..#",
    "#....##...##.",
    "#..####...##.",
    "..##..####..#",
    "..####.#.....",
    "##...#.#.#..#",
    "#.#..#.......",
    "...##.#..#..#",
    "..######.####",
    "##..#.#######",
    "###...#.##...",
    "..###..#.####",
    "##.#.####.##.",
    "",
    ".###.##.#",
    ".####.#..",
    ".#...####",
    "#..#.####",
    "....###.#",
    "..#.#.#.#",
    "####.###.",
    "...###.#.",
    ".####.#.#",
    ".#...###.",
    ".#...####",
    ".#...####",
    ".#...###.",
    "",
    ".#..#..#..#",
    ".##########",
    "##..####..#",
    "#..........",
    ".####..####",
    "###.#..#.##",
    "##..#..#..#",
    "#.##.##.##.",
    "..##....##.",
    "",
    "##.######.##..#.#",
    "##.######.##..#.#",
    "#.###..###.#...#.",
    "###.#..#.###.#...",
    ".#.#....#.#....#.",
    "...#....#...###.#",
    ".####..####..##.#",
    "..##.##.##..#####",
    ".#........#.##...",
    "#..######..#.#.#.",
    "...#.##.#....#.##",
    "#....##....##....",
    ".###....###.##..#",
    ".#.######.#....##",
    "####....####.....",
    "#...#..##..###.#.",
    "#...#..#...###...",
    "",
    "....#.###....##",
    ".##.#....#..#..",
    ".#.##....####..",
    "#..######....##",
    "....###........",
    "#####.#..####..",
    ".#..###..####..",
    "....###########",
    ".....####....##",
    "##.####..####..",
    "#.##.###.#..#.#",
    ".#..#####....##",
    "#.#.#.#..####..",
    "",
    "##...#.#.#.##",
    ".......#.###.",
    "###.#..###...",
    "##..#...#....",
    "..#.#...##...",
    "#####.#....##",
    "#####.#....##",
    "..#.#...##...",
    "##......#....",
    "###.#..###...",
    ".......#.###.",
    "##...#.#.#.##",
    "....##.#..###",
    "",
    "..##...",
    ".#.####",
    "..###..",
    "#.#..##",
    "...#...",
    "#...###",
    "#......",
    "#..####",
    ".####..",
    "#..####",
    "..##.##",
    "....#..",
    "..#.#..",
    "",
    "#.###......###.",
    ".#.##..##..##.#",
    ".#.##..##..##.#",
    "#.###......###.",
    "#..####..####..",
    "......####.....",
    "######.##..####",
    "...#...##...#..",
    "....###..###...",
    "",
    "#..##.#....##.###",
    ".#.#......#.##...",
    "#...#...#...#..##",
    "#..##..#.#..##...",
    "#########.##.##.#",
    "#########.##.##.#",
    "#..##..#.#..##...",
    "#...#...#...#..##",
    ".#.#......#.##...",
    "#..##.#..#.##.###",
    "#..#.##.#...#.###",
    ".#......#..###..#",
    ".##.##.##...##...",
    ".######..####..##",
    "####.#..#..#.#...",
    "####.#..#..#.#...",
    ".######..####..##",
    "",
    "...###.",
    "...###.",
    ".#...#.",
    "..#.###",
    ".#...#.",
    "....#.#",
    ".#.###.",
    ".#.###.",
    "....#.#",
    ".#...#.",
    "..#.###",
    "##...#.",
    "...###.",
    "",
    "##..###..##..##",
    "##..#####......",
    "#.##.#..#.####.",
    "######.##..##..",
    "#.##.##########",
    "#######..##..##",
    "#####..#.......",
    ".####..#...##..",
    "##..######.##.#",
    "",
    ".##.######.##..##",
    ".#####..#####..##",
    "##..##..##..####.",
    "#.#.#....###.##.#",
    ".#...#..#...#..#.",
    "##.###..###.####.",
    ".#..........#..#.",
    "...##.##.##......",
    "##...#..#...####.",
    "......##.........",
    "##..#.##.#..####.",
    "",
    "###..##",
    "####..#",
    "####..#",
    "..#..##",
    "##.#.##",
    "##...##",
    "...####",
    "#####..",
    "..#...#",
    "..#####",
    "###...#",
    "..#..#.",
    "##..#.#",
    "##.....",
    "###..##",
    "..###.#",
    "...##.#",
    "",
    ".#....###.#.#",
    "###.##.#.....",
    "###.##.#...#.",
    ".#....###.#.#",
    "#######..#...",
    "#######..#...",
    ".#....###.#.#",
    "###.##.#...#.",
    "###.##.#.....",
    ".#....###.#.#",
    "..#..#.....#.",
    "#.......#.#.#",
    "#.#####.#.##.",
    "....#...#..##",
    "..#.##.#.####",
    "####.######.#",
    "..###.#.#...#",
    "",
    "..#.#.#",
    "#####..",
    "...###.",
    "...#..#",
    "##..##.",
    "###..#.",
    "##.###.",
    "......#",
    "#.###.#",
    "####...",
    "..##..#",
    "##.....",
    "##.##.#",
    "##.####",
    "##.####",
    "",
    "####..###",
    "....##...",
    "..######.",
    "..##..##.",
    "##.####.#",
    "###.#..##",
    "##......#",
    "",
    "..#..####..",
    "..#.##..##.",
    "##.###..###",
    "##.###..###",
    "..#.##..##.",
    "..#..####..",
    "#...######.",
    "######..###",
    "...##....##",
    "#.#...##.#.",
    "#.##..##..#",
    "#...##..##.",
    ".##..#..#..",
    "",
    "#.#####",
    ".#.#..#",
    ".#.#..#",
    "#..####",
    "#....##",
    "#....##",
    "#..####",
    ".#.#..#",
    ".#.#..#",
    "#.#####",
    "##.##.#",
    "..##.##",
    "#..#.##",
    "#...#.#",
    "#.####.",
    "##.#...",
    ".#.####",
    "",
    "##.#..###....#..#",
    "#.###.##.#.##..##",
    "...##.#.#.##..#..",
    "#.#..####..##....",
    "#.#..####..##....",
    "...##.#.#.##.##..",
    "#.###.##.#.##..##",
    "##.#..###....#..#",
    "....#.#....#.##.#",
    "#.###...###.###.#",
    "##.##..#########.",
    "#.#....##.#..#.#.",
    ".##.#...###....#.",
    ".#.###...#..#..#.",
    ".#.###...#..#..#.",
    ".##.#...###....#.",
    "#.#....##.#..#.#.",
    "",
    "#.#.##.",
    "#...#..",
    "..#..#.",
    "##..#..",
    "##..#..",
    "..#..#.",
    "#...#..",
    "#.#.##.",
    "##..###",
    ".####..",
    ".#.#...",
    "###.##.",
    "##..#..",
    "##..#..",
    "###.#..",
    ".#.#...",
    ".####..",
    "",
    "###.#..#.##",
    "..##.#.....",
    "...#.###...",
    "...#.#...##",
    "....####...",
    "......#.#..",
    "...###.#.#.",
    "",
    "#.##.##.#",
    "..##..###",
    ".#.....#.",
    "##..##.##",
    "......##.",
    "#.##.#..#",
    "######.#.",
    "..##....#",
    "##..###.#",
    "#.##.####",
    "#.##.####",
    "##..###.#",
    "..##....#",
    "######.#.",
    "#.##.#..#",
    "......##.",
    "##..##.##",
    "",
    "####.##.######.#.",
    "...######....#.#.",
    "..###..###..#.##.",
    "..###..###..#.##.",
    "...######....#.#.",
    "####.##.######.#.",
    "#....##....#.....",
    "...#.##.#...##.#.",
    "..#..##..#..####.",
    "#.##....##.#.#.#.",
    "###############..",
    ".........#..#.#..",
    "############..#.#",
    "",
    ".##.#....#.",
    "..#.#....#.",
    "###..#..#..",
    "#...##..##.",
    "..###....##",
    "..#..####..",
    "####.#..#.#",
    "",
    "##.##......",
    "##..#.#..#.",
    "..#..#.##.#",
    "###.##.#..#",
    "....#.#..#.",
    "####.......",
    "..#...####.",
    "",
    "###.##.#####.",
    "####...######",
    "..#.##..####.",
    "##..#.#.#..#.",
    "###.##.######",
    "..#..##.#..#.",
    "########.##.#",
    "..##.#.######",
    "..#......##..",
    "..#....##..##",
    "##.####......",
    "",
    "...#..#.......##.",
    ".##....##...#####",
    "#..#..#..#.......",
    "..##..##..#......",
    ".###..###..#..##.",
    ".##....##.#...##.",
    "############.####",
    "#.#.##.#.#.##....",
    "#.##...#.#....##.",
    ".##.##.##....#..#",
    ".###..###.##.....",
    "#...##...#####..#",
    "###....###.##.##.",
    "#.##..##.#..##..#",
    "##......##.......",
    "##########..#####",
    "#.##..##.#..#.##.",
    "",
    ".#.#.####",
    "...#.#.##",
    "..###....",
    "#..##.#.#",
    "##..##...",
    ".###..#..",
    "##.#.####",
    "##.#.#..#",
    "#.#####..",
    "#...#.#.#",
    "#...#.#..",
    "#...#.#..",
    "#...#.#.#",
    "",
    "##.#..###.#..",
    "...####.#.###",
    "..#....##.#..",
    "###..##.##...",
    "##.####.#..##",
    "####.#..#..##",
    "###.#..##.###",
    "......##.#.##",
    "###....#..#..",
    "...##.#######",
    "##.#...#.#.##",
    "..#.####.#.##",
    "###...#..####",
    "..#..#.####.#",
    "##.##.#...###",
    "..####...##..",
    "...#...#.####",
    "",
    ".....##.#..#.####",
    ".##....#####....#",
    "#..##.###.###.##.",
    "######.##.....##.",
    ".##.#..##..###..#",
    "####..#.###.#####",
    "####.#..#..#.#..#",
    "####.#.#..###....",
    "########..##..##.",
    "#######.#.##.....",
    ".....##..#..#....",
    "",
    "#...#..######.#.#",
    "...#.###.##..#.#.",
    "###....#..#..#.#.",
    ".##.######.###.#.",
    "##..#..#..###....",
    "##..#..#..###....",
    ".##.##########.#.",
    "###....#..#..#.#.",
    "...#.###.##..#.#.",
    "#...#..######.#.#",
    ".##.#.#..#....##.",
    ".##.#.#..#....##.",
    "#...#..######.#.#"
};

class AshAndRocks {
public:
    AshAndRocks(const vector<string> _input)
        : ashandrocks(_input)
        , rows(_input.size())
        , columns(_input[0].size())
    {
        findMirror();
    }

    string getRow(int r)
    {
        string ret;
        if (0 <= r && r < rows)
            return ashandrocks[r];

        return ret;
    }

    string getColumn(int c)
    {
        string ret;
        if (0 <= c && c < columns)
            for (auto row : ashandrocks)
                ret += row[c];

        return ret;
    }

    void findMirror(int mr = -1, int mc = -1)
    {
        mirrorrow = -1;
        mirrorcolumn = -1;
        // Find matching row
        for (int r = 0; r < rows - 1; ++r) {
            if (getRow(r) == getRow(r + 1)) {
                mirrorrow = r;
                if (mirrorrow != mr)
                    for (int rt = 0; rt < r; ++rt) {
                        string r1 = getRow(rt);
                        string r2 = getRow(2 * mirrorrow + 1 - rt);
                        if (r1 != r2 && "" != r2) {
                            mirrorrow = -1;
                            break;
                        }
                    }
            }
            if (-1 != mirrorrow && mr != mirrorrow)
                break;
        }

        // Find matching column
        for (int c = 0; c < columns - 1; ++c) {
            if (getColumn(c) == getColumn(c + 1)) {
                mirrorcolumn = c;
                if (mirrorcolumn != mc)
                    for (int ct = 0; ct < c; ++ct) {
                        string c1 = getColumn(ct);
                        string c2 = getColumn(2 * mirrorcolumn + 1 - ct);
                        if (c1 != c2 && "" != c2) {
                            mirrorcolumn = -1;
                            break;
                        }
                    }
            }
            if (-1 != mirrorcolumn && mc != mirrorcolumn)
                break;
        }
    }

    bool valid()
    {
        if (-1 != mirrorrow && -1 != mirrorcolumn)
            return false;
        if (-1 == mirrorrow && -1 == mirrorcolumn)
            return false;

        return true;
    }

    long getResultA()
    {
        if (!valid())
            cout << "Detected either both, mirror column and row, or nothing." << endl;

        long resultA = 0;
        if (-1 != mirrorcolumn)
            resultA += mirrorcolumn + 1;
        if (-1 != mirrorrow)
            resultA += (mirrorrow + 1) * 100;

        return resultA;
    }

    void fixSmudge()
    {
        int oldmirrorrow = mirrorrow;
        int oldmirrorcolumn = mirrorcolumn;

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < columns; ++c) {
                char old = ashandrocks[r][c];
                ashandrocks[r][c] = ('#' == old ? '.' : '#');

                findMirror(oldmirrorrow, oldmirrorcolumn);
                if (oldmirrorrow != mirrorrow || oldmirrorcolumn != mirrorcolumn) {
                    if (oldmirrorrow == mirrorrow)
                        mirrorrow = -1;
                    if (oldmirrorcolumn == mirrorcolumn)
                        mirrorcolumn = -1;
                    if (valid())
                        return;
                }

                ashandrocks[r][c] = old;
            }

        cout << "I was unable to fix the smudge." << endl;
    }

    long getResultB()
    {
        fixSmudge();

        return getResultA();
    }

private:
    vector<string> ashandrocks;

    int mirrorrow;
    int mirrorcolumn;
    const int rows, columns;
};

class PointOfIncidence {
public:
    PointOfIncidence(const vector<string>& _input)
        : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        vector<string> tAshAndRock;

        // Parse data
        for (auto elem : input) {
            if ("" == elem) {
                AshAndRockss.push_back(AshAndRocks(tAshAndRock));
                tAshAndRock.clear();
            } else {
                tAshAndRock.push_back(elem);
            }
        }
        AshAndRockss.push_back(AshAndRocks(tAshAndRock));
    }

    long getResultA()
    {
        long resultA = 0;
        for (auto e : AshAndRockss)
            resultA += e.getResultA();

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = 0;
        for (auto e : AshAndRockss)
            resultB += e.getResultB();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    vector<AshAndRocks> AshAndRockss;
};

TEST_CASE("Testdata")
{
    PointOfIncidence PointOfIncidenceData(inputTestdata);
    REQUIRE(405 == PointOfIncidenceData.getResultA());
    REQUIRE(400 == PointOfIncidenceData.getResultB());
}

TEST_CASE("PointOfIncidence")
{
    PointOfIncidence PointOfIncidenceData(inputData);
    REQUIRE(28895 == PointOfIncidenceData.getResultA());
    REQUIRE(31603 == PointOfIncidenceData.getResultB());
}