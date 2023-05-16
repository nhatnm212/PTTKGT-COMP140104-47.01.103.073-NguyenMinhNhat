#include <iostream>
#include <vector>
#include <cstdlib> // for rand()
#include <ctime>   // for time()

using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j=low; j<=high-1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

int randomizedPartition(vector<int>& arr, int low, int high)
{
    srand(time(NULL)); // initialize random seed
    int random = low + rand() % (high - low); // generate a random number between low and high
    swap(arr[random], arr[high]); // move the randomly selected pivot element to the end
    return partition(arr, low, high);
}

void quicksort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int p = randomizedPartition(arr, low, high);
        quicksort(arr, low, p-1);
        quicksort(arr, p+1, high);
    }
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();
    quicksort(arr, 0, n-1);

    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

