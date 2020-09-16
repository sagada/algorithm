#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

struct Edge{
    int from ,to, cost;
    bool operator < (const Edge & other) const
    {
        return cost - other.cost;
    }
};


int p[200001];

int Find(int x)
{
    if (x == p[x])
    {
        return x;
    }
    else
    {
        return p[x] = Find(p[x]);
    }
}

void unionF(int y, int x)
{
    y = Find(y);
    x = Find(x);
    if (y != x)
    {
        p[x] = y;
    }
}
bool compare(Edge e, Edge u)
{
    return e.cost < u.cost;
}
int main()
{
    while(true)
    {
        memset(p, 0, sizeof(p));
        
        vector<Edge> vec;
        int m,n;
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        
        
        int sum = 0;
        
        for (int i = 0; i < m; i++)
        {
            p[i] = i;
        }
        
        for (int i = 0; i < n; i++)
        {
            int x,y,z;
            scanf("%d %d %d", &x, &y, &z);
            Edge d;
            d.from = x;
            d.to = y;
            d.cost = z;
            vec.push_back(d);
            sum += z;

        }
        
        sort(vec.begin(), vec.end(), compare);
        
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            Edge e = vec[i];
            
            int f = e.from;
            int t = e.to;
            if (Find(f) != Find(t))
            {
                unionF(f, t);
                ans += e.cost;
                cnt++;
            }

        }
        
        cout << sum - ans << "\n";
    }
}
