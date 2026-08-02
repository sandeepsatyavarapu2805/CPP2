// Q540.) Single Element in a Sorted Array where any element repeats only twice in leetcode

#include <iostream>
#include <vector>
using namespace std;

int SingleElement(vector<int> &arr);

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

    cout << "Single Element present in the Sorted Array with repetition of any element twice is : " << SingleElement(nums);

    return 0;
}

int SingleElement(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int st = 1;
    int end = n - 2;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
            (mid % 2 != 0 && arr[mid] == arr[mid - 1]))
        {
            st = mid + 1; // Single element is in the right half
        }
        else
        {
            end = mid - 1; // Single element is in the left half
        }
    }

    return -1;
}