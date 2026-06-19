// This is Dutch National Flag Algorithm (DNF)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void OptimizedSort_0s_1s_2s(vector<int> &arr, string order = "ascending");

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << "th index 0/1/2 only: ";
        cin >> nums[i];
    }

    OptimizedSort_0s_1s_2s(nums);
    OptimizedSort_0s_1s_2s(nums, "descending");

    return 0;
}

// This is most optimized where the array is passed only once with O(n)
void OptimizedSort_0s_1s_2s(vector<int> &arr, string order)
{
    int n = arr.size();

    if (order == "ascending")
    {
        int mid = 0, high = n - 1;
        int low = 0;

        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[high], arr[mid]);
                high--;
            }
        }
    }
    else if (order == "descending")
    {
        int mid = 0, high = n - 1;
        int low = 0;

        while (mid <= high)
        {
            if (arr[mid] == 2)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
    else
    {
        cout << "Specify Ascending or Descending order only!";
        return;
    }

    cout << "The Sorted array in " << order << " is : ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}