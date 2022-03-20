#include <bits/stdc++.h>

using namespace std;
int partition(int arr[], int lb, int ub)
{
    int pivot = lb;
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (arr[start] <= arr[pivot])
            start++;
        while (arr[end] > arr[pivot])
            end--;
        if (start < end)
            swap(arr[start], arr[end]);
    }
    swap(arr[end], arr[pivot]);
    return end;
}
void QuictSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(arr, lb, ub);
        QuictSort(arr, lb, loc - 1);
        QuictSort(arr, loc + 1, ub);
    }
}

int main()
{

    int arr[] = {5, 2, 15, 1, 6, 7, 10, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuictSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}