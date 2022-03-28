
#include <bits/stdc++.h>
using namespace std;
// int violations(int data[], int n)
// { // using insertion sort
//     int i, key, j;
//     int count = 0;
//     for (i = 1; i < n; i++)
//     {
//         key = data[i];
//         j = i - 1;

//         while (j >= 0 && data[j] > key)
//         {
//             j = j - 1;
//             count++;
//         }
//     }
//     return count;
// }
// here time complexity Big O (n^2)

int MERGE(int arr[], int lb, int mid, int ub)
{
    int count = 0;

    int i = lb;
    int j = mid;
    int k = 0;
    int len = ub - lb + 1;
    int B[len];

    while (i <= mid && j <= ub)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++;
        }
        else
        {
            B[k] = arr[j];
            j++;
            count = count + (mid - i);
        }
        k++;
    }
    if (j > ub)
    {
        while (i <= mid)
        {
            B[k] = arr[i];
            i++;
            k++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            B[k] = arr[j];
            j++;
            k++;
        }
    }
    k = 0;
    for (int i = lb; i <= ub; i++)
    {
        arr[i] = B[k];
        k++;
    }
    return count;
}

int _MERGESORT(int arr[], int lb, int ub)
{
    int mid, count = 0;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        count += _MERGESORT(arr, lb, mid);
        count += _MERGESORT(arr, mid + 1, ub);

        count += MERGE(arr, lb, mid + 1, ub);
    }

    return count;
}
// time complexity Big O (nlogn)
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = _MERGESORT(arr, 0, n - 1);
    cout << "\n"
         << res << endl;
    return 0;
}