#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> lastSet, precedeSet;
map<char, bool> lastVisited, precedeVisited;

void computeLast(char nonTerm) {
    if(lastVisited[nonTerm]) return;
    lastVisited[nonTerm] = true;

    for (auto &prod : grammar[nonTerm]) {
        char sym = prod.back();
        if (!isupper(sym)) {
            lastSet[nonTerm].insert(sym);
        } else {
            computeLast(sym);
            for (char c : lastSet[sym]) lastSet[nonTerm].insert(c);
        }
    }
}

void computePrecede(char nonTerm) {
    if(precedeVisited[nonTerm]) return;
    precedeVisited[nonTerm] = true;

    for (auto &prod : grammar[nonTerm]) {
        char sym = prod.front();
        if (!isupper(sym)) {
            precedeSet[nonTerm].insert(sym);
        } else {
            computePrecede(sym);
            for (char c : precedeSet[sym]) precedeSet[nonTerm].insert(c);
        }
    }
}

int main() {
    grammar['S'] = {"ABC", "SA"};
    grammar['A'] = {"ab", "a"};
    grammar['B'] = {"bc", "b"};
    grammar['C'] = {"cd", "c"};

    for (auto rule : grammar) computeLast(rule.first);
    for (auto rule : grammar) computePrecede(rule.first);

    cout << "LAST Sets:\n";
    for (auto &rule : lastSet) {
        cout << rule.first << " : { ";
        for (char c : rule.second) cout << c << " ";
        cout << "}\n";
    }

    cout << "\nPRECEDE Sets:\n";
    for (auto &rule : precedeSet) {
        cout << rule.first << " : { ";
        for (char c : rule.second) cout << c << " ";
        cout << "}\n";
    }
    cout<<"2023IMT-025 BRIJESH SINGH";
    return 0;
}
