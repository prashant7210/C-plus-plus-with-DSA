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

void reverseStackRecursively(stack<int> &st){
    if(st.empty())  return;
    int curr=st.top();
    st.pop();                        // Time Complexity = O(N^2)
    reverseStackRecursively(st);
    insertAtBottom(st,curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStackRecursively(st);
    while(not st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}