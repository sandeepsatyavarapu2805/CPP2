// Q31.) Next Permutation in leetcode
// Lexicographic Permutation: 123 -> 132 -> 213 -> 231 -> 312 -> 321

#include <iostream>
#include <vector>
using namespace std;

// Lexicographically next permutation
void NextPermutation(vector<int> &nums);

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

    NextPermutation(nums);

    for (int i : nums)
    {
        cout << i << " ";
    }

    return 0;
}

// Time Complexity : O(n) and Space Complexity : O(1)
void NextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int pivot_index = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot_index = i;
            break;
        }
    }

    if (pivot_index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > pivot_index; i--)
    {
        if (nums[i] > nums[pivot_index])
        {
            swap(nums[pivot_index], nums[i]);
            break;
        }
    }

    reverse(nums.begin() + pivot_index + 1, nums.end());
}