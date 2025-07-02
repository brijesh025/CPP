// 1.ARRAY INPUT AND OUTPUT
// #include <stdio.h> 
// int main(){
//     int n;
//     scanf("%d", &n);
//     int array[n];
//     for(int i=0;i<n;i++){
//         scanf("%d",&array[i]);        
//     }
//     for(int i=0;i<n;i++){
//         printf("%d ",array[i]);
//     }


// 2.PRINT ODD AND EVEN


    // printf("\nEVEN: ");

    // for (int i = 0; i < n; i++)
    // {
    //     if (array[i]%2==0){
    //         printf("%d ",array[i]);
    //     }
    // }
    // printf("\nODD: ");
    // for (int i = 0; i < n; i++)
    // {
    //     if (array[i]%2!=0){
    //         printf("%d ",array[i]);
    //     }
    // }

// 3.Print prime no.

    // printf("Prime no.: ");
    // for (int i = 0; i < n; i++)
    // {
    //     if (array[i]==2)
    //     {
    //         printf("%d",array[i]);
    //     }
        
    //     for (int j = 2; j <= array[i]/2; j++)
    //     {
    //         if (array[i]%j==0){
    //             continue;
    //         }
    //         else{
    //             printf(" %d", array[i]);
    //         }
    //     }
        
    // }
    
#include <stdio.h>
#include <string.h>
int main(){
    char str1[2];
    char str2[5]="brij";
    strcpy(str1,str2);
    printf("%s %d",str1,strlen(str1));
}