// 1.FACTORIAL
// #include <bits/stdc++.h>
// using namespace std;
// int fac(int n){
//     if (n==1 || n==0)
//     {
//         return 1;
//     }
//     return n*fac(n-1);
// }
// int main(){
//     int n=5;
//     // cin>>n;
//     cout<<fac(n);

// return 0;
// }

// 2.FIBONACCI SERIES
// #include <bits/stdc++.h>
// using namespace std;
// int fib(int n){
//     if (n==1) return 0;
//     if (n==2) return 1;
//     return fib(n-1)+fib(n-2);
// }
// int main(){
//     int n;
//     cin>>n;
//     for (int  i = 1; i <=n; i++)
//     {
//     cout<<fib(i)<<" ";        
//     }
    

// return 0;
// }

// 3.SUM DIGIT

// #include <bits/stdc++.h>
// using namespace std;
// int sum(int n){
//     if(n==0) return 0;
//     return (n%10)+(sum(n/10));
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<sum(n);
// return 0;
// }

// 4.RAISE TO POWER

// #include <bits/stdc++.h>
// using namespace std;
// int raise(int n,int m){
//     if(m==1) return n;
//     return n*raise(n,m-1);
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     cout<<raise(n,m);

// return 0;
// }


// 5.ARRAYS RECURSION

// A.PRINT ARRAY

// #include <bits/stdc++.h>
// using namespace std;
// void print(int arr[],int idx,int size){
//     if(idx==size) return;
//     cout<<arr[idx]<<" ";
//     return print(arr,idx+1,size);
// }
// int main(){
//     int arr[5]={1,2,3,4,5};
//     print(arr,0,5);
// return 0;
// }


// B.MAXM VALUE IN ARRAY 
// #include <bits/stdc++.h>
// #include <algorithm>
// using namespace std;
// int fmaxm(int v[],int size,int maxm){
//     if (size==1) return maxm;
//     return max(maxm,fmaxm(v,size-1,v[size-1]));
    

// }
// int main(){
//     int size;
//     cin>>size;
//     int v[size];
//     for(int &i:v) cin>>i;
//     cout<<fmaxm(v,size,v[size-1]);
// return 0;
// }

// C. SUMM ARRAY

// #include <bits/stdc++.h>
// using namespace std;
// int sum(int v[],int size,int idx){
//     if(idx==size-1) return v[idx];
//     return v[idx]+sum(v,size,idx+1);
// }
// int main(){
//     int size;
//     cin>>size;
//     int v[size];
//     for(int &i:v) 
//     {cin>>i;}
//     cout<<sum(v,size,0);
// return 0;
// }

// D.REMOVE ALL OCURRENCE OF A

// #include <bits/stdc++.h>
// using namespace std;
// string remv(string &s,int idx){
//   if (idx==s.size())
//   {
//     return "";
//   }
//   return ((s[idx]=='a') ? '\0':s[idx])+remv(s,idx+1);
  
// }
// int main(){
//     string s;
//     cin>>s;
//     cout<<remv(s,0);
// return 0;
// }

// E.CHECK PALLINDROME
// #include <bits/stdc++.h>
// using namespace std;
// bool is_pallindrome(int n,int *temp){
//     if(n>=1 and n<=9){
//         bool  result=((n%10)==(*temp%10));
//         (*temp)/=10;
//         return result;
//     }
//     bool result=is_pallindrome(n/10,temp) and (n%10)==(*temp)%10;
//     (*temp)/=10;
//     return result;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<is_pallindrome(n,&n);
// return 0;
// }

// F.PERMUTATION OF A STRINGS
// #include <bits/stdc++.h>
// using namespace std;
// void permutation(string s){

// }
// int main(){

// return 0;
// }

// G.FIND INCREASING SEQUENCE FROM 1 TO N
// #include <bits/stdc++.h>
// using namespace std;
// void print_no(int n){
//     if(n<1){
//         return;
//     }
//     print_no(n-1);
//     cout<<n<<" ";
// }
// int main(){
//     print_no(5);
// return 0;
// }

// H. PRINT K MULTIPLES OF A NUM
// #include <bits/stdc++.h>
// using namespace std;
// void print_multiples(int n,int k){
//     if(k<1){
//         return;
//     }
//     print_multiples(n,k-1);
//     cout<<n*k<<" ";
// }
// int main(){
//     print_multiples(2,10);
// return 0;
// }

