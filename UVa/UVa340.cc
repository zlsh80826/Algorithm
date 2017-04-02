#include <iostream>
#include <map>

int n;
int ans[1000 + 10];
int guess[1000 + 10];

int main(int argc, char const *argv[]) {
    int m = 0;
    while (std::cin >> n && n > 0) {
        std::cout << "Game " << ++ m << ":" << std::endl;
        for (int i = 0; i < n; ++ i)
            std::cin >> ans[i];

        while (true) {
            bool allzero = true;
            for (int i = 0; i < n; ++ i) {
                std::cin >> guess[i];
                if (guess[i] != 0)
                    allzero = false;
            }
            if (allzero) break;

            int A = 0, B = 0;
            for (int i = 0; i < n; ++ i) {
                if (ans[i] == guess[i]) ++ A;
            }

            for (int i = 1; i < 10; ++ i) {
                int ans_sum = 0, guess_sum = 0;
                for (int j = 0; j < n; ++ j) {
                    if (ans[j] == i) ++ ans_sum;
                    if (guess[j] == i) ++ guess_sum;
                }
                B += std::min(ans_sum, guess_sum);
            }

            std::cout << "    (" << A << "," << B - A << ")" << std::endl;
        }
    }
    
    return 0;
}