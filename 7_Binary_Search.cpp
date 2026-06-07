// BINARY SEARCH ALGORITHM

#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int target);
int RecursiveBinarySearch(vector<int> &arr, int target, int start, int end);

int main()
{

    int n;
    cout << "Enter n : ";
    cin >> n;

    int target;
    cout << "Enter Search Number: ";
    cin >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "th index number : ";
        cin >> nums[i];
    }

    int result = RecursiveBinarySearch(nums, target, 0, n-1);
    // int result = BinarySearch(nums, target); // normal binary search

    cout << result;

    return 0;
}

int BinarySearch(vector<int> &arr, int target)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int RecursiveBinarySearch(vector<int> &arr, int target, int start, int end)
{

    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target > arr[mid])
        {
            return RecursiveBinarySearch(arr, target, mid+1, end);
        }
        else if (target < arr[mid])
        {
            return RecursiveBinarySearch(arr, target, start, mid-1);
        }
        else
        {
            return mid;
        }
    }

    return -1;
}