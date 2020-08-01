#include<iostream>
#include<vector>

using namespace std;

int n;
int size[10];
int link[10];

int find(int x)
{
    while(x != link[x]) x= link[x];
    return x;
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

int find_x(int x) // 경로 압축
{
    if (x == link[x]) return x;
    return link[x] = find_x(link[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if (size[a] < size[b])
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    size[a] += size[b];
    link[b] = a;
}

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        link[i] = i;
        size[i] = 1;
    }
    
    
}
