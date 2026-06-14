// Bubble Sort

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void BubbleSort(vector<int> &arr);
void OptimizedBubbleSort(vector<int> &arr);

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << "th index number: ";
        cin >> nums[i];
    }

    BubbleSort(nums);
    OptimizedBubbleSort(nums);

    return 0;
}

// Time Complexity O(n^2) and if already sorted the loop runtime is approx same
void BubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "This is the sorted array using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

// Time Complexity O(n^2) and if already sorted decreases the loop runtime
void OptimizedBubbleSort(vector<int> &arr)
{
    int n = arr.size();
    bool swapped = false;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        // array is already sorted
        if (!swapped)
        {
            break;
        }
    }

    cout << "This is the sorted array using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}