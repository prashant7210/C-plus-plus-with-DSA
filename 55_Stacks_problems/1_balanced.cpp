#include<iostream>
#include <stack>
using namespace std;

bool isValid(string s){
    stack<int> st;
    for(int i=0; i<s.length(); i++){
        // Opening brackets
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')  st.push(s[i]);
        // Closing brackets
        else{
            if(s[i]==')' && not st.empty() and st.top()=='(')  st.pop();
            else if(s[i]=='}' && not st.empty() and st.top()=='{')  st.pop();
            else if(s[i]==']' && not st.empty() and st.top()=='[')  st.pop();
            else  return false;
        }
    }
    return st.empty();
}

int main(){
    string s = "([{}]{}({}[[()]]))";
    std::cout<<isValid(s);
    return 0;
}