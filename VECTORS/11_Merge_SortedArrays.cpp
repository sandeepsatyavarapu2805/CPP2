// Q88.) Merge Sorted Array in leetcode

#include <iostream>
#include <vector>
using namespace std;

// Merge the second array with (n) valid terms into first array with (m + n) valid terms
void MergeSortedArrays(vector<int> &arr1, int m, vector<int> &arr2, int n);

int main()
{
    int m;
    cout << "Enter number of first array non zero numbers: ";
    cin >> m;

    int n;
    cout << "Enter number of second array non zero numbers: ";
    cin >> n;

    vector<int> nums1(m + n);
    for (int i = 0; i < m + n; i++)
    {
        cout << "Enter the " << i << "th index number: ";
        cin >> nums1[i];
    }

    vector<int> nums2(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << "th index number: ";
        cin >> nums2[i];
    }

    MergeSortedArrays(nums1, m, nums2, n);

    return 0;
}

// Time Complexity : O(m+n) and Space Complexity : O(1)
void MergeSortedArrays(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    int idx = m + n - 1;
    int l1 = m - 1;
    int l2 = n - 1;

    while (l1 >= 0 && l2 >= 0)
    {
        if (arr1[l1] < arr2[l2])
        {
            arr1[idx] = arr2[l2];
            l2--;
        }
        else
        {
            arr1[idx] = arr1[l1];
            l1--;
        }
        idx--;
    }

    while (l2 >= 0)
    {
        arr1[idx] = arr2[l2];
        l2--;
        idx--;
    }

    for (int i : arr1)
    {
        cout << i << " ";
    }
}