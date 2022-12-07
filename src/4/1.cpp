#include <iostream>
#include <fstream>
#include <string>
#include <charconv>

std::pair<std::string_view, std::string_view> split(std::string_view line, char delim) {
    auto idx = line.find(delim);
    return { std::string_view(line).substr(0, idx), std::string_view(line).substr(idx+1) };
}

int main(int argc, const char** argv) {
    std::ifstream input("input.txt");
    std::string line;
    int cnt=0;
    while(std::getline(input, line, '\n')) {
        auto [r1, r2] = split(line, ',');
        auto [r1b, r1e] = split(r1, '-');
        auto [r2b, r2e] = split(r2, '-');

        long long r1bn, r1en, r2bn, r2en;
        std::from_chars(r1b.data(), r1b.data() + r1b.size(), r1bn);
        std::from_chars(r1e.data(), r1e.data() + r1e.size(), r1en);
        std::from_chars(r2b.data(), r2b.data() + r2b.size(), r2bn);
        std::from_chars(r2e.data(), r2e.data() + r2e.size(), r2en);

        if((r1bn <= r2bn && r1en >= r2en) || (r2bn <= r1bn && r2en >= r1en))
            ++cnt;
    }
    
    std::cout << cnt;
    return 0;
}