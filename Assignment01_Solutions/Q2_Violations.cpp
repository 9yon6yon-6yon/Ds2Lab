
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left[], int right[])
{
    int i = 0, j = 0;
    long count = 0;
    int l = sizeof(left) / sizeof(left[0]);
    int r = sizeof(right) / sizeof(right[0]);

    while (i < l || j < r)
    {
        // Loop till all elements in both subarrays are taken
        if (i == l)
        {
            arr[i + j] = right[j];
            j++; // Left subarray was fully traversed
        }
        else if (j == r)
        {
            arr[i + j] = left[i];
            i++; // Right subarray was fully traversed
        }
        else if (left[i] <= right[j])
        {
            arr[i + j] = left[i];
            i++; // Left element is less than Right element
            // Hence, no inversion. No count increment.
        }
        else
        {
            arr[i + j] = right[j];
            count += l - i;
            // Increment count with the number of inversions
            j++;
        }
    }
    cout << count << endl;
}
void MERGESORT(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        MERGESORT(arr, lb, mid);
        MERGESORT(arr, mid + 1, ub);
        merge(arr, lb, ub);
    }
}

int main()
{
    int arr[10];
    int len = sizeof(arr) / sizeof(arr[0]);
    MERGESORT(arr, 0, len - 1);

    return 0;
}