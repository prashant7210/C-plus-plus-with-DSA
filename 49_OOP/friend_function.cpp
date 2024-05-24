#include <iostream>
using namespace std;
class A{
    private:
    int x;
    friend void print(A &obj);
    public:
    A(int a){
        x=a;
    }
};
void print(A &obj){
    cout<<obj.x;
}
int main(){
    A obj(5);
    print(obj);
    return 0;
}