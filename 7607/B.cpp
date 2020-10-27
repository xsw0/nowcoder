#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Tree
{
    Tree *one;
    Tree *zero;
    Tree() : one(nullptr), zero(nullptr)
    {
    }

    Tree(int n) : one(nullptr), zero(nullptr)
    {
        insert(n);
    }

    void insert(int n)
    {
        if (n != 0)
        {
            if (n % 2 == 0)
            {
                if (zero)
                {
                    zero->insert(n / 2);
                }
                else
                {
                    zero = new Tree(n / 2);
                }
            }
            else
            {
                if (one)
                {
                    one->insert(n / 2);
                }
                else
                {
                    one = new Tree(n / 2);
                }
            }
        }
    }

    bool contain(int n)
    {
        return n == 0 || (n % 2 == 0 && zero && zero->contain(n / 2)) ||
               (one && one->contain(n / 2));
    }
};

int main()
{
    ifstream input("contain.in");
    ofstream output("_contain.out", ios::trunc | ios::out);
    int n, m;
    input >> n >> m;
    Tree tree;
    int maximum = 0;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        input >> x;
        tree.insert(x);
        maximum = max(maximum, x);
    }
    for (size_t i = 0; i < m; i++)
    {
        int x;
        input >> x;
        if (x <= maximum && tree.contain(x))
        {
            output << "yes" << endl;
        }
        else
        {
            output << "no" << endl;
        }
    }
    return 0;
}
