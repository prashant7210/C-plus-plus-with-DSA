#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &qu){
    stack<int> st;
    while(not qu.empty()){
        st.push(qu.front());
        qu.pop();
    }
    while(not st.empty()){
        qu.push(st.top());
        st.pop();
    }
}

void display(queue<int> qu){
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    display(qu);
    reverseQueue(qu);
    display(qu);
    return 0;
}