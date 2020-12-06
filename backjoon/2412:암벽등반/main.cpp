#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string.h>

using namespace std;

vector<pair<int, int>> v;
vector<int> vec;
int main()
{
    int n,T;
    cin >> n >> T;
    
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        v.push_back({a, b});
        vec.push_back(a);
    }
    
    sort(vec.begin(), vec.end());
    sort(v.begin(), v.end());

    queue<pair<pair<int,int>,int>> q;
    
    vector<bool> check(v.size() + 1);
    
    q.push({{0,0}, 0});


    while(!q.empty())
    {
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int cnt = q.front().second;

        q.pop();

        if (cur_y >= T)
        {
            cout << cnt << "\n";
            return 0;
        }
        
        int idx_min2 = (int)(lower_bound(vec.begin(), vec.end(), cur_x - 2) - vec.begin());
        int idx_max2 = (int)(upper_bound(vec.begin(), vec.end(), cur_x + 2) - vec.begin());
        
        
        for (int i = idx_min2; i <= idx_max2; i++)
        {
            if (abs(v[i].first - cur_x) > 2)
                break;
            if (!check[i] && (abs(v[i].first - cur_x) <= 2) && (abs(v[i].second - cur_y) <= 2))
            {
                check[i] = true;
                q.push({{v[i].first, v[i].second}, cnt + 1});
            }
            
        }
        
    }

    cout << "-1\n";
}
