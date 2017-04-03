#include <iostream>
const int size = 5;
char map[size][size];
int ymove[4] = {-1, 1, 0, 0};
int xmove[4] = {0, 0, -1, 1};

int trans(char c) {
    if (c == 'A')
        return 0;
    if (c == 'B')
        return 1;
    if (c == 'L')
        return 2;
    if (c == 'R')
        return 3;
    else
        return -1;
}

void print_table() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j == 0)
                std::cout << map[i][j];
            else
                std::cout << " " << map[i][j];
        }
        std::cout << "\n";
    } 
}

int main() {
    int n = 0;
    while (true) {
        char c;
        bool isterminate = false;
        int x = -1, y = -1;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                map[i][j] = getchar();
                if (i == 0 && j == 0 && map[i][j] == 'Z') {
                    isterminate = true;
                    break;
                }
                if (map[i][j] == ' ') {
                    y = i;
                    x = j;
                }
            }
            getchar();
        }
        if (isterminate)
            break;
        bool fail = false;
        while ( (c = getchar()) != '0' ) {
            int ind = trans(c);
            if (ind < 0 || fail) continue;
            int newx = xmove[ind] + x;
            int newy = ymove[ind] + y;
            if (newx >= size || newx < 0 || newy >= size || newy < 0) {
                fail = true;
            } else {
                char temp = map[newy][newx];
                map[newy][newx] = ' ';
                map[y][x] = temp;
                x = newx;
                y = newy;
            }
        }
        if ( n > 0 ) std::cout << '\n';
        std::cout << "Puzzle #" << ++n << ":" << std::endl;
        if (fail)
            std::cout << "This puzzle has no final configuration.\n";
        else {
            print_table();
        }
        getchar();
    }
}