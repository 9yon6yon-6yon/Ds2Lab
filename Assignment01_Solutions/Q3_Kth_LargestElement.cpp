#include <bits/stdc++.h>

using namespace std;
int kthElement(int arr[], int n, int k)
{
    sort(arr, arr + n, greater<int>());
    return arr[k-1];
}

int main()
{

    cout << "Enter no of inputs : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter kth value : ";
    int k;
    cin >> k;
    int res = kthElement(arr, n, k);
    cout << res << endl;

    return 0;
}