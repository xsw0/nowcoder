#include <iostream>
#include <map>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;
    map<array<size_t, 26>, size_t> sa;
    while (n--)
    {
        array<size_t, 26> count{};
        for (size_t i = 0; i < m; ++i)
        {
            char c;
            cin >> c;
            ++count[c - 'a'];
        }
        ++sa[count];
    }
    size_t count = 0;
    bool hasOdd = false;
    for (const auto &p : sa)
    {
        auto isPalindromic = [](const array<size_t, 26> &arr) {
            bool b = false;
            for (auto i : arr)
            {
                if (i % 2 != 0)
                {
                    if (b)
                    {
                        return false;
                    }
                    b = true;
                }
            }
            return true;
        };
        if (p.second % 2 == 0)
        {
            count += p.second;
        }
        else
        {
            count += p.second - 1;
            if (!hasOdd && isPalindromic(p.first))
            {
                hasOdd = true;
            }
        }
    }

    cout << (hasOdd ? m * count + m : m * count) << "\n";

    return 0;
}
