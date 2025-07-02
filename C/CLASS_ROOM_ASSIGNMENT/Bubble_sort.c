#include <stdio.h>
#include <stdbool.h>
int bubble_sort(int array[],int size){
    for (int i = 0; i < size-1; i++)
    {
        bool flag=false;
        for (int j = 0; j < size-i; j++)
        {
            if (array[j]>array[j+1])
            {
                flag=true;
                array[j]=array[j]+array[j+1];
                array[j+1]=array[j]-array[j+1];
                array[j]=array[j]-array[j+1];
            }
            if (flag==false)
            {
                break;
            }
            
            
        }
        
    }
    for (int i=0;i<size;i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
int main(){
    int size;
    scanf("%d",&size);
    int array[size];
    for (int i=0;i<size;i++)
    {
        scanf("%d", &array[i]);
    }
    bubble_sort(array,size);
return 0;
}