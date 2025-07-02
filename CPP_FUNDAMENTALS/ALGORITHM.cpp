// 1.sort odd even

// #include <iostream>
// #include <vector>
// using namespace std;
// void sortevenodd(vector<int> &v,int size){
//     for(int i=0;i<size;i++){
//         if (v[i]%2!=0){
//             for(int j=size-1;j>i;j--){
//             if(v[j]%2==0){int temp=v[i];
//             v[i]=v[j];
//             v[j]=temp;}
//             else{continue;}

//         }}
//         else{continue;}

//     }
// }
// int main(){
//     int size=9;
//     vector <int> v={44,11,12,19,64,62,63,64,65};
//     sortevenodd(v,size);
//     for (int i:v){cout<<i<<" ";}

// }

// 2.return squares in non-decreasing order

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// void sortedsquare(vector <int> &v){
//     int lpointer=0;
//     int rpointer=v.size()-1;
//     vector <int> res;
//     for(int i=0;rpointer>=lpointer;i++){
//         if(abs(v[lpointer])>abs(v[rpointer])){res.push_back(v[lpointer]*v[lpointer]);
//         lpointer++;

//         }
//         else{res.push_back(v[rpointer]*v[rpointer]);
//         rpointer--;}
//     }
//     reverse(res.begin(), res.end());
//         for(int i=0;i<res.size();i++){cout<<res[i]<<" ";}
//     }
// int main(){
//     vector <int> v={-4,2,3,4,5,6};
//     sortedsquare(v);
    
// }

// 3.prefix sum
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int runningsum(vector <int> &v){
//     for(int i=1;i<v.size();i++){
//         v[i]=v[i-1]+v[i];
// }

// }
// int main(){
//     vector <int> v={1,2,5,6,8};
//     runningsum(v);
// for(int i:v){cout<<i<<" ";}


// }

// 4.prefix sum equals to suffix sum
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int chksum(vector <int> &v){
//     int lpointer=0,rpointer=v.size()-1,lsum=v[lpointer],rsum=v[rpointer];
//     while(lpointer+1<rpointer){
//         if(lsum<rsum){
//             lsum+=v[lpointer+1];
//             lpointer++;
//         }
//         else if(lsum>rsum){rsum+=v[rpointer-1];
//         rpointer--;
//         }
//         else{
//             lsum+=v[lpointer+1];
//             lpointer++;
//             rsum+=v[rpointer-1];
//             rpointer--;}

//     }
//     if (lsum==rsum){cout<<"YES";}
//     else{cout<<"NO";}
//     cout<<lsum<<" "<<rsum;
// }
// int main(){
//     int size;
//     cout<<"ENTER SIZE: ";
//     cin>>size;
//     vector <int> v;
//     for (int i=0;i<size;i++){
//         int ele;
//         cin>>ele;
//         v.push_back(ele);
//     }
//     chksum(v);
// }

// 5. Q quary range sum

// #include <iostream>
// #include <vector>
// using namespace std;
// int sum(vector <int> &v){
//     for (int i=1;i<v.size();i++){
//         v[i]=v[i-1]+v[i];
//     }   
//     int q;
//     cout<<"ENTER NO. QUERY:";
//     cin>>q;
//     for(int i=1;i<=q;i++){
//         cout<<"ENTER RANGE:";
//         int a,b;
//         cin>>a;
//         cin>>b;
//         cout<<v[b]-v[a-1];
//     }
//  }

// int main(){
//     int size;
//     cout<<"ENTER SIZE:";
//     cin>> size;
//     vector <int> v(size+1,0);
//     for(int i=1;i<size+1;i++){
//     cin>>v[i];}
//     sum(v);



// }

// 6. SUM OF SUBARRAY
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














