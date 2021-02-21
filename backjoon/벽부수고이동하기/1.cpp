#include<iostream>
#include<queue>
#include<string.h>
#include<set>
#include<vector>
#include<map>
#include<tuple>
using namespace std;

int n, m;
int d[1001][1001];
int v[1001][1001][2];
int dy[] = {0,1,0,-1};
int dx[] = {-1,0,1,0};

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &d[i][j]);
        }
    }
    
    queue<tuple<int,int,int>> q;
    
    q.push(make_tuple(0, 0, 0));
    v[0][0][0]=1;
    while(!q.empty())
    {
        int y,x,z;
        
        tie(y,x,z) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            
            if (v[ny][nx][z] == 0 && d[ny][nx] == 0) // 다음 갈 곳이 벽이 아니고
            {
                v[ny][nx][z] = v[y][x][z] + 1;
                q.push(make_tuple(ny, nx, z));
            }
            
            if (z == 0 && d[ny][nx] == 1 && v[ny][nx][1] == 0)
            {
                v[ny][nx][1] = v[y][x][0] + 1;
                q.push(make_tuple(ny, nx, 1));
            }
        }
    }
    
    if (v[n - 1][m - 1][0] != 0 && v[n - 1][m - 1][1] != 0)
    {
        cout << min(v[n - 1][m - 1][0], v[n - 1][m - 1][1]) << '\n';
    }
    else if(v[n - 1][m - 1][0] != 0)
    {
        cout << v[n - 1][m - 1][0] << '\n';
    }
    else if(v[n - 1][m - 1][1] != 0)
    {
        cout << v[n - 1][m - 1][1] << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}
