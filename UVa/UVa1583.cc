#include <iostream>
#include <string.h>

int ans[100000 + 10000];

int main(int argc, char const *argv[]) {
    int T;
    std::cin >> T;
    memset(ans, 0, sizeof(ans));
    for (int i = 100000 + 1000; i >= 0; -- i) {
        int result = i;
        int tmp = i;
        while (tmp / 10) {
            result += tmp % 10;
            tmp /= 10;
        }
        result += tmp % 10;
        if (result <= 100000)
            ans[result] = i;
    }
    while (T --) {
        int query;
        std::cin >> query;
        std::cout << ans[query] << std::endl; 
    }
    return 0;
}