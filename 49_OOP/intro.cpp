#include <iostream>
using namespace std;
class fruit{
public:
    string name;
    string color;
    string taste;
    
};

class student{
public:
    string name;
    int roll;
    string branch;
};
int main(){
    fruit pineapple;
    pineapple.name = "Pineapple";
    pineapple.color = "Orange";
    pineapple.taste = "Sweet&Sour";

    fruit *mango = new fruit();
    mango->name = "Mango";
    mango->color = "Yellow";
    mango->taste = "Sweet";

    student Prashant;
    Prashant.name = "Prashant";
    Prashant.roll = 58;
    Prashant.branch = "ETC";

    cout<<pineapple.name<<" "<<pineapple.color<<" "<<pineapple.taste<<endl;
    cout<<Prashant.name<<" "<<Prashant.roll<<" "<<Prashant.branch<<endl;
    cout<<mango->name<<" "<<mango->color<<" "<<mango->taste<<endl;
    return 0;
}