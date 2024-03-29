#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "..F7.",
    ".FJ|.",
    "SJ.L7",
    "|F--J",
    "LJ..."
};

const vector<string> inputTestdata2 = {
    "...........",
    ".S-------7.",
    ".|F-----7|.",
    ".||.....||.",
    ".||.....||.",
    ".|L-7.F-J|.",
    ".|..|.|..|.",
    ".L--J.L--J.",
    "..........."
};
const vector<string> inputTestdata3 = {
    "..........",
    ".S------7.",
    ".|F----7|.",
    ".||....||.",
    ".||....||.",
    ".|L-7F-J|.",
    ".|..||..|.",
    ".L--JL--J.",
    ".........."
};
const vector<string> inputTestdata4 = {
    ".F----7F7F7F7F-7....",
    ".|F--7||||||||FJ....",
    ".||.FJ||||||||L7....",
    "FJL7L7LJLJ||LJ.L-7..",
    "L--J.L7...LJS7F-7L7.",
    "....F-J..F7FJ|L7L7L7",
    "....L7.F7||L7|.L7L7|",
    ".....|FJLJ|FJ|F7|.LJ",
    "....FJL-7.||.||||...",
    "....L---J.LJ.LJLJ..."
};

const vector<string> inputTestdata5 = {
    "FF7FSF7F7F7F7F7F---7",
    "L|LJ||||||||||||F--J",
    "FL-7LJLJ||||||LJL-77",
    "F--JF--7||LJLJ7F7FJ-",
    "L---JF-JLJ.||-FJLJJ7",
    "|F|F-JF---7F7-L7L|7|",
    "|FFJF7L7F-JF7|JL---7",
    "7-L-JL7||F7|L7F-7F7|",
    "L.L7LFJ|||||FJL7||LJ",
    "L7JLJL-JLJLJL--JLJ.L"
};

