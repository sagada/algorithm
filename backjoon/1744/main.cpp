#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> m;
    vector<int> p;
    
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        
        if (temp == 1)
        {
            one += 1;
        }
        else if (temp == 0)
        {
            zero += 1;
        }
        else
        {
            if (temp > 0)
            {
                p.push_back(temp);
            }
            else{
                m.push_back(temp);
            }
        }
    }
    
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
   
    
    sort(m.begin(), m.end());
    
    if (p.size() % 2 == 1)
    {
        p.push_back(1);
    }
    
    if (m.size() % 2 == 1)
    {
        if (zero > 0)
        {
            m.push_back(0);
        }
        else{
            m.push_back(1);
        }
    }
    
    int ans = one;
    for (int i = 0; i < p.size(); i+=2)
    {
        ans += p[i] * p[i+1];
    }
    
    for (int i = 0; i < m.size(); i += 2)
    {
        ans += m[i] * m[i+1];
    }
    cout << ans << '\n';
}
