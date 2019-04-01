#include <iostream>
#include <algorithm>

void play(int m, int q) {
    int* marbles = (int*) malloc(m * sizeof(int));
    for (int i = 0; i < m; ++ i) {
        std::cin >> marbles[i];
    }
    std::sort(marbles, marbles + m);
    for (int i = 0; i < q; ++ i) {
        int query;
        std::cin >> query;
        auto pos = std::lower_bound(marbles, marbles + m, query) - marbles;
        if (marbles[pos] != query) {
            std::cout << query << " not found\n";
        } else {
            std::cout << query << " found at " << pos + 1 << "\n";
        }
    } 
}


int main(int argc, char** argv) {
    int m, q;
    auto cases = 0;
    while (std::cin >> m >> q) {
        if (m == 0 and q == 0)
            break;
        std::cout << "CASE# " << ++cases << ":\n";
        play(m, q);
    }
    return 0;
}
