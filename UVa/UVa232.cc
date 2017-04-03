#include <iostream>
#include <iomanip>
char map[10][10];
int down_count[10];
int value[10][10];

void solve_across(int n, int m) {
    std::cout << "Across\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (isalpha(map[i][j])) {
                std::cout << " " << std::setw(2) << value[i][j] << ".";
                while (j < m && map[i][j] != '*') std::cout << map[i][j++];
                std::cout << std::endl;
            }
        }
    }
}

void solve_down(int n, int m) {
    std::cout << "Down\n";
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (value[i][j] > 0) {
                int start = i;
                std::cout << " " << std::setw(2) << value[i][j] << ".";
                while (start < n && map[start][j] != '*') {
                    value[start][j] = -1;
                    std::cout << map[start++][j];
                }
                std::cout << std::endl;
            }
        }
    }
}

void init() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            value[i][j] = -1;
        }
    }
}

void fill_value(int n, int m) {
    int v = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (((i < 1) || (j < 1) || map[i][j - 1] == '*' || map[i - 1][j] == '*') &&
                (map[i][j] != '*')) {
                value[i][j] = ++v;
            }
        }
    }
}

int main() {
    int N = 0;
    while (true) {
        int n, m;
        std::cin >> n;
        if (n == 0)
            break;

        std::cin >> m;
        init();

        for (int i = 0; i < m; ++i) {
            down_count[i] = n;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> map[i][j];
                if (map[i][j] == '*')
                    down_count[j] = std::min(i, down_count[j]);
            }
        }
        fill_value(n, m);
        if (N) std::cout << std::endl;
        std::cout << "puzzle #" << ++N << ":" << std::endl;
        solve_across(n, m);
        solve_down(n, m);
    }
}