// Searching a Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

int RecursiveRotatedArraySearch(vector<int> &arr, int target, int start, int end);
int RotatedArraySearch(vector<int> &arr, int target);

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

    int target;
    cout << "Enter target to search: ";
    cin >> target;

    int result = RotatedArraySearch(nums, target);

    if (result != -1)
    {
        cout << "Target found at index: " << result << endl;
    }
    else
    {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}

// Recursive
int RecursiveRotatedArraySearch(vector<int> &arr, int target, int start, int end)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }

    // Left Half Sorted
    if (arr[start] <= arr[mid])
    {
        if (target >= arr[start] && target < arr[mid])
        {
            return RecursiveRotatedArraySearch(arr, target, start, mid - 1);
        }
        else
        {
            return RecursiveRotatedArraySearch(arr, target, mid + 1, end);
        }
    }
    // Right Half Sorted
    else
    {
        if (target > arr[mid] && target <= arr[end])
        {
            return RecursiveRotatedArraySearch(arr, target, mid + 1, end);
        }
        else
        {
            return RecursiveRotatedArraySearch(arr, target, start, mid - 1);
        }
    }
}

// Logical Search
int RotatedArraySearch(vector<int> &arr, int target)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        // Left Half Sorted
        if (arr[start] <= arr[mid])
        {
            if (target >= arr[start] && target < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        // Right Half Sorted
        else
        {
            if (target > arr[mid] && target <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
}