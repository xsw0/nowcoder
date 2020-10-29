#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

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
        int64_t p;
        cin >> n >> m >> p;
        vector<int64_t> A;
        while (n--)
        {
            int64_t a;
            cin >> a;
            A.push_back(a);
        }
        while (m--)
        {
            size_t opt, l, r;
            int64_t v;
            cin >> opt;
            switch (opt)
            {
            case 1:
                cin >> l >> r >> v;
                --l;
                for (; l < r; ++l)
                {
                    A[l] += v;
                    A[l] %= p;
                }
                break;
            case 2:
                cin >> l >> r >> v;
                --l;
                for (; l < r; ++l)
                {
                    A[l] *= v;
                    A[l] %= p;
                }
                break;
            default:
                cin >> l >> r;
                --l;
                int64_t sum = 0;
                for (; l < r; ++l)
                {
                    for (size_t i = l + 1; i < r; ++i)
                    {
                        sum += A[l] * A[i];
                        sum %= p;
                    }
                }
                cout << sum << '\n';
                break;
            }
        }
    }

    return 0;
}