const vector<string>
    inputData = { "FJ.|-FL-J-F-J-L-F|7F7F7J.|J7|-FF7.7F--|-F7F-.7.F--F-J.F|7FJ-77.|-|-F|7FL|FF|7.FF-L|-J7L-|-L-|-L-F.F.L7F..|7F|.F-JF77F7.FL7F-7.F---7L|77FJ7-J", "L-FL.-J|.L|.|7J7JJ|LJ7..FLJF--F.|7FF7J..F.JFL.FL--J|L7.L|L|.L77..J7FJL7JL--J77-L.F|7.7J|||.|J.LFJ.L..FF7FF-JLF7.|F||-JJ-L7-L7F7.FJL.|7-|LFJ|", "|J|L|J.L--|.|L7JJFJL7JFFL7.F7.J..F-L77.-J7LF-FJ|FLJF-J7|F777LJ-7-|-L-7|J|.|-LL7LL7L--7F-F--|.|--7FJF|J|LJJ.F.||FLJJJ.J.|JJ|J|7LJJLLJJ|LLFJFJ", "LFL7|7LJ.F|FJFLJ7|L-J.|JF7.|7-.F7F7.|--JL|-F7|7|7||||||F||||L|LL-||.FJJ.J---F.L-J.-.L7L--..|.|JL||FFL-J7L..JJ.J7-J||FF-|--7.|JF|JFL7F7.L|FJJ", ".J7L-7|JL|7J-|.LF-J-L|---JF|--FFJ||FJJFF-J|F7J-7-J|LJFLFJL---77JFL77F|FFJFFF|.|FL7LL7LJL.|.|-F-F.|-|-J-7LJJ7.7J|77|--|JJL-JF77JJ|FJL7L7||LJ7", "J||J.|JJF77|F-J7L|J-LL-7L-7JFF-J-|-7.F-|JLLJLF-JFL7|L||L-7F-7|F-7L-L7LF7LJ7JLF77-J.L77F.|JFJ-F7LFL7|FLJ.|.|7F7.|7FF.J|F.|L7JL-JF-7-LF||L7|L7", ".F|.|-JFFJF|F-.|L-JF-|F7-7L.J|F|JL-|-|||-F7J.LFL7.|7F|F7LLJFJ||FJ7LL-7J77LJLF|L||LF7-7|LJ77JL||-|FFF7|-FFF7.JJ-|--77|LJ7-JJF7JFJ-|L|F7-7L77J", "-LJF.|JFJFJJLL--7JF|||L|7L-JJ7.77|-||FF--JJ--7JL|-LF77L7LF-JFJ|L-7.LLJLLJF--J.LF7.||F77.F|-F.||7J7FJL7-LF||JLFFJLJ.FJ7-F7.F|.L7..LFF.L-F.|7.", "||.F7L-7LJ.77|.|||LF-L-|L|JJLLJLF|-7FL||J.|F|LJ-|.L|L7F77L-7|FJF7L-777.L|-J||F7||F|L7L--F77-FJL7JLL7FJJ.|||LF7JF7F-|.LJL7-FJF-.--J.|-J|L-FL7", "|F-7J-7L-JF77L7F-7.L|.L|-FJF77JF-|LL-.L-J.LF|7F||L7L7LJL7FFJLJFJL7FJF-7FFJFF7||||FJFJ-JFJ|J7L7FJJJFJL7JF7||FJ|.|J|.|.||FJL-77|F|77.||FJ.L7JL", "F77|.|LJ|F||LLF-.L.||7.LF--7||F||L-7J7||J...J77.|-JLL--7L7L7F-JF7LJ||FJ7|FFJLJLJ||FJ-||L7|.F-J|F-7L-7L7||||L7L777LF7-L|J..|7-F-F|JFFF-J-FLJ|", "7|F7-F|7FF|77L|J7LJFL-7FL-7L7JLL7-JJ-J.|F7FLLJ|FFFJF7F7L7|.||F7||F7FJL7F-7L7F7F-J|L7.F7FJ|-L-7LJFJF-JFJ||||.L7|F7F77J-F-|7L-J|-JLFJ|||LF77|J", "|FF|L7F-JJ|-J7.FL.LLJJLLF7L7|.F||LJ7.|-F7J--|7L-F77||||FJL-J||LJ||||F-J|FJFLJ||F7|FJFJLJFJFF7L-7L-JF-JFJ||L7L||||||..F77L|.LFJ7J.L7LL7F--J7.", "7F7|7|L.F-JLF7F77-FL.|F|||||L-7F-7JF7JF|L7|JL7|L||FJLJ||F--7||F-J|LJL--J|F-7FJ|||||-L--7L-7||F7L--7L-7L7|L7L-JLJLJ|F7||7..FFJ-77-LJJL|7-LL7L", "|F|-.|F7JF7.LF7LF7LFFFF-JL7L7FJ|FJFJ|F-JFJF7.|77||L7F-JLJF7|LJL-7|F-----JL7|L7LJLJ|F-7LL-7||||L---JF-JFJL7|F7F----J|LJL7-||J7.L-.LJ..LL-JL|J", "7.LJ--||LJLLFJF7-|7JL||F-7L7|L-J|.L7||F-JL|L7F7FJ|FJ|-F7FJLJF7F-J|L7F7LF--JL-JF7F-J|FJF-7|LJ|L----7L-7|F-JLJ||JLF--JF-7||L7-77..7J|-J7....F7", "|F-||-JJJ...7-||JL|7.FLJFL7|L7F-JF7|||L77FJFJ|||FJL7|FJLJF--JLJF7L7LJL7|F7F7F-JLJF7||.L7||F-JFF-7FJF-J||LF--JL7FJF-7L7LJF-|-J7-J7F-77|.FLL7L", "FL7L7..|..F-J||--7.-7||JF7|L7|L7FJ||||FJFJFJFJ|||-|||L7F7|F7F7FJL7|F--JLJ|||L7F7FJLJL7FJLJL7F7L7|L7L--JL7L--7FJ|FJ7|FJJLJ-|.|JLL7-|LLL-|JL|J", "-7LL|JFF7FJL.LJJ|LJLLF--JLJFJ|FJL7LJ|||FJFJ-L7||L7FJL7LJ|||||LJF7|||F--7.LJL7|||L-7F-JL-7F-J||FJL7|F----JF7FJ|FJL-7|L77J.LJ-L-77J--F|.FJ.L|7", "FL7F7F-|L--JF|7.LJJ|.L----7|FJ||FJF-J||L7L7-FJLJFJ|F-JF7|||||F-JLJ||L-7|F7F7|||L7FJ|JF7|||F7||L-7LJL--7F-JLJFJ|F--JL-J7F|7.FJ7L-77L7-7-LF77J", "7LLJL7J|.FJ-|JFJ7JF7F7||F-J|L7L-JFJF-JL7L7L7L--7L7||F-JLJ||LJL-7F7||F7|||||||||FJL7L7||FJ|||||F7L7F---JL---7L-JL7F-77F-7F777L-7LF--JL-7-|L|J", "F7.F7|FJJ7-FJ7|F7.||||F7L-7L7L7F7L7L-7FJFJFJF7FJFJ||L---7|L7F--J||||||||||||||||F7L7||LJFJ|LJLJ|FJL7F7FF7F7|F---JL7L7L7LJ|77JFF7LF7|||..J7L.", "||7LFJF|L7L7|F-FL-|LJLJ|F7L7|.LJL7|F-JL7L7L7||L7L7|L7JF7||-|L-7FJ||||||||LJLJ||||||||L-7|-|F---JL7FJ|L7|LJLJ|F7F7-|FJFJF-J7.FJJLFFJ||-F-L|FF", "L|J-L-J|FF.|-7|L7L|F--7LJL-JL7F-7||L--7L7L7|||FJFJL7L-J||L-JF-J|FJ|LJ|||L---7|||||FJL7FJL-J|LF7F-JL-JFJL-7F7LJLJL7|L-JFJ7LF7-J7FL77FJ.-JLJF7", "L|.FF-77-FLJ7.F.F7LJF7L----7FJL7LJ|FF7L7L7|LJ||FJ7JL--7||F--JLFJL7L7FJ||-F7-||||||L-7|L---7L7||L7F---J7F7LJL7F---J|F--J.F7|L7JFJ7|-JL7|.FLLJ", ".L.FL7.|JLL--||F||-FJL7|F77|L7JLS7L7|L-JFJL-7||L7FF7F7|LJ|F7F7|F-JFJL7|L7||FJ||LJL7J||F7F7|FJ||FJL----7|L7F7|L7F--JL---7|||FJ7JL7J77LF--|7|L", "L|FJ7|.|7|L7|F-FJL7L-7L-JL-JFJF--JFJ|F-7|F--J|L7L7||||L7FJ||||||F7L-7||FJ||L7||F--JFJLJLJLJ|-||L7F7F--JL7||||FJ|F------J|||L77-.JJ-JLL7-L-7.", "LJJF7J7||L7FLF7L7FJFFJF----7L7L--7L7|L7LJL-7FJ7L7LJ||L-JL7|LJLJLJL7FJ|||FJL-J||L7F7L----7F-JFJL7||LJLF7FJ||||L7||F7F--7.|||FJ.LL|F-L7LF-F.LF", "-7LJ|-7LJFL7J||-||F7L-JF7F7|FJ7F7|FJL7L-7F7||.F-JF-JL---7||F------JL7LJ|L---7||FJ||F----J|F7L7FJ||7F7||L7||LJFJ|LJLJF-JFJLJ|F77LJL77-FJ|.L|L", "||-LLJJ7.FJJL||FJLJ|F--JLJ|||F7|LJL-7|F-J|||L7L-7|F7LF7FJLJL7FF-7JF7L7FJF-7L|LJL-J|L----7LJL7||FJL-J||L7||L-7L-JF---JF-JF--J||J7L-LL-L---7L7", "|....LJ.FLJFFJ|L7F7|L----7||LJ|L7F--J||F7|LJFJF-J||L7||L--7FJFJFJFJL-J|-L7L-JF7F--J-F---JF--J|||F---JL7|||F7|F--JF-7FJF7|F7-||7|.7.LL-L|J7L-", "--7-LJ|F-F7-L7|.LJ||LF7F-J|L-7|FJL7F7||||L7FJJL-7||FJ|L--7|||L7L-JF7F7|F7L---J|L-7F7L---7|FF-JLJL--7F7|||||||L-7FJFJ|FJ|LJL-JL-7F7-7J.|JJ|FL", "|-|77.||LFFJJ|L7F-JL7||L-7L7.||L-7|||||||FJL-7F-J|||FJF7FJ||F7L7F-JLJLJ||F7F7.|F-J||LF7FJL7L--7F---J|||||||LJF-J|FJFJL7L7F7F7F-J|L7-7F|7F--7", "|7JF-.F-7L-F-JFJL--7LJ|F7L7L-JL--JLJ|||||L7F7|L-7||||FJ||FJ|||FJ|F-7F7FJ|||||FJL-7|L7||L7FJF7FJ|F7F7|||||||F-JF-JL-JF7|JLJLJ|L--JFJ..7|F.|.J", "L7FJ.FJLJLLL-7L7LF7L-7LJL-JF--7F7F-7|||||L||LJF7||||||JLJL7|||L7||FJ|||FJ||||L7F-JL7|||F||7||L7|||||||||||||F-JF7F7FJLJF7F-7L-7F-JJJ-LLJ7FF7", ".L7-7JJ||77LJL7L-JL--JF7F-7L-7LJ||FJLJLJ|FJ|F7|||||||L-7F-J|||FJLJL7|||L7|||L7||F7FJ|||FJ|FJL7|||||||||LJ||||F-JLJ|L-7F|||FJF7LJF7|J|F|J.FF7", "F7--||-F-L-JFLL7F7F--7|LJJL7FJF7LJL----7||FJ||||||||L7FJL7FJ||L7F--J|LJJLJ|L7||||||FJ||L7||F-J|LJ||||||F7LJLJL--7FJF7L-JLJL-JL7.||7.LJL7-|J|", "FL-J.F-7||F.7..LJLJF-J|F--7||FJL-----7FJ||L-J||LJ|||FJL--J|FJL7||F-7L-7F--JFJ||||LJL7||FJ||L7FJ.FJ|||LJ|L-------JL-J|F7F7F-7F7L-JL7-|.|.L|7F", "|L7.LJ-J7||-F7.F-7.L7FJL7FJLJL-----7FJ|FJ|F--JL-7|||L-7F--JL-7||||7L7FJL--7L7|||L7F-J|LJFJ|FJL7FJFJ|L7-L-------7F--7LJLJ|L7||L----JF7-F7L77J", "F-F-J7JL7JFJ||-L7|F7LJF7|L--7F-----JL-JL7||F-7F7||||F-JL-7F7FJ||||F-JL-7JFJFJ|||FJ|F7L-7|FJL7FJL-JFL-JF--------J|F-JF7F7L-J||F7F7F7|L7||7|FJ", "L7L-JJ-7L7JFJL-7||||F-JLJF--JL--------7FJ|||FJ|||LJ|L--7FJ||L7||LJ|F-7FJFJFJ|LJ|L7||L7FJ||7|||FF----7FL-------7||L7||LJL--7|||||||||FJ||-F7J", "F|7|J7.|LJ7L--7LJ|||L---7L7F7F-------7|L7|||L7||L7FJF-7|L7||FJ||F-J|FJL7|FJ|F7LL7|||FJ|FJL7FJL7|F7F7L7-F7F7F-7L7L7L-JF7F--JLJ|||||||L-JL-J|.", "FLL--7-|-L-F7FL-7|||F-77L7|||L-7F---7LJ-LJ|||||L7||FJFJL7||LJ|LJL--J|F7||L7FJ|F7||LJL7|L7FJL--JLJLJL7L-JLJLJ.L7L-JF--JLJF-7F7|||||||F-----J7", "-|7|FJFJ-.|||F7|||||L7L7-||||F7LJF--JF---7|L7||FJ||L7L-7||L--7F-----J|LJL7LJFJ|LJL--7||FJ|F7F-------JF------7FJF-7L--7F7|FJ|||||LJLJL7F7J|F|", "|LJJFJ7LJFFJLJL-JLJ|J|FJFJLJLJL--JF--JF--JL-JLJL7|L7L7FJ|L7F7|L7F7F7FJF--JF7L7L7F7F-JLJL7LJ|L--------JF-----JL7L7L-7FJ||||7|LJLJF7F-7LJL-777", "|JJJ|.FF.FJF7F7F--7|FJL-JF7F------JF-7L--------7|L7|FJ|FJFJ|LJF||||||FJF7FJL7L7|||L--7F-JF7|F7F-----7FJF---7F7|FJF7LJFJLJL7|F--7||L7|F-7FJ-7", "-.-.-L-|-L-JLJLJF7||L----JLJF------J-L---7F7F7FJL-J|||LJ.L7L--7||||||L7|||JFJFJ|||F--JL7FJ|||||F7F-7LJFJF--J||LJFJL--JF---J||F7LJ|FJ|L7LJJ--", "|7-|LF7JF7F7F-7FJLJL--------JF--7F------7LJLJLJF7F-JL-7F--JF--J||||LJFLJ||FJFJ-LJ||F7-FJL7|LJ|LJLJFJF-JJL---JL7FJF----JF7LFJ||L-7|L7L7L-77|J", "|F7J7F-7|LJ|L7LJF7F-7F--7F7F7|7FJ|JF7F--JF-----J||F-7FJL7F7L-7FJ|||F-7F-J|L7L-7F-JLJL7|F7|L7FJF---JFJF7F-----7|L7|F----JL7L7LJF-JL-JFL-7|JJ7", ".LF-FL7|L7FJFJF-JLJ7LJF-J|LJLJFJFJFJLJF7-|F--7F7|||FJL-7|||F7||FJLJL7LJF7L7L7FJL7F7F-JLJ|L7||FJF7F7|.||L----7LJ.||L7F--7FJFJF7L-------7LJ|F7", "7LF7F7||7||FJFJF-----7L-7|LF-7L-JFL---JL7|L-7||LJLJL-7FJLJ||||||F7F-JF-JL7L7||F-J||L7F--JFJ|||FJLJLJFJL-----JLF-JL-JL-7|L-JFJL-----7F-J.FF|J", "F-F-JLJ|FJLJFJ.L7F-7FJF7LJFJFJF7F----7F7LJF7|LJF-7F7FJL-7FJ||||LJ|L-7L-7LL7|LJL-7||FJL--7|JLJLJF7F7FJF-7F7F7F7|F7F7F-7|L--7L-7FF7F7LJLL--7||", "JJ|F--7LJF7FJF7.LJFJL-JL-7L7L-J|L---7|||F7|LJF-JFJ||L-7FJL7|LJL-7L7FJF7|F-JL---7|||L77F-J|F--7J|||LJFJ-LJLJLJLJ|LJ|L7|L--7L7FJFJLJL7F7|JFJ.|", "|.LJ.LL--JLJFJ|F--JF7F--7|LL7F7L----J||LJ|L77L7FJFJL7JLJ|FJL7F7JL7||FJ||L7F7F7FJ|||FJFJF-JL-7L7||L--J7F7F---7F7L7JL-JL7F7L7||J|F--7|||7||LF|", "-7.FL7FF7LF-JFJL--7|LJ|FJ|F7LJ|F7F--7|L-7L7L--JL-JF-JF---JF7LJ|F7LJ||JLJ7||||||FJ|||FJFJF--7L7LJ|F7|F7||L--7||L7L7F7F7||L7|LJFJ|F7LJ|L--7FJJ", "LF7LJFL|L7|F7L----J|F-7L7||L--J|||F-JL--J-L---7F-7L-7|F7F7|L7FJ||JFJL7F7FJ|LJ|||FJ|||FJ.L-7L-JF7LJL-JLJL--7||L7L7LJLJ|LJFJL7.L7LJ|F7L7F-J7J7", "7L7JFFFL7LJ||F-----JL7|FJLJF-7FJLJL-7F-------7|L7L7FJ||||||FJL-JL7|F7LJ|L7L-7|||L7LJLJF7F7L---JL7F7F7F7F-7LJL-J7L7F-7L-7L--JF-JF-J|L-JL-77L-", "FF7.FL77L-7|LJF------JLJF-7L7LJF7F--J|F-7F-7FJ|FJJLJ|LJ||LJ|F7F7FJ|||F-J-L7FJ|||FJF---JLJL7FF7F7LJLJ||LJLL---77F7LJ||F7L-7F-JF-JF-JF7F--JL7J", "LL|-.F-F77LJF7|F7F7F7F-7L7L-JF7||L---JL7LJ|LJF|L7F----7||F-J|||||FJ||L---7|L7LJLJLL------7L-J||L-7F7LJF77F7F7|FJ|F-7LJ|F7LJF-JLFJF-JLJ-F7.LJ", ".|L-JF|||F7FJLJ|||LJLJFJFJF--JLJL------JF7F7F7L-J|F7F-JLJL-7|||LJL7||F7F-JL7|7|F--7F--7F7L--7|L-7LJL7FJL-JLJLJ|FJL7L-7|||F7L---JFJ7F77FJL7--", "F7|.LFFJLJLJF-7|LJF---JFJFL----7F7F-----JLJLJL--7||||LF7-F-J||L--7||||||-F-J|7LL-7LJF7LJL---JL77L--7|L-------7||F7|F-JLJLJL----7L--JL7|F-J.|", "|L777FL---7FJFJL7FJF7F-JLF-----J|LJF7F7F7F7F----JLJ|L7|L7L7FJ|F7FJ||||LJ.L-7L7-|FL-7||F-----7FJF7-FJL--------J|||||L7F7F7F----7L7F--7LJL7-F7", "|.|LLJ|LF-JL7L--JL-JLJJF7L------JF-JLJLJLJ|L7F7F-7F|FJ|FJFLJJLJ|L7LJLJ7.F|LL7L7|FLFLJLJF7F--JL7||FJF---7F--77FJLJ||FJ|||LJF7F7|FJL7FJF-7L7JJ", "F7L7.LJJL-7FJF-----7-F7|L-7F-----JF77F--7FL-J|||FJFJL-JL--7JF7FL-JJJ.|-L-FJFL7|77---F--JLJF--7||LJFJLF-J|F-JFJF-7LJL-JLJF-JLJLJ|F7||FJFJFJJ.", "F-..JFLJ.FJL7L-7F-7|FJLJF7LJF-7F--JL-JF-JF7F7||||FJF----7FJ7F7JF|.|7F|||FLF7LLJLJ|JLL7F7F-JF-J|L--JF-JF-J|F7L7|-L7F7F--7|F7F7F7|||||L7L7L7-L", "JF|7||JLFL-7|J7LJFJLJF-7|L7FJFJ|F----7L--JLJLJLJ|L7|F--7|L77||-FF-|-F|7FJ-LJ|LJ77LJF7LJLJF-JF7L--7FJF7L77LJL-JL7FJ|LJF7LJ||||||LJLJ|FJ-|FJ7|", "FJ|LF-JFJ..LJ7F--JF7FJJLJFJL7|FJL---7L7F-7F7F7F-JFJLJF7|L-JFJL--7---J.|JJFJ||.LFJ|FJL----JF7|L7F7LJFJL7|F-----7|L7L--JL--JLJLJ||F7JLJ-FJL-77", "|.J-J77FJ-F---JF--JLJ.F7FJF7|LJF7F7FJJ|L7||LJLJFFJF-7|||F-7|F7F-J7L|.--7--.77.F|F-L-----7FJLJ.LJL7FJF-J|L----7||.L7F-7F7F7F7F7|FJL-7--L7F7L7", "|.J7JL|7J.L----JJF-7F7||L-JLJF-JLJLJF7|FJLJF7F-7|FJ7LJLJL7|||LJ|-L7LL..|JFF-JF7-|J-|F7F7LJF7F-7F-JL7|F-JFF7F-JLJF-J||||||||LJLJL7F-JL|7LJL7|", "F7FL7.|LF|J-F7F7FL7LJLJL--7F7L------J|LJF77|||FJ||F---7|FJ||L--7-J|L|.|J--JLLLJ.JJF-JLJL--J|L7||F7FJLJLF-JLJ-F7FJF7L7LJLJLJF7JF7||F7F--7JJLJ", "|-F7J.-7-|-|||||F7|F7F---7|||F7F--7F7L--JL7|LJL-JLJF--JFJFJ|F--JJL|FF..|7JLF-J-7.-L-7F-7F-7L-JLJ|LJF77FJF7-F7||L-JL-J.F----JL7|||||||F-J---J", "LFJJ.F7L7LFF|||LJ|LJLJFF7|||LJ|L-7LJL-----J|F---7F7L-7LL7L-JL7.F77||L|7F|F|L|JFL-J|LLJ.LJJL--7F-JF-JL7L-JL-JLJL7F-----JF-----J|||LJLJL-77LJ|", "F-JJ.|L-F--7||L-7|7F7.FJLJLJF7L--JF---7F---JL--7LJL--JF7|F--7L-J|.LJJLFF-77--7FJ|||.F7F7F----J|F7L--7L7F-------J|F---7FJF7F7F-JLJF--7F7L77L|", "|L--7-|JL-7||L-7||FJL7L--7F-J|F-7FJF--J|F-7F7F7L------JLJL-7L7F7L7L|..||FJ7||J|LFLJFJLJLJF--7FJ|||F7L7|L------7-||F77|L-JLJLJF7F7L-7LJL7|J||", "7-JLJ-|LJ-||L-7||LJF7L---J|F-JL7||FJF7FJL7LJLJ|F--7F---7F-7L7LJL-JF77|F|L7F7JL-7.|.L--7F-JF-J|FJL-JL-JL----7F-JFJLJL7|F----7FJLJ|F7L--7LJ.LJ", "J-..|J|7F-|L7FJ||F7||F7F-7||F-7|LJL-JLJF7L---7|L7F|L-7FJL7|FJF-7J-JJF--JFJ||-L.7JJ7.|-LJF7|F-J|F7F-7F7F7F-7|L--JF-7FJ|L---7|L--7|||F--JL|7.|", "|.--F.F-7.L7|L7|LJLJLJLJFJ|||JLJJF7F-7FJ|F---JL7L7|F7||F7||L7|FJJL|-L--7|7||.|-L-F-7F-77||LJF-J|||LLJLJLJFJ|F7F7|FJL7L7F-7||F7FJ||||JLL-JL-|", "77-L|-L7L--JL-JL-------7L7|||F---J|L7||.|L----7|FJLJLJLJ|||FJ|L77FJ7JF7|L7|L-7-|L7J-L7|FJL--JF-JLJF7F----J|LJLJLJ|F7L7LJ7|||||L7||LJ7JJJ|LF-", ".F7F-77L---7F7F7F---7F7L7LJLJL---7L-J|L7L-----JLJF---7F-J|LJFJFJ-J.F-J|L7LJF-J.F7JF-FJ|L--7F-JF-7FJLJF-7F7-F--7F7LJL-JFF7LJLJL-JLJ|.LJ7F7|||", "F|JJ..-F---J|LJLJF7JLJ|FJF7F-7F--JF7JL-JF7F------JF--JL7FJF7L7|F7J7L-7|FJF7L--7||-F7L7|-F7LJF7L7|L-7FJLLJL7L7FJ||-F----JL-------7J-7-|-LFFJL", "FLJFFF.L----JF---JL---JL7||L7|L--7|L-7F-JLJF7F-7F-JF7JFJ|FJL-JLJL7F7FJ|L7|L7F-J||FJL7||FJ|-FJ|FJ|F7LJLF---JJ||FJL7|F---7F---7F--J7F-.F-LLF7J", "JJ-FFJ-J|LF-7|F7F7F7F7F7LJL-JL7F7LJF-J|F---J|L7|L--JL7L-JL7F--7F-J|||FJ7|L7|L7FJ|L-7LJ|L7L7L7|L7LJL---JF----JLJF7LJL7F7LJF7|LJ|J.--F---7|L7.", "||..LL--77L7|LJLJLJLJLJL-----7LJL--JF7||F--7|FJ|F-7F7|F7F-J|F-J|-FJLJ|F7|FJL-JL7|F7L7FJ.L7L-JL-JF-7F7F7|F---7F-J|F-7LJL--JL---7F--7JL|.|FLL-", "|LF-LJL|FF7|L-7F7|F7F7F7F7|F7L------JLJLJF-JLJFLJ7LJLJ||L--JL-7L7L--7LJLJL--7.L|LJL-J|F7FL--7F7FJJLJ||LJL--7LJF7LJ.L--7F------JJ--L7.--J|7F.", "|LJ.LFFF-JLJF7LJL-JLJLJLJL-J|F--------7F7L7F7F7JF7F7FFJL--7FF7L7L7F7|F---7F-J-FJF---7|||F7-FJ||L---7||F-7F7L--JL7-F7F7LJF7F---7.L|F-7JL-JF--", "LF-|7L-L-7F7|L-------7F--7F7LJF------7LJL7||LJL7|||L7|F-7FJFJL7|FJ|||L--7LJ.F7L-JF--J||||L7|FJL7F--JLJL7LJL---7FJFJLJL7FJLJF--J.F-J-|F-J.|-J", "LLFJL7J|JLJLJF-------JL7FJ|L7FJF-----JF-7|LJF--J|LJFJLJ7||FJF7LJL7||L7F7L-7FJ|F77L--7||LJFJ||F-J|F-----JF----7LJFJF---J|F--JF-7-FL-7-|7L|J7|", "..7JLJJF.|L|.L7F---7F7FJL7L7||FJF-----JFJ|F7L---JF-JF7F7||L-JL--7LJ|FJ|L--JL7LJL7F7FJLJF7L7LJL--JL------JF---JFFJFJF7FFJL---JFJ.7F-7-F|7|LLF", "F7J|F.-777.LF-J|F-7LJLJF7L-JLJL7|F-----J|LJL-----JF-JLJ||L7-F7F7L-7||FJF7-F7L--7||LJF--JL-J.F------------JF7FF7|FJ-||FJF7F---JJFJ7.L.|.77FF|", "||FL|.F7-FLLL--JL7|F7F7||F7F7F7LJL--------7-F7F7F-JF---JL7L-J||L7FJ|||FJL7|L-7FJ|L-7L--7F7F7L-------------JL7|LJL--J||FJ|L-----7JJL7F7-F7--L", "7F-7|FL7|..LF-7F-JLJLJ||LJLJLJL7F---------JFJ||LJF-JLF7F7L7F7LJFJL7||LJF-JL-7|L7|F-JF7FJ||||F----7F--------7LJF-7F-7LJL7L------J.7--LJ.--J-J", "LJJFLJFLF..FL7|L-----7||F-----7LJF-7F7F7F77|FJ|F-JLF7||||LLJL7FJF7|||F-JF7F7|||||L-7|LJL|LJ|L---7|L7F-7F--7|F7L7LJ||F-7L-----7LFF.J7|.7JJ-F7", "L|.L|J-7F--LJ|L------J|LJF--7FJF7||LJ||LJL-JL-JL--7||||||F7F-JL-JLJLJL7FJ|||||FJL7FJL7|FJF-JF7FFJ|.LJFLJLFJ||L7L7F-JL7|F----7L--777FLFJ..7J|", "FF|||7F|J|.|.L--7F---7L-7L-7|L-JLJF--J|F----7F-7F-J||||||||L-------7F-JL7LJLJ||F7|L-7L7|FJF-JL7L7L--7F7|FJ.LJ-|FJL-7FJ|L---7|F--J-FJ-|-F-||.", "L7LF7JJ.L-7-7.F7LJF--JF7L-7|L--7F7L---J|FF-7||FJL--J|||||||F77F7F7FJL7JJL7F--JLJ|L-7L7LJ|L|F-7|LL--7LJL7L----7|L-7FJL7L7F7FJ|L---7L|-|.|7||J", "LJ.L||7.|||JF-JL--JF7FJ|F7LJF-7LJL7F7F7L7|FJLJL7F7F-J||||||||FJ||LJF7L7FFJL--7F7L-7|FJF-JFJL7||F---JF-7L-----JL--JL7FJ||||L7L7F-7|7|L7FFLJ|.", ".F7JF-FJJ-|.L-----7|||FJ|L7FJFL7F7LJLJL7LJL--77LJLJ7FJ||||LJ|L7|L-7|L7|FJF---J||F-J|L7L77|F-JLJL--7FJ.L--7F7JF7F7F7|L-7||L-J7LJ-LJ||.L-|FLJ-", "FLJF|-L7J.|.L-F---J|LJL7|7LJ|F7LJL----7|F----JF7F--7L7LJLJF-JFJ|F-JL7LJL7|F7-FJ|L-7L7|FJFJL-7F7FF7LJ7F-7FJ|L7|LJ|||L--JLJF-7F7|FJ-FL7.|LFL7J", "LL|7FFJ-.-L..FL---7|F-7LJF-7FJL-------J|L77F7-|LJF7L7L---7L7F|FJL-7FJ|F-JLJL7L7L7LL7LJL7|F--J||FJL7F7L7|L-JFJ|F-J||F7F-77L7LJL77.---L7L7JLF.", "F--JJ|LF7|77FLF--7LJL7|F7L7LJF--7F-7.F7L-JFJL7L7FJL-JF7F7|FJFJ|JF7||F7L--7F-JFJFJF7L--7|||F-7||L-7LJ|FJL---JFJL--J|||L7L7FJF--J7.|J.|F7|.|LL", "|FFJ-|7FL-7F--JF7L---JLJL-JF7|F7LJ7L-JL-7.|F-JFJL-7F7|||LJL7L7|FJ||LJL7F7||F7L7L7|L7F7|||||FJ||F7L-7|L7F-7F7L7F---J|L7|FJL7|F7J.F7L77.F.L-.|", "--|JF--7JJ-L---J|F7F----7F-JLJ||F-------JFJ|F7|F--J||||L-7FJFJ|L7LJF--J|LJLJL7L7|L7||LJ|||||-|||L7FJ|FJ|7LJL-JL--7JL7|||F-JLJL7FJL7||F-7L|FJ", "|L|F7.LL||FF---7LJLJF7F-J|F7F-JLJF---7F-7L7|||||F7-|LJ|F-JL-JFJJ|F-JF7-L-7F--JFJL7||L-7LJ|||FJ||FJL7|L-JF--7F7F--JF7|||LJF-7F7LJF-JF77L|L|7J", "F7L||7.||FFL--7|7F7FJLJF-J||L---7|JF-J|FJFJLJ||||L7L-7|L-7F--JF7||F7||F7FJ|F--JF-J|L-7|F7LJ||FJ|L7FJL7F7L-7|||L---JLJLJF-J7LJL--JJFJL7.|.FJJ", "F|JLJJ-7F-----JL-JLJF7FJ-FJL-7F-JL7|F7||.L-7FJ|||FJF7||F7||LF7||||||||||L7|L--7|F7L-7|LJ|F-J||-L7|L7FJ||FFJ|||F7F--7F-7L---7F-----JF7|77..L7", "FJ|LJ7|LL7F7F-7F-7F-J||F-JF-7LJF--JLJ|||F-7|L7|||L7|||||||L7|LJ||||||||L-JL7F7|||L7FJL7FJL7FJL7FJ|FJ|FJL7L7LJLJ||F7|L7L7F--J|F-----JLJ7--7.-", "7JJ-|--|FLJLJFJ|FJL7-LJL7FJLL7FJF----J||L7||7||||FJ|LJ||LJFJL-7||||LJ|L--7FJ|||LJFJ|F-J|F-JL7FJ|FJL7LJ7LL7L-7F-JLJ||FJFJ|7F-JL------7FF7LJ7|", ".|.FJ|.LJJF--JFJL7FJF7F-J|F7FJL7L7F7F-J|FJ|L7LJ||L7L7F|L-7L-7FJ||LJF-JF-7|L7||L-7L7||F7|L7F-JL7||F7L--7JFJF-J|F-7FJLJ-L7L-JF7F---7F7|-|-.F-7", "FF77.7-L.LL-7FJF-J|FJLJF7||LJF-JFLJ||F-JL7|FJF-JL7|FJFJF-J|FJL7LJF-JF7L7|L7|||F-JJ||LJ||FJL-7FJ|LJ|F-7L7L7L-7LJ-|L---7FJF7FJ|L--7LJLJJL|-7-|", "-FJ.FF7.L7..LJFJF7|L---JLJL7FJF----J|L7F7||L7L-7FJ|L7L7L--7|F7L7FJF7||FJ|FJ|||L--7LJF-J|L7F7|L7L-7|L7L7|-|F7L-7FJF7F7||FJ|L7L7F-J||.||F-7|L|", "L|L|-|-F.|-L7-L7|||F-7F----JL7L7F7F7L7LJ||L-JJFJL7|FJFJF--J||L-JL7||||L7||FJ|L7F-JF-JF7|FJ|||FJF-JL-J7|L7|||F7||FJLJLJ||J|FJ7||F777|LJ7JLL.J", ".7JL-7.L-J7LF--J|LJL7LJF-7F7FJFJ|||L-JJFJL-7|FJF7|||7L7L--7|L-7F7||LJ|FJLJ|FJFJL7.L-7||||FJ||L7L--7.F-JFJ||LJLJ|L-7F7|||FJL-7|LJL-7J|L|-7J..", "L7-FL77J.L|.L--7|...L-7L7LJ||LL7|||F---JF7FJFJFJ||||F-JF7FJ|F-J|LJL7FJL7F-JL7L-7L-7FJ|LJ|L7||L|F-7L7L7FJ.|L-7F7L7FJ|L7|||F-7|L-7F-J7J..||JF|", "FJF--LLJF-.7JJLLJ.F7|L|FJF-JL-7||||L7F-7||L7|FJFJ||||F7|||FJL-7|F7FJL7FJL7F7|F-JF-JL7L-7L7|LJFJL7L-J||L-7|F7LJL7|L7L7LJ|||FJL-7|L-7L7..F7.|.", "|.-..|.LF|7L|FJ7-F7F7FJL7L7F7FJLJ|L7||JLJL7||L7L7|||LJ||||L7F-JLJ|L-7|L-7||||L-7L--7L7FJFJ|F-JF7L---7L7FJ|||F7FJ|FJFJF7||||F-7|L--J-J77||F-L", "J7J-|7FFFF-.LF7J.|||LJF-J|LJ||F--JFJ|L7F--J|L7|F|||L7LLJ||FJ|FF7FL-7||F7||||L7F|F-7|FJL7L-JL7FJL7F7FJ|LJ7LJ|||L7LJ-L7|||LJLJ-||.|J.LLF77-J.|", ".L7..F-J.|7F-FJLFJLJF7L7F7F7LJL7F7L7L7|L7F7L7|L7|||FJF--J|L7L-JL--7LJ||LJLJL7|FJL7|||F7|F--7|L-7LJ|L--7F--7LJL7L-7F7LJ|L-7L|.LJ7|.7LL|L--L-7", "7.|.-JJFFJFL-F7LL--7||FJ|LJL---J|L7L7LJ-LJL7|L7|LJ||.L--7|FJF7F7F7L7F|L---7|LJL7FJ||||LJL-7LJF7L-7|F-7LJF-J.F-JF7LJL7|L7FJ7.FJ.F--|7F--L-|-L", "FFLLJ|JF7.FJ.LL-LF-J||L7L7F7F--7L7L7|F-----JL7LJF7LJF7F-J||FJ|||||FJFJF7F-JF7F-J||LJ||F---JF7|L7FJ|L7L-7L-7FJF-J|F7FJ-JLJLJF7|LJ|FJ--|L|7F-J", "-7JLFJ|L|7L-7.|7LL-7||FJ.|||L7.L7L7|||F7F--7FJ-FJL-7|LJF7||L7|||||L7|FJ||F-JLJF7L-7.LJ|F--7||L7||JL7L-7L7FJL7L-7LJLJ77|LJ|LL|7F7-JJJ.F-7FLLJ", "||J...|.FJ.LF-LJ|.FLJLJ|-LJL7|F-JFJ||||LJF-JL--JF7FJL-7|||L7|||LJ|FJ|L7||L7F7FJ|F7L--7||LFJ||FJ|L-7L7FJLLJFFJF7L--7-L7FJ-JJ|LL7LJ7|J.L.|7.||", "L--77L--||FJF-L|J77L7.FL.FJF||L7FJL||LJF7|F7F---J|L7.FJ||||LJ|L-7LJ|L7|LJLLJ|L7||L7F7||L7L7||L7|F7L7LJF7F-7L7|L7F-J77|LF77-|JL-|LL7FF7F.F7-F", "|LL-JJJF-J.FJ-.LJ|JJ777|-J-FJL7LJJ.||F-J|LJ|L--77L7L7L7|||F--JF7L---7||F-7F-JFJ||FJ|||L-J.||L7|LJL7L--J|L7L7||FJL7JL7|F-FL.|.||.FL-JFJJ7LJL-", "-7LLF-F7L|LJJLJJF.|L-J|L-7FL7FJL|FFLJL-7L7FL7F7L-7L7|FJ||||F7FJ|F7F7|||L7LJF7L7LJL7|||F7F7LJ.|L--7L----JJ|FJLJL7FJJ.L|..|FF|-LLF-7JFJ|JF7LFJ", "L|7.|LL--L.LF7.L|.FJL-L.FF|LLJ..77L|LF-JFJF7|||F-JFJ|L-J||LJ||J||LJ||LJ-L7FJL7L--7|||LJLJ|F--JF-7L7FF----J|F7F7||J.--7-JJ7F---J|F7-L7J|L|L||", ".FJF-7FJ.F7FL-L-7J|7..L|-FJ|LJLLJLFF7L-7|F|LJ|||F7L7L-7FJ|F-JL7LJF-J|F-77LJF-JF7FJLJ|F7F7|L7F7|-|FJFJF7F-7LJLJ|LJJ7|FJJ.FFFJL7-JJL-FJ-L-7|.7", "FJ|L-77.F-|L|.L|J7|FJJ-L7|J7.7J|FFFJL--JL7L-7|LJ||-L--JL7|L-7FJF7L-7|L7L---JF7|LJ7F-J|LJLJFJ|||FJL-JFJ|L7|F-7FJJL-F7|..LLJL--F7L-J..L-7FFJ-|", "-.|7..J-J-|JL7LL.LJ||J7JFJL-7JL7-FJF----7L--JL--JL-----7||F-JL-JL-7|L7L-7F7FJ||.F-JF7L7F7JL7|LJL7F7FJFL-JLJFJ|77|LJF--7||J-J-|--|77L7.--L.||", "LJ7-F7JL|||LFJ.J.F-7J-L7JF--J.L|L|FJF7F7L7F-7F-7F7F---7|LJ|F-7F7F-JL7L-7||||FJL7|F7|L7LJL7FJ|FF-J||L-7-F7F7L-JF|7-LL7F--7J-|LF-7L-7|-FJJ..F-", "F--7LJ|LFJ.F|7-7F|7|FJ--7LJ|J.F7JLJFJLJL-J|FJL7|||L--7|L7J|L7|||L7|.L--J||||L7FJ||||FJF7FJL7|FJF7||F7L7|LJL-7-FJ|-J.|7JL7|.|JJ.|FL||L-J7F-7J", "|.L|7FJ7|F7-7JL|7FL|7|-|J----L-L7..L7F7F-7|L7FJLJ|F--JL-JFJFJ||L7|J7|J|FLJ||FJ|FJ|LJL-J||J7|||FJ||||L7LJF--7|-7|L7|.L77-7-|F-..LFL--.L7F-.|J", "LF7L7JJF-|JJL7FL-F7F-7F||||.7J.L|-LJ||||FJ|FJL7F-J|F7F-7|L7L7|L7LJ|FJ||7.FJ|L-JL7L7F---JL-7LJ||7|||L7L-7L7-LJFJ77.FJ.LL7F7L7F77-FJ7F|JFJF7J.", "|L77|||L|J|7--7.|L-J-7JJ-.7-L7LF|-L-LJLJL7||F-JL7FJ||L7L-7L7||FJ-|-JF7L-LL7|J-|F|FJL-7F7F-JF-JL7||L-JJFJFJ.||7L7-F7--JFFLL7LJ.7-|FF77JFJ7|F7", "FJ||LFJ|L7L7J7|-L.LFF-JJ.JJ7L|.7|F..L|7J||||L7F7|L-JL7L7FJ|LJ|L77.L|F-7|FL|||.FFLJF--J|LJ-LL-7FJ|L7.F-JFJJLJ|FFJ-|J.LFJ7J|7|.7JF|FL|.FJ.FF7.", "L-FJ|F.L-LF-7-LJL7|F7J77-LF-FJ||L7FL-JL7LLJL7||LJF7F7L-JL7F--JFJ-J||J|LJ--|L77..|7L--7L7-LJ||LJL|FJ-L-7|JFJFLF.-7LJ..|JJ7F|7-|LFJ7.77-JF|JLJ", "L7JLJJ.L-.|-|7J7F7-LJ|-7-LL-7JLJLLFJLF|-7L|JLJL7FJ|||F7F-J|F-7L-7J||FLFJ-F|FJJF7LJ-FFJFJ7.F-|F|-LJ.|LLLJ||JL----L-JF7J7FLJ|L7|FJ..FLJ|F7|L7|", "L-J.|-77-FJ7LJF7|J..FL7|-.FF|F||F-F7JFJJ|7LFLF-JL7|||||L-7LJFJF-J7F7J-|FFLLJ7FFJF||FJFJ.L.F7|LLL.|FF-L7LLJ|.FL77J|7F|J-JL||LJF7-F7L|FF-L|-|J", "FJL-L-FJ-7-77LLL---7.FL-.F7-F-7LJ||JJLJ.L-7F7L7F-JLJLJL7FJJJL7L7L7JJL-7F|FLJ7-L--F7L-J-7-J||J7.|7FL-..L---JJ7FJ|--FLJJ7--L7J.-J7L7-F|LL|JFJ7", "F.||JFJ.7.F|J.LF|7-J--J.L-7F7FJ|LJ---L-J7.FJL-JL-7F----JL-7|||FJL-7.L-F-L7|JJ.||J|L7-|7L.|-|J7F7---F--LLFJ|.LJ||7|.|-|FF7LL.|.L|-J7LJ.J.FLJ|", "L7-LF-L-J-J.L-.7-JLLJLJ|LLLFJL.F.|.LJL7J--L------JL-------J7-LJJ7.|J..LL-JJJ.-FJFF-L-7JJ-|-|-F---L-J.-.L|-FJ-L--J7-J7.FF-LJ.J7-FJL7.L-.LFJ.|" };

