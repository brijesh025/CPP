// 1. FRACTIONAL KNAPSACK
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n = 4, max_w = 100;
//     double max_v = 0;
//     double crnt_w = 0;
//     vector<double> weight = {10, 20, 30, 40};
//     vector<double> value = {60, 100, 120, 240};
//     vector<pair<double, int>> ratio;
//     for (int i = 0; i < n; i++) {
//         double r = value[i] / weight[i];
//         ratio.push_back({r, i});
//     }
//     // Sort ratios in descending order
//     sort(ratio.begin(), ratio.end(), greater<pair<double, int>>());
//     for (int i = 0; i < n && max_w > 0; i++) {
//         int idx = ratio[i].second;
//         if (weight[idx] <= max_w) {
//             max_v += value[idx];
//             crnt_w += weight[idx];
//         } else {
//             max_v += max_w * ratio[i].first; // Take a fraction of the current item's value
//             break;
//         }
//     } 
//     cout << max_v;
//     return 0;
// }


// 2. 0/1 KNAPSACK
// A.USING CRNT_WT
// #include <bits/stdc++.h>
// using namespace std;

// int maxm(const vector<int> &wt, const vector<int> &val, int max_wt, int crnt_wt, int value, int crnt_ind, vector<vector<int>> &dp) {
//     if (crnt_ind == wt.size()) return value;

//     if (dp[crnt_ind][crnt_wt] != -1) return dp[crnt_ind][crnt_wt]; // Return cached result

//     int exclude = maxm(wt, val, max_wt, crnt_wt, value, crnt_ind + 1, dp); // Exclude current item
//     int include = 0;

//     if (crnt_wt + wt[crnt_ind] <= max_wt) { // Include current item if it fits
//         include = maxm(wt, val, max_wt, crnt_wt + wt[crnt_ind], value + val[crnt_ind], crnt_ind + 1, dp);
//     }

//     // Cache the result
//     return dp[crnt_ind][crnt_wt] = max(include, exclude);
// }//-->TC==>O(n*w)

// int main() {
//     vector<int> wt = {2, 4, 8};
//     vector<int> val = {20, 25, 60};
//     int W = 12;
//     int n = wt.size();

//     // Initialize the DP table with -1 (indicating uncomputed states)
//     vector<vector<int>> dp(n, vector<int>(W + 1, -1));
//     // int dp[n+1][W+1];
//     // for(int i=0;i<=n;i++){
//     //     for(int j=0;j<=W;j++){
//     //         if(i==0 or j==0)dp[i][j]=0;
//     //         else if(wt[i-1]<=j)dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
//     //         else dp[i][j]=dp[i-1][j];
//     //     }
//     // }
//     // cout<<dp[n][W];

//     cout << maxm(wt, val, W, 0, 0, 0, dp);
//     return 0;
// }

// B.USING REMAINING WEIGHT
#include <bits/stdc++.h>
using namespace std;
int max_knapsack(vector<int> wt,vector<int> val,int crnt_ind,int remaining_wt,vector<vector<int>> &dp){
    if(crnt_ind==wt.size())return 0;
    if(dp[crnt_ind][remaining_wt]!=-1)return dp[crnt_ind][remaining_wt];
    int exclude=max_knapsack(wt,val,crnt_ind+1,remaining_wt,dp);
    int include=0;
    if(remaining_wt>=wt[crnt_ind])include=val[crnt_ind]+max_knapsack(wt,val,crnt_ind+1,remaining_wt-wt[crnt_ind],dp);
    return dp[crnt_ind][remaining_wt]=max(include,exclude);
}
int main(){
    vector<int> wt = {2, 4, 8};
    vector<int> val = {20, 25, 60};
    int W = 12;
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << max_knapsack(wt, val, 0, W, dp);
    return 0;
}
