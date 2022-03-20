#include <bits/stdc++.h>
// 011201366
// Md Asif Karim Chayon
using namespace std;

int main()
{
    char str[20];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        char newString[m];
        for (int j = 0; j < m; j++)
            cin >> newString[j];

        for (int j = m - 1; j >= 1; j--)
        {
            cout << newString[j] << newString[j - 1] << " ";
        }

        cout << "\n";
    }
}