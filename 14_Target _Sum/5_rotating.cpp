#include <iostream>
using namespace std;
int main(){
    int array[] = {1,2,3,4,5} , ans_array[5];
    int n=5 , k;
    cout<<"k : ";
    cin>>k;
    k %= n;     // k can be greater than n
    int j=0;
    // Inserting last k  elements...
    for(int i=n-k; i<n; i++){
        ans_array[j++] = array[i];
    }
    // Inserting first n-k elements...
    for(int i=0; i<n-k; i++){    // OR i <= k
        ans_array[j++] = array[i];
    }
    cout<<"Rotated array = ";
    for(int i=0; i<n; i++){
        cout<<ans_array[i]<<" ";
    }
    return 0;
}