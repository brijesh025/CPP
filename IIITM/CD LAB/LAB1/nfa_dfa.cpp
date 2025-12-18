//NFA TO DFA
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

map<pair<int, char>, set<int>> nfa;

map<set<int>, map<char, set<int>>> dfa;
set<set<int>> dfaStates;

vector<char> symbols = {'a', 'b'};

void printSet(const set<int>& s) {
    cout << "{";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it;
        if (next(it) != s.end()) cout << ", ";
    }
    cout << "}";
}

void convertNFAtoDFA(int startState) {
    queue<set<int>> q;
    set<int> startSet = {startState};
    q.push(startSet);
    dfaStates.insert(startSet);

    while (!q.empty()) {
        set<int> current = q.front();
        q.pop();

        for (char symbol : symbols) {
            set<int> nextSet;

            for (int state : current) {
                auto key = make_pair(state, symbol);
                if (nfa.find(key) != nfa.end()) {
                    nextSet.insert(nfa[key].begin(), nfa[key].end());
                }
            }

            if (!nextSet.empty()) {
                dfa[current][symbol] = nextSet;

                if (dfaStates.find(nextSet) == dfaStates.end()) {
                    dfaStates.insert(nextSet);
                    q.push(nextSet);
                }
            }
        }
    }
}

int main() {
    nfa[{0, 'a'}] = {0, 1};
    nfa[{0, 'b'}] = {0};
    nfa[{1, 'b'}] = {2};
    nfa[{2, 'a'}] = {2};

    int startState = 0;
    convertNFAtoDFA(startState);

    cout << "DFA Transitions:\n";
    for (const auto& [fromState, transitions] : dfa) {
        for (const auto& [symbol, toState] : transitions) {
            printSet(fromState);
            cout << " -" << symbol << "-> ";
            printSet(toState);
            cout << endl;
        }
    }
    cout<<"2023IMT-025 BRIJESH SINGH";
    return 0;
}