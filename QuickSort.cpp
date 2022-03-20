#include <bits/stdc++.h>

using namespace std;
void quickSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {2, 5, 7, 1, 3, 10, 6, 9, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}