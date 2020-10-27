#include <iostream>

using namespace std;

size_t gcd(size_t a, size_t b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, q;
    cin >> n >> q;
    while (q--)
    {
        size_t x, y;
        cin >> x >> y;
        if (x == y)
        {
            cout << "0\n";
        }
        else if (gcd(x, y) == 1)
        {
            cout << "1\n";
        }
        else
        {
            cout << "2\n";
        }
    }

    return 0;
}
