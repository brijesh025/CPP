#include <stdio.h>
#include <stdbool.h>
int binary_search(int array[],int size,int target){
    int strt=0;
    int end=size-1;
    while (strt<=end)
    {
        int mid=end+(strt-end)/2;
        if(array[mid]==target){
            return mid;
        }
        else if(array[mid]<target){
            strt=mid+1;
        }
        else if(array[mid]>target){
            end=mid-1;
        }
        else{return -1;}
    }
    
}
int main(){
    int size;
    scanf("%d",&size);
    int array[size];
    for (int i=0;i<size;i++)
    {
        scanf("%d", &array[i]);
    }
    int target;
    scanf("%d",&target);
    printf("%d",binary_search(array,size,target));
    
return 0;
}