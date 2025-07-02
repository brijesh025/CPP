#include <bits/stdc++.h>
using namespace std;
class disjoint_set{
    vector<int> parent, rank, size;
    public:
    disjoint_set(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            size[i]=1;
            rank[i] = 0;
        }
    }
    int find(int node) {            //Time complexity--> O(4*alpha)=O(1)
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]); // Path compression
    }
    void union_set_rank(int x, int z) {                    //Time complexity--> O(4*alpha)=O(1)
        int p_x = find(x);
        int p_z = find(z);
    
        if(p_x == p_z) return; // Already in the same set
    // Union by rank
        if(rank[p_x] > rank[p_z]) {
            parent[p_z] = p_x; // Make p_x the parent of p_z
        } 
        else if(rank[p_x] < rank[p_z]) {
            parent[p_x] = p_z; // Make p_z the parent of p_x
        } 
        else {
            parent[p_z] = p_x; // Make p_x the parent
            rank[p_x]++; // Increase rank of p_x
        }
}
    void union_set_size(int x, int z) {                    //Time complexity--> O(4*alpha)=O(1)
        int p_x = find(x);
        int p_z = find(z);
        if(p_x == p_z) return; // Already in the same set
        if(size[p_x] > size[p_z]) {
            parent[p_z] = p_x;
            size[p_x]+=size[p_z]; // Make p_x the parent of p_z
        } 
        else{
            parent[p_x] = p_z; // Make p_z the parent of p_x
            size[p_z]+=size[p_x];
        } 
}
};

int main(){
    int n;
    cin >> n;
    disjoint_set ds(n);
    bool rslt=ds.find(1)==ds.find(5);
    cout<<rslt<<endl;
    ds.union_set_size(1,5);
    rslt=ds.find(1)==ds.find(5);
    cout<<rslt<<endl;
return 0;
}
