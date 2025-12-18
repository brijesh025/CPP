// 1
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int i;
//     cin>>i;
//     bitset<10> a(i);
//     cout<<a.count();
//     return 0;
// }

// 2.
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);    
//     int a;
//     cin>>a;
//     if(a<<1 ==0)cout<<"yes";
//     else cout<<"no";
//     return 0;
// }

// 3.
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin>>n;
//     bitset<32> b(n);
//     cout<<b<<endl;
//     for(int i=0;i<32;i+=2)b.flip(i);
//     cout<<b;
//     return 0;
// }

// 4.
// #include <bits/stdc++.h>
// using namespace std;
// string chk_paln(bitset<4> b){
//     int i=0,j=3;
//     while(i<j){
//         if(b[i]!=b[j])return "no";
//         i++;j--;
//     }
//     return "yes";
// }
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin>>n;
//     bitset<4> b(n);
//     cout<<b<<endl;
//     cout<<chk_paln(b);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// 5.
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;cin>>n;
//     bitset<5> b(n);
//     cout<<b<<endl;
//     int f_b=b[0];
//     b=b<<1;
//     b[5]=f_b;
//     cout<<b;
    
//     return 0;
// }

// 6.
// #include <bits/stdc++.h>
// using namespace std;
// int find(vector<int> v){
//     int n=v.size();
//     int x=0;
//     for(int i=0;i<=n;i++)x^=i;
//     for(int i=0;i<n;i++)x^=v[i];
//     return x;
// }
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cout<<find({0,1,2,4,5});
    
    
//     return 0;
// }

// 7.
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
    
//     int n;cin>>n;
//     bitset<32> b(n);
//     cout<<b<<endl;
//     int cnt=0;
//     for(int i=31;i>=0;i--){
//         if(b[i]==0)cnt++;
//         else break;
//     }
//     cout<<cnt;
//     return 0;
// }

// 8.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;cin>>n>>m;
    bitset<32>b1(n);bitset<32>b2(m);
    cout<<b1<<endl;cout<<b2<<endl;
    bitset<32> ans(0);
    for(int i=31;i>=0;i--){
        if(b1[i]==b2[i])ans[i]=0;
        else ans[i]=1;
    }
    cout<<ans<<endl;
    return 0;
}
