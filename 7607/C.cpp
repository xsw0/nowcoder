#include <iostream>
#include <string>
#include <array>
#include <locale>

using namespace std;

size_t moder = 998244353;

class modNum
{
public:
    static size_t moder;
    size_t n;
    modNum(size_t n = 0) : n(n % moder){};
    size_t operator+(const modNum &other) const
    {
        return (n % moder + other.n % moder) % moder;
    }
    size_t operator*(const modNum &other) const
    {
        return ((n % moder) * (other.n % moder)) % moder;
    }
};

int main()
{
    string s;
    size_t n;
    cin >> s >> n;

    array<size_t, 26> arr;

    for (const auto c : s)
    {
        ++arr[c - 'a'];
    }

    for (size_t i = 0; i < n; ++i)
    {
        string t;
        cin >> t;
        size_t index = 0;
        modNum result = 0;
        char pre = n;
        bool isNum = false;
        string::const_iterator numBeg;
        for (auto it = t.cbegin(); it != t.cend(); ++it)
        {
            if (std::isdigit(*it))
            {
                if (!isNum)
                {
                    isNum = true;
                    numBeg = it;
                }
            }
            else
            {
                if (isNum)
                {
                    size_t 
                }
            }
        }
    }

    return 0;
}
