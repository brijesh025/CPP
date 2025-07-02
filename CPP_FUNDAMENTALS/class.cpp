// #include<bits/stdc++.h>
// using namespace std;
// class students{
//     public:
//     int roll_no;
//     string name;
//     string batch;
// };
// class fruit{
//     public:
//     string name;
//     string color;
// };
// // CONSTRUCTOR AND DESTRUCTOR
// class rectangle{    
//     public:
//     int l;
//     int b;

//     // default constructor
//     rectangle(){
//         l=0;
//         b=0;
//     }
//     // parametrised constructor
//     rectangle(int x,int y){
//         l=x;
//         b=y;
//     }
//     // copy constructor
//     rectangle(rectangle &r){
//         l=r.l;
//         b=r.b;
//     }
//     // destructor
//     ~rectangle(){
//         cout<<"DESTRUCTOR"<<endl;//calls only when main function ends//
//     }
// };
// // ENCAPSULATION
// class ABC{
//     int x;
//     public:
//     void set(int n) {x=n;}
//     int get() {return x;}
// };
// int main(){
//     // object method-1
//     students brijesh;
//     cin>>brijesh.roll_no;
//     cin>>brijesh.name;
//     cin>>brijesh.batch;
//     cout<<brijesh.roll_no<<" ";
//     cout<<brijesh.name<<" ";
//     cout<<brijesh.batch<<" "<<endl;
//     // pointer mathod-2
//     fruit *mango=new fruit();
//     cin>>mango->name;
//     cin>>mango->color;
//     cout<<mango->color<<" ";
//     cout<<mango->color<<" "<<endl;
//     // constructor
//     // deafult
//     rectangle r1;
//     cout<<r1.l<<" "<<r1.b<<endl;
//     // parametrised
//     rectangle r2(3,4);
//     cout<<r2.l<<" "<<r2.b<<endl;
//     // copy
//     rectangle r3=r2;
//     cout<<r3.l<<" "<<r3.b<<endl;
//     // use of delete
//     rectangle *r4;
//     delete r4; 
//     // ENCAPSULATION
//     ABC obj;
//     obj.set(10);
//     cout<<obj.get()<<endl;
// }




// CHP-2 INHRITANCE

// #include <bits/stdc++.h>
// using namespace std;
// class parents{
//     public:
//     int x;
//     protected:
//     int y;
//     private:
//     int z;
// };
// // method of inheritance
// class child1:public parents{
//     // all values types remains same
// };
// class child2:protected parents{
//     // all public becomes protetced rest same
// };
// class child3:private parents{
//     // all public and protected becomes private and private is inaccessable
// };
// // types of inheritance
// // single level
// class child4:public parents{

// };
// // multi level
// class child5:public child4{

// };
// // hierchy
// class child6:public parents{

// };
// class child7:public parents{

// };
// // hybrid level
// class child8:public child7{

// };
// // multiple inheritance
// class child9: public parents,child1{

// };
// int main(){

// return 0;
// }


// CHP-3-->POLYMORPHISM


// A.funtion overloading
// #include <bits/stdc++.h>
// using namespace std;
// class area_sum{
// public:
//     void sum(int a,int b,int c){
//         cout<<a+b+c<<endl;
//     }
//     void sum(int a,int b,int c,int d){
//         cout<<a+b+c+d<<endl;
//     }
//     void sum(float a,float b,float c){
//         float add=a+b+c;
//         cout<<add<<endl;
//     }

// };
// // B.operartor overloading
// class complexs{
// public:
//     int real;
//     int imaginary;
//     complexs(int x,int y){
//         real=x;
//         imaginary=y;
//     }
//     complexs operator+ (complexs &c2){
//         complexs ans(0,0);
//         ans.real=real+c2.real;
//         ans.imaginary=imaginary+c2.imaginary;
//         return ans;
//     }
// };

// //C. Function overriding
// class parents{
// public:
//     virtual void print(){
//         cout<<"PARENT CLASS"<<endl;
//     }
//     void show(){
//         cout<<"parent class"<<endl;

//     }
// };
// class child:public parents{
// public:
//     void print(){
//         cout<<"child class"<<endl;
//     }
//     void show(){
//         cout<<"CHILD CLASS"<<endl;
//     }

// };
// int main(){
//     // function overloading
//     area_sum a_s;
//     a_s.sum(4,5,6);
//     a_s.sum(4,5,6,9);
//     a_s.sum(float(5.5),float(5.9),float(6.4));

//     // operator overloading
//     complexs c1(1,2);
//     complexs c2(1,3);
//     complexs c3=c1+c2;
//     cout<<c3.real<<"+"<<c3.imaginary<<"i"<<endl;

//     // FUNCTION overriding
//     parents *p;
//     child c;
//     p=&c;
//     p->print();
//     p->show();

// return 0;
// }

// CHP 4-->FRIEND FUNCTION
#include <bits/stdc++.h>
using namespace std;
class A{
    int x;
public:
    A(int val){
        x=val;
    }
   friend void print(A &object); //give acess to fun A of private variables
};
void print(A &object){
    cout<<object.x<<endl;
}
int main(){
    A object(5);
    print(object);
return 0;
}