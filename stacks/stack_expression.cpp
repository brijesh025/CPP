// A.PREFIX EVAVLUTAION

// B.POSTFIX EVALUATION
// #include <bits/stdc++.h>
// using namespace std;
// int post_fix_sol(string s){
//     stack <char> hold_ele;
//     int res=0;
//     for(char &c:s){
//         if(isdigit(c)) hold_ele.push(c-'0');
//         else{
//             int b=hold_ele.top();
//             hold_ele.pop();
//             int a=hold_ele.top();
//             hold_ele.pop();
//             switch(c){
//                case '+':
//                 res=a+b;
//                 break;
//                case '-':
//                 res=a-b;
//                 break;
//                case '*':
//                 res=a*b;
//                 break;
//                case '/':
//                 res=a/b;
                // break;
                //   case '^':
                //   res=pow(a,b);
                //   break;
//             }
//             hold_ele.push(res);
//         }
//     }
//     return hold_ele.top();
// }
// int main(){
//     string s;
//     cin>>s;
//     cout<<post_fix_sol(s);
// return 0;
// }

// C.INFIX EVALUATE
// #include<bits/stdc++.h>
// using namespace std;
// class stacks{
//     int arr[INT16_MAX];
//     int max_size;
//     int top;
//     public:
//     stacks(int size){
//         max_size=size;
//         top=-1;
//     }
//     bool is_empty(){
//         return top==-1;
//     }
//     bool is_full(){
//         return max_size==top+1;
//     }
//     void push(int data){
//         if(is_full()) return;
//         arr[++top]=data;
//     }
//     void pop(){
//         if(is_empty()) return;
//         --top;
//     }
//     int top_ele(){
//         if(is_empty()) return -1;
//         return arr[top];
//     }
// };
// int cal(int a,int b,char c){
//     if(c=='+') return a+b;
//     else if(c=='-') return a-b;
//     else if(c=='*') return a*b;
//     else if(c=='/') return a/b;
// }
// int precedence(char ch){
//     if(ch=='+' or ch=='-') return 1;
//     if(ch=='*' or ch=='/') return 2;
//     return 0;
// }
// int infix_sol(string s){
//     stack<int> hold_digit;
//     stack <char> hold_operator;
//     for (char &c:s){
//         if(isdigit(c)){
//             hold_digit.push(c-'0');
//         }
//         else if(c=='('){
//             hold_operator.push(c);
//         }
//         else if(c==')'){
//             while(!hold_operator.empty() and hold_operator.top()!='('){
//                 int b=hold_digit.top();
//                 hold_digit.pop();
//                 int a=hold_digit.top();
//                 hold_digit.pop();
//                 hold_digit.push(cal(a,b,hold_operator.top()));
//                 hold_operator.pop();
//             }
//             if(!hold_operator.empty())hold_operator.pop();
//         }
//         else{
//             while(!hold_operator.empty() and precedence(hold_operator.top())>=precedence(c)){
//                 int b=hold_digit.top();
//                 hold_digit.pop();
//                 int a=hold_digit.top();
//                 hold_digit.pop();
//                 hold_digit.push(cal(a,b,hold_operator.top()));
//                 hold_operator.pop();
//             }
//             hold_operator.push(c);
//         }
//     }
//     while(!hold_operator.empty()){
//         int b=hold_digit.top();
//         hold_digit.pop();
//         int a=hold_digit.top();
//         hold_digit.pop();
//         hold_digit.push(cal(a,b,hold_operator.top()));
//         hold_operator.pop();
//     }
//     return hold_digit.top();
// }
// int main(){
//     string s = "1+2+3+(5*6)";
//     cout << infix_sol(s);
//     return 0;
// }

// E. PreFIX-->PostFIX
// #include <bits/stdc++.h>
// using namespace std;
// string pre_to_post(string &s){
//     stack <string> st;
//     reverse(s.begin(),s.end());
//     for(char &c:s){
//         if(isdigit(c)) st.push(to_string(c-'0'));
//     else{
//         string s1=st.top();
//         st.pop();
//         string s2=st.top();
//         st.pop();
//         string new_exp=s1+s2+c;
//         st.push(new_exp);
//     }
//     }
//     return st.top();
// }
// int main(){
//     string s="*+32-15";
//     cout<<pre_to_post(s);
// return 0;
// }

// F.POST TO PRE
// #include <bits/stdc++.h>
// using namespace std;
// string post_pre(string s){
//     stack <string> st;
//     for(char &c:s){
//         if(isdigit(c)) st.push(to_string(c-'0'));
//         else {
//             string a=st.top();
//             st.pop();
//             string b=st.top();
//             st.pop();
//             string new_exp=c+b+a;
//             st.push(new_exp);
//         }
//     }
//         return st.top();
// }
// int main(){
//     string s="32+15-*";
//     cout<<post_pre(s);
// return 0;
// }

// // G.POSTFIX->INFIX
// #include <bits/stdc++.h>
// using namespace std;
// string post_to_in(string s){
//     stack<string> st;
//     for(char &c:s){
//         if(isdigit(c)) st.push(to_string(c-'0'));
//         else{
//             string a=st.top();
//             st.pop();
//             string b=st.top();
//             st.pop();
//             string new_exp=a+c+b;
//             st.push(new_exp);
//         }
//     }
//     return st.top();
// }
// int main(){
//     string s="15+63+28+^*";
//     string ans=post_to_in(s);
//     reverse(ans.begin(),ans.end());
//     cout<<ans;
// return 0;
// }

// H.INFIX TO POSTFIX
#include <bits/stdc++.h>
using namespace std;
class stacks{
    char arr[INT16_MAX];
    int top;
    int size;
    public:
    stacks(int data){
        top==-1;
        size=data;
    }
    bool is_full(){
        return top==size; 
    }
    bool is_empty(){
        return top==-1;
    }
    void push(char data){
        if(is_full()) return;
        arr[++top]=data;
    }
    void pop(){
        if(is_empty()) return;
        top--;
    }
    char peak(){
        if(is_empty()) return ' ';
        return arr[top];
    }
};
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
bool right_assot(char c){
    return c=='^';
}
void infixToPostfix(string s) {
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); 
        }
        else {
            while (!st.empty() && prec(s[i]) < prec(st.top()) ||
                   !st.empty() && prec(s[i]) == prec(st.top()) &&
                   !right_assot(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    cout << result << endl;
}
int main() {
    string exp = "a+b*c-(a+b)/c";
    infixToPostfix(exp);
    return 0;
}