#include <bits/stdc++.h>
using namespace std;
int solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a)cin>>i;
    int d=0,cnt0=0,cnt1=0,t_1=0;
    for(auto i:a){
        t_1+=(i==1);
        if(cnt0-cnt1<=0){
            cnt0=(i==0);
            cnt1=(i==1);
        }
        else {
            cnt0+=(i==0);
            cnt1+=(i==1);
        }
        d=max(d,cnt0-cnt1);
    }
    if (d == 0) return t_1 - 1;
    return d+t_1;
}
int main() {
    cout << solve() << endl;
    return 0;
}