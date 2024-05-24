#include <iostream>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    int *ptrx = &x , *ptry = &y;
    int result;
    int *result_ptr = &result;
    *result_ptr = *ptrx + *ptry;
    cout<<"x + y = "<<result;
    return 0;
}