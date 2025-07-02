// #include <stdio.h>
// #include <stdbool.h>
// int selection_sort(int array[],int size){
//     for (int i = 0; i < size-1; i++)
//     {
//         int minm_ind=i;
//         int flag=false;
//         for (int j = i; j < size; j++)
//         {
//             if (array[minm_ind]>array[j])
//             {
//                 flag=true;
//                 minm_ind=j;
//             }           
//         }
//         if (flag==true)
//         {
//                 array[minm_ind]=array[i]+array[minm_ind];
//                 array[i]=array[minm_ind]-array[i];
//                 array[minm_ind]=array[minm_ind]-array[i];
            
//         }
        
                
        
//     }
//     for (int i=0;i<size;i++)
//     {
//         printf("%d ", array[i]);
//     }
//     return 0;
// }
// int main(){
//     int size;
//     scanf("%d",&size);
//     int array[size];
//     for (int i=0;i<size;i++)
//     {
//         scanf("%d", &array[i]);
//     }
//     selection_sort(array,size);
// return 0;
// }
