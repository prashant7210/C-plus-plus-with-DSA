#include <iostream>
using namespace std;
int main(){
    int x=20;
    void *ptr = &x;
    cout<<*(int *)ptr;
    return 0;
}