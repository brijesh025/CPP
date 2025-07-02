#include <stdio.h>
#include <stdbool.h>
int insertion_sort(int array[],int size){
    for (int i = 1; i < size; i++)
    {int current=array[i];
    int j=i-1;
    while (j>=0 && array[j]>current)
    {

        array[j+1]=array[j];
        j--;
    }
    array[j+1]=current;
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
    insertion_sort(array,size);
return 0;
}