#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
vector<int> vec[100001];
queue<int> q;
bool d[100001];
int order[100001];
int parent[100001];

void bfs(int x, int m)
{
    q.push(x);
    d[x] = true;
    
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        int cnt = 0;
        
        for (int r : vec[cur])
        {
            if (!d[r])
            {
                cnt++;
                parent[r] = cur;
            }
        }
        
        for (int i = 0; i < cnt; i++)
        {
            if(m + i >= n || parent[order[m + i]] != cur)
            {
                cout << "0\n";
                return;
            }
            
            q.push(order[m + i]);
            d[order[m + i]] = true;
        }
        m += cnt;
        
    }
    
    cout << "1\n";
    return ;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
    }
    
    bfs(1, 1);
    
}
