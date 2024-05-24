#include <iostream>
#include <vector>
using namespace std;
void ins_sort(vector<int>&v){
    for(int i=1; i<v.size(); i++){
        int current=v[i];
        int j=i-1;
        // Correct position for for current element 
        while(j>=0 && v[j]>current){
            v[j+1] = v[j];
            j--;
        }
        // Insert current element
        v[j+1] = current;
    }
}
int main(){
    vector<int> v = {8,9,7,5,6,2,4,3,1};
    ins_sort(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}