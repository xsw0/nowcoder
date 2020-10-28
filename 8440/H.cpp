#include <iostream>
#include <bitset>
#include <numeric>

using namespace std;

class float16_t
{
    bool sign;
    bitset<5> exp;
    bitset<10> fraction;

public:
    float16_t(float f)
    {
        bitset<32> bs(*(uint32_t *)(&f));
        sign = bs[31];
        exp = (bs << 4 >> 4 >> 23).to_ulong() - 127 + 15;
        fraction = (bs << 9 >> 9 >> 13).to_ulong();
    }
    operator float() const
    {
        bitset<32> bs;
        bs[31] = sign;
        bs |= (exp.to_ullong() - 15 + 127) << 23;
        bs |= fraction.to_ullong() << 13;
        auto ull = bs.to_ullong();
        return *(float *)(&ull);
    }

    bitset<16> to_bitset() const
    {
        bitset<16> result;
        result[15] = sign;
        result |= exp.to_ullong() << 10;
        result |= fraction.to_ullong();
        return result;
    }

    bitset<16> operator+(const float16_t &other) const
    {
        return float16_t(float(*this) + float(other)).to_bitset();
    }
    bitset<16> operator*(const float16_t &other) const
    {
        return float16_t(float(*this) * float(other)).to_bitset();
    }
};

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
        switch (op)
        {
        case 2:
            cout << float16_t(a) + float16_t(b);
            break;
        case 3:
            cout << float16_t(a) * float16_t(b);
            break;
        default:
            cout << float16_t(a).to_bitset();
            break;
        }
        cout << "\n";
    }

    return 0;
}
