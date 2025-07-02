// 1.PALLINDROME
// #include<stdio.h>
// void main(){
//     int m,n=0;
//     printf("enter: ");
//     scanf("%d",&m);
//     for (int i = m; i>0;i=i/10){
//         n=(n*10)+(i%10);
//     }
//     printf("%d\n",n);
//     if(m==n){
//         printf("YES");
//     }
//     else{printf("NO");}   
// }

// 2. SUM OF EVEN NO.

// #include<stdio.h>
// void main(){
//     int m,n=0,sum=0;
//     printf("enter: ");
//     scanf("%d",&m);
//     for(int i=1;i<=m;i++){
//     scanf("%d",&n);
//     if(n%2==0 && n%2==0 && n%5==0){
//         sum+=n;
//     }
//     else{
//         continue;

//     }
//     }
//     printf("%d",sum);
// }

// 3.PASCALS TRAINGLE

// #include<stdio.h>
// int main(){
//     int n;
//     scanf("%d",&n);
//     int up_mul,down_mul,result=1;
//     for(int i=0;i<n;i++){ 
//         for(int j=0;j<=i;j++){
//             up_mul=i;
//             if(j==0 || j==i){
//                 printf("1 ");
//             }
//             else{
//                 for(int k=j;k<=1;k--){
//             result*=up_mul/down_mul;       
//                 }
//             printf("%d ",result);
//             up_mul--;
//             down_mul--;
//             }       }
//             printf("\n");
//     }
// }


// 4.Swap with temp
// #include <stdio.h>
// int main(){
//     int a,b,temp;
//     scanf ("%d",&a);
//     scanf ("%d",&b);
//     temp=a;
//     a=b;
//     b=temp;
//     printf("a:%d",a);
//     printf("b:%d",b);
// }

// 5.Swap without temp

// #include <stdio.h>
// int main(){
//     int a,b;
//     scanf ("%d%d",&a,&b);
//     a=a+b;
//     b=a-b;
//     a=a-b;
//     printf("a:%d",a);
//     printf("\n");
//     printf("b:%d",b);
// }

// 6.His DA IS 40% of his salary and HRA is 20% of his salary

// #include <stdio.h>
// int main(){
//     float basic;
//     scanf ("%f",&basic);
//     float total=basic+(0.2*basic)+(0.4*basic);
//     printf("total:%f",total);
// }


// 7.in a class marks of 5 students are given as follows: 80,85,70,75,60

// #include <stdio.h>
// int main(){
//     int a=80,b=85,c=70,d=75,e=60;
//     float avg=(a+b+c+d+e)/5;
//     printf("total:%f",avg);
// }

// 8. temp of a city in faraenhite
//  #include <stdio.h>
// int main(){
//     float tmpf;
//     scanf ("%f",&tmpf);
//     float tmpc =(tmpf-32)*5/9;
//     printf("temp in celcius:%f",tmpc);
// }



// 9.Greater no.

// #include <stdio.h>
// void main(void){
//     int num1,num2;
//     printf("Enter num1:");
//     scanf("%d",&num1);
//     printf("Enter num2:");
//     scanf("%d",&num2);
//     if(num1>num2){
//         printf("NUM1 IS GREATER");
//     }
//     else if(num1<num2){
//         printf("NUM2 IS GREATER");
//     }
//     else{printf("EQUAL");}
// }

// 10.ODD EVEN

// #include <stdio.h>
// void main(void){
//     int num1;
//     printf("Enter num1:");
//     scanf("%d",&num1);
//     if(num1%2==0){
//         printf("EVEN");
//     }
//     else{printf("ODD");}
    
    
//     }


// 11.LEAP YEAR

// #include <stdio.h>
// void main(void){
//     int y;
//     printf("ENTER YEAR:");
//     scanf("%d",&y);
//     if(y%100==0&&y%400==0){
//         printf("LEAP YEAR");
//     }
//     else if(y%4==0&&y&100!=0){
//         printf("LEAP YEAR");
//     }
//     else{printf("NOT LEAP");}
//     }

// 12.ROOT OF QE
// #include <stdio.h>
// #include <math.h>
// int main(){
//     float a,b,c;
//     printf("Enter coef:");
//     scanf("%f""%f""%f",&a,&b,&c);
//     if((b*b)-(4*a*c)<0){float d=-((b*b)-(4*a*c));
//     printf("%f",-b/(2*a));
//     printf("+%fi\n",sqrt(d)/(2*a));
//     printf("%f",-b/(2*a));
//     printf("-%fi",sqrt(d)/(2*a));
// }
//     else{float d=((b*b)-(4*a*c));
//     float res1=(-b+sqrt(d))/(2*a);
//     float res2=(-b-sqrt(d))/(2*a);
//         printf("%f\n""%f",res1,res2);}
// }

// 12. POINTER PRBLMS

// #include <stdio.h>
// int pointer(int a){
//     printf("Value of a: %d\n",a);
//     int *pntr1=&a;
//     int **pntr2=&pntr1;
//     printf("Adress of a: %p\n",pntr1);
//     printf("Adress of pntr1: %p\n",pntr2);
// }
// int sum(int a,int b){
//     int *pntr1=&a;
//     int *pntr2=&b;
//     int sum=*pntr1+*pntr2;
//     return sum;

// }
// int swap(int a,int b){
//     int *pntr1=&a;
//     int *pntr2=&b;
//     a=*pntr2+*pntr1; 
//     b=*pntr1-*pntr2;
//     a=*pntr1-*pntr2;
//     printf("value of a: %d\n""value of b: %d\n",a,b);
//     }
// int main(){
//     // 1.Demonstrate
//     int a;
//     scanf("%d",&a);
//     int b;
//     scanf("%d",&b);
//     pointer(a);
//     // 2.sum
//     printf("sum of a and b: %d\n",sum(a,b));
//     // 3.swap
//     swap(a,b);




// return 0;
// }
