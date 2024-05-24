#include<iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

vector<int> span(vector<int> &input){
    int n=input.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    // Previous Greater
    reverse(input.begin(),input.end());
    for(int i=1; i<n; i++){
        while(not st.empty() and input[i]>input[st.top()]){
            output[st.top()]=n-i-1;
            st.pop();
        }
        st.push(i);
    }
    reverse(input.begin(),input.end());
    reverse(output.begin(),output.end());
    return output;
}

int main(){
    vector<int> i={100,80,60,70,60,75,85,101};
    vector<int> v=span(i);
    for(int i=0; i<v.size(); i++){
        cout<<i-v[i]<<" ";
    }
    return 0;
}