#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int histogram(vector<int> &input){
    int ans=INT16_MIN;
    stack<int> st;
    st.push(0);
    int n=input.size();
    for(int i=1; i<n; i++){
        while(!st.empty() && input[i]<input[st.top()]){
            int el=input[st.top()];
            st.pop();
            int nsi=i;
            int psi=st.empty() ? -1:st.top();
            ans=max(ans,el*(nsi-psi-1));
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> v={2,1,5,6,2,3,0,2,1,5,6,2,3};
    cout<<histogram(v);
    return 0;
}