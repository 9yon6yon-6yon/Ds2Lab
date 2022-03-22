
#include <bits/stdc++.h>
using namespace std;
int violations(int data[], int n)
{ // using insertion sort
    int i, key, j;
    int count = 0;
    for (i = 1; i < n; i++)
    {
        key = data[i];
        j = i - 1;

        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
            count++;
        }
        data[j + 1] = key;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    // int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = violations(arr, n);
    cout << "\n"
         << res << endl;
    return 0;
}