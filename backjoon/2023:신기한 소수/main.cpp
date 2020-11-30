#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string.h>

using namespace std;

int n;
bool isPrime(int c)
{
    if (c < 2)
        return false;
    
    int cn = sqrt(c);
    for (int i = 2; i <= cn; i++)
    {
        if (c % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

void dfs(int cur, int index)
{
    if (index == n)
    {
        cout << cur << '\n';
        return ;
    }
     
    for (int i = 1; i <= 9; i++)
    {
        int next = cur * 10;
        next += i;
        
        if (isPrime(next))
        {
            dfs(next, index + 1);
        }
    }
}
int main()
{
    cin >> n;
    
    dfs(0, 0);
    
}
