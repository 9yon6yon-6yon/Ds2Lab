/*Array of size n
for(i=0 to n)
	for(j=i+1 to n)
		if(Array[i]==Array[j])
			Array[j]=-1;
Traverse the Array and Print all element except -1

printf ----------> cout<<
scanf -----------> cin >>

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[]= {4,256,2,4,3,3,5}; ///Array Declaration
    int n = sizeof(arr)/sizeof(arr[0]);///size n
    for(int i=0; i<n; i++) ///for(i=0 to n)
    {
        bool flag = true;
        for(int j=i+1; j<n; j++) ///for(j=i+1 to n)
        {
            if(arr[i]==arr[j])
            {
                flag = false;
                ///arr[j]=-1;
                break;
            }
        }
        if(flag==true) cout<< arr[i] << " ";
    }
    /*
    for(int i=0;i<n;i++) ///    Traverse the Array and Print all element except -1
    {
        if(arr[i]!=-1) cout<< arr[i] << " ";
    }*/
    return 0;
}
