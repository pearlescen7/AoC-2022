#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::ifstream input("input.txt");
    std::string line;
    std::unordered_set<char> s;
    long long sum = 0;
    while(std::getline(input, line, '\n')) {
        auto r1 = std::string_view(line).substr(0, line.length()/2);
        auto r2 = std::string_view(line).substr(line.length()/2);

        for(const auto& c : r1)
            s.insert(c);

        char shared;
        for(const auto& c : r2) {
            if (s.find(c) != s.end()){
                shared=c;
                break;
            }
        }
        sum += std::islower(shared) ? int(shared) - 96 : (int(shared) - 38);
        s.clear();
    }

    std::cout << sum;

    return 0;
}