struct direction {
    bool n = false, e = false, s = false, w = false;
};

class PipeMaze {
public:
    PipeMaze(const vector<string>& _input)
        : maze(_input)
    {
        mazesize.first = maze.size(); // y coordinate, line
        mazesize.second = maze[0].size(); // x coordinate, column
        cout << "Size of maze: " << mazesize.second << " x " << mazesize.first << endl;

        // Find S:
        for (long line = 0; line < mazesize.first; ++line)
            for (long column = 0; column < mazesize.second; ++column)
                if ('S' == maze[line][column])
                    spos = { line, column };

        // What is S for an element?
        direction dirS;
        direction dir;
        dir = getDirection(getPipe({ spos.first - 1, spos.second }));
        if (dir.s)
            dirS.n = true;
        dir = getDirection(getPipe({ spos.first + 1, spos.second }));
        if (dir.n)
            dirS.s = true;
        dir = getDirection(getPipe({ spos.first, spos.second - 1 }));
        if (dir.e)
            dirS.w = true;
        dir = getDirection(getPipe({ spos.first, spos.second + 1 }));
        if (dir.w)
            dirS.e = true;

        // Check that S has exactly two options
        int dircount = 0;
        if (dirS.n)
            ++dircount;
        if (dirS.e)
            ++dircount;
        if (dirS.s)
            ++dircount;
        if (dirS.w)
            ++dircount;

        if (2 != dircount)
            cout << "S has more than on options!" << endl;

        if (dirS.n && dirS.s)
            spipe = '|';
        else if (dirS.e && dirS.w)
            spipe = '-';
        else if (dirS.n && dirS.e)
            spipe = 'L';
        else if (dirS.n && dirS.w)
            spipe = 'J';
        else if (dirS.s && dirS.w)
            spipe = '7';
        else if (dirS.s && dirS.e)
            spipe = 'F';
        else
            cout << "Unknown S pipe!" << endl;
    }

