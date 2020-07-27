// https://www.acmicpc.net/problem/1759
// 암호 만들기
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int n,m;
int sum = 0;
vector<char> vec;
char arr[20];
bool check[26];

bool isMo(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    else
        return false;
}

void solve(int len, char arr[], int goal, int start)
{
    
    if(len == goal)
    {
        int mo, ja;
        mo = ja = 0;
        
        for (int i = 0; i < len; i++)
        {
            if(isMo(arr[i]))
                mo++;
            else
                ja++;
        }
        
        if(mo >= 1 && ja >= 2)
        {
            
            for(int i = 0; i < len; i++)
            {
                cout << arr[i];
            }
            cout << "\n";
        }
        
        return ;
    }
    
    for (int i = start; i < vec.size(); i++)
    {
        if(check[vec[i] - 'a']) continue;
        check[vec[i] - 'a'] = true;
        arr[len] = vec[i];
        solve(len + 1, arr, goal, i + 1);
        check[vec[i] - 'a'] = false;
    }

}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        char temp;
        cin >> temp;
        vec.push_back(temp);
    }
    
    sort(vec.begin(), vec.end());
    
    solve(0, arr, n, 0);
}
