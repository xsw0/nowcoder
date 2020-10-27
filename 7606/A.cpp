#include <iostream>

using namespace std;

int main()
{
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        int A = 0, B = 0, C = 0, D = 0;
        for (size_t j = 0; j < 4; ++j)
        {
            char c;
            cin >> c;
            switch (c)
            {
            case 'A':
                ++A;
                break;
            case 'B':
                ++B;
                break;
            case 'C':
                ++C;
                break;
            case 'D':
                ++D;
                break;
            default:
                break;
            }
        }
        if (D != 0 || C > 1)
        {
            cout << "failed" << endl;
        }
        else if (A > 2)
        {
            cout << "sp offer" << endl;
        }
        else
        {
            cout << "offer" << endl;
        }
    }
    return 0;
}
