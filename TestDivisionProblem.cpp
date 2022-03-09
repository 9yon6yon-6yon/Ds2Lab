/*PROBLEM SAMPLE: NUMBER OF CORRECT SUBMISSION OF CODE

UIU Intra Department Programming challenges have three divisions. In one challenge, there are N problems in each division, but some problems may be shared among multiple divisions. Each problem is uniquely identified by a code — a string containing only uppercase English letters. Each participant can only submit in one of the divisions.

You want to find the number of correct solutions, in total among all three divisions, for each problem. Given a list of N problem codes with the numbers of correct solutions for each problem in each division, find the total number of correct solutions for each problem and sort them in non-decreasing order.
Input
    • The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
        ◦ The first line of each test case contains a single integer N.
        ◦ N lines follow. For each valid i, the i-th of these lines contains a string S3,i followed by a space and an integer C3,i — the problem code and the number of correct solutions on the ii-th problem in the third division.
        ◦ N more lines follow. For each valid i, the i-th of these lines contains a string S2,i followed by a space and an integer C2,i — the problem code and the number of correct solutions on the i-th problem in the second division.
        ◦ Finally, N more lines follow. For each valid i, the i-th of these lines contains a string S1,I followed by a space and an integer C1,i — the problem code and the number of correct solutions on the i-th problem in the first division.
Output
For each test case, let P be the number of distinct problems; you should print P space-separated integers — the number of solutions for each of these problems, sorted in non-decreasing order.

Sample Input            Sample Output
3                       6
1                       1 1 2 2
A 1                     300
A 2
A 3
2
AA 1
AB 1
AB 1
AC 1
AC 1
AD 1
1
Z 100
Z 100
Z 100

Explanation
Example case 1: There is only 11 problem in each division and no problems are shared among divisions, so the total number of distinct problems is 33 and the numbers of solutions are: 11 for "A", 22 for "B", 33 for "C".
Example case 2: There are 22 problems in each division and each pair of consecutive divisions shares 11 problem, so the total number of distinct problems is 44 and the numbers of solutions are: 11 for "AA", 22 for "AB", 22 for "AC", 11 for "AD". We need to sort them in non-decreasing order, so the final answer is (1,1,2,2)(1,1,2,2).
Example case 3: There is only 11 problem "Z" in the entire contest, shared among all divisions, and the number of solutions for it is 300300.

Constraints
    • 1≤T≤101≤T≤10
    • 1≤N≤2⋅1041≤N≤2⋅104
    • 1≤|S1,i|,|S2,i|,|S3,i|≤81≤|S1,i|,|S2,i|,|S3,i|≤8 for each valid ii
    • S1,i,S2,i,S3,iS1,i,S2,i,S3,i contain only uppercase English letters for each valid ii
    • 1≤C1,i,C2,i,C3,i≤5⋅1081≤C1,i,C2,i,C3,i≤5⋅108 for each valid ii
    • the problem codes in each division are pairwise distinct, but some problem codes may appear in multiple divisions
    • the sum of NN over all test cases does not exceed 105105


Sample Input            Sample Output
2                       1 2 3 4 4 6
3                       2 4
A 1
BB 2
BC 2
AA 4
AS 4
BB 2
EE 2
AS 2
BC 1
1
AEW 2
ADF 2
AEW 2
*/

#include <bits/stdc++.h>
using namespace std;

struct setoftestCases
{
    vector<pair<string, int>> finalOutput; // vector to save outputs in sorted  order
};

bool compare(pair<string, int> a, pair<string, int> b) // function to sort calculaed values in non-decrising order
{
    return a.second < b.second;
}
int main()
{

    int testCase;
    cin >> testCase;                      // takes input of number of test cases
    struct setoftestCases sotc[testCase]; // structure declared for sorted outputs

    for (int i = 0; i < testCase; i++) // for loop to take inputs n times / test cases / divition
    {
        int n;                          // number of problem in each divition
        map<string, int> problemsets;   // creates a map . map has two types of data (key,value). Here String is key and int is value
        cin >> n;                       // takes no of divition
        for (int j = 0; j < 3 * n; j++) // if n = 1 then it has 3 divition
        {
            string code;
            int noOfSubmissions;
            cin >> code;
            cin >> noOfSubmissions;
            if (problemsets.find(code) != problemsets.end())
            {

                problemsets.find(code)->second = problemsets.find(code)->second + noOfSubmissions;
            }
            else
            {
                problemsets.insert({code, noOfSubmissions});
            }
        }
        vector<pair<string, int>> sortedVector; // FOR SORTING THE MAP. Vector is a like an array with one data type
        for (auto &i : problemsets)
        {
            sortedVector.push_back(i);//push_back() method is pushing data to vector. It's like inserting data.
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