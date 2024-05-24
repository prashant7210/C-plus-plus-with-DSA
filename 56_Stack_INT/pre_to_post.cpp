#include <bits/stdc++.h>
using namespace std;

string preToPost(string &pre){
    reverse(pre.begin(),pre.end());
    stack<string> st;
    for(int i=0; i<pre.size(); i++){
        if(isdigit(pre[i]))  st.push(to_string(pre[i]-'0'));
        else{
            string v1=st.top();
            st.pop();
            string v2=st.top();
            st.pop();
            st.push(v1+v2+pre[i]);
        }
    }
    return st.top();
}

int main(){
    string s="*+32-15";
    cout<<preToPost(s);
    return 0;
}