#include<bits/stdc++.h>

using namespace std;

void MERGE(int arr[],int lb, int mid,int ub)
{
    ///pointer initialization
    int i = lb;
    int j = mid+1;
    int k = 0;
    ///Space Allocation for new array
    int len = ub-lb+1;
    int B[len];

    ///Both Alive
    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            B[k]=arr[i];
            i++;
        }
        else
        {
            B[k]=arr[j];
            j++;
        }
        k++;
    }
    ///j Dead i alive
    if(j>ub)
    {
        while(i<=mid)
        {
            B[k]=arr[i];
            i++;
            k++;
        }
    }
    ///i Dead j alive
    if(i>mid)
    {
        while(j<=ub)
        {
            B[k]=arr[j];
            j++;
            k++;
        }
    }
    ///Transfer B to arr
    k=0;
    for(int i=lb; i<=ub; i++)
    {
        arr[i]=B[k];
        k++;
    }

}

void MERGESORT(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int mid = (lb+ub)/2;
        MERGESORT(arr,lb,mid);
        MERGESORT(arr,mid+1,ub);
        MERGE(arr,lb,mid,ub);
    }
}

void PRINTARRAY(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<< arr[i] << " ";
    }
}

int main()
{
    int arr [] = {4,2,1,80,9,11,1,4,88};
    int len = sizeof(arr)/sizeof(arr[0]);
    MERGESORT(arr,0,len-1);
    PRINTARRAY(arr,len);
    return 0;
}
