// A.GREEDY APPROACH
// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
// int total_cost(vector<vector<int>>cost){
//     int n=cost.size();
//     vector<bool>check(n,false);
//     int root=0,minnode=-1,totalCost=0;
//     cout<<root<<" ";
//     for(int i=0; i<n; i++){
//         int edgecost=INT_MAX;
//         for(int j=0; j<n;j++){
//             if(i!=n-1 and j!=0 ){
//                 if(check[j]==false and root!=j){
//                     if(cost[root][j]<edgecost){
//                         edgecost=cost[root][j];
//                         minnode=j;
//                     }
//                 }
//             }
//             if(i==n-1 and j==0){
//                 edgecost=cost[root][j];
//                 minnode=j;
//                 break;
//             }
//         }
//         root=minnode;
//         check[root]=true;
//         cout<<root<<" ";
//         totalCost+=edgecost;
//     }
//     cout<<"-> Cost="<<totalCost<<endl;
//     return totalCost;
// }
// };
// int main(){
// 	int tc;
// 	cin >> tc;
// 	while(tc--){
// 		int n;
// 		cin >> n;
// 		vector<vector<int>>cost(n, vector<int>(n, 0));
// 		for(int i = 0; i < n; i++)
// 			for(int j = 0; j < n; j++)cin >> cost[i][j];			
// 		Solution obj;
// 		int ans = obj.total_cost(cost);
// }
// 	return 0;
// }
    
#include<bits/stdc++.h>
using namespace std;

int TSP(vector<vector<int>> mat,vector<bool> check,int cost, int root, int count ){
    if(count<mat.size()-1){
        vector<int> v;
        for(int i=1; i<mat.size();i++){
            if(check[i]==false and root!=i){
                vector<bool>check2=check;
                check2[i]=true;
                v.push_back(TSP(mat,check,cost+mat[root][i],i,count+1));
            }
        }
        cost=v[0];
        for(int ele:v)cost=min(cost,ele);
    }
    else{
        cost+=mat[root][0];
        check[0]=true;
    }
    return cost;
}
class Solution {
public:
int total_cost(vector<vector<int>>cost){
    int n=cost.size();
    vector<bool>check(n,false);
    return TSP(cost,check,0,0,0);
    
}
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
}
	return 0;
}