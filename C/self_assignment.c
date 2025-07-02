// 1. DIGIT SUM
// #include <stdio.h>
// int main(){
//     int a;
//     scanf("%d",&a);
//     int sum=0;
//     while(a>0){
//         sum+=a%10;
//         a/=10;
//     }
//     printf("%d",sum);

// return 0;
// }

// 2.leap or not
// #include <stdio.h>
// int main(){
//     int a;
//     scanf("%d",&a);
//     if (a%4==0 && a%100!=0)
//     {
//         printf("leap year");
//     }
//     else if(a%400==0){printf("LEAP");}
//     else{printf("not leap");}




// return 0;
// }


// 3.QUADRATIC EQUATION
// #include <stdio.h>
// #include <math.h>
// int main(){
// float a,b,c;
// scanf("%f""%f""%f",&a,&b,&c);
// float d=((b*b)-(4*a*c));
// if (d>=0)
// {
//     float r1=(-b+sqrt(d))/(2*a);
//     float r2=(-b-sqrt(d))/(2*a);
//     printf("root1=%.2f\nroot2=%.2f",r1,r2);
// }
// else{
//     printf("root1=%.2f+%.2fi\n",-b/(2*a),sqrt(-d)/(2*a));
//     printf("root2=%.2f-%.2fi",-b/(2*a),sqrt(-d)/(2*a));
// }

// }

// 4.fibonacci series

// #include <stdio.h>
// int main(){
//     int n;
//     printf("enter: ");
//     scanf("%d",&n);
//     int temp=0,curnt=1,res=0;
//     while (n>0)
//     {
//         printf("%d ",res);
//         temp=curnt;
//         curnt=res;
//         res=temp+curnt;
//         n--;
//     }



// }

// 5.binary equivalent
//#include <stdio.h>
//int main(){
//int n,rem=0,i=1,res=0;
//scanf("%d",&n);
//while(n>0){
//    rem=n%2;
//    res=res+rem*i;
//    n/=2;
//    i*=10;
//
//}
//printf("%d",res);

//6.no.--> word
//#include <stdio.h>
//
//void digit_word(int n){
//    while(n>0){
//    switch(n%10){
//    case 1:printf("one ");
//    break;
//    case 2:printf("two ");
//    break;
//    case 3:printf("three ");
//    break;
//    case 5:printf("five ");
//    break;
//    case 6:printf("six ");
//    break;
//    case 7:printf("seven ");
//    break;
//    case 8:printf("eight ");
//    break;
//    case 9:printf("nine ");
//    break;
//    default:printf("zero ");
//    break;
//    }
//    n/=10;
////    digit_word(n/10);
//    }
//}
//int main(){
//int a,n=0;
//scanf("%d",&a);
//while(a>0){
//    n=(n*10)+(a%10);
//    a/=10;
//}
//digit_word(n);
//
//
//}


//7.matrix multiplication
//#include <stdio.h>
//int *multiply(int m,int n,int p,int q,int v1[m][n],int v2[p][q],int res[m][q]){
//    for (int i = 0; i<m; i++)
//    {
//        for (int j = 0; j <q; j++)
//        {int result=0;
//            for (int k = 0;  k< n; k++)
//            {
//                result+=v1[i][k]*v2[k][j];
//            }
//        res[i][j]=result;
//        }
//
//    }
//
//
//}
//int mat_in(int row,int column,int v[row][column]){
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < column; j++)
//        {
//            scanf("%d",&v[i][j]);
//        }
//
//    }
//    }
//int mat_out(int row,int column,int v[row][column]){
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < column; j++)
//        {
//            printf("%d ",v[i][j]);
//        }
//        printf("\n");
//
//    }
//
//
//}
//int main(){
//    int m,n,p,q;
//    scanf("%d""%d""%d""%d",&m,&n,&p,&q);
//    int v1[m][n];
//    int v2[p][q];
//    if (n!=p)
//    {
//        printf("NOT POSSIBLE");
//        return 0;
//    }
//
//    int res[m][q];
//    mat_in(m,n,v1);
//    mat_in(p,q,v2);
//    multiply(m,n,p,q,v1,v2,res);
//    mat_out(m,q,res);
//
//}

//8.mtrix transpose
// #include <stdio.h>
// int *transpose(int m,int n, int v[m][n],int trans[n][m]){
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             trans[j][i]=v[i][j];
//         }
//
//     }
//
// }
// int mat_in(int row,int column,int v[row][column]){
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < column; j++)
//         {
//             scanf("%d",&v[i][j]);
//         }
//
//     }
//     }
// int mat_out(int row,int column,int v[row][column]){
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < column; j++)
//         {
//             printf("%d ",v[i][j]);
//         }
//         printf("\n");
//
//     }
// }
// int main(){
//     int m,n;
//     scanf("%d""%d",&m,&n);
//     int v[m][n];
//     int trans[n][m];
//     mat_in(m,n,v);
//     transpose(m,n,v,trans);
//     mat_out(n,m,trans);
//
// }


