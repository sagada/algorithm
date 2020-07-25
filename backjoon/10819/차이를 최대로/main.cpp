// https://www.acmicpc.net/problem/10819
// 차이를 최대로
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int temp;


int calc(vector<int>& vec)
{
    int sum = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        sum += abs(vec[i] - vec[i - 1]);
    }
   
    return sum;
}
int main(int argc, const char * argv[])
{
    
    int ret = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end()); // 첫 순열을 구하기 위해서 정렬
    
    do
    {
        int cnt = calc(a);
        ret = max(cnt, ret);
        
    }while (next_permutation(a.begin(), a.end()));
        
    cout << ret << "\n";
}
