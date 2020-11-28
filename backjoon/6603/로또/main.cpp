#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string.h>

using namespace std;

vector<int> lotto;

void solve(vector<int> & a, int index, int cnt)
{
    if (cnt == 6)
    {
        for (int i = 0; i < lotto.size(); i++)
        {
            cout << lotto[i] << " ";
        }
        cout << "\n";
        return ;
    }
    
    if (index == a.size())
        return ;
    
    lotto.push_back(a[index]);
    solve(a, index + 1, cnt + 1);
    lotto.pop_back();
    solve(a, index + 1, cnt);
}

int main()
{
    while(true)
    {
        int n;
        cin >> n;
        
        if (n == 0)
            break;
        
        vector<int> vec(n);
        
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        
        solve(vec, 0, 0);
        
    }
    
}
