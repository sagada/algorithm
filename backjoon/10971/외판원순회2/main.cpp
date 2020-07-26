// https://www.acmicpc.net/problem/10971
// 외판원 순회2

#define MAX 999999999

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[11][11];
int n;
vector<int> v;

int main(int argc, const char * argv[]) {
    
    cin >> n;
        
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
        
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
        
    }
    
    int ret = MAX;
    int sum = 0;
    do
    {
        
        sum = 0;
        bool test = true;
        
        for (int idx = 0; idx < v.size() - 1; idx++)
        {
            if(map[v[idx]][v[idx + 1]] == 0) test = false;
            sum += map[v[idx]][v[idx + 1]];
        }
        
        if(test && map[v[v.size() - 1]][v[0]] != 0)
        {
            sum += map[v[v.size() - 1]][v[0]];
            ret = min(ret, sum);
        }
        
    }
    while(next_permutation(v.begin(), v.end()));
    
    
    cout << ret << "\n";
    
}
