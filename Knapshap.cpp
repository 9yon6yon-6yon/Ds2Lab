// #include <bits/stdc++.h>

// using namespace std;
// struct Knap
// {
//     int weight;
//     int value;
// };
// typedef struct Knap knap;
// int frac_knap(knap arr[], int n, int knapsack_Weight)
// {
//     int cost = 0;
//     int fraction = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i].weight <= knapsack_Weight)
//         {
//             cost += arr[i].value;
//             knapsack_Weight -= arr[i].weight;
//         }
//         else
//         {
//             fraction = knapsack_Weight / arr[i].weight;
//             cost += arr[i].value * fraction;
//             break;
//         }
//     }

//     return cost;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     knap array[n];
//     int weight;
//     cin >> weight;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> array[i].weight >> array[i].value;
//     }
//     cout << frac_knap(array, n, weight) << endl;

//     return 0;
// }
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }


void printknapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
					K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	int res = K[n][W];
	cout<< res << endl;
	
	w = W;
	for (i = n; i > 0 && res > 0; i--) {
		
		if (res == K[i - 1][w])
			continue;
		else {

			cout<<" "<<wt[i - 1] ;
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
    cout << endl; 
}
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	
	printknapSack(W, wt, val, n);
	
	return 0;
}