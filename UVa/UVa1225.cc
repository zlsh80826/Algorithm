#include <iostream>

const int MAX = 10000 + 10;
int ans[MAX][10];

void init() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < 10; ++j) {
            ans[i][j] = 0;
        }
    }
}

void cal(int n) {
    int dim1 = n;
    for (int i = 0; i < 10; ++i) {
        ans[n][i] = ans[n - 1][i];
    }
    while (n / 10) {
        ans[dim1][n % 10]++;
        n /= 10;
    }
    ans[dim1][n % 10]++;
}

int main() {
    init();
    for (int i = 1; i < MAX; ++i) {
        cal(i);
    }

    int T, n;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < 10; ++i) {
            if (i == 0)
                std::cout << ans[n][i];
            else
                std::cout << " " << ans[n][i];
        }
        std::cout << "\n";
    }
}