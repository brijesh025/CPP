#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    unordered_map<int,vector<int>> prefixMap;
    prefixMap[0].push_back(-1);
    int xr=0;
    int count=0;

    for(int i=0;i<n;i++){
        xr^=a[i];
        int need=xr^k;
        if(prefixMap.find(need)!=prefixMap.end()){
            for(auto idx:prefixMap[need]){
                count++;
                cout<<"Path "<<count<<": ";
                for(int j=idx+1;j<=i;j++)cout<<a[j]<<" ";
                cout<<"\n";
            }
        }
        prefixMap[xr].push_back(i);
    }

    cout<<"Total magical paths: "<<count<<"\n";
    return 0;
}
