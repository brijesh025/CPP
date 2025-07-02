// /1. sum of no.
// #include <iostream>
// using namespace std;
// int main(){
//     int a;
//     int b;
//     cin>>a;
//     cin>>b;
//     cout<<"The sum of no. is="<<a+b;
//     return 0;
    
// }


// 2.Operators

// A. Arthmatic operator

// #include <iostream>
// using namespace std;
// int main(){
//     cout<<(6==3)<<endl;
//     cout<<(6!=3)<<endl;
//     return 0;
// }

// B.Bitwise operator

// #include <iostream>
// using namespace std;
// int main(){
//     int a=7; 
//     cout<<(a<<2)<<endl; /*left shift*/
//     cout<<(a>>2)<<endl; /*right shift*/
//     int b=8;
//     cout<<(a&b)<<endl; /*AND*/
//     cout<<(a|b); /*OR*/
//     return 0;

// } 


// C. MISC OPERATOR

// #include <iostream>
// using namespace std;
// int main(){
//     int a=5;
//     cout<<sizeof(a)<<endl; /*sizeof in bits*/
//     a==5?a=10:a=8; /*? conditional*/
//     cout<<a<<endl;
//     cout<< &a<<endl;/*address*/
//     cout<<++a<<endl;/*pre*/
//     cout<<a++<<endl;/*post*/
//     cout<<a<<endl;
//     return 0;
// }

// D. CONDITIONAL

// 1.check vowel or consonant(SWITCH)

// #include <iostream>
// using namespace std;
// int main(){
//     char alphabet;
//     cout<<"Enter your alphabet:";
//     cin>>alphabet;
//     switch (alphabet)
//     {
//     case 'a':
//         cout<<"VOWEL";
//         break;
//     case 'e':
//         cout<<"VOWEL";
//         break;
//     case 'i':
//         cout<<"VOWEL";
//         break;
//     case 'o':
//         cout<<"VOWEL";
//         break;
//     case 'u':
//         cout<<"VOWEL";
//         break;
    
//     default:
//     cout<<"CONSONANT";
//     break;
//     }
//     return 0;
// }


// E.LOOP

// a. DO WHILE
#include <iostream>
using namespace std;
int main(){
int i=0;
do
{
    cout<<i<<endl;
    i++;
} while (i<=10);
}























