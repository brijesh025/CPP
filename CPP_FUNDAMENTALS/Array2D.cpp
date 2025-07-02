//1.Taking input
// #include <iostream>
// using namespace std;

// int main(){
//     int n,m;
//     cin>>n;
//     cin>>m;
//     int array[n][m];
//     for(int i=0;i<n;i++){
//         for (int j=0;j<m;j++){
//             cin>>array[i][j];
//         }
//     }
//     for(int i=0;i<n;i++){
//         for (int j=0;j<m;j++){
//             cout<<array[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


// 2.Matrix Multiplication

// #include <iostream>
// using namespace std;
// int main(){
//     int m,n,p;
//     cout<<"ENTER NO. OF ROW1:";
//     cin>>m;
//     cout<<"ENTER NO. OF COLUMN1:";
//     cin>>n;
//     cout<<"ENTER NO. OF COLUMN2:";
//     cin>>p;
//     int matrix1[m][n];
//     int matrix2[n][p];
//     int matrix3[m][p];
//     for (int i=0;i<m;i++){
//             cout<<"ENTER: ";
//         for(int j=0;j<n;j++){
//             cin>>matrix1[i][j];
//         }}
        
//     for (int i=0;i<n;i++){
//             cout<<"ENTER: ";
//         for(int j=0;j<p;j++){
//             cin>>matrix2[i][j];
//         }
//         }
//         cout<<"THE TWO MATRIX:"<<endl;
//     for (int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cout<<matrix1[i][j]<<" ";
//         }
//         cout<<endl;
//         }
//         cout<<endl;
//     for (int i=0;i<n;i++){
//         for(int j=0;j<p;j++){
//             cout<<matrix2[i][j]<<" ";
//         }
//         cout<<endl;
//         }
//     for (int i = 0; i <m ; i++)
//     {
//         for (int j = 0; j <p; j++)
//         {
//             int ans=0;
//             for (int k = 0; k < n; k++)
//             {
//                 ans+=matrix1[i][k]*matrix2[k][j];
//             }
            
//         matrix3[i][j]=ans;
//         }
        
//     }
//     cout<<"multiplaction of matrix1 and matrix2: "<<endl;
//     for (int i=0;i<m;i++){
//         for(int j=0;j<p;j++){
//             cout<<matrix3[i][j]<<" ";
//         }
//         cout<<endl;
//         }
    




//     }


// 3.PASCAL'S TRAINGLE

// A.BY FACTORIAL

#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"ENTER NO. OF ROW: ";
    cin>>m;
    n=m;
    for(int i=0;i<m;i++){
        for(int a=0;a<=n/2;a++){cout<<" ";}
        for(int j=0;j<=i;j++){
            if (i==0||j==0){cout<<1<<" ";}
            else{
                int num=i,deno=1,num_mul=i,deno_mul=1;
                for(int k=1;k<j;k++){
                    num*=--num_mul;
                    deno*=++deno_mul;
                }
                cout<<num/deno<<" ";
            }
            }
            cout<<endl;  
            n-=2;          
    }
}

// B.BY PATTERN USING 2D VECTOR

// #include <iostream>
// #include <vector>
// using namespace std;
// vector <vector<int>> pascaltriangle(int n ){
//     vector <vector<int>> v(n);
//     for(int i=0;i<n;i++){
//         v[i].resize(i + 1);
//         for(int j=0;j<=i;j++){
//             if(j==0||j==i){
//                 v[i][j]=1;
//             }
//             else{
//                 v[i][j]=v[i-1][j-1]+v[i-1][j];
//             }
//         }
//     }
//     return v;
// }
// int main(){
//     int n;
//     cout<<"ENTER: ";
//     cin>>n;
//     vector <vector<int>> u(n);
//     u=pascaltriangle(n);
//     for(int i=0;i<u.size();i++){
//         for(int j=0;j<u[i].size();j++){
//             cout<<u[i][j]<<" ";
//         }
//         cout<<endl;
//     } 
// }


// 4.MAXM NO. OF 1S
// #include <iostream>
// #include <vector>
// using namespace std;
// vector <vector<int>> find(vector <vector<int>> &v){
//     int count=0;
//     int cntres=0;
//     int result=0;
//     for(int i=0;i<v.size();i++){
//         for(int j=0;j<v[i].size();j++){
//             if(v[i][j]==1){
//                 count++;
//             }
//         }
        
//         if(count>cntres){result=i;}
//     }
//     cout<<"ROW: "<<result<<endl;
//     for(int i=0;i<v[result].size();i++){
//         cout<<v[result][i]<<" ";
//     }

// }

// int main(){
//     vector <vector<int>> v={{1,2,1},{3,4,1},{1,1,1},{5,8,9,1,1,1,1}};
//     find(v);

// }

