#include <bits/stdc++.h>
// 011201366
// Md Asif Karim Chayon
using namespace std;
void reverse(string s, int n, int i)
{
    if (n == i)
        return;
    reverse(s, n, i + 1);
    if (n > i)
        cout << s[i] << s[i - 1] << " ";
}
int main()
{
    char str[20];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        // char newString[m];
        //  for (int j = 0; j < m; j++)
        string newString;
        cin >> newString;
        reverse(newString, m, 1);

        // for (int j = m - 1; j >= 1; j--)
        // {
        //     cout << newString[j] << newString[j - 1] << " ";
        // }

        cout << "\n";
    }
}