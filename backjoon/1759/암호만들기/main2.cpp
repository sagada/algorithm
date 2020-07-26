// https://www.acmicpc.net/problem/1759
// 암호 만들기
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int n,m;


bool check(string &password)
{
    int ja = 0;
    int mo = 0;
    
    for (char x : password)
    {
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            mo++;
        else
            ja++;
    }
    
    return ja >= 2 && mo >= 1;
}

void go(int len, vector<char> &arr, string password, int i)
{
    if(len == password.length())
    {
        if(check(password))
            cout << password << "\n";
        
        return ;
    }
    
    if(i == arr.size()) return;
    go(len, arr, password + arr[i], i + 1);
    go(len, arr, password, i + 1);
}

int main()
{
    cin >> n >> m;
    vector<char> vec(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vec[i];
    }
    
    sort(vec.begin(), vec.end());
    
    go(n, vec, "", 0);
}
