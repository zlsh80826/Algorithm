#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <stack>
#include <set>
#include <map>

typedef std::set<int> Set;

int get_id(std::map<Set, int>& stoi, std::map<int, Set>& itos, Set s) {
    if (stoi.count(s)) {
        return stoi[s];
    } else {
        stoi[s] = stoi.size();
        itos[stoi[s]] = s;
        return stoi[s];
    }
}

Set get_set(std::map<int, Set>& itos, int id) {
    return itos[id];
}

void execute() {
    int n_op;
    std::stack<int> s;
    std::map<Set, int> stoi;
    std::map<int, Set> itos;
    std::cin >> n_op;
    for (int i = 0; i < n_op; ++ i) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "PUSH") {
            Set x;
            s.push(get_id(stoi, itos, x));
        } else if (cmd == "DUP") {
            Set x = get_set(itos, s.top());
            s.push(get_id(stoi, itos, x));
        } else if (cmd == "UNION") {
            Set first = get_set(itos, s.top()); s.pop();
            Set second = get_set(itos, s.top()); s.pop();
            Set x;
            std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::inserter(x, x.begin()));
            s.push(get_id(stoi, itos, x));
        } else if (cmd == "INTERSECT") {
            auto first = get_set(itos, s.top()); s.pop();
            auto second = get_set(itos, s.top()); s.pop();
            Set x;
            std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), std::inserter(x, x.begin()));
            s.push(get_id(stoi, itos, x));
        } else if (cmd == "ADD") {
            auto first = s.top(); s.pop();
            auto second = get_set(itos, s.top()); s.pop();
            second.insert(first);
            s.push(get_id(stoi, itos, second));
        } else {
            assert(false);
        }
        std::cout << get_set(itos, s.top()).size() << '\n';
    }
    std::cout << "***\n";
}

int main(int argc, char** argv) {

    int r;
    std::cin >> r;

    for (int i = 0; i < r; ++ i) {
        execute();
    }

}
