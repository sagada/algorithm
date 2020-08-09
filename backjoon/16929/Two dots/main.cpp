#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

char d[51][51];
bool v[51][51];
int dist[51][51];
int n, m;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

bool ret = false;
bool dfs(int y, int x, int cnt, char temp)
{
    if (v[y][x])
    {
        return cnt - dist[y][x] >= 4;
    }
    
    v[y][x] = true;
    dist[y][x] = cnt;
    
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;

        if (d[ny][nx] == temp)
        {
            if(dfs(ny, nx, cnt + 1, temp))
            {
                return true;
            }
        }
    }
    return false;
}

bool dfs2(int y,int x, int cnt, char temp)
{
    if(v[y][x])
    {
        return cnt - dist[y][x] >= 4;
    }
    
    dist[y][x] = cnt;
    v[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        
        if (d[ny][nx] == temp)
        {
            if(dfs2(ny,nx,cnt +1 ,temp)){
                
                return true;
            }
        }
    }
    return false;
}
int main()
{
    memset(d, 0, sizeof(d));
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        for (int j = 0; j < str.size(); j++)
        {
            d[i][j] = str[j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            if(v[i][j]) continue;
            memset(dist, 0, sizeof(dist));
            
            bool t = dfs(i, j, 0, d[i][j]);
            
            if(t)
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    
    cout << "No\n";
    return 0;
    
}
