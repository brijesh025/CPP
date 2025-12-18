// 1. Quick sort
#include <bits/stdc++.h>//Smaller on the left and larger on the right, pick a pivot element and put it at correct positon,use two pointer
using namespace std;//take two pointer in left and right and swap element larger than pivot in right. 
int partition(int arr[],int low,int high){
    int pivot_ele=arr[low];
    int left=low+1;
    int right=high;
    while(left<=right){
        while(left<=high and arr[left]<=pivot_ele) left++;
        while(right>=low and arr[right]>pivot_ele) right--;
        if(left<right){
            swap(arr[left],arr[right]);
        }
    }
    swap(arr[low],arr[right]);
    return right;
}
void quick_sort(int arr[],int low,int high){// TC-->O(nlogn) OR O(n^2)
    if(low>=high) return;
    int pi=partition(arr,low,high);
    quick_sort(arr,low,pi-1);
    quick_sort(arr,pi+1,high);
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int &i:arr)cin>>i;
    quick_sort(arr,0,size-1);
    for(int &i:arr)cout<<i<<" ";
return 0;
}


// 2.Sedgewick 2-way partionting --> here keep playing with the pivot element while true 
#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low-1,j=high+1;
    while(true){
        do{i++;}while(arr[i]<pivot);
        do{j--;}while(arr[j]>pivot);
        if(i>=j) return j;
        swap(arr[i],arr[j]);
    }
}
void quick_sort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi);
        quick_sort(arr,pi+1,high);
    }
}
int main(){
    int n;cin>>n;
    int arr[n];for(int &x:arr)cin>>x;
    quick_sort(arr,0,n-1);
    for(int x:arr)cout<<x<<" ";
}


//3. Dijtrak's 3 way partitioning
// Idea in simple words:
// Maintain 3 regions:
// < pivot
// == pivot
// > pivot
// We scan the array once, and whenever we see an element:
// If < pivot, throw it to the left.
// If > pivot, throw it to the right.
// If == pivot, keep it in the middle.
// This way, duplicates don’t recurse anymore.
#include <bits/stdc++.h>
using namespace std;
void partition3(int arr[],int low,int high,int &lt,int &gt){
    int pivot=arr[low];
    lt=low; 
    gt=high; 
    int i=low;
    while(i<=gt){
        if(arr[i]<pivot) swap(arr[i++],arr[lt++]);
        else if(arr[i]>pivot) swap(arr[i],arr[gt--]);
        else i++;
    }
}
void quick_sort(int arr[],int low,int high){
    if(low>=high) return;
    int lt,gt;
    partition3(arr,low,high,lt,gt);
    quick_sort(arr,low,lt-1);
    quick_sort(arr,gt+1,high);
}
int main(){
    int n;cin>>n;
    int arr[n];for(int &x:arr)cin>>x;
    quick_sort(arr,0,n-1);
    for(int x:arr)cout<<x<<" ";
}

// 4. bentley McIlroy Partition

pair<int,int> bentleyMcIlroyPartition(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2];
    int i = low, j = high;
    int p = low, q = high;
    while (true) {
        while (i <= j && arr[i] < pivot) i++;
        while (i <= j && arr[j] > pivot) j--;
        if (i > j) break;
        swap(arr[i], arr[j]);
        if (arr[i] == pivot) {
            swap(arr[i], arr[p]);
            p++;
        }
        if (arr[j] == pivot) {
            swap(arr[j], arr[q]);
            q--;
        }
        i++;
        j--;
    }
    int lt = j;
    int gt = i;
    int k;
    for (k = low; k < p; k++, lt--) swap(arr[k], arr[lt]);
    for (k = high; k > q; k--, gt++) swap(arr[k], arr[gt]);

    return {lt + 1, gt - 1};
}



// 5. Dual Pivot Partition 
pair<int,int> dualPivotPartition(int arr[], int low, int high) {
    if (arr[low] > arr[high]) 
        swap(arr[low], arr[high]);
    int p1 = arr[low];
    int p2 = arr[high];
    int lt = low + 1;
    int gt = high - 1;
    int i = lt;
    while (i <= gt) {
        if (arr[i] < p1) {
            swap(arr[i], arr[lt]);
            lt++;
            i++;
        }
        else if (arr[i] > p2) {
            swap(arr[i], arr[gt]);
            gt--;
        }
        else {
            i++;
        }
    }
    swap(arr[low], arr[lt-1]);
    swap(arr[high], arr[gt+1]);

    return {lt-1, gt+1
    };
}
void quick_sort(int arr[], int low, int high) {
    if (low >= high) return;
    auto p = dualPivotPartition(arr, low, high);
    int lt = p.first;
    int gt = p.second;
    quick_sort(arr, low, lt - 1);
    quick_sort(arr, lt + 1, gt - 1);
    quick_sort(arr, gt + 1, high);
}


