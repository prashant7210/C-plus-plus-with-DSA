#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &input, int n){
    stack<int> temp;
    while(not input.empty()){
        temp.push(input.top());
        input.pop();
    }
    
    input.push(n);  // Inserting element

    while(not temp.empty()){
        input.push(temp.top());
        temp.pop();
    }
}

void insertAtBottomRecursively(stack<int> &input, stack<int> &result, int n){
    // base case
    if(input.empty()){
        result.push(n);
        return;
    }
    int curr=input.top();
    input.pop();
    insertAtBottomRecursively(input,result,n);
    result.push(curr);
}

void insertAtk(stack<int> &input, int n, int k){
    stack<int> temp;
    int count=0;
    int size=input.size();
    while(count<size-k){
        count++;
        temp.push(input.top());
        input.pop();
    }
    input.push(n);
    while(not temp.empty()){
        input.push(temp.top());
        temp.pop();
    }
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    insertAtk(st,0,3);
    while(not st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}