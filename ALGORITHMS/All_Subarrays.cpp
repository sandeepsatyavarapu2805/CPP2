// to print all subarrays

#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter n : ";
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "th index number : ";
        cin >> array[i];
    }

    for (int st = 0; st < n; st++)
    {
        string print = "";
        for (int end = st; end < n; end++)
        {
            print += to_string(array[end]) + " ";
            cout << print << endl;
        }
    }

    return 0;
}