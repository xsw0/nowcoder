#include <iostream>

using namespace std;

size_t fib_except0_mod(size_t index, size_t moder)
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

    size_t T;
    cin >> T;
    while (T--)
    {
        size_t n, m;
        cin >> n >> m;
        auto result = fib_except0_mod(n, m);
        if (result == 0)
        {
            cout << m - 1 << '\n';
        }
        else
        {
            cout << result - 1 << '\n';
        }
    }

    return 0;
}
