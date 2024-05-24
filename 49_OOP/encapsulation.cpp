#include <iostream>
using namespace std;
class ABC{
    private:
    int x;

    public:                      // Encapsulation
    void set(int n){
        x = n;
    }
    int get(){
        return x;
    }
};

int main(){
    ABC d1;
    d1.set(4);
    cout<<d1.get()<<endl;
    return 0;
}