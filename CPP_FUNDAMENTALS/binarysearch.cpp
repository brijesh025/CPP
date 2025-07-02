// 1.BY LOOPS 
// #include <bits/stdc++.h>
// using namespace std;
// int binary_search(vector<int> &v, int target ){
//     // my search space
//     int strt=0;
//     int end=v.size()-1;
//     // searching
//     while (strt<=end)
//     {

    // modified mid memory prblm
    
//     int mid=end+(strt-end)/2;
// //         int mid=(strt+end)/2;
//         if(v[mid]==target){
//             return mid;
//         }
//         else if(v[mid]>target){
//             end=mid-1;
//         }
//         else if(v[mid]<target){
//             strt=mid+1;
//         }

//     }
//     return -1;
    

// }
// int main(){
//     int size;
//     cin>>size;
//     vector <int> v;
//     for (int i=0;i<size;i++)
//     {
//         int x;
//         cin>>x;
//         v.push_back(x);
//     }
//     int target;
//     cin>>target;
//     cout<<binary_search(v, target);

// return 0;
// }


// 2. BY RECURSION
// TIME:O(log(n))
// SPACE:O(log(n))
// #include <bits/stdc++.h>
// using namespace std;
// int binary_search(vector <int> &v,int strt,int end,int mid,int target){
//     if (v[mid]==target){return mid;}
//     else if(strt<=end && v[mid]>target){
//     binary_search(v,strt,mid-1,(strt+end)/2,target);}
//     else if(strt<=end && v[mid]<target){
//         binary_search(v,mid+1,end,(strt+end)/2,target);}
//     else {return -1;}
// }
// int main(){
//     int size;
//     cin>>size;
//     vector <int> v;
//     for (int i=0;i<size;i++)
//     {
//         int x;
//         cin>>x;
//         v.push_back(x);
//     }
//     int target;
//     cin>>target;
//     cout<<binary_search(v,0,v.size()-1,v.size()/2,target);

// return 0;
// }

// 3.Left Most return
#include <bits/stdc++.h>
using namespace std;
int binary_search(vector <int> &v,int strt,int end,int mid,int target){
    int ans=-1;
    if (v[mid]==target){ans=mid;}
    if (strt>end) return ans;
    else if(v[mid]>=target){
    binary_search(v,strt,mid-1,(strt+end)/2,target);}
    else if(v[mid]<target){
        binary_search(v,mid+1,end,(strt+end)/2,target);}
}
int main(){
    int size;
    cin>>size;
    vector <int> v;
    for (int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int target;
    cin>>target;
    cout<<binary_search(v,0,v.size()-1,v.size()/2,target);
return 0;
}