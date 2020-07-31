#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int a, b;

vector<int> vec[1001];
bool c[1001];

void go(int index)
{

    for (int i = 0; i < vec[index].size(); i++)
    {
        if(!c[vec[index][i]])
        {
            c[vec[index][i]] = true;
            go(vec[index][i]);
        }
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    int ret = 0;
    
    for (int i = 1; i <= n; i++)
    {
        
        
        if (!c[i])
        {
            ret++;
            c[i] = true;
            go(i);
        }
    }
    
    cout << ret << "\n";
    
}
