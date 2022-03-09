#include <bits/stdc++.h>

using namespace std;

int main()
{

    int arr[] = {4, 256, 2, 4, 3, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                arr[j] = -1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
            cout << arr[i] << " ";
    }
    return 0;
}