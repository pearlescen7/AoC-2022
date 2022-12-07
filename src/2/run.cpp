#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

// A B C
// X Y Z
// R P S

int main(int argc, const char** argv) {
    std::map<std::pair<char, char>, int> m = {
        {{'A', 'X'}, 4}, //rock rock => 1 + 3
        {{'A', 'Y'}, 8}, //rock paper => 2 + 6
        {{'A', 'Z'}, 3}, //rock sci => 0 + 3
        {{'B', 'X'}, 1}, //paper rock => 0 + 1
        {{'B', 'Y'}, 5}, //paper paper => 3 + 2
        {{'B', 'Z'}, 9}, //paper sci => 3 + 6
        {{'C', 'X'}, 7}, //sci rock => 1 + 6
        {{'C', 'Y'}, 2}, // sci paper => 2 + 0
        {{'C', 'Z'}, 6}, // sci sci => 3 + 3
    };

    //X Y Z
    //L D W
    std::map<std::pair<char, char>, int> m2 = {
        {{'A', 'X'}, 3}, //rock sci => 0 + 3
        {{'A', 'Y'}, 4}, //rock rock => 3 + 1
        {{'A', 'Z'}, 8}, //rock paper => 2 + 6
        {{'B', 'X'}, 1}, //paper rock => 0 + 1
        {{'B', 'Y'}, 5}, //paper paper => 3 + 2
        {{'B', 'Z'}, 9}, //paper sci => 3 + 6
        {{'C', 'X'}, 2}, //sci rock => 1 + 6
        {{'C', 'Y'}, 6}, // sci paper => 2 + 0
        {{'C', 'Z'}, 7}, // sci sci => 3 + 3
    };


    std::ifstream input("input.txt");
    std::string line;
    long long point=0;
    while(getline(input, line, '\n')) {
        char o = line[0], me=line[2];
        point+=m2[{o, me}];
    }

    std::cout << point;

    return 0;
}