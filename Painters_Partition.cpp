// Given N length array with unit lenght number for each plank also M painters which take 1 unit time - 1 unit of plank

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool IsValid(vector<int> &arr, int maxAllowed_time, int painters);
// Minimum time taken by the painter to paint the boards in continuous manner i.e when 2nd painter starts 1st painter is out of work
int MinimumPainting_Time(vector<int> &arr, int painters);

int main()
{
    int n;
    cout << "Enter number of planks: ";
    cin >> n;

    vector<int> lenghts(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << "th index number: ";
        cin >> lenghts[i];
    }

    int painters;
    cout << "Enter number of painters: ";
    cin >> painters;

    int min_time = MinimumPainting_Time(lenghts, painters);

    cout << "The minimum time taken by " << painters << " painters to paint " << n << " boards is " << min_time;

    return 0;
}

// Time Complexity --> O(n)
bool IsValid(vector<int> &arr, int maxAllowed_time, int painters)
{
    int needed_painters = 1;
    int current_time = 0;

    for (int time : arr)
    {
        if (time > maxAllowed_time)
        {
            return false;
        }
        if (current_time + time <= maxAllowed_time)
        {
            current_time += time;
        }
        else
        {
            needed_painters++;
            current_time = time;
        }
    }

    return needed_painters <= painters;
}

// Time Complexity --> O(logN * n) where N is range(end)
int MinimumPainting_Time(vector<int> &arr, int painters)
{
    int boards = arr.size();
    int start = 0;
    int end = reduce(arr.begin(), arr.end(), 0);

    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (IsValid(arr, mid, painters))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}