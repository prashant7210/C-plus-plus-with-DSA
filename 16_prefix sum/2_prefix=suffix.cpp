#include <iostream>
#include <vector>
using namespace std;
void p_s(vector <int> &v){
    int total_sum = 0 , prefix_sum = 0 , suffix_sum , c;
    for(int i=0; i<v.size(); i++){
        total_sum += v[i];
    }
    for(int i=0; i<v.size(); i++){
        prefix_sum += v[i];
        suffix_sum = total_sum - prefix_sum;

        if(prefix_sum == suffix_sum){
            cout<<"Prefix_sum = Suffix_sum at "<<i<<endl;
            c++;
        }
    }
    if(c=0){
        cout<<"Prefix sum != Suffix sum";
    }
}
int main(){
    vector <int> v;
    int n;
    cout<<"n : ";  cin>>n;
    cout<<"Enter elemets : ";
    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    p_s(v);
    return 0;
}