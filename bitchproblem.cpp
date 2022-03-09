#include <bits/stdc++.h>
using namespace std;

struct setoftestCases
{
    vector<pair<string, int>> finalOutput;
};

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}
int main()
{

    int testCase;
    cin >> testCase;
    // array of sorted vector
    struct setoftestCases sotc[testCase];

    for (int i = 0; i < testCase; i++)
    {
        int n; // number of problem in each divition
        map<string, int> problemsets;
        cin >> n;
        for (int j = 0; j < 3 * n; j++)
        {
            string code;
            int noOfSubmissions;
            cin >> code;
            cin >> noOfSubmissions;
            if (problemsets.find(code) != problemsets.end())
            {

                problemsets.find(code)->second = problemsets.find(code)->second + noOfSubmissions;
            }
            // find() function
            else
            {
                problemsets.insert({code, noOfSubmissions});
            }
        }
        vector<pair<string, int>> sortedVector;//FOR SORTING THE MAP
        for (auto &i : problemsets)
        {
            sortedVector.push_back(i);
        }
        sort(sortedVector.begin(), sortedVector.end(), compare);
        sotc[i].finalOutput = sortedVector;
    } // output
    for (int i = 0; i < testCase; i++)
    {
        for (auto &j : sotc[i].finalOutput)
        {
            cout << j.second << " ";
        }
        cout << endl;
    }
    return 0;
}