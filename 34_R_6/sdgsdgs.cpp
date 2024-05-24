#include <iostream>
#include <string>
using namespace std;
string f( int N ) {

if (N == 0) return "a";

if (N == 1) return "b";

if (N == 2) return "c";

return f( N - 1 ) + f( N - 2 ) + f( N - 3 );

}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}