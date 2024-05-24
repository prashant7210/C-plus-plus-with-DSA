#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NextGreaterElement(vector<int> &input){
    int n=input.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() and input[i]>input[st.top()]){
            output[st.top()]=input[i];
            st.pop();
        }
        st.push(i);
    }
    while(not st.empty()){
        output[st.top()]=-1; // Not mandatory (Refer to line 8 why?)
        st.pop();
    }
    return output;
}

using namespace std;
int main(){
    vector<int> v={4,6,3,1,0,9,5,6,7,3};
    v=NextGreaterElement(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}