#include <iostream>
#include <algorithm>
#include <queue>

int main(int argc, char const *argv[]) {
    int T;
    std::string str;
    std::cin >> T;
    while (T --) {
        std::cin >> str;
        std::priority_queue<std::string, std::vector<std::string>, 
                            std::greater<std::string> > PQ;
        for (int i = 0; i < str.size(); ++ i) {
            PQ.push(str);
            str.push_back(str[0]);
            str.erase(str.begin());            
        }
        std::cout << PQ.top() << std::endl;
    }

    return 0;
}