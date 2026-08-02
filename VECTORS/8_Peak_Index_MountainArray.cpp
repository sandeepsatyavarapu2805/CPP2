// Q852.) Peak Index in Mountain Array in leetcode

#include <iostream>
#include <vector>
using namespace std;

int PeakIndex(vector<int> &arr);

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

    int peak = PeakIndex(nums);

    cout << "Peak Index in the Mountain Array is " << peak << " and the element is " << nums[peak];

    return 0;
}

int PeakIndex(vector<int> &arr)
{
    int st = 0;
    int end = arr.size() - 1;

    while (st < end)
    {
        int mid = st + (end - st) / 2;

        // Peak is right of mid
        if (arr[mid] < arr[mid + 1])
        {
            st = mid + 1;
        }
        // Peak is left of mid
        else
        {
            end = mid;
        }
    }

    return st;
}