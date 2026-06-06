#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    vector<int> nums1(n);
    vector<int> nums2(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "th index element for first vector";
        cin >> nums1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "th index element for second vector";
        cin >> nums2[i];
    }

    unordered_set<int> copy1;
    unordered_set<int> printed;
    bool found = false;

    for (int x : nums2)
    {
        copy1.insert(x);
    }

    for (int x : nums1)
    {
        if (copy1.count(x) && !printed.count(x))
        {
            cout << x << " ";
            printed.insert(x);
            found = true;
        }
    }

    if (found == false)
    {
        cout << "There is no common element in the two given arrays";
    }

    return 0;
}