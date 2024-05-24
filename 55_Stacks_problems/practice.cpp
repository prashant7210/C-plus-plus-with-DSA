#include<iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreater(vector<int> &input){
    int n=input.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() && input[i]>input[st.top()]){
            output[st.top()]=input[i];
            st.pop();
        }
        st.push(i);
    }
    return output;
}

vector<int> nextSmaller(vector<int> &input){
    int n=input.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() && input[i]<input[st.top()]){
            output[st.top()]=input[i];
            st.pop();
        }
        st.push(i);
    }
    return output;
}

vector<int> previousSmaller(vector<int> &input){
    int n=input.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    reverse(input.begin(),input.end());
    for(int i=1; i<n; i++){
        while(not st.empty() and input[i]<input[st.top()]){
            output[st.top()]=input[i];
            st.pop();
        }
        st.push(i);
    }
    reverse(input.begin(),input.end());
    reverse(output.begin(),output.end());
    return output;
}

vector<int> previousGreater(vector<int> &input){
    int n=input.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    reverse(input.begin(),input.end());
    for(int i=1; i<n; i++){
        while(not st.empty() and input[i]>input[st.top()]){
            output[st.top()]=input[i];
            st.pop();
        }
        st.push(i);
    }
    reverse(input.begin(),input.end());
    reverse(output.begin(),output.end());
    return output;
}

vector<int> span(vector<int> &input){
    int n=input.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    reverse(input.begin(),input.end());
    for(int i=1; i<n; i++){
        while(!st.empty() && input[i]>input[st.top()]){
            output[st.top()]=n-i-1;
            st.pop();
        }
        st.push(i);
    }
    reverse(output.begin(),output.end());
    reverse(input.begin(),input.end());
    return output;
}

int main(){
    vector<int> v={2,4,3,1,6,0};
    v=span(v);
    for(int i=0; i<v.size(); i++){
        cout<<i-v[i]<<" ";
    }
    return 0;
}