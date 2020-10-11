#include <limits>
class ArrayList
{
private:
    int *arr;
    int size;
    int ind;
    int partition(int low, int high);
    int lcmUtility(int num1, int num2);
    int gcdUtility(int num1, int num2);
    void swap(int *num1, int *num2);
    void sorter(int low, int high);
public:
    ArrayList(){
        this->size = 0;
        this->arr = new int[this->size];
        this->ind = 0;
    }
    int sum();
    void add(int data);
    void reverse();
    int search(int k);
    void sort();
    int min();
    int max();
    int frequency(int k);
    int lcmOfArray();
    int gcdOfArray();
    void printArray();
    bool remove(int data_to_remove);

};

/*
Finding the sum of the elements in the array
Returns the sum of the array
*/
int ArrayList::sum()
{
    int array_sum = 0, index;
    for (index = 0; index < this->size; index++)
        array_sum += this->arr[index];
    return array_sum;
}

/*
Reverse the array
The Reverse operation happens in place
*/
void ArrayList::reverse()
{
    int index, safe;
    for (index = 0; index < this->size / 2; index++)
    {
        safe = this->arr[index];
        this->arr[index] = this->arr[(this->size) - index - 1];
        this->arr[(this->size) - index - 1] = safe;
    }
}
/*
Add a new item to the ArrayList
*/
void ArrayList::add(int data)
{
    this->size++;
    this->arr[this->ind++] = data;
}
/*
Prints the array
*/
void ArrayList::printArray()
{
    for(int tempInd = 0; tempInd<this->size ; tempInd++)
        std::cout<<this->arr[tempInd]<<" ";
    std::cout<<std::endl;
}
/*
Removes the element from the ArrayList
*/
bool ArrayList::remove(int data_to_remove)
{
    int tempInd;
    for(tempInd =0; tempInd<this->ind; tempInd++)
    {
        if(this->arr[tempInd] == data_to_remove){
            break;
        }
    }
    if(tempInd < this->size){
        (this->size)--;
        for(int delInd = tempInd; delInd<this->size; delInd++ ){
            this->arr[delInd] = this->arr[delInd+1];
        }
        return true;
    }
    return false;
}
/*
searching for an element in the array
Returns the index where the element is found, returns -1 if not found
*/
int ArrayList::search(int k)
{
    int first = 0;
    int last = this->size - 1;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (arr[mid] == k)
            return mid;
        else if (this->arr[mid] > k)
            last = mid - 1;
        else if (this->arr[mid] < k)
            first = mid + 1;
    }
    return -1;
}

/*
Swaps two elements
*/
void ArrayList::swap(int *num1, int *num2)
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
int ArrayList::partition(int low, int high)
{
    int pivot = this->arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (this->arr[j] <= pivot)
        {
            i++;
            swap(&(this->arr[i]), &(this->arr[j]));
        }
    }
    swap(&(this->arr[i + 1]), &(this->arr[high]));
    return (i + 1);
}

/*
Sorts the array
*/
void ArrayList::sorter(int low, int high)
{
    if (low < high)
    {
        int pos = partition(low, high);

        sorter(low, pos - 1);
        sorter(pos + 1, high);
    }
}

void ArrayList::sort()
{
    sorter(0, this->size - 1);
}

/*
Returns the minimum element from the array
*/
int ArrayList::min()
{
    int minimum = INT_MAX, index;
    for (index = 0; index < this->size; index++)
    {
        if (this->arr[index] < minimum)
            minimum = this->arr[index];
    }
    return minimum;
}

/*
Returns the maximum element from the array
*/
int ArrayList::max()
{
    int maximum = INT_MIN, index;
    for (index = 0; index < this->size; index++)
    {
        if (this->arr[index] > maximum)
            maximum = this->arr[index];
    }
    return maximum;
}

/*
Returns the frequency of an element in an array
*/
int ArrayList::frequency(int k)
{
    int count = 0, index;
    for (index = 0; index < this->size; index++)
    {
        if (this->arr[index] == k)
            count++;
    }
    return count;
}

/*
Returns the HCF of two numbers
*/
int ArrayList::gcdUtility(int num1, int num2)
{
    if (num2 == 0)
        return num1;
    else
        gcdUtility(num2, num1 % num2);
}

/*
Returns the LCM of two numbers
*/
int ArrayList::lcmUtility(int num1, int num2)
{
    return (num1 * num2) / gcdUtility(num1, num2);
}

/*
Returns the HCF of the entire array
*/
int ArrayList::gcdOfArray()
{
    int safe = gcdUtility(this->arr[0], this->arr[1]), index;
    for (index = 2; index < this->size; index++)
    {
        safe = gcdUtility(this->arr[index], safe);
    }
    return safe;
}

/*
Returns the LCM of the entire array
*/
int ArrayList::lcmOfArray()
{
    int safe = lcmUtility(this->arr[0], this->arr[1]), index;
    for (index = 2; index < this->size; index++)
    {
        safe = lcmUtility(this->arr[index], safe);
    }
    return safe;
}



