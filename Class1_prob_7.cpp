#include <bits/stdc++.h>

using namespace std;

string conv_to_lower(string chk)
{
    for (int i = 0; i < chk.size(); i++)
    {
        char b = chk[i];
        b = tolower(b);
        chk[i] = b;
    }
    return chk;
}
string remove_ws(string chk)
{
    chk.erase(remove_if(chk.begin(), chk.end(), ::isspace), chk.end()); // condition & howmuch

    return chk;
}
int main()
{

    string input, lowercase;
    getline(cin, input);
    lowercase = conv_to_lower(input);
    string finaloutput = remove_ws(lowercase);
    cout << finaloutput << endl;
    return 0;
}