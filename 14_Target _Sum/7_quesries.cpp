#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"n : ";
    cin>>n;
    cout<<"Enter elements : ";
    vector <int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    const int N = 1e5 + 10;
    vector <int> frequency(N,0);
    for(int i=0; i<n; i++){
        frequency[v[i]]++;
    }
    cout<<"Enter number of queries : ";
    int q;
    cin>>q;
    while(q--){
        cout<<"Enter query : ";
        int querey_element;
        cin>>querey_element;
        cout<<"Number of occurence = "<<frequency[querey_element]<<endl;
    }
    return 0;
}