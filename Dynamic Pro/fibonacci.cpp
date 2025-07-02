// A.MEMOIZATION
// #include <bits/stdc++.h>
// using namespace std;
// int fibbonacci(int n,int dp[]){
//     if(n<=1)return dp[n]=n;
//     if(dp[n]!=-1)return dp[n];
//     return dp[n]=fibbonacci(n-1,dp)+fibbonacci(n-2,dp);
// }
// int main(){
//     int n;
//     cin>>n;
//     // vector<int> dp(n+1,-1);
//     int dp[n+1];
//     memset(dp,-1,sizeof(dp));
//     fibbonacci(n,dp);
//     for(int &i:dp)cout<<i<<" ";
// return 0;
// }

// B.TABULATION
#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n,int dp[]) {
    if (n <= 1) return n;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
}
int main(){
    int n;
    cin>>n;
    // vector<int> dp(n+1,-1);
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    fibonacci(n,dp);
    for(int &i:dp)cout<<i<<" ";
return 0;
}
