//Libraries
#include<bits/stdc++.h>
#define MAX_N 1001

using namespace std;
typedef long long lld;
typedef unsigned long long llu;
//initializig values
int n, m;
int match_score, mismatch_score, gap_score;
string A, B;
int dp[MAX_N][MAX_N];
inline int needleman_wunsch();
inline pair<string, string> get_optimal_alignment();
//main function
int main()
{
    n = 5, m = 6;
    match_score = 2, mismatch_score = 1, gap_score = 1;
    A = "CATGT";
    B = "ACGCTG";
    printf("%d\n",needleman_wunsch());
    pair<string, string> alignment = get_optimal_alignment();
    printf("%s\n%s\n", alignment.first.c_str(), alignment.second.c_str());
    return 0;
}
//Needleman Wunsch Algorithm
inline int needleman_wunsch()
{
    for (int i=0;i<=n;i++) dp[i][0] = dp[0][i] = -i * gap_score;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            int S = (A[i-1] == B[j-1]) ? match_score : -mismatch_score;
            dp[i][j] = max(dp[i-1][j-1] + S, max(dp[i-1][j] - gap_score, dp[i][j-1] - gap_score));
        }
    }
    return dp[n][m];
}
//Sequence Alignment
inline pair<string, string> get_optimal_alignment()
{
    string retA, retB;
    stack<char> SA, SB;
    int ii = n, jj = m;
    while (ii != 0 || jj != 0)
    {
        if (ii == 0)
        {
            SA.push('-');
            SB.push(B[jj-1]);
            jj--;
        }
        else if (jj == 0)
        {
            SA.push(A[ii-1]);
            SB.push('-');
            ii--;
        }
        else
        {
            int S = (A[ii-1] == B[jj-1]) ? match_score : -mismatch_score;
            if (dp[ii][jj] == dp[ii-1][jj-1] + S)
            {
                SA.push(A[ii-1]);
                SB.push(B[jj-1]);
                ii--; jj--;
            }
            else if (dp[ii-1][jj] > dp[ii][jj-1])
            {
                SA.push(A[ii-1]);
                SB.push('-');
                ii--;
            }
            else
            {
                SA.push('-');
                SB.push(B[jj-1]);
                jj--;
            }
        }
    }
    while (!SA.empty())
    {
        retA += SA.top();
        retB += SB.top();
        SA.pop();
        SB.pop();
    }
    return make_pair(retA, retB);
}
