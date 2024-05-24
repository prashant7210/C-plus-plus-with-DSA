#include <bits/stdc++.h>
using namespace std;
string decode(string s){
    string result="";
    for(int i=0; i<s.length(); i++){
        if(s[i]!=']')  result.push_back(s[i]);
        else{
            string str="";
            // ********Extracting str from parent string*******
            while(!str.empty()  && str.back()!='['){
                str.push_back(s[i]);
                result.pop_back();
            }
            // ******Reversing str******
            reverse(str.begin(),str.end());

            //*******Removing last character from result which is [ ******
            result.pop_back();

            // *******Extracting num from result*******
            string num="";
            while(!result.empty() && (result.back()>='0' && result.back()<='9')){
                num.push_back(result.back());
                result.pop_back();
            }

            //Reversing num string
            reverse(num.begin(),num.end());

            //Converting num string to integer
            int num_str = stoi(num);

            //Inserting str num times
            while(num_str--){
                result += str;
            }
        }
    }
    return result;
}
int main(){
    string s;
    cin>>s;
    cout<<decode(s);
    return 0;
}