#include <iostream>
using namespace std;
int main(){
    int size , a[size] , key , ans = -1;
    cout<<"Size of array : ";
    cin>>size;
    cout<<"Enter elemets : ";
    for(int i=0; i<size; i++){
        cin>>a[i];
    }

    cout<<"Enter key : ";
    cin>>key;

    for(int i=0; i<size; i++){
        if(a[i]==key){
            ans = i;
            break;
        }
    }
    cout<<ans;

    return 0;
}