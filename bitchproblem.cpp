#include <bits/stdc++.h>
using namespace std;

struct problemset
{
    int s1;
    int s2;
    int s3;
};

int main()
{

    int n;
    cin >> n;
    struct problemset problms[n];
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        string s[m * 3];
        int sol[m * 3];
        for (int j = 0; j < m * 3; j++)
        {
            cin >> s[j];
            cin >> sol[j];
        }
    }

    return 0;
}