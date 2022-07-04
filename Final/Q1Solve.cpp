#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

int ct[1000],Vi[1000],N,M,Pi[1000][1000];

int sol (int idx,int val)
{
    if(idx==N)
    {
        if(val>=M)
            return 0;
        else
            return INF;
    }
    if(Pi[idx][val] !=-1)
        return Pi[idx][val];
    int v1 = sol(idx+1,val);
    int v2 = sol(idx+1,val+Vi[idx]+1)+ct[idx];
    int ans = min(v1, v2);
    Pi[idx][val] = ans;
    return Pi[idx][val];
}





int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin >> N ;
        M=N;
        for(int i = 0; i < N; i++)
        {
            cin >> Vi[i] >> ct[i];
        }
        memset(Pi, -1, sizeof Pi);
        int ans = sol(0, 0);
        if(ans != INF)
            cout <<sol(0,0)<< endl;
        else
            cout << "NOT POSSIBLE" << endl;
    }
    return 0;
}
