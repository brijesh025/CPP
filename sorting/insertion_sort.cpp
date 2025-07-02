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
    for (int  i = 1; i < size; i++)
    {
        int current=array[i];
        int j=i-1;
        while (j>=0 && array[j]>current)
        {
            array[j+1]=array[j];//find correct position of current element
            j--;
        }
        array[j+1]=current;
    }
             for (int &i:array)
    {
        cout<<i<<" ";
    }
return 0;
}