    char getPipe(pair<long, long> pos)
    {
        if (pos.first < 0 || pos.first >= mazesize.first || pos.second < 0 || pos.second >= mazesize.second)
            return '.';

        return maze[pos.first][pos.second];
    }

    direction getDirection(pair<long, long> pos)
    {
        if (pos == spos)
            return getDirection(spipe);

        return getDirection(getPipe(pos));
    }

    static direction getDirection(char pipe)
    {
        direction dir;
        switch (pipe) {
        case '|':
            dir.n = true;
            dir.s = true;
            break;
        case '-':
            dir.e = true;
            dir.w = true;
            break;
        case 'L':
            dir.n = true;
            dir.e = true;
            break;
        case 'J':
            dir.n = true;
            dir.w = true;
            break;
        case '7':
            dir.s = true;
            dir.w = true;
            break;
        case 'F':
            dir.s = true;
            dir.e = true;
            break;
        case '.':
            break;
        default:
            cout << "Unknown pipe: " << pipe;
            return dir;
        }

        return dir;
    }

    long getResultA(bool fillPath = false)
    {
        long resultA = 0;
        pair<long, long> curpos(spos);
        char lastdirection = ' ';

        auto tempmaze = maze;

        do {
            direction dir = getDirection(curpos);
            if (lastdirection == 's')
                dir.n = false;
            if (lastdirection == 'n')
                dir.s = false;
            if (lastdirection == 'e')
                dir.w = false;
            if (lastdirection == 'w')
                dir.e = false;

            if (dir.n) {
                --curpos.first;
                lastdirection = 'n';
            } else if (dir.s) {
                ++curpos.first;
                lastdirection = 's';
            } else if (dir.e) {
                ++curpos.second;
                lastdirection = 'e';
            } else if (dir.w) {
                --curpos.second;
                lastdirection = 'w';
            } else {
                cout << "No possible move at << " << curpos.first << "x" << curpos.second << endl;
                return 0;
            }

            tempmaze[curpos.first][curpos.second] = '0';

            ++resultA;
        } while (curpos != spos);

        resultA /= 2;

        if (fillPath)
            maze = tempmaze;

        cout << "resultA: " << resultA << endl;
        return resultA;
    }

