// Insertion Sort - we will compare the first element of the unsorted space with all the elements in the sorted space and place it

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void InsertionSort(vector<int> &arr, string order = "ascending");

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

    InsertionSort(nums);
    InsertionSort(nums, "descending");

    return 0;
}

// Time Complexity O(n^2)
void InsertionSort(vector<int> &arr, string order)
{
    int n = arr.size();

    if (order == "ascending")
    {
        for (int i = 1; i < n; i++)
        {
            int curr = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > curr)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = curr;
        }
    }
    else if (order == "descending")
    {
        for (int i = 1; i < n; i++)
        {
            int curr = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] < curr)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = curr;
        }
    }
    else
    {
        cout << "Specify Ascending or Descending order only!";
        return;
    }

    cout << "This is the sorted array " << order << " using Insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}