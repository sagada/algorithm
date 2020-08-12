#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v[10]; // 결과 저장
bool c[10001]; // 사용 했으면 true

vector<int> vec;
int n,m;
// index 번째를 채운다.
void go(int index, int n, int m, int start)
{
    if(index == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        
        return;
    }
    
    for (int i = start; i < vec.size(); i++)
    {
        if(c[vec[i]]) continue;
        c[vec[i]] = true;
        v[index] = vec[i];
        go(index + 1, n, m, i + 1);
        c[vec[i]] = false;
    }
}


int main(int argc, const char * argv[])
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    
    go(0, n, m, 0);
}