// 5.SPIRAL MATRIX
// #include <iostream>
// #include <vector>
// using namespace std;
// vector <vector<int>> spiral(vector<vector<int>> & v){
//     int cntr=0;
//     int chk=1;
//     while (chk<=v.size()*v[cntr].size())
//     {
//     // LEFT TO RIGHT 
//     for(int i=cntr;i<v[cntr].size()-cntr;i++){
//         cout<<v[cntr][i]<<" ";
//         chk++;
//     }
//     // TOP TO BOTTOM
//     if (chk>=v.size()*v[cntr].size())
//     {
//        break;
//     } 
//     for(int i=cntr+1;i<v.size()-cntr;i++){
//         cout<<v[i][v[cntr].size()-cntr-1]<<" ";
//         chk++;
//     }
//     // RIHGHT TO LEFT
//      if (chk>=v.size()*v[cntr].size())
//     {
//        break;
//     }
//     for(int i=v[cntr].size()-cntr-2;i>=cntr;i--){
//         cout<<v[v.size()-cntr-1][i]<<" ";
//         chk++;
//     }
//     // BOTTOM TO TOP
//      if (chk>=v.size()*v[cntr].size())
//     {
//        break;
//     }
//     for(int i=v.size()-cntr-2;i>cntr;i--){
//         cout<<v[i][cntr]<<" ";
//         chk++;
//     }
//     cntr++;
//     }
// }
// int main(){
//     vector<vector<int>> v={{1,2,3,4,6},{4,5,6,7,5},{7,8,9,10,9}};
//     // for(int i=0;i<v.size()-1;i++){
//     //     for(int j=0;i<v[i].size()-1;i++){
//     //         cout<<v[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     spiral(v);
// }

// 6.SPIRAL MATRIX SQUARE ASSIGN
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<vector<int>> spiral(vector<vector<int>> &v,int n){
//     int dirn=0;
//     int top=0;
//     int right=v[0].size()-1;
//     int left=0;
//     int bottom=v.size()-1;
//     int cnt=1;
//     while(left<=right && top<=bottom){
//         if (dirn==0)
//         {
//             for(int col=left;col<=right;col++){v[top][col]=cnt*cnt;
//             cnt++;
//             }
//         top++;      
//         }
//         else if (dirn==1)
//         {
//             for(int row=top;row<=bottom;row++){v[row][right]=cnt*cnt;
//             cnt++;           
//             }
//             right--;           
//         }
//         else if(dirn==2){
//             for(int col=right;col>=left;col--){v[bottom][col]=cnt*cnt;
//             cnt++;}
//             bottom--;
//         }
//         else {
//             for (int row=bottom;row>=top;row--){
//                 v[row][left]=cnt*cnt;
//                 cnt++;
//             }
//             left++;
//         }
//         dirn++;
//         dirn%=3;       
//     }
//     return v;
// }
// int main(){
//     int n;
//     cout<<"ENTER: ";
//     cin>> n;
//     vector<vector<int> > v(n,vector <int>(n));
//     spiral(v,n);
//         for(int i=0;i<v.size();i++){
//         for(int j=0;j<v[i].size();j++){
//             cout<<v[i][j]<<" ";
//         }
//         cout<<endl;
//     } 
//     }

// 7.SUM OF RECTUNGLAR 
// A.SIMPLE METHOD
// #include<iostream>
// #include<vector>
// using namespace std;
// int sum(vector<vector<int>> &v,int l1,int r1,int l2,int r2){
//     int result=0;
//     for(int i=l1;i<=l2;i++){
//         for(int j=r1;j<=r2;j++){
//             result+=v[i][j];
//         }
//     }
//     return result;
// }
// int main(){
//     int m,n;
//     cout<<"ENTER ROW:";
//     cin>>m;
//     cout<<"ENTER COL:";
//     cin>>n;
//     vector<vector<int>> v(m, vector<int>(n));
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin>>v[i][j];
//         }
//     }
//     int l1,r1,l2,r2;
//     cout<<"ENTER: ";
//     cin>>l1;
//     cin>>r1;
//     cin>>l2;
//     cin>>r2;
//     cout<<"RESULT="<<sum(v,l1,r1,l2,r2);
// }


// 8.PREFIX SUM OVER COLUMNS AND ROWS 
// #include<iostream>
// #include<vector>
// using namespace std;
// int sum(vector<vector<int>> &v,int l1,int r1,int l2,int r2){
//     // PREFIX ROW SUM  
//     for(int i=0;i<v.size();i++){
//         for (int j=1;j<v[i].size();j++){
//             v[i][j]+=v[i][j-1];
//         }
//     }
//     // PREFIX COLUMN SUM
//     for(int i=0;i<v[i].size();i++){
//         for(int j=1;j<v.size();j++){
//             v[j][i]+=v[j-1][i];
//         }
//     }
//     for(int i=0;i<v.size();i++){
//         for (int j=0;j<v[i].size();j++){
//             cout<<v[i][j]<<" ";
//         }
//         cout<<endl;
//     } 
// }
// int main(){
//         int m,n;
//     cout<<"ENTER ROW:";
//     cin>>m;
//     cout<<"ENTER COL:";
//     cin>>n;
//     vector<vector<int>> v(m, vector<int>(n));
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin>>v[i][j];
//         }
//     }
//     int l1,r1,l2,r2;
//     cout<<"ENTER: ";
//     cin>>l1;
//     cin>>r1;
//     cin>>l2;
//     cin>>r2;
//     sum(v,l1,r1,l2,r2);
//     int result=v[l2][r2]-v[l1-1][r2]-v[l2][r1-1]+v[l1-1][r1-1];
//     cout<<"sum: "<<result;
// }

