#include <cstdio>

int main(int argc, char const* argv[]) {
    char in;
    bool flag = true;

    while ((in = getchar()) != EOF) {
        if (in == '"') {
            printf("%s", flag ? "``" : "''");
            flag = !flag;
        } else {
            printf("%c", in);
        }
    }

    return 0;
}