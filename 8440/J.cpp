#include <iostream>
#include <vector>

using namespace std;

inline bool between(int n, int lower_bound, int upper_bound)
{
    return n > lower_bound && n < upper_bound;
}

class TriRegion
{
    struct xy
    {
        int x;
        int y;
    };
    xy p0;
    xy v1;
    xy v2;
    int det;

public:
    TriRegion(int x0, int y0,
              int x1, int y1,
              int x2, int y2)
        : p0{x0, y0},
          v1{x1 - x0, y1 - y0},
          v2{x2 - x0, y2 - y0},
          det((x1 - x0) * (y2 - y0) -
              (y1 - y0) * (x2 - x0)) {}
    bool in(int x, int y) const
    {
        x -= p0.x;
        y -= p0.y;
        int root1_det = x * v2.y - y * v2.x;
        int root2_det = v1.x * y - v1.y * x;
        if (det < 0)
        {
            return between(root1_det, det, 0) &&
                   between(root2_det, det, 0) &&
                   between(root1_det + root2_det, det, 0);
        }
        else
        {
            return between(root1_det, 0, det) &&
                   between(root2_det, 0, det) &&
                   between(root1_det + root2_det, 0, det);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, q;
    cin >> n >> q;
    vector<TriRegion> triRegions;
    triRegions.reserve(q);
    while (n--)
    {
        int x0, y0,
            x1, y1,
            x2, y2;
        cin >>
            x0 >> y0 >>
            x1 >> y1 >>
            x2 >> y2;
        triRegions.emplace_back(x0, y0,
                                x1, y1,
                                x2, y2);
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        bool in = false;
        for (auto &reg : triRegions)
        {
            in ^= reg.in(x, y);
        }
        cout << (in ? "Yes\n" : "No\n");
    }

    return 0;
}
