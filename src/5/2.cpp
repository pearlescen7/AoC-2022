#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::stack<char> s[9]{};
    s[0].push('B'); s[0].push('S'); s[0].push('V'); s[0].push('Z'); s[0].push('G'); s[0].push('P'); s[0].push('W');
    s[1].push('J'); s[1].push('V'); s[1].push('B'); s[1].push('C'); s[1].push('Z'); s[1].push('F');
    s[2].push('V'); s[2].push('L'); s[2].push('M'); s[2].push('H'); s[2].push('N'); s[2].push('Z'); s[2].push('D'); s[2].push('C'); 
    s[3].push('L'); s[3].push('D'); s[3].push('M'); s[3].push('Z'); s[3].push('P'); s[3].push('F'); s[3].push('J'); s[3].push('B'); 
    s[4].push('V'); s[4].push('F'); s[4].push('C'); s[4].push('G'); s[4].push('J'); s[4].push('B'); s[4].push('Q'); s[4].push('H'); 
    s[5].push('G'); s[5].push('F'); s[5].push('Q'); s[5].push('T'); s[5].push('S'); s[5].push('L'); s[5].push('B'); 
    s[6].push('L'); s[6].push('G'); s[6].push('C'); s[6].push('Z'); s[6].push('V'); 
    s[7].push('N'); s[7].push('L'); s[7].push('G'); 
    s[8].push('J'); s[8].push('F'); s[8].push('H'); s[8].push('C');

    std::ifstream input("input.txt");
    std::string line;
    while(std::getline(input, line, '\n')) {
        std::stringstream ss{line};
        std::string temp;
        int cnt, s1, s2;
        ss >> temp >> cnt >> temp >> s1 >> temp >> s2;
        --s1; --s2;

        std::stack<char> temp_s;
        for(int i = 0; i < cnt; ++i) {
            temp_s.push(s[s1].top());
            s[s1].pop();
        }
        for(int i = 0; i < cnt; ++i) {
            s[s2].push(temp_s.top());
            temp_s.pop();
        }
    }

    std::cout << s[0].top() << s[1].top() << s[2].top() << s[3].top() << s[4].top() << s[5].top() << s[6].top() << s[7].top() << s[8].top();

    return 0;
}


