// Q238.) Product of Array Except Self in leetcode

#include <iostream>
#include <vector>
using namespace std;

// We have to solve the question without using division operation
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 1);

    for (int i = 1; i < n; i++)
    {
        result[i] = result[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        result[i] *= result[i - 1] * nums[i];
    }

    return result;
}

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

    vector<int> product_array = productExceptSelf(nums);
    for (int i = 0; i < n; i++)
    {
        cout << product_array[i] << ' ';
    }

    return 0;
}