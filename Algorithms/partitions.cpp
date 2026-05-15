#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int k, vector<vector<vector<int>>> &part, vector<vector<int>> crnt,  int ind=0){
        if(ind==nums.size()){
            part.push_back(crnt);
            return;
        }
        vector<int> temp;
        int mx=INT_MIN, mn=INT_MAX;
        for(int i=ind;i<nums.size();i++){
            temp.push_back(nums[i]);
            mx=max(mx,nums[i]); mn=min(mn,nums[i]);
            if(mx-mn>k)continue;
            crnt.push_back(temp);
            solve(nums,k,part,crnt,i+1);
            crnt.pop_back();
        }
    }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;cin>>n;
    vector<int>a(n);
    for(auto&i:a)cin>>i;

    vector<vector<vector<int>>> ans;
    vector<vector<int>> cur;

    solve(a,4,ans,cur);

    for(auto &i:ans){
        cout<<"{";
        for(auto &j:i){
            cout<<" [";
            for(auto &k:j)cout<<k<<" ";
            cout<<"]";
        }
        cout<<" }\n";
    }
}
