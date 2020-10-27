#include <iostream>

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
        int op, a, b;
        cin >> op >> a >> b;
        switch (op)
        {
        case 1:
            cout << a + b << '\n';
            break;
        case 2:
            cout << a - b << '\n';
            break;
        case 3:
            cout << a * b << '\n';
            break;
        case 4:
            cout << a / b << '\n';
            break;
        default:
            break;
        }
    }

    return 0;
}
