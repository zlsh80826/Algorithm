#include <iostream>

int main(int argc, char const *argv[]) {
    int T;
    std::string str;
    std::cin >> T;
    while (T --) {
        int score = 0;
        int sum = 0;
        std::cin >> str;
        for (int i = 0; i < str.size(); ++ i) {
            if (str[i] == 'O') sum += (++ score);
            else score = 0;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}