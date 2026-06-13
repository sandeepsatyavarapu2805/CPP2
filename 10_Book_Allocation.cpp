// Q410.) Split Array Largest Sum problem is similar to this logic in leetcode
// Book Allocation of N books to M students where every stdudent gets atleast 1 book in contiguoug order in leetcode

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool IsValid(vector<int> &arr, int maxPagesAllowed, int original_students);
// Allocate books such that the student with max pages in all poosible allocations where it will min
int AllocateBooks(vector<int> &arr, int students);

int main()
{
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    int m;
    cout << "Enter number of students: ";
    cin >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << "th index number: ";
        cin >> nums[i];
    }

    int min_max_allocatedpages = AllocateBooks(nums, m);

    cout << "The minimum of the max pages amount for valid allocation of books : " << min_max_allocatedpages;

    return 0;
}

// Time Complexity --> O(n)
bool IsValid(vector<int> &arr, int maxPagesAllowed, int original_students)
{
    int student = 1;
    int currentpages = 0;

    for (int page : arr)
    {
        if (page >= maxPagesAllowed)
        {
            return false;
        }

        if (currentpages + page <= maxPagesAllowed)
        {
            currentpages += page;
        }
        else
        {
            student++;
            currentpages = page;
        }
    }

    if (student > original_students)
        return false;

    return student;
}

// Time Complexity --> O(logN * n) where N is range(end)
int AllocateBooks(vector<int> &arr, int students)
{
    int books = arr.size();
    if (students > books)
        return -1;

    int start = 0;
    int end = reduce(arr.begin(), arr.end(), 0);

    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (IsValid(arr, mid, students))
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