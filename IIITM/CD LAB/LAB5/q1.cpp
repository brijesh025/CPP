#include <bits/stdc++.h>
using namespace std;

string input;
int pos;

bool A_rule1(); // for (a) A → ab | a
bool A_rule2(); // for (b) A → a | ab

bool S_rule1() { // S → cAd using A_rule1
    int start = pos;
    if(pos < input.size() && input[pos] == 'c') {
        pos++;
        if(A_rule1()) {
            if(pos < input.size() && input[pos] == 'd') {
                pos++;
                return pos == input.size();
            }
        }
    }
    pos = start;
    return false;
}

bool S_rule2() { // S → cAd using A_rule2
    int start = pos;
    if(pos < input.size() && input[pos] == 'c') {
        pos++;
        if(A_rule2()) {
            if(pos < input.size() && input[pos] == 'd') {
                pos++;
                return pos == input.size();
            }
        }
    }
    pos = start;
    return false;
}

bool A_rule1() { // A → ab | a
    int start = pos;
    if(pos < input.size() && input[pos] == 'a') {
        pos++;
        if(pos < input.size() && input[pos] == 'b') {
            pos++;
            return true;
        }
        return true; // just 'a'
    }
    pos = start;
    return false;
}

bool A_rule2() { // A → a | ab
    int start = pos;
    if(pos < input.size() && input[pos] == 'a') {
        pos++;
        return true; // just 'a'
    }
    pos = start;
    if(pos < input.size() && input[pos] == 'a') {
        pos++;
        if(pos < input.size() && input[pos] == 'b') {
            pos++;
            return true;
        }
    }
    pos = start;
    return false;
}
int main() {
    cout << "Enter string: ";
    cin >> input;

    pos = 0;
    bool res1 = S_rule1();
    pos = 0;
    bool res2 = S_rule2();

    cout << "Grammar (a): " << (res1 ? "Accepted" : "Rejected") << "\n";
    cout << "Grammar (b): " << (res2 ? "Accepted" : "Rejected") << "\n";
    cout<<"Brijesh Singh 2023IMT-025";
    return 0;
}
