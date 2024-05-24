#include <iostream>
using namespace std;
class parent{
    public:
    parent(){
        cout<<"Parent class\n";
    }
};
class parent_2{
    public:
    parent_2(){
        cout<<"Parent 2\n";
    }
};
class child: public parent{
    public:
    child(){
        cout<<"Child class\n";   // Single Inherintance
    }
};
class grandchild: public child{
    public:
    grandchild(){
        cout<<"Grand child\n";    // Multilevel Inheritance
    }
};
class child_3: public parent,parent_2{
    public:
    child_3(){
        cout<<"child 3";
    }
};
int main(){
    child c1;
    grandchild c2;
    child_3 c3;
    return 0;
}