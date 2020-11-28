#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string.h>

using namespace std;

int n, s;

vector<int> v;

int cnt = 0;

void go(int index, int sum)
{
    if (index == n)
    {
        if (sum == s)
            cnt++;
        
        return ;
    }
    
    go(index + 1, sum + v[index]);
    go(index + 1, sum);
}

int main()
{
    cin >> n >> s;
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    go(0, 0);
    if (s == 0) cnt -= 1;
    cout << cnt << "\n";
}
