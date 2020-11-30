#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string.h>

using namespace std;

int n, m;
int k;
int d[201][201];
int c[201][201][31];
int dy[] = {0,1,0,-1};
int dx[] = {-1,0,1,0};

int py[] ={-1,-2,-2,-1,1,2,2,1};
int px[] ={-2,-1,1,2,2,1,-1,-2};

const int MAX = 999999;
int ans = MAX;

int main()
{
    cin >> k;
    
    cin >> m >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> d[i][j];
        }
    }
    bool test = false;
    queue<pair<pair<int,int>, int>> q;
    
    memset(c, MAX, sizeof(int) * (201 * 201 * 31));
    
    q.push({{0,0}, k});
    c[0][0][k] = 0;
    
    while(!q.empty())
    {
        int _y = q.front().first.first;
        int _x = q.front().first.second;
        
        int jump = q.front().second;
        q.pop();
        
        if (_y == n - 1 && _x == m - 1)
        {
            test = true;
            ans = min(ans, c[_y][_x][jump]);
        }
        
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + _y;
            int nx = dx[i] + _x;
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            
            if (c[ny][nx][jump] > c[_y][_x][jump] + 1 && d[ny][nx] != 1)
            {
                c[ny][nx][jump] = c[_y][_x][jump] + 1;
                q.push({{ny, nx}, jump});
            }
        }
        
        for (int i = 0; i < 8; i++)
        {
            int ny = py[i] + _y;
            int nx = px[i] + _x;
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            
            if (jump > 0 && c[ny][nx][jump - 1] > c[_y][_x][jump] + 1 && d[ny][nx] != 1)
            {
                c[ny][nx][jump - 1] = c[_y][_x][jump] + 1;
                q.push({{ny, nx}, jump - 1});
            }
            
        }
    }
    
    if (!test)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
    
}
