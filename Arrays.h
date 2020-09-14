#include<limits>

int sum(int arr[], int n);
void reverse(int arr[], int n);
int search(int arr[], int n, int k);
void sort(int arr[], int n);
int partition (int arr[], int low, int high);
void swap(int *num1, int *num2);
int min(int arr[], int n);
int max(int arr[], int n);


/*
Finding the sum of the elements in the array
Returns the sum of the array
*/
int sum(int arr[], int n)
{
    int array_sum = 0, index;
    for(index=0; index<n ;index++)
        array_sum += arr[index];
    return array_sum;
}

/*
Reverse the array
The Reverse operation happens in place
*/
void reverse(int arr[], int n)
{
    int index, safe;
    for(index=0; index<n/2; index++)
    {
        safe = arr[index];
        arr[index] = arr[n-index-1];
        arr[n-index-1] = safe;
    }
}

/*
searching for an element in the array
Returns the index where the element is found, returns -1 if not found
*/
int search(int arr[], int n, int k)
{
    int first = 0;
    int last = n - 1;
    while( first <= last)
    {
        int mid = (first + last) / 2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]>k)
            last = mid - 1;
        else if(arr[mid]<k)
            first = mid + 1;
    }
    return -1;
}

/*
Swaps two elements
*/
void swap(int *num1, int *num2)
{
    int safe;
    safe = *num1;
    *num1 = *num2;
    *num2 = safe;
}
/*
Helper function for sorting
Partitions according to the pivot element
*/
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/*
Sorts the array
*/
void sorter(int arr[], int low, int high)
{
    if (low < high)
    {
        int pos = partition(arr, low, high);

        sorter(arr, low, pos - 1);
        sorter(arr, pos + 1, high);
    }
}

void sort(int arr[], int n)
{
    sorter(arr, 0, n-1);
}

/*
Returns the minimum element from the array
*/
int min(int arr[], int n)
{
    int minimum = INT_MAX, index;
    for(index=0; index<n; index++)
    {
        if(arr[index]<minimum)
            minimum = arr[index];
    }
    return minimum;
}

/*
Returns the maximum element from the array
*/
int max(int arr[], int n)
{
    int maximum = INT_MIN, index;
    for(index=0; index<n; index++)
    {
        if(arr[index]>maximum)
            maximum = arr[index];
    }
    return maximum;
}



