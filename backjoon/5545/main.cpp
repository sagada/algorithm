#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a, b;
    
    cin >> a>> b;
    
    int c;
    cin >> c;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int cal = c;
    
    
    int cost = a;
    int bef = c / cost;
    for (int i = 0 ; i < n; i++)
    {
        int cost = a + (b * (i + 1));
        cal += v[i];
        
        int val = cal / cost;
        
        if (bef > val)
        {
            cout << bef << '\n';
            break;
        }
        else
        {
            bef = val;
        }
    }
    
    
}