    long getResultB()
    {
        long resultB = 0;

        // Make the loop double the size of the maze
        vector<string> loop;
        for (long line = 0; line < mazesize.first; ++line) {
            string currentline;
            for (long column = 0; column < mazesize.second; ++column) {
                currentline += maze[line][column];
                if (getDirection({ line, column }).e && getDirection({ line, column + 1 }).w)
                    currentline += "-";
                else
                    currentline += ";";
            }
            loop.push_back(currentline);

            // Add additional line
            currentline.erase();
            for (long column = 0; column < mazesize.second; ++column) {
                if (getDirection({ line, column }).s && getDirection({ line + 1, column }).n)
                    currentline += "|;";
                else
                    currentline += ";;";
            }
            loop.push_back(currentline);
        }

        maze = loop;
        mazesize.first *= 2;
        mazesize.second *= 2;
        spos.first *= 2;
        spos.second *= 2;

        getResultA(true);

        // Erase Border
        for (long line = 0; line < mazesize.first; ++line) {
            if ('0' != maze[line][0])
                maze[line][0] = ' ';
            if ('0' != maze[line][mazesize.second - 1])
                maze[line][mazesize.second - 1] = ' ';
        }
        for (long column = 0; column < mazesize.second; ++column) {
            if ('0' != maze[0][column])
                maze[0][column] = ' ';
            if ('0' != maze[mazesize.first - 1][column])
                maze[mazesize.first - 1][column] = ' ';
        }

        // Floodfil outer area
        bool found = true;
        while (found) {
            found = false;

            for (long line = 1; line < mazesize.first - 1; ++line)
                for (long column = 1; column < mazesize.second - 1; ++column)
                    if ('0' != maze[line][column] && ' ' != maze[line][column])
                        for (long l = line - 1; l <= line + 1; ++l)
                            for (long r = column - 1; r <= column + 1; ++r)
                                if (' ' == maze[l][r] && (line != l || column != r)) {
                                    maze[line][column] = ' ';
                                    found = true;
                                }
        }

        // Count fields
        for (long line = 0; line < mazesize.first; line+=2)
            for (long column = 0; column < mazesize.second; column+=2)
                if (maze[line][column] != '0' && maze[line][column] != ';' && maze[line][column] != ' ')
                    ++resultB;

        // Re-paint maze
        for (long line = 1; line < mazesize.first; ++line)
            for (long column = 1; column < mazesize.second; ++column)
                if ('0' == maze[line][column]) {
                    switch (maze[line][column]) {
                    case 'F':
                        maze[line][column] = 218;
                        break;
                    case 'L':
                        maze[line][column] = 192;
                        break;
                    case 'J':
                        maze[line][column] = 217;
                        break;
                    case '7':
                        maze[line][column] = 191;
                        break;
                    case '-':
                        maze[line][column] = 196;
                        break;
                    default:
                        maze[line][column] = maze[line][column];
                        break;
                    }
                }

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    vector<string> maze;

    pair<long, long> mazesize;
    pair<long, long> spos;
    char spipe;
};

TEST_CASE("Testdata")
{
    PipeMaze PipeMazeData(inputTestdata);
    REQUIRE(8 == PipeMazeData.getResultA());
    REQUIRE(1 == PipeMazeData.getResultB());
}

TEST_CASE("Testdata2")
{
    PipeMaze PipeMazeData(inputTestdata2);
    REQUIRE(4 == PipeMazeData.getResultB());
}

TEST_CASE("Testdata3")
{
    PipeMaze PipeMazeData(inputTestdata3);
    REQUIRE(4 == PipeMazeData.getResultB());
}

TEST_CASE("Testdata4")
{
    PipeMaze PipeMazeData(inputTestdata4);
    REQUIRE(8 == PipeMazeData.getResultB());
}

TEST_CASE("Testdata5")
{
    PipeMaze PipeMazeData(inputTestdata5);
    REQUIRE(10 == PipeMazeData.getResultB());
}

TEST_CASE("PipeMaze")
{
    PipeMaze PipeMazeData(inputData);
    REQUIRE(6778 == PipeMazeData.getResultA());
    REQUIRE(433 == PipeMazeData.getResultB());
}