#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int n, m;

vector<pair<int,int>> war; // 전쟁
vector<pair<int,int>> uni; // 동맹

int size[1000001];
int link[1000001];

int find(int x)
{
    while(x != link[x]) x = link[x];
    return x;
}

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void unite(int a, int b, int op)
{
    a = find(a);
    b = find(b);
    
    if(a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        
        link[b] = a;
        
        if (op == 1)
        {
            size[a] += size[b];
        }
        else
        {
            size[a] -= size[b];
        }
        
        size[b] = 0;
    }
        
}

int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        // union find initialize
        
        link[i] = i;
        
        int temp;
        cin >> temp;
        size[i] = temp;
    }
    
    for (int i = 0; i < m; i++)
    {
        int o,p,q;
        
        cin >> o >> p >> q;
        
        if (o == 1)
        {
            unite(p, q, 1);
        }
        else
        {
            unite(p, q, 2);
        }
    }
    
    
    
    
    vector<int> vec;
    
    for (int i = 1; i <= n; i++)
    {
        if(size[i] > 0)
            vec.push_back(size[i]);
    }
    
    cout << vec.size() << "\n";
    
    sort(vec.begin(), vec.end());
    
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    
    cout << "\n";
    
}
