#include <bits/stdc++.h>
using namespace std;

int weight(vector<int>freq, int i, int j) 
{ 
    int s = 0; 
    for (int r = i+1; r <= j; r++) s += freq[r]; 
    return s; 
}
int optCost(vector<int> freq, int i, int j) 
{ 
    if (j <= i)
        return 0; 
    if (j == i+1)
        return freq[j];
    int wt = weight(freq, i, j); 
    cout<<"i:"<<i<<" j:"<<j<<" wt:"<<wt<<endl;
    // Initialize minimum value 
    int minCost = INT_MAX; 
    // One by one consider all elements 
    // as root and recursively find cost 
    // of the BST, compare the cost with
    // min and update min if needed 
    for (int r = i+1; r <= j; r++) 
    { 
        minCost = min(minCost,optCost(freq, i, r - 1) + optCost(freq, r, j)); 
        
    } 
    // Return minimum value 
    return minCost + wt; 
} 

int main() 
{ 
    //coz algorithm mein 1 based indexing use ki hai issliye idhar bhi 1 based indexing use karni hogi
    vector<int> keys = {0,10, 12, 20}; 
    vector<int>freq = {0,34, 8, 50}; 
    //assuming keys are sorted. if not then sort it and arrange the keys accordingly
    int n = keys.size();
    cout<<optCost(freq,0,3);
    
    return 0; 
}