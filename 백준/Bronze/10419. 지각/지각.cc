#include <iostream>
using namespace std;

int main()
{
    int T, d;

    cin >> T;

    while (T--)
    {
        cin >> d;

        int t = 0, s = 0;

        while (1)
        {
            if (d < t + s)
            {
                t--;
                break;
            }

            t++;
            s = t * t;
        }

        cout << t << '\n';
    }

    return 0;
}