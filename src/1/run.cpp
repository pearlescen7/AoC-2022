#include <iostream>
#include <fstream>
#include <string>
#include <queue>

int main(int argc, const char** argv) {
    std::ifstream input("input.txt");

    long long sum=0;
    std::string line;
    std::priority_queue<long long> q;
    while(getline(input, line, '\n')) {
        if(line.empty()) {
            q.push(sum);
            sum=0;
        }
        else
            sum+=std::stoll(line);
    }

    long long total_sum = 0;
    for(int i = 0; i < 3; ++i)
    { total_sum += q.top(); q.pop(); }

    std::cout << total_sum;

    return 0;
}