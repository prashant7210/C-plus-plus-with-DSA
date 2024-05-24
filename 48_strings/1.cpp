#include <bits/stdc++.h>
using namespace std;
string count_sort(string s)
{
    vector<char> freq(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a'; // Storing frequency of char of s
        freq[index]++;
    }
    int j = 0;
    for (int i = 0; i < 26; i++)
    {
        while (freq[i]--)
        {
            s[j++] = i + 'a';
        }
    }
    return s;
}
int main()
{
    string str;
    cin >> str;
    cout << count_sort(str);
    return 0;
}