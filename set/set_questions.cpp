// 1.COMMON ELELMENTS BTWN TWO VECTORS
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     set<int> s;
//     vector<int> v1={1,1,2,3,3,3};
//     vector<int> v2={5,6,7,5,2,3,6};
//     vector<int> comn_ele;
//     for(int &i:v1)s.insert(i);
//     for(int &i:v2){
//         if(s.count(i)) comn_ele.push_back(i);
//     }
//     for(int &i:comn_ele) cout<<i<<" ";
// return 0;
// }

// 2.CHECK ALPHABETS

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     string s;
//     set<char> alphabets;
//     cin>>s;
//     for(char &c:s ){
//         alphabets.insert(tolower(c));
//     }
//     if(alphabets.size()==26) cout<<"YES";
//     else cout<<"NO";
// }

// 3.possible marks
 #include <bits/stdc++.h>
 using namespace std;
 int main(){
 int n,p,q,marks=0;
 unordered_set<int> s;
 cin>>n>>p>>q;
 for(int i=0;i<=n;i++){
    for(int j=0;j<=n-i;j++){
        marks=(p*i)+(q*j);
        s.insert(marks);
    }
 }
 for(auto i:s){
    cout<<i<<" ";
 }
 return 0;
 }