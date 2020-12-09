#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string.h>
#include<map>
using namespace std;
map<int, int> m;
map<int, int> q;
int n,k,c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> n >> c>> k;

    for (int i = 0; i < n ; i++)
    {
        int a,b;
        cin >> a >> b;

        if (m.find(a) == m.end())
        {
            m[a] = b;
            q[-a] = b;
        }
    }

    for (int i = 0; i < c; i++)
    {
        int h, key, value;
        cin >> h;

        if (h == 1)
        {
            cin >> key >> value;
            m[key] = value;
            q[-key] = value;
        }
        else if (h == 2)
        {
            cin >> key >> value;
            if (key == 0)
            {
                m[m.lower_bound(0)->first] = value;
                q[-1 * m.lower_bound(0)->first] = value;
                continue;
            }
            if (m.find(key) != m.end())
            {
                m[key] = value;
                continue;
            }
            
    
            auto right_lower = m.lower_bound(key);
            auto left_lower = q.lower_bound(-key);
            
            
            int r_diff = right_lower-> first - key;
            int l_diff = left_lower -> first * -1;
            l_diff = key - l_diff;
            r_diff = abs(r_diff);
            l_diff = abs(l_diff);

            if (r_diff == l_diff)
                continue;
            
            if (r_diff < l_diff && r_diff <= k)
            {
                m[right_lower-> first] = value;
                q[right_lower->first *-1] = value;
            }
            else if (l_diff < r_diff && l_diff <= k)
            {
                m[left_lower->first * -1] = value;
                q[left_lower->first] = value;
            }
            else if (r_diff < l_diff && r_diff >= k && l_diff <= k)
            {
                m[right_lower-> first] = value;
                q[right_lower->first *-1] = value;
            }
            else if (l_diff < r_diff && l_diff >= k && r_diff <= k)
            {
                m[left_lower->first * -1] = value;
                q[left_lower->first] = value;
            }

            
        }
        else
        {
            cin >> key;
            if (key == 0)
            {
                cout << m[m.lower_bound(0)->first] << '\n';
            
                continue;
            }
            if (m.find(key) != m.end())
            {
                cout << m[key] << "\n";
                continue;
            }
            
            auto right_lower = m.lower_bound(key);
            auto left_lower = q.lower_bound(-key);
            
            
            int r_diff = right_lower-> first - key;
            int l_diff = left_lower -> first * -1;
            l_diff = key - l_diff;
            r_diff = abs(r_diff);
            l_diff = abs(l_diff);

            if (abs(r_diff) == abs(l_diff))
            {
                cout << "?\n";
                continue;
            }
            
            if (r_diff < l_diff && r_diff <= k)
            {
                cout << m[right_lower-> first] << "\n";
            }
            else if (l_diff < r_diff && l_diff <= k)
            {
                cout << q[left_lower->first] << "\n";
            }
            else if (r_diff < l_diff && r_diff >= k && l_diff <= k)
            {
                cout << q[left_lower->first] << "\n";
            }
            else if (l_diff < r_diff && l_diff >= k && r_diff <= k)
            {
                cout << m[right_lower-> first] << "\n";
            }
            else
            {
                cout << -1 << "\n";
                continue;
            }
            

        }


    }
}
