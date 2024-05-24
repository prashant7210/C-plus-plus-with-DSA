#include <bits/stdc++.h>
using namespace std;

int calc(char op, int v1, int v2){
    switch(op){
        case '^': return pow(v1,v2);
        case '%': return v1%v2;
        case '*': return v1*v2;
        case '/': return v1/v2;
        case '+': return v1+v2;
        case '-': return v1-v2;
    }
}

int precidence(char ch){
    if(ch=='^')  return 3;
    else if(ch=='*' || ch=='/')  return 2;
    else if(ch=='+' || ch=='-')  return 1;
    else return -1;
}

int infixEval(string &str){
    stack<int> st1;
    stack<char> st2;
    for(int i=0; i<str.length(); i++){
        char ch=str[i];
        if(isdigit(ch))  st1.push(ch-'0');
        else if(ch='(')  st2.push(ch);
        else if(ch=')'){
            while(not st2.empty() and st2.top()!='('){
                // Extracting opearor
                char op=st2.top();
                st2.pop();

                // Extracting numbers
                int v2=st1.top();
                st1.pop();
                int v1=st1.top();
                st1.pop();

                // Evaluating
                st1.push(calc(op,v1,v2));
            }
            if(!st2.empty())  st2.pop();
        }
        else{
            while(not st2.empty() && precidence(st2.top())>=precidence(str[i])){
                // Evaluate 
                char op=st2.top();
                st2.pop();

                int v2=st1.top();
                st1.pop();
                int v1=st1.top();
                st1.pop();

                st1.push(calc(op,v1,v2));
            }
            st2.push(ch);
        }
    }
    while(not st2.empty() and not st1.empty()){
        char op=st2.top();
        st2.pop();

        int v2=st1.top();
        st1.pop();
        int v1=st1.top();
        st1.pop();
        st1.push(calc(op,v1,v2));
    }
    return st1.top();
}

int main(){
    string s="1+(2*(3-1))+2";
    cout<<infixEval(s);
    return 0;
}