// A.BASIC SYNTAX

// #include<iostream>
// using namespace std;
// int main( ) {
// int x = 18;
// float y = 7.9;
// -----------------// Create a pointer that can store address of x;
// // As x is an integer variable , so we need a pointer
// // that can store address of integer type
// int *ptr = &x;
// cout << "Address stored inside ptr: " << ptr << "\n";
// cout << "Value present at the address stored in ptr: " <<* ptr << "\n"; // dereference
// -----------------// Create a pointer that can store address of y
// // y is a float variable, so we need to store it in a
// // float pointer
// float *ptrf = &y;
// cout << "Address stored inside ptrf: " << ptrf << "\n";
// cout << "Value present at the address stored in ptrf: " <<* ptrf << "\n";
// x = 23; ----------// the bucket x updated the
// // but ptr is still pointing to same bucket
// // now if we derefernce ptr, we will get 23
// cout << "New updated value of x " << x << "\n";
// cout << "ptr still pointing to same memory which has 23 instead of 18 - " <<* ptr << "\n";
// ------------// updating x with pointer
// *ptr = 50;
// cout << "New value of x " << x << "\n";
// cout << "New value pointed by ptr " <<* ptr << "\n";
// int valueAtX = *ptr;
// return 0;
// }

// B.ADDITION

// #include<iostream>
// using namespace std;
// int main(){
// int m,n,*pntr1=&m,*pntr2=&n;
// cin>>m>>n;
// cout<<"sum= "<<pntr1+*pntr2;

// }

// c.swap using pointer

// #include <bits/stdc++.h>
// using namespace std;
// int swap(int *a,int *b){
//     *a=*a+*b;
//     *b=*a-*b;
//     *a=*a-*b;
    

// }
// int main(){
//     int x=10,y=20;
//     int *p1=&x;
//     int *p2=&y;
//     swap(p1,p2);
//     cout<<x<<" "<<y;
// return 0;
// }

// D.NULL POINTER
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int *ptr=0;
//     cout<<*ptr; /*GIVE SEGMENTATION FAULT*/
// return 0;
// }

// E.TRAVERSING IN ARRAY USING POINTER
#include <bits/stdc++.h>
using namespace std;
int print(int *arr){
    for (int  i = 0; i < 5; i++)
    {
        cout<<(arr+i)<<" ";
    }
    
}
int main(){
    int arr[5]={1,2,3,4,5};
    print(arr);
return 0;
}