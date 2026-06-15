// Bubble Sort - it runs (n-1) times and swaps consecutive elements to meet the requirement of sorting

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void BubbleSort(vector<int> &arr, string order = "ascending");

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
    BubbleSort(nums, "descending");

    return 0;
}

// Time Complexity O(n^2) and if sorted decreases runtime using isswapped edge case
void BubbleSort(vector<int> &arr, string order)
{
    int n = arr.size();

    if (order == "ascending")
    {
        for (int i = 0; i < n - 1; i++)
        {
            bool swapped = false;
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
    }
    else if (order == "descending")
    {
        for (int i = 0; i < n - 1; i++)
        {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] < arr[j + 1])
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
    }
    else
    {
        cout << "Specify Ascending or Descending order only!";
        return;
    }

    cout << "This is the sorted array " << order << " using Optimized Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}