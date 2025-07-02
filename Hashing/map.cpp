// 1.BASIC FUNCTIONLATIES
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
// map<int,int> m;
// unordered_map<int,int> u_m;
// multimap<int,int> mm;
// unordered_multimap<int,int> u_mm;
//   map<string,long long int,greater<string>> directory={{"BRIJESH",7984920911}};
//   directory.insert(make_pair("CHHAYA",8953340003));
//   directory["CHANDRA PRAKASH"]=7380559563;
//   directory["AKSHIT"]=6445447441;
//   for(auto i:directory) cout<<i.first<<" "<<i.second<<endl;
//   map<string,long long int>::reverse_iterator i;
//   for(i=directory.rbegin();i!=directory.rend();i++){
//     cout<<i->first<<"-"<<i->second<<endl;
//   }
// return 0;
// }

// 2.REAARNGE ELEMENT IN ASECEDING ORDER OF OCCURANCE
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int size;
//     cin>>size;
//     vector<int> v(size);
//     map<int,int> m;
//     multimap<int,int,greater<int>> mm;
//     for(int &i:v)cin>>i;
//     for(int &i:v) {
//         cout<<i<<" ";
//         m[i]++;
//     }
//     cout<<endl;
//     for(auto i:m){
//         mm.insert(make_pair(i.second,i.first));
//     }
//     for(auto i:mm){
//         for (int j=1;j<=i.first;j++)cout<<i.second<<" ";
//     }
// return 0;
// }

// 3.CAN MAKE STRINGS EQUAL
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int size;
//     map<char,int> m;
//     cin>>size;
//     string str[size];
//     for(string &s:str){
//         cin>>s;
//         for(char &c:s){
//             m[c]++;
//         }
//     }
//     for(auto i:m){
//         if((i.second)%size!=0){
//             cout<<"NO"<<endl;
//             return 0;
//         }
//     }
//     cout<<"YES";
// return 0;
// }

// 4.CHECK FOR POLYMORPHISM OF TWO STRINGS
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
// string s1,s2;
// cin>>s1>>s2;
// map<char,char> m;
// for(int i=0;i<s1.size();i++){
//     if(m.find(s1[i])!=m.end()){
//         if(m.find(s1[i])->second!=s2[i]){
//             cout<<"NO";
//             return 0;
//         }
//     }
//    else {for(auto itr:m){
//         if(itr.second==s2[i]){
//             cout<<"NO";
//             return 0;
//         }
//     }
//     }
//     m[s1[i]]=s2[i];
// }
// cout<<"YES";
// return 0;
// }

// 5.LONGEST SUBARRAY HAVING SUM ZERO
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
// int size;
// cin>>size;
// vector<int> v(size);
// map<int,int> m;
// for(int &i:v) cin>>i;
// int pre_sum=0,max_len=1;
// for(int i=0;i<size;i++){
//     pre_sum+=v[i];
//     if(m.find(pre_sum)!=m.end()){
//         max_len=max(max_len,i-m[pre_sum]);
//         }
//     else m[pre_sum]=i;
// }
// cout<<max_len;
// return 0;
// }