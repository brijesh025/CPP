#include<set> 
#include <bits/stdc++.h>
using namespace std;
int main(){
    // set<int> set1;
    // multiset<int> set1;
    multiset<int,greater<int>> set1;

    // 1.insert elements
    set1.insert(1);
    set1.insert(2);
    set1.insert(6);
    set1.insert(5);
    set1.insert(1);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);
    set1.insert(6);
    set1.insert(-1);

    // 2.return size 
    cout<<set1.size()<<endl;; //same elements can not be inserted

    // 3.traversal of set
    // A.USING iterator
    for(set<int>::iterator i=set1.begin();i!=set1.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    for (auto i:set1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    // B.USING auto
    
    

    // 4.DELETING ELEMENT
    // A.
    auto i=set1.begin();
    advance(i,2);//take iterator position to +2 position
    set1.erase(i);
    // B.
    auto end_i=set1.begin();
    advance(end_i,3);
    set1.erase(set1.begin(),end_i);
    for (auto i:set1) cout<<i<<" ";
    cout<<endl;
return 0;
}