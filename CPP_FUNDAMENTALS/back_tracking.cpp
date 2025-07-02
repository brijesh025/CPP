// A.PERMUTATION OF A STRINGS
// #include <bits/stdc++.h>
// using namespace std;
// void permutation(string &s,int i){
//     if(i==s.size()){
//         cout<<s<<endl;
//         return;
//     }
//     for(int j=i;j<s.size();j++){
//         swap(s[i],s[j]);
//         permutation(s,i+1);
//         swap(s[j],s[i]);//BACKTRACKING
//     }
// }
// int main(){
//     string s="abc";
//     permutation(s,0);
// return 0;
// }

// B.RAT IN A MAZE
// #include <bits/stdc++.h>
// using namespace std;
// bool cango(int i,int j,vector<vector<int>> grid){
//     return ((i>=0 and j>=0 and i<grid.size() and j<grid[0].size()) and grid[i][j]==1);
// }
// int f(int i,int j,vector<vector<int>> grid){
//     int n=grid.size();
//     int m=grid[0].size();
//     if(i==n-1 and j==m-1){
//         for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             cout<< grid[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<"*******"<<endl;
//     return 1;
//     }
//     int ans=0;
//     grid[i][j]=2;
//     if(cango(i,j+1,grid)){//right
//         ans+=f(i,j+1,grid);
//     }
//     if(cango(i+1,j,grid)){//right
//         ans+=f(i+1,j,grid);
//     }
//     if(cango(i,j-1,grid)){//left
//         ans+=f(i,j-1,grid);
//     }
//     if(cango(i-1,j,grid)){//up
//         ans+=f(i-1,j,grid);
//     }
//     grid[i][j]=1;//BACKTRACKING
//     return ans;
// }
// int main() {
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> grid(m, vector<int>(n));
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> grid[i][j];
//         }
//     }
//     cout << f(0, 0, grid);
//     return 0;
// }

// C. N QUEENS
// #include <bits/stdc++.h>
// using namespace std;
// bool can_place(int row,int col,vector<vector<char>> &grid){
//     for(int i=row-1;i>=0;i--){
//         if(grid[i][col]=='q') return false;
//     }
//     for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--){
//         if(grid[i][j]=='q')return false;
//     }
//     for(int i=row-1,j=col+1;i>=0 and j<grid.size();i--,j++ ){
//         if(grid[i][j]=='q')return false;
//     }
//     return true;
// }
// void f(int crnt_row,int n,vector<vector<char>> &grid){
//     if(crnt_row==n){
//             for (int i = 0; i < n; i++) {
//                 for (int j = 0; j < n; j++) {
//                 cout<<grid[i][j]<<" ";
//                 }
//             cout<<endl;
//             }
//     cout<<"*********"<<endl;
//     return;
//     }
//     for(int col=0;col<n;col++){
//         if(can_place(crnt_row,col,grid)){
//             grid[crnt_row][col]='q';
//         f(crnt_row+1,n,grid);
//         grid[crnt_row][col]='.';//BACKTRACKING
//         }
//     }
// }
// int main(){
//     int n;
//     cin>>n;
// vector<vector<char>> grid(n,vector<char>(n,'.'));
// f(0,n,grid);
// return 0;
// }


