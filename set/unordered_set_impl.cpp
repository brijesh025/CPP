#include <bits/stdc++.h>
using namespace std;
int main(){
    // unordered_set <int> s;
    unordered_multiset <int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(-1);
    s.insert(10);
    s.insert(5);
    for(auto i:s) cout<<i<<" ";
return 0;
}