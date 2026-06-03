// KADANE'S ALGORITHM

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

    int currsum = 0, maxsum = 0;

    for (int i = 0; i < n; i++)
    {
        currsum = currsum + nums[i];
        maxsum = max(maxsum, currsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }

    cout << "The Maximum Subarray Sum is : " << maxsum << endl;

    return 0;
}