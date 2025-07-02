// 1.Sort the string
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     string s,sorted_s;
//     cin>>s;
//     int freq[26]={0};
//     for(char &c:s) freq[c-'a']++;
//     for(int i=0;i<26;i++) {
//         for(int j=0;j<freq[i];j++){
//             sorted_s.push_back(char(i+'a'));
//         }
//     }
//     cout<<sorted_s;
// return 0;
// }


// 2.isomorphic
// #include <bits/stdc++.h>
// using namespace std;
// bool is_iso(string &s1,string &s2){
//     if(s1.length()!=s2.length()) return false;
//     int map1[26]={0};
//     int map2[26]={0};
//     for(int i=0;i<s1.length();i++){
//         if(map1[s1[i]-'a']==0 and map2[s2[i]-'a']==0) {
//             map1[s1[i]-'a']=s2[i];
//             map2[s2[i]-'a']=s1[i];
//         }
//         else if(map1[s1[i]-'a']!=s2[i] or map2[s2[i]-'a']!=s1[i]) return false;
//     }
//     return true;
// }
// int main(){
//     string s1,s2;
//     cin>>s1>>s2;
//     cout<<is_iso(s1,s2);
// return 0;
// }


// 3.longest common prefix
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int size;
//     cin>>size;
//     vector <string> str(size);
//     for(string &s:str) cin>>s;
//     sort(str.begin(),str.end());
//     int strt=0;
//     int end=str.size()-1;
//     int i=0;
//     string res;
//     while(str[strt][i]==str[end][i]) {
//         res.push_back(str[strt][i]);
//         i++;}
//         cout<<res;
// return 0;
// }