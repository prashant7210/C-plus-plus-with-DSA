#include <iostream>
using namespace std;
class Sum{
    public:
    void add(int x, int y){
        cout<<x+y<<endl;
    }

    void add(int x, int y, int z){
        cout<<x+y+z<<endl;
    }

    void add(float x, float y){
        cout<<x+y<<endl;
    }
};
int main(){
    Sum s;
    s.add(2,3);
    s.add(2,3,4);
    s.add(float(2.3),float(2.75));
    return 0;
}