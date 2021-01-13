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

int dy[] = {0,1,0,-1};
int dx[] = {-1,0,1,0};
int b[1001][1001];
int ret[1001][1001];
bool visit[1001][1001];
int mark[1001][1001];
int position = 0;

bool mark_check[1000001];
void bfs(int y, int x)
{
    queue<pair<int,int>> q;
    vector<pair<int,int>> vec;
    position++;
    q.push({y, x});
    visit[y][x] = true;
    vec.push_back({y, x});
    int cnt = 0;
    while(!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        cnt++;
        q.pop();
        mark[cy][cx] = position;
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + cy;
            int nx = dx[i] + cx;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            
            if (!visit[ny][nx] && d[ny][nx] == 0)
            {
                visit[ny][nx] = true;
                q.push({ny, nx});
                vec.push_back({ny, nx});
            }
        }
    }
    
    for (int i = 0; i < vec.size(); i++)
    {
        b[vec[i].first][vec[i].second] = cnt;
    }
    
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &d[i][j]);
            mark[i][j] = -1;
        }
    }
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (d[i][j] == 0 && !visit[i][j])
            {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            if (d[i][j] == 1)
            {
                int cnt = 0;
                
                if (mark[i - 1][j] != -1 && !mark_check[mark[i - 1][j]] && d[i - 1][j] == 0 && i - 1 >= 0) // 위쪽
                {
                    mark_check[mark[i - 1][j]] = true;
                    cnt += b[i-1][j];
                }
                
                if (mark[i][j - 1] != -1 && !mark_check[mark[i][j - 1]] && d[i][j - 1] == 0 && j - 1 >= 0) // 왼쪽
                {
                    mark_check[mark[i][j - 1]] = true;
                    cnt += b[i][j-1];
                }
                
                if (mark[i + 1][j] != -1 && !mark_check[mark[i + 1][j]] && d[i + 1][j] == 0 && i + 1 < n)
                {
                    mark_check[mark[i + 1][j]] = true;
                    cnt += b[i + 1][j];
                }
                
                if (mark[i][j + 1] != -1 && !mark_check[mark[i][j + 1]] && d[i][j + 1] == 0 && j + 1 < m)
                {
                    mark_check[mark[i][j + 1]] = true;
                    cnt += b[i][j + 1];
                }
                
                ret[i][j] = (cnt + 1) % 10;
                
                if (i - 1 >= 0)
                {
                    mark_check[mark[i - 1][j]] = false;
                }
                
                if (j - 1 >= 0)
                {
                    mark_check[mark[i][j - 1]] = false;
                }
                
                if (i + 1 < n)
                {
                    mark_check[mark[i + 1][j]] = false;
                }
                
                if (j + 1 < m)
                {
                    mark_check[mark[i][j + 1]] = false;
                }
            }

        }
    }
    
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << ret[i][j];
        }
        cout <<'\n';
    }
}
