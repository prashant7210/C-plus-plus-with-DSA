#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> score(int n, int p, int q){
    unordered_set<int> s;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            int corr=i;
            int incorr=j;
            int unatt=n-i-j;
            if(unatt>=0){
                int score=corr*p+incorr*q;
                s.insert(score);
            }
            else  break;
        }
    }
    return s;
}

int main(){
    unordered_set<int> s=score(2,1,-1);
    cout<<s.size()<<endl;
    for(auto val:s){
        cout<<val<<" ";
    }
    return 0;
}