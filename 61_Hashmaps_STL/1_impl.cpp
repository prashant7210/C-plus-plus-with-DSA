#include <iostream>
#include <map>
using namespace std;
int main(){
    map<string,int>dir;
    dir["Prashant"]=721065;
    dir["Gojo Satoru"]=995373;
    dir["Itadori"]=742870;
    dir.insert({"Prashant",99999});
    dir.insert(make_pair("Lala",388310));

    for(auto keys:dir){
        cout<<keys.first<<" : ";
        cout<<keys.second<<endl;
    }
    return 0;
}