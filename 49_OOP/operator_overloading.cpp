#include <iostream>
using namespace std;
class complex{
public:
    int real;
    int img;

    complex(int x, int y){
        real=x;
        img=y;
    }

    complex operator+ (complex(&c)){
        complex ans(0,0);
        ans.real = real+c.real;
        ans.img = img+c.img;
        return ans;
    }

    complex operator* (complex &c){
        complex ans(0,0);
        ans.real = real*c.real-img*c.img;
        ans.img = real*c.img+img*c.real;
        return ans;
    }
};
int main(){
    complex c1(1,2), c2(1,3);
    complex c=c1+c2;
    cout<<c.real<<" + i"<<c.img<<endl;
    c=c1*c2;
    cout<<c.real<<" + i("<<c.img<<")";
    return 0;
}