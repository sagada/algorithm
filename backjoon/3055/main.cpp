#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<string.h>
#include<cmath>
using namespace std;
char d[51][51];
int water_map[51][51];
int b_map[51][51];

int dy[] = {0,1,0,-1};
int dx[] ={-1,0,1,0};

int r, c;
vector<pair<int,int>> water;
int dot_y, dot_x;
int _y, _x;

void water_bfs()
{
    
    queue<pair<int,int>> wat;
    
    for (int i = 0; i < water.size(); i++)
    {
        wat.push({water[i].first, water[i].second});
        water_map[water[i].first][water[i].second] = 0;
    }
    water_map[dot_y][dot_x] = 999999;
    while(!wat.empty())
    {
        int cur_y = wat.front().first;
        int cur_x = wat.front().second;
        
        wat.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            
            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;
            
            if (d[ny][nx] != 'D' && d[ny][nx] != 'X' && water_map[ny][nx] == 0)
            {
                water_map[ny][nx] = water_map[cur_y][cur_x] + 1;
                wat.push({ny, nx});
            }
        }
        
    }
}
void print_water_map()
{
    for (int i =0 ; i <r ;i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%9d", water_map[i][j]);
        }
        cout << "\n";
    }
}

int bfs_beaber()
{
    queue<pair<int,int>> q;
//    for (int i = 0; i < r; i++)
//    {
//        for (int j = 0; j < c; j++)
//        {
//            b_map[i][j] = -1;
//        }
//    }
    q.push({_y, _x});
    
    b_map[_y][_x] = 0;
    while(!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        if (cur_y == dot_y && cur_x == dot_x)
        {
            return b_map[cur_y][cur_x];
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            
            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;
            
            if (d[ny][nx] !='X' && d[ny][nx] !='*' && b_map[ny][nx] == 0)
            {
                
                if (water_map[ny][nx] == 0 || water_map[ny][nx] > b_map[cur_y][cur_x] + 1)
                {
                    b_map[ny][nx] = b_map[cur_y][cur_x] + 1;
                    q.push({ny, nx});
                }
            
            }
            
        }
    }
    
    return -1;
}
void print_b()
{
    cout << "print_b()\n\n\n";
    for (int i =0 ; i <r ;i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%9d", b_map[i][j]);
        }
        cout << "\n";
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        
        for (int j = 0; j < str.size(); j++)
        {
            d[i][j] = str[j];
            
            if (d[i][j] == '*')
            {
                water.push_back({i, j});
            }
            else if (d[i][j] == 'D') // 비버의 굴
            {
                dot_y = i;
                dot_x = j;
            }
            else if (d[i][j] == 'S') // 비버의 위치
            {
                _y = i;
                _x = j;
            }
        }
    }
    
    water_bfs();
//    print_water_map();
    int cn = bfs_beaber();
//    print_b();
    if (cn == -1)
    {
        cout << "KAKTUS\n";
    }
    else{
        cout << cn << '\n';
    }
    
}
