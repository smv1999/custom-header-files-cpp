#include<iostream>
#include "Arrays.h"

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};

    cout<<sum(arr,5)<<endl;

    cout<<search(arr, 5, 10);

    reverse(arr,5);
    cout<<"\n";
    for(int i=0;i<5;i++)
        cout<<arr[i];
    sort(arr, 5);
    cout<<"\n";
    for(int i=0;i<5;i++)
        cout<<arr[i];
    cout<<endl;
    cout<<min(arr, 5);
    cout<<max(arr, 5);

    return 0;
}

