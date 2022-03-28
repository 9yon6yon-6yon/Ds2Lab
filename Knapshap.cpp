#include <bits/stdc++.h>

using namespace std;
struct Knap
{
    int weight;
    int value;
};
typedef struct Knap knap;
int frac_knap(knap arr[], int n, int knapsack_Weight)
{
    int cost = 0;
    int fraction = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= knapsack_Weight)
        {
            cost += arr[i].value;
            knapsack_Weight -= arr[i].weight;
        }
        else
        {
            fraction = knapsack_Weight / arr[i].weight;
            cost += arr[i].value * fraction;
            break;
        }
    }

    return cost;
}

int main()
{
    int n;
    cin >> n;
    knap array[n];
    int weight;
    cin >> weight;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i].weight >> array[i].value;
    }
    cout << frac_knap(array, n, weight) << endl;

    return 0;
}