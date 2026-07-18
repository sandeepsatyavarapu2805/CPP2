#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "th index element";
        cin >> nums[i];
    }

    int maxnum = nums[0];
    int minnum = nums[0];

    for (int i = 0; i < n; i++)
    {
        maxnum = max(maxnum, nums[i]);
        minnum = min(minnum, nums[i]);
    }

    cout << "Maximum Element is" << maxnum << endl;
    cout << "Minimum Element is" << minnum << endl;

    return 0;
}