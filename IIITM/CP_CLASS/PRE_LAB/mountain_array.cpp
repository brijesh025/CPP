#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector <int>& nums) {
        bool isAsc = false, isDesc = false;
        int i = 0;
        while(i<nums.size()-1 && nums[i]<nums[i+1]){
            isAsc = true; i++;
        }
        while(i<nums.size()-1 && nums[i]>nums[i+1]){
            isDesc = true; i++;
        }
        if(i>=nums.size()-1 && isAsc && isDesc){
            return true;
        }
        return false;
    }
};