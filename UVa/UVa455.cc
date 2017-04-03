#include <iostream>
#include <string>

int main() {
    int T;
    std::string str;
    std::cin >> T;
    while (T--) {
        std::cin >> str;
        int ans = 0;
        for (int i = 1; i <= str.size(); ++i) {
            if (ans)
                break;
            if (str.size() % i > 0)
                continue;
            bool match = true;
            std::string substr = str.substr(0, i);
            for (int l = 0; l < str.size() && match; l += i) {
                std::string ref = str.substr(l, i);
                if (ref != substr)
                    match = false;
            }
            if (match)
                ans = i;
        }
        std::cout << ans << std::endl;
        if (T)
            std::cout << '\n';
    }
}