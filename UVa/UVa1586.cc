#include <iomanip>
#include <iostream>
#include <map>
#include <stack>

std::map<char, double> value;
std::stack<char> stk;

int main() {
    int T;
    std::string str;
    std::cin >> T;
    value['C'] = 12.01;
    value['H'] = 1.008;
    value['O'] = 16.00;
    value['N'] = 14.01;
    while (T--) {
        std::cin >> str;
        double sum = 0.0;
        for (int i = 0; i < str.size(); ++i) {
            if (isalpha(str[i]))
                stk.push(str[i]);
            if (isdigit(str[i])) {
                int multi = str[i] - '0';
                while (isdigit(str[i + 1])) {
                    multi *= 10.0;
                    multi += (str[++i] - '0');
                }
                sum += value[stk.top()] * multi;
                stk.pop();
            }
        }
        while (!stk.empty()) {
            sum += value[stk.top()];
            stk.pop();
        }
        std::cout << std::fixed << std::setprecision(3) << sum << std::endl;
    }
}