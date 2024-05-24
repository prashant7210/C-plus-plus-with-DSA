#include <iostream>
using namespace std;
bool f(int num, int *temp){
    if(num>=0 and num<10){
        int lsd = (*temp)%10;
        (*temp)/=10;
        return (num == lsd);
    }
    bool result = (f(num/10 , temp) and (num%10) == ((*temp)%10));
    (*temp) /= 10;
    return result;

}
int main(){
    int n;
    cout<<"n : ";  cin>>n;
    int p = n;
    int *q = &n;
    cout<<f(p,q);
    return 0;
}