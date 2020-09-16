#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
    bool operator < (const Edge & other) const
    {
           return cost < other.cost;
    }
};

int p[100001];
Edge vec[1000001];
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

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
    {
        p[x] = y;
    }
}

int main()
{
    
    int n,m;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        
        scanf("%d %d %d", &from, &to, &cost);
        
        vec[i] = {from, to, cost};
    }
    
    sort(vec, vec + m);
    
    int ans = 0;
    int cnt = 0;
    int p,w;
    int i = 0;
    while(cnt != n - 2)
    {
        p = vec[i].from;
        w = vec[i].to;
        
        if (Find(p) != Find(w))
        {
            Union(p, w);
            ans += vec[i].cost;
            cnt ++;
        }
        i++;
    }
    printf("%d", ans);
    
}
