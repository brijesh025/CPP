/*In fast and slow pointer we take two pointers and strt traversing while 
incrementing them them at diffent speed as per the question requirements*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int sqr_sum(int n){
        int ans=0;
        while(n!=0){
            ans+=(n%10)*(n%10);
            n/=10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int pntr1=sqr_sum(n);
        int pntr2=sqr_sum(sqr_sum(n));
        if(sqr_sum(pntr1)==1 or sqr_sum(pntr2)==1)return true;
        while(pntr1!=pntr2){
            if(sqr_sum(pntr1)==1 or sqr_sum(pntr2)==1)return true;
            pntr1=sqr_sum(pntr1);
            pntr2=sqr_sum(sqr_sum(pntr2));
        }
        return false;
    }
};
int main(){
    int n=2;
    Solution s;
    s.isHappy(n);
return 0;
}