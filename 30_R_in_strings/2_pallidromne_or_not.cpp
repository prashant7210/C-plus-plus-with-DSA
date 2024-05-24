#include <iostream>
using namespace std;
int rev(int n, int temp){
    if(n==0)  return temp;
    temp = (temp*10)+(n%10);
    return rev(n/10, temp);
}
int main(){
   int n;
   cout<<"Enter a number : ";
   cin>>n;
   if(n==rev(n,0))  cout<<n<<" is pallindrome";
   else  cout<<n<<" is not pallindrome";
   return 0;
}