//9.string reverse
//#include <stdio.h>
//#include <string.h>
//int compute(char str[],char chr,int *f,int *l){
//    for(int i=0;i<strlen(str);i++){
//        if(chr==str[i]){
//                *f=i;
//            break;
//        }
//    }
//    for(int i=strlen(str)-1;i>=0;i--){
//            if(chr==str[i]){
//                *l=i;
//                break;
//            }
//    }
//
//}
//int main(){
//    int size;
//    scanf("%d",&size);
//    char str[size];
//    scanf("%s",&str);
//    char ch;
//    printf("Enter a character: ");
//    scanf(" %c", &ch);
//    int f=-1;
//    int l=-1;
//    int * pf=&f;
//    int * pl=&l;
//    compute(str,ch,pf,pl);
//    printf("%d",f);
//    printf("%d",l);
//
//}



//10.occurence count

//#include <stdio.h>
//int main(){
//    int size;
//    scanf("%d",&size);
//int arr[size];
//for(int i=0;i<size;i++){
//    scanf("%d",&arr[i]);
//}
//for(int i=0;i<size;i++){
//        if(arr[i]==-1){
//                continue;}
//        int sum=0;
//        int curnt=arr[i];
//    for(int j=i;j<size;j++){
//        if(curnt==arr[j]){
//            sum++;
//            arr[j]=-1;
//        }
//
//
//}
//printf("NO. OF %d: %d\n",curnt,sum);
//}
//}



//11.first and last index of a char using pointer

//#include <stdio.h>
//#include <string.h>
//int compute(char str[],char chr,int *f,int *l){
//    for(int i=0;i<strlen(str);i++){
//        if(chr==str[i]){
//                *f=i;
//            break;
//        }
//    }
//    for(int i=strlen(str)-1;i>=0;i--){
//            if(chr==str[i]){
//                *l=i;
//                break;
//            }
//    }
//
//}
//int main(){
//    int size;
//    scanf("%d",&size);
//    char str[size];
//    scanf("%s",&str);
//    char ch;
//    printf("Enter a character: ");
//    scanf(" %c", &ch);
//    int f=-1;
//    int l=-1;
//    int * pf=&f;
//    int * pl=&l;
//    compute(str,ch,pf,pl);
//    printf("%d",f);
//    printf("%d",l);
//
//}

/// 12.maxm and min using ternary operator
// #include <stdio.h>
// int main(){
//     int a,b,c;
//     scanf("%d""%d""%d",&a,&b,&c);
//     (a>b && b>c) ? printf("maxm=%d minm=%d",a,c):(b>a && a>c) ? printf("maxm=%d minm=%d",b,c):(b>c && c>a) ? printf("maxm=%d minm=%d",b,a):(c>a&&a>b) ? printf("maxm=%d minm=%d",c,b):(c>b && b>a) ? printf("maxm=%d minm=%d",c,a):printf("maxm=%d minm=%d",a,b);
// }


// 13.swap using pointer

// #include <stdio.h>
// int swap(int *a,int *b){
//     int temp=*a;
//     *a=*b;
//     *b=temp;

// }
// int main(){
// int x=10,y=20;
// swap(&x,&y);
// printf("%d %d",x,y);
// return 0;
// }

// 14.matrix transpose using pointer

// #include <stdio.h>
// int mat_in(int rows,int col,int *v){
//     for(int i=0;i<rows;i++){
//         for(int j=0;j<col;j++){
//             scanf("%d",*(v+i+j));

//         }
//     }
// }
// int mat_out(int rows,int col,int *v){
//      for(int i=0;i<rows;i++){
//         for(int j=0;j<col;j++){
//             printf("%d ",*(v+i+j));

//         }
//         printf("\n");
//     }

// }
// int main(){
//     int rows,col;
//     scanf("%d""%d",rows,col);
//     int v[rows][col];
//     mat_in(rows,col,v);
//     mat_out(rows,col,v);
    

// return 0;
// }

// 15.factorial using recursion
// #include <stdio.h>

// // Recursive function to calculate factorial
// int factorial(int n) {
//     // Base case: factorial of 0 or 1 is 1
//     if (n == 0 || n == 1) {
//         return 1;
//     } else {
//         // Recursive case: n! = n * (n-1)!
//         return n * factorial(n - 1);
//     }
// }

// int main() {
//     int num;

//     // Input: Get the number from the user
//     printf("Enter a number: ");
//     scanf("%d", &num);

//     // Check if the number is non-negative
//     if (num < 0) {
//         printf("Factorial is not defined for negative numbers.\n");
//     } else {
//         // Call the recursive function to calculate factorial
//         int result = factorial(num);

//         // Output: Display the factorial of the number
//         printf("Factorial of %d is: %d\n", num, result);
//     }

//     return 0;
// }


