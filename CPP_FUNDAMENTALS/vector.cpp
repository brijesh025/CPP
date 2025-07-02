// 1.basic operation
// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     vector <int> v;
//     cout<<"Size:"<<v.size()<<endl;
//     cout<<"Capacity:"<<v.capacity()<<endl;
//     v.push_back(1);
//     cout<<"Size:"<<v.size()<<endl;
//     cout<<"Capacity:"<<v.capacity()<<endl;
//     v.push_back(2);
//     cout<<"Size:"<<v.size()<<endl;
//     cout<<"Capacity:"<<v.capacity()<<endl;
//     v.push_back(3);
//     cout<<"Size:"<<v.size()<<endl;
//     cout<<"Capacity:"<<v.capacity()<<endl;
//     v.resize(5);
//     cout<<"Size:"<<v.size()<<endl;
//     cout<<"Capacity:"<<v.capacity()<<endl;
//     v.resize(6);
//     cout<<"Size:"<<v.size()<<endl;
//     cout<<"Capacity:"<<v.capacity()<<endl;
//     v.pop_back(); 
//     cout<<"Size:"<<v.size()<<endl;
    // cout<<"Capacity:"<<v.capacity()<<endl;
// }

// Looping in  vector
// 2.Input/output method


// #include<iostream>
// #include <vector>
// using namespace std;
// int main (){
//     vector <int> v;
//     for (int i=0;i<=4;i++){
//         int ele;
//         cin>>ele;
//         v.push_back(ele);
//     }
//     for (int ele:v){
//         cout<<ele<<" ";
//     }


// 3.Target sum
// #include<iostream>
// using namespace std;
// int cntsum(int v[],int size,int tar_sum,int res=0){
//     for (int i=0;i<size;i++){
//         for(int j=i+1;j<size;j++){
//             if(v[i]+v[j]==tar_sum){res++;}
//             else{continue;}
//         }
//     }
//     cout<<res;
//     return 0;
// }
// int main(){
//     int size,tar_sum; 
//     cout<<"ENTER ARRAY SIZE:";
//     cin>>size;
//     int v[size];
//     for(int &i:v){cin>>i;}
//     cin>>tar_sum;
//     cntsum(v,size,tar_sum);
// }

// 4.Unique no.

// #include<iostream>
// using namespace std;
// int unqele(int v[],int size,int res=-1){
//     for (int i=0;i<size;i++){
//         for(int j=i+1;j<size;j++){res;
//             if(v[i]==v[j]){v[i]=v[j]=-1;}
//             else{continue;}
//         }
//     }
//     for(int k=0;k<size;k++){if(v[k]>=0)
//     {cout<<"UNIQUE ELEMENTS ARE:"<<v[k]<<endl;}
//     else{continue;}}
//     return 0;}
//  int main(){
//     int size; 
//     cout<<"ENTER ARRAY SIZE:";
//     cin>>size;
//     int v[size];
//     for(int &i:v){cin>>i;}
//     unqele(v,size);
//  }

// 5.Second largest no.

#include <iostream>
using namespace std;
int chkrpt=INT16_MIN;
int larelein(int size,int v[]){
    int larind=-1,larele=INT16_MIN;
    for (int i=0;i<size;i++)
    {
        if(larele<=v[i]){larele=v[i];
        larind=i;}
        
    }
    return larind;
}
int main(){
    int size=6,cnt=0;
    int v[]={1,2,3,4,5,4};
    for (int j=1;j<=2;j++){
        cnt++;
        int lareleindex=larelein(size,v);
        if(chkrpt==v[lareleindex]&&cnt<size){j=1;
        }
        else if(j==2||cnt==size){cout<<v[lareleindex];
        break;}
        chkrpt=v[lareleindex];
        v[lareleindex]=INT16_MIN;
    }
}

// 6.Rotate Array using extra no.

// #include <iostream>
// using namespace std;
// int rotatefun(int v[],int size,int no_rot,int res[]){
//     for (int i=0;i<size-no_rot;i++){
//         res[i]=v[i+no_rot];
//     }
//     for (int i=0;i<no_rot;i++){
//         res[size-no_rot+i]=v[i];
//     }
//     for (int i=0;i<size;i++){
//         cout<<res[i]<<endl;
//     }

// }
// int main(){
//     int size=5,no_rot;
//     int v[size]={1,2,3,4,5};
//     int res[size];
//     cin>>no_rot;
//     no_rot=no_rot%size;
//     rotatefun(v,size,no_rot,res);   
// }


// 7.rotate array using inbuilt revese function
// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     int nrot;
//     cin>>nrot;
//     vector <int> v={1,2,3,4,5};
//     nrot%=v.size();
//     reverse(v.begin(), v.begin()+nrot-1);
//     reverse(v.begin(), v.end());
//     reverse(v.begin(), v.end()-nrot);   
//     for(int i=0;i<v.size();i++){std::cout << v[i] << std::endl;}
// }

// 8.given no. is present in how much frequency

// #include<iostream>
// #include <vector>
// using namespace std;
// int main(){
//     int size;
//     cin>>size;
//     int v[size];
//     for(int &i:v){
//         cin>>i;
//     }
//     int noquery;
//     cout<<"ENTER NO. OF QUERY:";
//     cin>>noquery;
//     for (int i=1;i<=noquery;i++){
//         int query;
//         cout<<"ENTER YOU QUERY:";
//         cin>>query;
//         int cnt=0;
//         for (int i=0;i<size;i++){
//             if (query==v[i]){
//                 cnt++;
//             } 

//         }
//             cout<<"QUERY COUNT:"<<cnt<<endl;
//     }

// }

// 9.sorting 0s and 1s


