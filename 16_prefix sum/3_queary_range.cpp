#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"n : ";   cin>>n;
    vector <int> v(n+1,0);
    cout<<"Enter elements : ";
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    for(int i=1; i<=n; i++){
        v[i] += v[i-1];
    }
    int q , l , r , ans;
    cout<<"Query : ";   cin>>q;
    while(q--){
        cout<<"Lower limit : ";   cin>>l;
        cout<<"Upper limit : ";   cin>>r;
        ans = v[r] - v[l-1];   // ans = prefix(r) - prefix(l-1)
        cout<<"Ans = "<<ans<<endl;
    }
    return 0;
}