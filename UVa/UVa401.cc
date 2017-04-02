#include <iostream>
#include <string.h>

std::string mirror = "A   3  HIL JM O   2TUVWXY51SE Z  8";
std::string message[4] = {" -- is not a palindrome.", " -- is a regular palindrome.", " -- is a mirrored string.",
                          " -- is a mirrored palindrome."};

char rev(char c) {
    if (isalpha(c))
        return mirror[c - 'A'];
    else
        return mirror[c - '1' + 26];
}

int main(int argc, char const* argv[]) {
    std::string in;

    while (std::cin >> in) {
        if (std::cin.eof())
            break;
        int isp = 1, ism = 2;
        int length = in.size();
        for (int i = 0; i < length; ++i) {
            if (in[i] != in[length - i - 1])
                isp = 0;
            if (in[length - i - 1] != rev(in[i]))
                ism = 0;
        }
        std::cout << in << message[isp + ism] << std::endl;
        std::cout << std::endl;
    }

    return 0;
}