#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t t;
    cin >> t;
    while (t--)
    {
        size_t n;
        cin >> n;
        vector<string> name(n * 3);
        for (size_t j = 0; j < n * 3; ++j)
        {
            string s;
            s.reserve(20);
            size_t a;
            cin >> s >> a;
            name[a - 1] = s;
        }
        for (size_t j = 0; j < n; ++j)
        {
            cout << "ACM-" << j << ' ' << name[j * 3 + 2] << ' ' << name[j * 3 + 1] << ' ' << name[j * 3] << '\n';
        }
    }

    return 0;
}
