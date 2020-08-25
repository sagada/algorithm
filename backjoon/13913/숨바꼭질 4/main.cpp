#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;
int a, b;
int maxV = 100000;
int dist[100001];
int from[100001];
bool check[100001];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    
    dist[x] = 0;
    check[x] = true;
        
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now == b)
        {
            
        }
        
        if (now + 1 <= maxV && !check[now + 1])
        {
            q.push(now + 1);
            dist[now + 1] = dist[now] + 1;
            check[now + 1] = true;
            from[now + 1] = now;
        }
        
        if (now - 1 >= 0 && !check[now - 1])
        {
            q.push(now - 1);
            dist[now - 1] = dist[now] + 1;
            check[now - 1] = true;
            from[now - 1] = now;
        }
        
        if (now * 2 <= maxV && !check[now * 2])
        {
            q.push(now * 2);
            dist[now * 2] = dist[now] + 1;
            check[now * 2] = true;
            from[now * 2] = now;
        }
    }
    
    
}
int main()
{
    cin >> a >> b;
    bfs(a);
    
}
