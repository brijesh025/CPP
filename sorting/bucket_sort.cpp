#include <bits/stdc++.h>
using namespace std;
float maxm(vector<float> arr){
    float maxm_ele=FLT_MAX;
    for(int i=0;i<arr.size();i++){
        maxm_ele=max(maxm_ele,arr[i]);
    }
    return maxm_ele;
}
float minm(vector<float> arr){
    float minm_ele=FLT_MAX;
    for(int i=0;i<arr.size();i++){
        minm_ele=min(minm_ele,arr[i]);
    }
    return minm_ele;
}
void bucket_sort(vector<float> &arr){
    vector<vector<float>> bucket(arr.size());
    for(int i=0; i<arr.size(); i++){
        float range=(maxm(arr)-minm(arr))/arr.size();
        // int index=arr[i]*arr.size();
        int index=(arr[i]-minm(arr))/range;\
        if(index==arr.size()) bucket[index-1].push_back(arr[i]); //if arr[i]=max_ele cause out of bound
        else bucket[index].push_back(arr[i]);
    }
    for(int i=0; i<arr.size(); i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(), bucket[i].end());
        }
    }
    int sorted_idx = 0;
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<bucket[i].size(); j++){
            arr[sorted_idx++] = bucket[i][j];
        }
    }
}

int main(){
    vector<float> arr = {0.7, 0.89, 10.47, 05.1};
    bucket_sort(arr);
    for(float &i : arr){
        cout << i << " ";
    }
    return 0;
}