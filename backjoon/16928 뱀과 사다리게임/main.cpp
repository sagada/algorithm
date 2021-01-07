#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include <sstream>
#include<set>
#include<string.h>
using namespace std;
int n,m;
int t;
int nexta[101];
int  dist[101];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <=100;i++)
    {
        dist[i] = -1;
        nexta[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        nexta[x] = y;
    }
    
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        nexta[x] = y;
    }
    
    queue<int> q;
    q.push(1);
    
    dist[1] = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (int i = 1; i <= 6; i++)
        {
            int ne = i + cur;
            if (ne > 100) continue;
            
            ne = nexta[ne];
            if (dist[ne] == -1)
            {
                q.push(ne);
                dist[ne] = dist[cur] + 1;
            }
        }
    }
    
    cout << dist[100] << '\n';
}

