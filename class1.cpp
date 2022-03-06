#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of inputs" << endl;
    cin >> n;

    string name[n];
    int id[n];
    int slary[n];
    cout << "Enter names "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        getline(cin, name[i]);
    }
    cout << "Enter id  " << endl;

    for (int i = 0; i < n; i++)
    {

        cin >> id[i];
    }
    cout << "Enter salary" << endl;

    for (int i = 0; i < n; i++)
    {

        cin >> slary[i];
    }

    return 0;
}