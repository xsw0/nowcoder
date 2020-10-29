#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

class Path
{
    size_t preSum;
    size_t lastWeight;
    size_t count;

public:
    Path(size_t weight)
        : preSum(0),
          count(1),
          lastWeight(weight) {}

    Path &operator+=(size_t weight)
    {
        if (lastWeight == weight)
        {
            ++count;
        }
        else
        {
            if (count < 3)
            {
                preSum += count * lastWeight;
            }
            lastWeight = weight;
            count = 1;
        }
        return *this;
    }

    Path operator+(size_t weight) const
    {
        return Path(*this) += weight;
    }

    size_t weight() const
    {
        return count < 3 ? preSum + count * lastWeight : preSum;
    }
};

struct node
{
    int64_t count = 0;
    map<size_t, size_t> edges;
    vector<Path> paths;
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
        size_t n, k;

        vector<node> edges(n);

        while (--n)
        {
            size_t u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            edges[u].edges.insert(v, w);
            edges[v].edges.insert(u, w);
        }

        int64_t base = 0;
        int64_t sum = 0;
        for (size_t i = 1; i < edges.size(); ++i)
        {
            function<void(size_t, const Path &)> f =
                lower_bound
                    [&](size_t index, const Path &path)
                        ->void
            {
                for (auto it = edges[index].edges.cbegin();
                     it != edges[index].edges.cend() && it->first < i;
                     ++it)
                {
                    if ((path + it->second).weight() < k)
                    {
                        f(index; path + it->second);
                    }
                }
            };
        }
    }

    return 0;
}
