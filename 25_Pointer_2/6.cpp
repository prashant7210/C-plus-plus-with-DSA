#include <iostream>
using namespace std;
int main (){
    int arr[5] = {1,2,3,4,5};
    int *ptr = &arr[0];
    cout<<ptr<<" "<<arr<<endl;
    cout<<*ptr<<" "<<*arr<<endl;;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout<<*(arr+i)<<" ";
    }
    return 0;
}