// #include <iostream>
// using namespace std;
// int main(){
//     int size;
//     cin>>size;
//     int v[size];
//     for (int &i:v){
//         cin>>i;
//     }
//     int cnt0=0;
//     int cnt1=0;
//     for (int i=0;i<size;i++){
//         if (v[i]==0){cnt0++;}
//         else{cnt1++;}
//     }
//     for (int i=0;i<cnt0;i++){v[i]=0;}
//     for (int i=cnt0;i<size;i++){v[i]=1;}
//     for (int i=0;i<size;i++){
//         cout<<"RESULT:";
//         cout<<v[i]<<endl;}
// }

// 10.sortevenodd
// #include <iostream>
// using namespace std;
// int sortevenodd(int v[],int size){
//     int res[size];
//     int cnt=0;
//     for(int i=0;i<size;i++){
//         if(v[i]%2==0){res[cnt]=v[i];
//         cnt++;}
//     }
//     for(int i=0;i<size;i++){
//         if(v[i]%2!=0){
//             res[cnt]=v[i];
//             cnt++;
//         }
//     }
//     for (int i=0;i<size;i++){
//         cout<<res[i]<<" ";
//     }
// }
// int main(){
//     int size=7;
//     int v[size]={1,2,3,4,5,6,7};
//     sortevenodd(v,size); 
    
// }

// 11.Merging and sorting array
// A. MY WAY
// #include <iostream>
// #include <vector>
// using namespace std;
// int mergesorted(vector<int> &v1,vector <int> &v2, vector <int> &v3,int size){
//     for (int i=0;i<size+1;i++){
//         if(v1[0]>v2[0]){v3.push_back(v2[0]);
//         v2.erase(v2.begin());}
//         else{v3.push_back(v1[0]);
//         v1.erase(v1.begin());}
//         v1.push_back(INT16_MAX);
//         v2.push_back(INT16_MAX);
//     }
// }
// int main(){
//     vector <int> v1={1,3,9,40,44,100,1000,2001 };
//     vector <int> v2={-2,-1,0,45,45,90};
//     vector <int> v3; 
//     int size=v1.size()+v2.size()-1;
//     mergesorted(v1,v2,v3,size);
//     for(int i:v3){cout<<i<<" ";}
// }

// B.ONE WAY

// #include <iostream>
// #include <vector>
// using namespace std;
// int mergesorted(vector<int> &v1,vector <int> &v2, vector <int> &v3,int size1,int size2,int size){
//     int arr1cnt=0;
//     int arr2cnt=0;
//     while(arr1cnt<size1 and arr2cnt<size2){
//         if(v1[arr1cnt]<v2[arr2cnt]){v3.push_back(v1[arr1cnt]);
//         arr1cnt++;}
//         else{v3.push_back(v2[arr2cnt]);
//         arr2cnt++;}
//     }
//     while(arr1cnt<size1){v3.push_back(v1[arr1cnt]);
//     arr1cnt++;}
//     while(arr2cnt<size2){v3.push_back(v2[arr2cnt]);
//     arr2cnt++;}
// }
// int main(){
//     vector <int> v1={1,3,9,40,44,100,1000,2001 };
//     vector <int> v2={-2,-1,0,45,45,90};
//     vector <int> v3; 
//     int size1=v1.size();
//     int size2=v2.size();
//     int size=v1.size()+v2.size()-1;
//     mergesorted(v1,v2,v3,size1,size2,size);
//     for(int i:v3){cout<<i<<" ";}
// }


//12.traverse using for each loop

// #include<iostream>
// using namespace std;
// int main(){
//     int array[]={1,2,3,4,5};
//     for (int elements:array){
//         cout<<elements<<endl;  
//     }
// }

// input in array
// #include <iostream>
// using namespace std;
// int main(){
//     char vo_ar[5];
//     for(char &in_ele:vo_ar)
//     {cin>>in_ele;}
//     for(char out_ele:vo_ar)
//     {cout<<out_ele<<endl;}
    
// }


// 13.sum of array

// #include <iostream>
// using namespace std;
// int main(){
//     int arr[5]={1,2,3,4,5};
//     int sum=0;
//     for(int ele:arr){
//         sum+=ele;
//     }
//     cout<<sum;
// }

// 14.linear search

// #include<iostream>
// using namespace std;
// int main(){
//     int arr[]={1,5,6,9,78,4};
//     int s_no;
//     cin>>s_no;
//     int out=-1;
//     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
//         if(arr[i]==s_no){
//         out=i;
//         break;
//     }
// }
// cout<<out;

// }

// 15.checking if sorted

#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> v(5);


    for(int &ele:v){
        cin>>ele;
    }
    int chkd=0;
    int chka=0;
    for(int i=0;i<=v.size()-2;i++){
        if(v[i]<=v[i+1]){chkd++;}
        if(v[i]>=v[i+1]){chka--;}
    }
    if (chkd==v.size()-1){cout<<"Decending";}
    else if(chka==-(v.size()-1)){cout<<"Ascending";}
    else{cout<<"NOT SORTED!";}
}

// 16.check if three no. can be made same under three operation

// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
        
//     while (t>=1)
//     {
//         int v[3];
//         for (int &i:v)
//         {
//             cin>>i;
//         }
//         int len=sizeof(v)/sizeof(v[0]);
//         sort(v,v+len);
//         int sum=0;
//         bool found=true;
//         for(int i=1;i<3;i++){
//             if (v[i]%v[0]==0)
//             {
//                 sum+=((v[i]/v[0])-1);
//             }
//             else{
//                 found=false;
//                 break;}
//         }
//         if (found==true && sum<=3){cout<<"YES"<<endl;}
//         else{cout<<"NO"<<endl;}
//             t--;
//     }

    
// }

























