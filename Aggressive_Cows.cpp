// We need to assign C cows to N stalls such that the min distance between them is largest possible

#include <iostream>
#include <vector>
using namespace std;

bool IsPossible(vector<int> &arr, int cows, int MaxAllowedSpace);
// to find the max valid min distance between the cows
int AssignCows(vector<int> &arr, int cows);

int main()
{

    int n;
    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << "th index number: ";
        cin >> dist[i];
    }

    int cows;
    cout << "Enter the number of cows: ";
    cin >> cows;

    int max_min_dist = AssignCows(dist, cows);

    cout << "The maximum min distance between the " << n << " stalls for " << cows << " is " << max_min_dist;

    return 0;
}

// Time Complexity --> O(n)
bool IsPossible(vector<int> &arr, int cows, int MaxAllowedSpace)
{
    if (cows <= 1)
        return true;

    int needed_cows = 1;
    int lastPosition = arr[0];
    int end = arr.size();

    for (int i = 1; i < end; i++)
    {
        if (arr[i] - lastPosition >= MaxAllowedSpace)
        {
            needed_cows++;
            lastPosition = arr[i];
        }

        if (needed_cows >= cows)
            return true;
    }

    return false;
}

// Time Complexity --> O(logN * n) where N is range(end)
int AssignCows(vector<int> &arr, int cows)
{
    sort(arr.begin(), arr.end());

    int start = 1;
    int end = arr.back() - arr.front();

    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (IsPossible(arr, cows, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}