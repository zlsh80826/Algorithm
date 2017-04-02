#include <cstdio>

int main(int argc, char const* argv[]) {
    char in;

    char right[47] = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    while ((in = getchar()) != EOF) {
        int i;
        for (i = 0; (i < 47) && (right[i] != in); ++i);
        if (i < 47) {
            printf("%c", right[i - 1]);
        } else {
            printf("%c", in);
        }
    }

    return 0;
}