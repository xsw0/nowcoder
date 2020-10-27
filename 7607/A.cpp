#include <iostream>
#include <vector>

using namespace std;

vector<bool> prime = {false, false, true};

int main()
{
    size_t a, b;
    cin >> a >> b;
    prime.resize(b + 1, true);
    size_t result = 0;
    for (size_t i = 0; i < prime.size(); ++i)
    {
        if (prime[i])
        {
            for (size_t j = i + i; j < prime.size(); j += i)
            {
                prime[j] = false;
            }
            if (i >= a)
            {
                result += i;
            }
            for (size_t j = i * i; j < prime.size(); j *= i)
            {
                if (j >= a)
                {
                    result += i - 1;
                }
            }
        }
        else if (a <= i && i <= b)
        {
            ++result;
        }
    }

    cout << result << endl;

    return 0;
}
