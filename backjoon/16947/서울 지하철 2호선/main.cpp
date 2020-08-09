#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int n;

int v[3001];
int dist[3001];

vector<int> vec[3001];

int go(int cur, int bef)
{
    if (v[cur])
    {
        return cur;
    }
    
    v[cur] = 1;
    
    for (int next : vec[cur])
    {
        if(next == bef) continue;
        
        int res = go(next, cur);
        
        if(res == -2) return -2;
        
        if(res >= 0)
        {
            v[cur] = 2;
            
            if(cur == res) // 현재 정점이 사이클의 시작점과 같으면 사이클에 포함 X
            {
                return -2;
            }
            else
            {
                return res;
            }
        }
    }
    
    return -1;
    
}

void bfs()
{
    queue<int> q;
    
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 2)
        {
            dist[i] = 0;
            q.push(i);
        }
        else
        {
            dist[i] = -1;
        }
    }
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : vec[x])
        {
            if(dist[y] == -1)
            {
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
    }

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    go(1, -1);
    bfs();
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << "\n";
}
