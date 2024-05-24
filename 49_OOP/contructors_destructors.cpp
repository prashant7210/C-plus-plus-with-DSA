#include <iostream>
using namespace std;
class rectangle{
public:
    int l,b;

    // Deafult Constructor....
    rectangle(){
        l=0;
        b=0;
    }

    // Prarmeterised constructors....
    rectangle(int x, int y){
        l=x;
        b=y;
    }

    //Copy Constructor.....
    rectangle(rectangle&r){
        l=r.l;
        b=r.b;
    }

    // Destructor.....
    ~rectangle(){
        cout<<"Destructor is called"<<endl;;
    }
};
int main(){
    rectangle *r1 = new rectangle();
    cout<<r1->l<<" "<<r1->b<<endl;
    delete r1;

    rectangle r2(3,4);
    cout<<r2.l<<" "<<r2.b<<endl;

    rectangle r3(r2);
    cout<<r3.l<<" "<<r3.b<<endl;
    return 0;
}