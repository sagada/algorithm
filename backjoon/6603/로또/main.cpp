// https://www.acmicpc.net/problem/6603
// 로또
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int arr[10];
bool check[51];

void solve(int index, vector<int> & vec, int n, int k, int start)
{
    if(index == k)
    {
        for (int i = 0; i < k; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return ;
    }
    
    for (int i = start; i < vec.size(); i++)
    {
        if(check[vec[i]]) continue;
        arr[index] = vec[i];
        check[vec[i]] = true;
        solve(index + 1, vec, n, k, i + 1);
        check[vec[i]] = false;
    }
    
}

int main(int argc, const char * argv[]) {

    while(true)
    {
        cin >> n;
        
        if(n == 0)
            break;
        
        vector<int> a(n);
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        solve(0, a, n, 6, 0);
        cout << "\n";
    }
    

    
}
