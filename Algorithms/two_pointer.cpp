/*
The two-pointer approach is a popular technique in programming, especially useful for 
solving problems involving arrays, strings, or linked lists. It involves using two 
pointers (often called left and right) to scan through a data structure, usually with 
one pointer starting at the beginning and the other at the end, or both 
starting from different points and converging or diverging based on the problem.
1.Finding Pairs with a Given Sum
2.Removing Duplicates in a Sorted Array
3.Partitioning Problems
4. Two Pointers for Maximum Subarray Sum
5.Reversing an Array or String
********sorting sometime get better**********
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {1, 2, 3, 4, 6};
    int target = 6;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            break;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
return 0;
}
