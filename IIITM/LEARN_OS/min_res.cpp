// 1.Similar resources requirements
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int p,m;
//     cout<<"ENTER NO. OF PROCESSES:";
//     cin>>p;
//     cout<<"ENTER NO. OF RESOURCES REQUIRED PER PROCESS:";
//     cin>>m;
//     cout<<p+(m-1);
    
//     return 0;
// }

// 2.Diffrent resources requirements
#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    vector<int> v(p);
    cout<<"ENTER NO. OF PROCESSES:";
    cin>>p;
    cout<<"ENTER NO. OF RESOURCES REQUIRED PER PROCESS:";
    for(int i=0;i<p;i++){
        cin>>v[i];
    }
    int sum=0;
    for(int i=0;i<p;i++){
        sum+=(v[i]-1);
    }
    cout<<sum+1;
    
    return 0;
}