#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string d[51][51];
int ch[51][51];
bool v[51][51];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int max_area = 0;
int n, m;
int cmc = 0;
int sum_area[2501];

void init()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            string str ="";
            
            while(temp > 0)
            {
                str += temp % 2 == 1 ? "1": "0";
                temp /= 2;
            }
            
            while(str.size() != 4)
            {
                str += "0";
            }
            
            reverse(str.begin(), str.end());
            
            d[i][j] = str;
        }
    }
}

int fs = 0;
void checkAll()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                
                if (ny < 0 || ny >= m || nx < 0 || nx >=n)
                    continue;
                
                if (ch[i][j] != ch[ny][nx])
                {
                
                    fs = max(sum_area[ch[i][j]] + sum_area[ch[ny][nx]], fs);
                }
            }
        }
    }
}
void bfs(int y, int x)
{
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({y, x});
    v[y][x] = true;
    
    while(!q.empty())
    {
        int _y = q.front().first;
        int _x = q.front().second;
        q.pop();
        ch[_y][_x] = cmc;
        cnt ++;
        for (int i = 0; i < 4; i++)
        {
            int ny = 0;
            int nx = 0;
            if (d[_y][_x][i] == '0')
            {
                ny = dy[i] + _y;
                nx = dx[i] + _x;
            }
            
            if (ny < 0 || ny >= m || nx < 0 || nx >= n)
                continue;
            
            if (v[ny][nx])
            {
                continue;
            }
            
            v[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    sum_area[cmc] = cnt;
    max_area = max(max_area, cnt);
}
int main()
{
    cin >> n >> m;
    init();
    
   
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!v[i][j])
            {
                
                bfs(i, j);
                
                cmc++;
            }
        }
    }
    checkAll();
    
    
    cout << cmc << '\n';
    cout << max_area << "\n";
    cout << fs << "\n";
}