// I.SUM ALTERNATE SIGN NATURAL NO.
// #include <bits/stdc++.h>
// using namespace std;
// int alternate_sum(int n){
//     if(n==1)return n;
//     return alternate_sum(n-1)+((n%2==0) ? -n:n);
// }
// int main(){
//     cout<<alternate_sum(5);
// return 0;
// }

// J.GCD--->[Euclid's Theorem]= If we subtract smaller no. from bigger no. GCD remains same
// #include <bits/stdc++.h>
// using namespace std;
// int my_gcd(int x,int y){
//     if((max(x,y)%min(x,y))==0) return min(x,y);
//     my_gcd(min(x,y),(max(x,y)%min(x,y)));
// }
// int gcd(int x,int y){
//     if(y>x) gcd(y,x);
//     if(y==0) return x;
//     return gcd(y,x%y);
// }
// int main(){
//     cout<<my_gcd(14,14)<<endl;
//     cout<<gcd(1,4);
// return 0;
// }

// K.ARMSTRONG_NO.

// #include <bits/stdc++.h>
// using namespace std;
// int armstrong(int n,int d){
//     if(n==0) return pow(n,d);
//     return pow(n%10,d)+armstrong(n/10,d);
// }
// int main(){
//     cout<<armstrong(25,2);
// return 0;
// }

// L.RECURSSIVE FROG

// #include <bits/stdc++.h>
// using namespace std;
// int min_cost(int arr[],int i,int size){
//     if(i==size-1) return 0;
//     if(i==size-2) return min_cost(arr,i+1,size)+abs(arr[i]-arr[i+1]);
//     return min((min_cost(arr,i+1,size)+abs(arr[i]-arr[i+1])),(min_cost(arr,i+2,size)+abs(arr[i]-arr[i+2]))); 
// }
// int main(){
//   int  arr[]={10,30,40,20};
//   cout<<min_cost(arr,0,4);
// return 0;
// }

// M. SUM OF SUBARRAY
// #include <bits/stdc++.h>
// using namespace std;
// void sum_subarray(int arr[],int size,int i=0,int sum=0){
//     if(i==size){
//         cout<<sum<<" ";
//         return;
//         }
//         sum_subarray(arr,size,i+1,sum+arr[i]);
//         sum_subarray(arr,size,i+1,sum);

// }
// int main(){
//     int arr[]={3,2};
//     sum_subarray(arr,2);
// return 0;
// }

// N.NO  OF POSSIBLE WAYS---------------------->IMPORTANT[Every cell have teo option and added those two options and have those two options call ]
// #include <bits/stdc++.h>
// using namespace std;
// int no_of_path(int m,int n,int r=0,int d=0){
//     if(d==m or r==n) return 0;
//     if(d==m-1 and r==n-1){
//         return 1;
//         }
//    return no_of_path(m,n,r+1,d)+no_of_path(m,n,r,d+1);
// }
// int main(){
//     int m=3,n=3;
//     cout<<no_of_path(m,n);
// return 0;
// }

// O.SUBSEQUNCE OF STRING
// #include <bits/stdc++.h>
// using namespace std;
// void subsequence(string s,int i=0,string sub=""){
//     if(i==s.size()){
//         cout<<sub<<" ";
//         return;
//     }
//     subsequence(s,i+1,sub+s[i]);
//     subsequence(s,i+1,sub);
// }
// int main(){
//     subsequence("abc");
// return 0;
// }

// P.POSSIBLE COMBINATION OF KEYPAD 
#include <bits/stdc++.h>
using namespace std;
void combinations(string s,int i,vector <string> mapping,string ans=""){
    if(i==s.size()) {
        cout<<ans<<" ";
        return;
        }
    if(s[i]-'0'<=1){
        combinations(s,i+1,mapping,ans);
        return;
    }
    for(int j=0;j<mapping[s[i]-'0'].size();j++){
        combinations(s,i+1,mapping,ans+mapping[s[i]-'0'][j]);
    }
    return;
}
int main(){
    vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    combinations("23",0,mapping);
return 0;
}