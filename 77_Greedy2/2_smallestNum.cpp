#include <iostream>
#include <vector>
using namespace std;

vector<int> smallestNumber(int s, int d){
    vector<int> v(d,0);
    if(9*d<s)  return v;
    if(s<10){
        v[d-1]=s-1;
        v[0]=1;
        return v;
    }
    int i=0;
    for(i=d-1; i>=0; i--){
        v[i]=9;
        s-=9;
        if(s<=9){
            i--;
            break;
        }
    }
    if(i==0)  v[0]=s;
    else{
        v[0]=1;
        v[i]=s-1;
    } 
    return v;
}

int main(){
    vector<int> v=smallestNumber(35,6);
    for(int i=0; i<v.size(); i++)   cout<<v[i];
    return 0;
}