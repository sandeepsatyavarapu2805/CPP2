// BINARY SEARCH ALGORITHM

#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int target);

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

    int result = BinarySearch(nums, target);
    cout << result;

    return 0;
}

int BinarySearch(vector<int> &arr, int target)
{
    int start = 0, end = arr.size();

    for (int i = start; i < end; i++)
    {
        int mid = (start + end) / 2;
        if (target > arr[mid])
        {
            start = mid;
        }
        else if (target == arr[mid])
        {
            return mid;
        }
        else
        {
            end = mid;
        }
    }

    return target;
}