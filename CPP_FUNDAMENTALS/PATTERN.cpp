// 1.RECTANGULAR STAR

// #include <iostream>
// using namespace std;
// int main(){
//     cout<<"ENTER ROW:";
//     int m;
//     cin>>m;
//     cout<<"ENTER COLUMN:";
//     int n;
//     cin>>n;
//     for (int i=1;i<=m;i++){
//         for (int j=1;j<=n;j++){cout<<"*";};
//         cout<<endl;
//     }
//     return 0;
// }

// 2.HOLLOW RECTANGLE STAR

// #include <iostream>
// using namespace std;
// int main(){
//     cout<<"ENTER ROW:";
//     int m,n;
//     cin>>m;
//     cout<<"ENTER COLUMN:";
//     cin>>n;
//     for (int i=1;i<=m;i++){
//         for (int j=1;j<=n;j++){
//             if (i==1||i==m||j==1||j==n){cout<<"*";}
//             else{cout<<" ";}
//             };
//         cout<<endl;
//     }
//     return 0;
// }

// 3.HALF Traingular star

// #include <iostream>
// using namespace std;
// int main(){
//     int m,n;
//     cout<<"ENTER NO. OF ROWS:";
//     cin>>m;
//     n=m;
//     for (int i=1;i<=m;i++){
//         for (int j=1;j<=i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// 4.REV HALF TRAINGLE STAR

// #include <iostream>
// using namespace std;
// int main(){
//    int m,k=0;
//    cout<<"ENTER ROW:";
//    cin>>m;
//    for(int i=m;i>=1;i--){
//     k++;
//     for (int j=1;j<=m;j++){
//         if(j>=m-k+1){cout<<"*";}
//         else{cout<<" ";}
//     }
//     cout<<endl;
//    }
//    return 0;
// }

// 5.STAR TRAINGLE

// #include <iostream>
// using namespace std;
// int main(){
//    int m,k=0;
//    cout<<"ENTER ROW:";
//    cin>>m;
//    for(int i=m;i>=1;i--){
//     for(int j=1;j<=2*m-1;j++){
//         if (j>=((2*m)/2)-k&&j<=(2*m)/2+k){cout<<"*";}
//         else{cout<<" ";}
//     }
//     cout<<endl;
//     k++;
//    }
//    return 0;
// }

// 6.STAR RHOMBUS

// #include <iostream>
// using namespace std;
// int main(){
//     int m,k=0;
//     cout<<"ENTER NO. OF ROW:";
//     cin>>m;
//     for (int i=1;i<=(2*m);i++){
//            for (int j=1;j<=2*m-1;j++){
//             if (j>=m-k && j<=m+k)
//             {
//                 cout<<"*";
//             }
//             else{cout<<" ";}
            
//         }
//         if(i<m){k++;}
//         else{k--;}     
//         cout<<endl;
//     }
// }


// 7.NUMBER RHOMBUS

// #include <iostream>
// using namespace std;
// int main(){
//     int m,k=0,l=0;
//     cout<<"ENTER ROW:";
//     cin>>m;
//     for(int i=1;i<=2*m;i++){
//         for(int j=1;j<=4*m;j++){
//             if(j>=m-k && j<=m+k){
//                 l++;
//                 cout<<l;
//             }
//             else{cout<<" ";}
//         }
//         cout<<endl;
//         l=0;
//         if(i<m){k++;}
//         else{k--;}
        
//     }
// }


// 8.Square
#include<iostream>
using namespace std;
int main(){
    int s;
    cin>>s;
    for(int i=1;i<=s;i++){
        for(int j=1;j<=s;j++){
            if(i==1||i==s||j==1||j==s){cout<<"*";}
            else{cout<<" ";}
        }
        cout<<endl;
    }

}





// 9.ALPHABET RHOMNUS

// #include <iostream>
// using namespace std;

// int main(){
//     int n,m,k=0;
//     cout<<"ENTER NO.:";
//     cin>>n;
//     for(int i=1;i<=2*n;i++){
//         char l=(char)65;
//         for(int j=1;j<=n*2-1;j++){
//             if(j>=n-k&&j<=n+k){
//                 cout<<l;
//                 l++;
//             }
//             else{cout<<" ";}
//         }
//         if(i<n){k++;}
//         else{k--;}
//         cout<<endl;
//     }
// }

// 10.PLUS PATTERN

// #include <iostream>
// using namespace std;
// int main(){
//     int m,n,k;
//     cout<<"ENTER NO.";
//     cin>>m;
//     for(int i=1;i<=m;i++){
//         for(int j=1;j<=m;j++){
//             if(j==(m+1)/2||i==(m+1)/2){cout<<"*";}
//             else{cout<<" ";}
//         }
//         cout<<endl;

//     }
// }

















