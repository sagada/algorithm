#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
using namespace std;
int n,m,k;
int d[1001][1001];
int dist[1001][1001][11][2];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int main(){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        for (int j = 0; j < str.size(); j++)
        {
            d[i][j] = str[j] - '0';
        }
    }
    queue<tuple<int,int,int,int>> q;
    q.push(make_tuple(0,0,0,0));
    dist[0][0][0][0] = 1;
    while(!q.empty())
            {
                int _y, _x, ct, night;
                
                tie(_y, _x, ct, night) = q.front();
                q.pop();

                if (_y == n - 1 && _x == m - 1)
                {
                    cout << dist[_y][_x][ct][night] << "\n";
                    return 0;
                }

                for (int i = 0; i < 4; i++)
                {
                    int ny = dy[i] + _y;
                    int nx = dx[i] + _x;

                    if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                        continue;

                    if (d[ny][nx] == 0 && dist[ny][nx][ct][1 - night] == 0)
                    {
                        dist[ny][nx][ct][1 - night] = dist[_y][_x][ct][night] + 1;
                        q.push(make_tuple(ny, nx, ct, 1 - night));
                    }

                    // 벽이고 부술 수있으면
                    if (night == 0 && ct + 1 <= k && d[ny][nx] == 1 && dist[ny][nx][ct + 1][1 - night] == 0) {
                        dist[ny][nx][ct + 1][1 - night] = dist[_y][_x][ct][night] + 1;
                        q.push(make_tuple(ny, nx, ct + 1, 1 - night));
                    }
                }

                if (dist[_y][_x][ct][1 - night] == 0)
                {
                    dist[_y][_x][ct][1 - night] = dist[_y][_x][ct][night] + 1;
                    q.push(make_tuple(_y, _x, ct, 1 - night));
                }
            }
    
    cout << -1 << '\n';
    
    
}
