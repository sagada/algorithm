#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
using namespace std;
char d[101][101];
bool v[101][101];

int dy[] = {0,1,0,-1};
int dx[] = {-1,0,1,0};
int n;
map<char, int> m;

bool can(bool isJuk, char from, char to)
{
    if (from == to)
        return true;
    
    if (isJuk)
    {
        if (from == 'R' && to == 'G')
            return true;
        
        if (from == 'G' && to == 'R')
            return true;
    }
    
    return false;
}

void bfs(int y, int x, bool isJuk)
{
    queue<pair<int,int>> q;
    q.push({y, x});
    v[y][x] = true;
        
    while(!q.empty())
    {
        int _y = q.front().first;
        int _x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + _y;
            int nx = dx[i] + _x;
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;
            
            if (!v[ny][nx] && can(isJuk, d[y][x], d[ny][nx]))
            {
                q.push({ny, nx});
                v[ny][nx] = true;
            }
        }
    }
}

int main(){
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            d[i][j] ='0';
        }
    }
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> d[i][j];
        }
    }
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!v[i][j])
            {
                a++;
              
                bfs(i, j, false);
            }
        }
    }
    
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!v[i][j])
            {
                b++;
                bfs(i, j, true);
            }
        }
    }
    cout << a<< " " << b << '\n';
}
