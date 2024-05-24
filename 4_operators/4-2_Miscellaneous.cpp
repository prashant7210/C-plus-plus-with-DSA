#include<iostream>
using namespace std;
int main()
{
    int a = 4;
    char p = 'a';
    cout<<"Size of a : "<<sizeof(a)<<endl;
    cout<<"Size of p : "<<sizeof(p)<<endl;

bool flag;
    a==p? flag=true : flag=false;
    cout<<"flag : "<<flag<<endl;

    cout<<"Address of a : "<<(&a)<<endl;  
    return 0;
}