#include <iostream>
#include <bitset>

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
        int op;
        float a, b;
        cin >> op >> a >> b;
        auto printFloat16 = [](float f) {
            bitset<sizeof(float) * 8> bs(*(uint32_t *)(&f));

            // sign
            cout << bs[31];

            // exp
            {
                bitset<8> exp8;
                for (size_t i = 0; i < 8; ++i)
                {
                    exp8.set(i, bs[i + 23]);
                }
                if (exp8.to_ulong() < (127 - 15))
                {
                    cout << "00000";
                }
                if (exp8.to_ulong() - (127 - 15) > 0b11111)
                {
                    cout << "11111";
                }
                else
                {
                    bitset<5> exp5(exp8.to_ulong() - (127 - 15));
                    cout << exp5;
                }
            }

            // fraction
            for (size_t i = 22; i > 12; --i)
            {
                cout << bs[i];
            }
        };
        switch (op)
        {
        case 2:
            printFloat16(a + b);
            break;
        case 3:
            printFloat16(a * b);
            break;
        default:
            printFloat16(a);
            break;
        }
        cout << "\n";
    }

    return 0;
}
