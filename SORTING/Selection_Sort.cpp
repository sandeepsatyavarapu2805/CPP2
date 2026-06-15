// Selection Sort - it runs (n-1) times and swaps the minimum element next to the last sorted place to meet the requirement of sorting

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void SelectionSort(vector<int> &arr, string order = "ascending");

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

    SelectionSort(nums);
    SelectionSort(nums, "descending");

    return 0;
}

// Time Complexity O(n^2) and if sorted decreases runtime using isswapped edge case
void SelectionSort(vector<int> &arr, string order)
{
    int n = arr.size();

    if (order == "ascending")
    {
        for (int i = 0; i < n; i++)
        {
            int targetIndex = i;
            int min = 0;
            for (int j = i; j < n; j++)
            {
                if (arr[j] < arr[targetIndex])
                {
                    min = j;
                }
            }

            if (targetIndex != min)
            {
                swap(arr[min], arr[targetIndex]);
            }
        }
    }
    else if (order == "descending")
    {
        for (int i = 0; i < n; i++)
        {
            int targetIndex = i;
            int max = 0;
            for (int j = i; j < n; j++)
            {
                if (arr[j] > arr[targetIndex])
                {
                    max = j;
                }
            }

            if (targetIndex != max)
            {
                swap(arr[max], arr[targetIndex]);
            }
        }
    }
    else
    {
        cout << "Specify Ascending or Descending order only!";
        return;
    }

    cout << "This is the sorted array " << order << " using Selection Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}