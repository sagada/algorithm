#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<tuple>
using namespace std;

int n,m;
int b[101][101];
int d[101][101];
bool v[101][101];
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

int main()
{
    string str;
    cin >> m >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        
        for (int j = 0; j < m; j++)
        {
            b[i][j] = str[j] - '0';
        }
    }
   
    
    queue<pair<int,int>> q;
    queue<pair<int,int>> next_q;
    
    q.push({0, 0});
    d[0][0] = 0;
    
    
    while(!q.empty())
    {
        int _y, _x;
        tie(_y, _x) = q.front();
        
        q.pop();
        
       
        for (int i = 0; i < 4; i++)
        {
            int ny = _y + dy[i];
            int nx = _x + dx[i];
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            
            if (v[ny][nx])
                continue;
            
            v[ny][nx] = true;
            
            if (b[ny][nx] == 1)
            {
                d[ny][nx] = d[_y][_x] + 1;
                next_q.push({ny, nx});
            }
            else
            {
                d[ny][nx] = d[_y][_x];
                q.push({ny, nx});
            }
        }
        
        if (q.empty())
        {
            q = next_q;
            next_q = queue<pair<int,int>>();
        }
    }
    
    
    cout << d[n - 1][m - 1] << "\n";
}
