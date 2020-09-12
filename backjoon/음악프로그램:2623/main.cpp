#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int ind[1001];
vector<int> vec[1001];
bool check[1001];
int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int cnt;
        cin >> cnt;
        
        vector<int> temp;
        
        for (int j = 0; j < cnt; j++)
        {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        
        for (int j = 0; j < cnt - 1; j++)
        {
            vec[temp[j]].push_back(temp[j + 1]);
            ind[temp[j + 1]]++;
        }
    }
    
    queue<int> q;
    
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ret;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        check[cur] = true;
        
        ret.push_back(cur);
        
        for (int next : vec[cur])
        {
            ind[next] --;
            if (ind[next] == 0)
            {
                q.push(next);
            }
        }
    }
    
    bool test =false;
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            test = true;
        }
    }
    
    if (test)
    {
        cout << "0\n";
    }
    else{
        for (int i =0 ;i<ret.size(); i++)
        {cout <<ret[i] << "\n";}
    }
}
