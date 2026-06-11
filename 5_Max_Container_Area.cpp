// Q11.) Maximum Container Area in leetcode

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &height);

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << "th index height: ";
        cin >> heights[i];
    }

    cout << "The maximum area possible is " << maxArea(heights) << endl;
    return 0;
}

int maxArea(vector<int> &height)
{
    int max_area = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right)
    {
        int width = right - left;
        int water_level = min(height[left], height[right]);
        int current_area = water_level * width;
        max_area = max(max_area, current_area);

        height[left] < height[right] ? left++ : right--;
    }

    return max_area;
}