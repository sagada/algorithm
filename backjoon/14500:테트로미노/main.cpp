#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string.h>

using namespace std;

int n, m;
int ans = 0;

int d[501][501];
int v[501][501];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

void dfs(int index, int y, int x, int sum)
{
    if (index == 4)
    {
        ans = max(ans, sum);
        return ;
    }
    
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        
        if (!v[ny][nx])
        {
            v[ny][nx] = true;
            dfs(index + 1, ny, nx, sum + d[y][x]);
            v[ny][nx] = false;
        }
    }
}

void check(int y, int x)
{
    // ㅏ
    if (x + 1 < m && y - 1 >= 0 && y + 1 < n)
    {
        ans = max(ans, d[y][x] + d[y - 1][x] + d[y + 1][x] + d[y][x + 1]);
    }
    
    // ㅓ
    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < n)
    {
        ans = max(ans, d[y][x] + d[y -1][x] + d[y + 1][x] + d[y][x - 1]);
    }
    
    // ㅗ
    if (y - 1 >= 0 && x - 1 >= 0 && x + 1 < m)
    {
        ans = max(ans, d[y][x] + d[y][x -1] + d[y][x + 1] + d[y-1][x]);
    }
    
    // ㅜ
    if (y + 1 < n && x - 1 >= 0 && x + 1 < m)
    {
        ans = max(ans, d[y][x] + d[y][x-1]+ d[y][x+ 1]+d[y+1][x]);
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> d[i][j];
        }
    }
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            v[i][j] = true;
            dfs(0, i, j, 0);
            v[i][j] = false;
            check(i, j);
        }
    }
    
    cout << ans << "\n";
}
