#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int n;

int p[20];
int t[20];

int ret = 0;

void go(int day, int sum)
{
    if (day == n + 1) // 퇴사 할 수 있으면
    {
        ret = max(ret, sum);
        return ;
    }
    
    if(day > n + 1)
        return;
    
    // 상담 안한 경우, 상담 한경우
    go(day + 1, sum);
    go(day + t[day], sum + p[day]);

}


int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }
    
    go(1, 0);
    
    cout << ret << "\n";
}
