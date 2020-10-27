#include <iostream>

using namespace std;

const size_t mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, x;
    cin >> n >> x;

    size_t oneSum = 0;
    size_t evenSum = 0;
    size_t binary = 0;
    while (n--)
    {
        size_t a;
        cin >> a;
        binary ^= a;
        if (binary == x)
        {
            oneSum += evenSum + 1;
            oneSum %= mod;
        }
        else if (binary == 0)
        {
            evenSum += oneSum;
            evenSum %= mod;
        }
    }

    if (binary == x)
    {
        cout << (evenSum + 1) % mod << "\n";
    }
    else if (binary == 0)
    {
        cout << oneSum << "\n";
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}
