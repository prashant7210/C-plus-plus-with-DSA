#include <iostream>
#include <stack>
using namespace std;

stack<int> copyStack(stack<int> &input){
    stack<int> temp;
    while(not input.empty()){
        temp.push(input.top());
        input.pop();
    }
    stack<int> result;
    while(not temp.empty()){
        result.push(temp.top());
        temp.pop();
    }
    return result;
}

void copyStackUsingRecursion(stack<int> &input, stack<int> &result){
    // base case
    if(input.empty()) return;

    // recursive case and self work;
    int curr=input.top();
    input.pop();
    copyStackUsingRecursion(input,result);
    result.push(curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    stack<int> result1;
    copyStackUsingRecursion(st,result1);

    while(not result1.empty()){
        cout<<result1.top()<<" ";
        result1.pop();
    }
    return 0;
}