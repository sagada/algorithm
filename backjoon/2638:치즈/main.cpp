#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;
int n,m;
int d[101][101];
int checkCheese[101][101];
bool v[101][101];
int dy[]={0,1,0,-1};
int dx[]={-1,0,1,0};

void pr()
{
    for (int i =0 ; i< n;i++)
    {
        for (int j =0;j<m;j++)
        {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}
void melting_check()
{
    queue<pair<int,int>> q;
    
    memset(checkCheese, 0 ,sizeof(checkCheese));
    memset(v, false, sizeof(v));
    
    q.push({0,0});
    v[0][0] = true;
    while(!q.empty())
    {
        int _y = q.front().first;
        int _x = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ;i++)
        {
            int ny = _y + dy[i];
            int nx = _x + dx[i];
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            
            if (v[ny][nx])
                continue;
            
            if (d[ny][nx] == 1)
            {
                checkCheese[ny][nx]++;
            }
            
            if (d[ny][nx] == 0)
            {
                q.push({ny, nx});
                v[ny][nx] = true;
            }
        }
    }
//    pr();
}
void deleteMelting()
{
    for (int i =0 ; i< n;i++)
    {
        for (int j =0;j<m;j++)
        {
            if(checkCheese[i][j] >= 2)
            {
                d[i][j] = 0;
            }
        }
    }
}
bool isAllMelting()
{
    for (int i =0 ; i< n;i++)
    {
        for (int j =0;j<m;j++)
        {
            if (d[i][j] == 1)
            {
                return false;
            }
        }
    }
    
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i =0 ; i< n;i++)
    {
        for (int j =0;j<m;j++)
        {
            cin >> d[i][j];
        }
    }
    
    int cnt = 0;
    
    bool isFinish = false;
    while(!isFinish)
    {
        cnt++;
        melting_check();
        deleteMelting();
        isFinish = isAllMelting();
    }
    
    cout << cnt << "\n";
}
