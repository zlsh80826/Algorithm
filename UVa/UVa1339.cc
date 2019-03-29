#include <algorithm>
#include <iostream>
#include <cstring>

bool compare(char* str1, char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    if (not len1 == len2) 
        return false;

    const int size = 26;
    int cnt1[size] = {0};
    int cnt2[size] = {0};

    for (size_t i = 0; i < len1; ++ i) {
        cnt1[str1[i] - 'A'] += 1;
        cnt2[str2[i] - 'A'] += 1;
    }

    std::sort(cnt1, cnt1 + size, std::greater<int>());
    std::sort(cnt2, cnt2 + size, std::greater<int>());

    for (int i = 0; i < size; ++ i) {
        // std::cout << cnt1[i] << " " << cnt2[i] << std::endl;
        if (not (cnt1[i] == cnt2[i]))
            return false;
    }
    return true;
}

int main(int argc, char** argv) {

    char str1[110];
    char str2[110];

    while (std::cin >> str1 >> str2) {
        if (compare(str1, str2)) 
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}
