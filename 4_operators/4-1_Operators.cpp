#include<iostream>
using namespace std;
int main()
{
    int num1 = 6 , num2 = 3;

    cout<<"Arithematic Operators"<<endl;
    cout<<"sum of num 1 and num2 : "<<(num1+num2)<<endl;
    cout<<"subtrcation of num 1 and num2 : "<<(num1-num2)<<endl;
    cout<<"product of num 1 and num2 : "<<(num1*num2)<<endl;
    cout<<"division of num 1 and num2 : "<<(num1/num2)<<endl;
    cout<<"modulus of num 1 and num2 : "<<(num1%num2)<<endl;
    cout<<"increment of num1 : "<<(num1++)<<endl;
    cout<<"decrement of num1 : "<<(num1--)<<endl;

    cout<<"\nRelational Operators"<<endl;
    cout<<(num1==num2)<<endl;
    cout<<(num1!=num2)<<endl;
    cout<<(num1<num2)<<endl;
    cout<<(num1>num2)<<endl;
    cout<<(num1>=num2)<<endl;
    cout<<(num1<=num2)<<endl;

    cout<<"\nLogical OPertaors"<<endl;
    bool exp1 = true , exp2 = false;
    cout<<"\n"<<(exp1&&exp2)<<endl;
    cout<<(exp1||exp2)<<endl;
    cout<<(!exp1)<<endl;
    cout<<(!exp2)<<endl;

    cout<<"\nAssignment Opertaors"<<endl;
    cout<<"\nnum1+=3 : "<<(num1+=3)<<endl;
    cout<<"num2+=2 : "<<(num2-=2)<<endl;

num1 = 6;
    cout<<"\nBitwise Operators"<<endl;
    cout<<"Complement : "<<(~num1)<<endl;                 // NOt Correct!!!!           
    cout<<"Left shift : "<<(num1<<1)<<endl;
    cout<<"Right shift : "<<(num1>>1)<<endl;
    return 0;
}