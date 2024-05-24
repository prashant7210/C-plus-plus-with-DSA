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

int postfix(string &str){
    stack<int> st;
    for(int i=0; i<str.length(); i++){
        char curr=str[i];
        if(isdigit(curr))  st.push(curr-'0');
        else{
            int v2=st.top();
            st.pop();
            int v1=st.top();
            st.pop();
            st.push(calc(curr,v1,v2));
        }
    }
    return st.top();
}

int prefix(string &str){
    stack<int> st;
    for(int i=str.length()-1; i>=0; i--){
        char ch=str[i];
        if(isdigit(ch))  st.push(ch-'0');
        else{
            int v2=st.top();
            st.pop();
            int v1=st.top();
            st.pop();
            st.push(calc(ch,v1,v2));
        }
    }
    return st.top();
}

int main(){
    string s="-9+*132";
    // cout<<postfix(s);
    cout<<prefix(s);
    return 0;
}