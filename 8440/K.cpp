#include <iostream>

using namespace std;

const size_t moder = 1e9 + 7;

size_t fib_mod(size_t index, size_t moder)
{
    size_t prepre = 0, pre = 1;
    for (size_t i = 1; i < index; i++)
    {
        size_t sum = (prepre % moder + pre % moder) % moder;
        prepre = pre;
        pre = sum;
    }
    return pre;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, x;
    cin >> n >> x;

    size_t count;
    size_t bin = 0;
    while (n--)
    {
        size_t a;
        cin >> a;
        bin ^= a;
        if (bin == x)
        {
            ++count;
            bin = 0;
        }
    }

    if (bin != 0)
    {
        cout << "0\n";
    }
    else
    {
        cout << fib_mod(count, moder) << "\n";
    }

    return 0;
}
