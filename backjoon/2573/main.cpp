#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<stack>
#include<string.h>
using namespace std;
int d[501][501];
bool v[501][501];

int cp[301][301];
int n, m;
int dy[] = {0,1,0,-1};
int dx[] = {-1,0,1,0};

void cp_map()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cp[i][j] = d[i][j];
        }
    }
}

void melt()
{
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            d[i][j] = cp[i][j];
        }
    }

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (d[i][j] != 0)
            {
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++)
                {
                    int ny = dy[dir] + i;
                    int nx = dx[dir] + j;
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                        continue;
                    if (d[ny][nx] == 0)
                    {
                        cnt++;
                    }
                }
                
                // 복사본 맵 업데이트
                cnt = d[i][j] - cnt > 0? d[i][j] - cnt : 0;
                cp[i][j] = cnt;
            }
        }
    }
    
    
}

int main(){
  
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> d[i][j];
            cp[i][j] = d[i][j];
        }
    }
    int cnt = 0;
    while(true)
    {
        cnt++;
        melt();
        
        
        int isF = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                v[i][j] = false;
                // 녹지 않은 위치 카운트
                if (cp[i][j] != 0)
                {
                    isF++;
                }
            }
        }
        
        // 녹지 않은 곳이 없으면 종료
        if (isF == 0)
        {
            break;
        }
        
        // 구간 개수 카운트
        int b = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (cp[i][j] != 0 && !v[i][j])
                {
                    b++;
                    v[i][j] = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    
                    while(!q.empty())
                    {
                        int _y = q.front().first;
                        int _x = q.front().second;
                        q.pop();
                        
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int ny = dy[dir] + _y;
                            int nx = dx[dir] + _x;
                            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                                continue;
                            if (cp[ny][nx] != 0 && !v[ny][nx])
                            {
                                q.push({ny, nx});
                                v[ny][nx] = true;
                            }
                        }
                    }
                }
            }
        }
        
        if (b != 1)
        {
            cout << cnt << "\n";
            return 0;
        }
    }
    
    cout << 0 << "\n";
}
