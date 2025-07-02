#include <bits/stdc++.h>
using namespace std;
int main(){
    int size;
    cin>>size;
    int array[size];
    for (int &i:array)
    {
        cin>>i;
    }
    for (int j = 0; j < size-1; j++)
    {
    int flag=false;
    for (int i = 0; i < size-1-j; i++)
    {
        if(array[i]>array[i+1]){
            flag=true;
            swap(array[i],array[i+1]);
        }
    }
        if(!flag){
            break;
        }
    }
     for (int &i:array)
    {
        cout<<i<<" ";
    }
    

return 0;
}

