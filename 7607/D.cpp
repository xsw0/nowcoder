#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>
// #include <fstream>

using namespace std;

int main()
{
    // ifstream cin("move.in");
    // ofstream cout("_move.out", ios::trunc | ios::out);
    size_t n, m;
    cin >> n >> m;
    map<size_t, vector<pair<size_t, size_t>>> closes;
    for (size_t i = 0; i < m; ++i)
    {
        size_t a, b, c;
        cin >> a >> b >> c;
        closes[a].push_back({b, c});
    }

    auto isClose = [&](size_t pos, size_t time) -> bool {
        for (auto &p : closes[pos])
        {
            if ((p.first <= time && time <= p.second))
            {
                return true;
            }
        }
        return false;
    };

    auto hasClose = [&](size_t pos, size_t begin, size_t end) -> bool {
        for (auto &p : closes[pos])
        {
            if ((p.first <= begin && begin <= p.second) ||
                (p.first <= end && end <= p.second))
            {
                return true;
            }
        }
        return false;
    };

    auto next_open = [&](size_t pos, size_t time) -> size_t {
        size_t next_time = time;
        for (auto &p : closes[pos])
        {
            if (p.first <= time && time <= p.second)
            {
                next_time = max(next_time, p.second + 1);
            }
        }
        return next_time;
    };

    map<size_t, set<size_t>> pos_time = {{0, {0}}};
    while (true)
    {
        auto pos = pos_time.rbegin()->first;
        auto time = *pos_time.rbegin()->second.begin();
        pos_time[pos].erase(time);
        if (pos_time[pos].empty())
        {
            pos_time.erase(pos);
        }
        if (pos < n)
        {
            auto next_time = next_open(pos + 1, time + 1);
            if (!hasClose(pos, time, next_time - 1))
            {
                if (pos + 1 == n)
                {
                    cout << next_time + 1 << endl;
                    return 0;
                }
                pos_time[pos + 1].insert(next_time);
            }
        }
        if (!isClose(pos, time))
        {
            pos_time[pos].insert(time + 1);
        }
        if (pos > 0)
        {
            auto next_time = next_open(pos - 1, time + 1);
            if (!hasClose(pos, time, next_time - 1))
            {
                pos_time[pos - 1].insert(next_time);
            }
        }
    }

    return 0;
}
