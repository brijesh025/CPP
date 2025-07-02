// 1. BINARY TO DECIMAL

// #include <iostream>
// using namespace std;
// int main(){
//     int a,b=0,c=0;
//     cout<<"ENTER NO.:";
//     cin>>a;
//     for(int i=0;a>0;i++){
//     b=(a%10);
//         for (int j=0;j<i;j++){b*=2;}
//     a/=10;
//     c+=b;
//     }
//     cout<<c;
// }

// 2.DECIMAL TO BINARY

#include <iostream>
using namespace std;
int main(){
    int b_no,ans=0,pow=1;
    cout<<"ENTER NO:";
    cin>>b_no;
    do{
    ans+=(b_no%2)*pow;
    b_no/=2;
    pow*=10;
    }while(b_no>0);
    cout<<ans;
}