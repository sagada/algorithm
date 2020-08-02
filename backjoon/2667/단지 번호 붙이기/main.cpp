#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int d[26][26];
bool v[26][26];
int n;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

vector<int> result;

int bfs(int y, int x)
{
    queue<pair<int, int>> q;
    
    q.push({y, x});
    v[y][x] = true;
    int count = 0;
    
    while (!q.empty())
    {
        int _y = q.front().first;
        int _x = q.front().second;
        count ++;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + _y;
            int nx = dx[i] + _x;
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;
            
            if (!v[ny][nx] && d[ny][nx]  == 1)
            {
                q.push({ny, nx});
                v[ny][nx] = true;
            }
        }
    }
    
    return count;
}
int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        for (int j = 0; j < str.size(); j++)
        {
            d[i][j] = str[j] - '0';
        }
    }
    
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
             if (!v[i][j] && d[i][j] == 1)
             {
                 result.push_back(bfs(i, j));
             }
        }
    }
    
    sort(result.begin(), result.end());
    
    cout << result.size() << "\n";
    
    for (int count : result)
    {
        cout << count << "\n";
    }
    
    
}
