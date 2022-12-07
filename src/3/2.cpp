#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::ifstream input("input.txt");
    // std::stringstream input{"vJrwpWtwJgWrhcsFMMfFFhFp\njqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\nPmmdzqPrVvPwwTWBwg\nwMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\nttgJtRGJQctTZtZT\nCrZsJsPPZsGzwwsLwLmpwMDw"};
    std::string line;
    std::set<char> s, s2, diff;
    long long sum = 0;
    short line_cnt = 0;
    while(std::getline(input, line, '\n')) {
        char badge;
        switch(line_cnt) {
            case 0:{
                for(const auto& c : line)
                    s.insert(c);
                
                ++line_cnt;
                break;
            }
            case 1:{
                for(const auto& c : line)
                    s2.insert(c);

                std::set_intersection(s.begin(), s.end(),
                                    s2.begin(), s2.end(),
                                    std::inserter(diff, diff.begin())
                                );

                ++line_cnt;
                break;
            }
            case 2:{
                for(const auto& c : line) {
                    if(diff.find(c) != diff.end()) {
                        badge = c;
                        break;
                    }
                }
                
                sum += std::islower(badge) ? int(badge) - 96 : (int(badge) - 38);
                s.clear(); s2.clear(); diff.clear();
                line_cnt=0;
                break;
            }
            default:
                __builtin_unreachable();
        }
    }

    std::cout << sum;

    return 0;
}
