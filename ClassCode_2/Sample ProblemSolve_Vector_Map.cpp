#include<bits/stdc++.h>

using namespace std;

struct setOfVectors
{
    vector<pair<string,int>> problems;
};
bool compare(pair<string,int> a, pair<string,int> b)
{
    return a.second < b.second;
}
int main()
{
    int testCase;
    cin>>testCase;
    struct setOfVectors totalVectors[testCase];
    for(int i=0; i<testCase; i++)
    {
        int N;
        cin>>N;
        map<string,int>problemSets;
        for(int j=0; j<3*N; j++) /// for each testcase
        {
            string code;
            int numberOfSubmissions;
            cin>> code >> numberOfSubmissions;
            if(problemSets.find(code)!= problemSets.end())/// the input code match with any of the existing code
            {
                problemSets.find(code)->second = problemSets.find(code)->second + numberOfSubmissions;
            }
            else problemSets.insert({code, numberOfSubmissions});

        }
        vector<pair<string,int>> sortedVector;
        ///for(auto& i= problemSets.begin(); i!=problemSets.end(); i++)
        for(auto& i: problemSets)
            sortedVector.push_back(i);

        sort(sortedVector.begin(),sortedVector.end(),compare);

        /*for(auto& i: sortedVector)
            cout<<i.second;*/ ///Debugging
        totalVectors[i].problems = sortedVector;
    }

    for(int i=0; i<testCase; i++)
    {
        //vector<pair<string,int>> print = totalVectors[i].problems;
        for(auto& j: totalVectors[i].problems)
        {
            cout<< j.second << " ";
        }
        cout<<endl;
    }

    return 0;
}
