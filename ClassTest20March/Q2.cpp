#include <bits/stdc++.h>
// 011201366
// Md Asif Karim Chayon
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        map<const int, int> m;
        for (int j = 0; j < N; j++)
        {
            int value;
            cin >> value;
            if (m.find(value) != m.end())
            {
                m.find(value)->second = m.find(value)->second + 1;
            }
            else
                m.insert({value, 1});
        }

        for (auto &i : m)
        {
            if (i.second > (N / 2))
                cout << i.first << endl;   
            else
                cout << 0 << endl;
        }
    }
    return 0;
}