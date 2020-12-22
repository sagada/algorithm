#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include <sstream>
using namespace std;
int d[51][51];
int ct[51];
int main()
{
    int n,m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        string str;
        cin >> str;
        
        for (int j = 0; j < str.size(); j++)
        {
            
            if (str[j] - '0' == 0)
            {
                count++;
                
            }
            
            d[i][j] = str[j] - '0';
        }
        
        ct[i] = count;
    }

    int k;
    cin >> k;
    
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        int eqaulNum = 1; // 자신 포함
        
        if (ct[i] <= k && ( (k - ct[i]) % 2 == 0))
        {
            
            for (int t = 0; t < n; t++)
            {
                if (t == i)
                    continue;
                
                if (!(ct[t] <= k && ( (k - ct[t]) % 2 == 0)))
                {
                    continue;
                }
                
                bool equalTest = false;
                
                for (int z = 0; z < m; z++)
                {
                    if (d[i][z] != d[t][z])
                    {
                        equalTest = true;
                        break;
                    }
                }
                
                if (!equalTest)
                {
                    eqaulNum++;
                }
            }
        }
        else
        {
            continue;
        }
        
        
        ans = max(ans, eqaulNum);
    }
    
    cout << ans << "\n";
}
