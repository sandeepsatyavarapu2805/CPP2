// Q50.) POW(x,n) in leetcode

#include <iostream>
using namespace std;

int main()
{

    double x;
    int n;
    cout << "Enter x and n : ";
    cin >> x >> n;

    double ans = 1;
    int copyn = n;
    double copyx = x;

    if (n > 0)
    {
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans *= x;
            }
            x *= x;
            n /= 2;
        }
    }
    else
    {
        x = 1 / x;
        n = -n;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans *= x;
            }
            x *= x;
            n /= 2;
        }
    }

    cout << "The value of the exponent of " << copyx << " raised to the power of " << copyn << " is " << ans;

    return 0;
}