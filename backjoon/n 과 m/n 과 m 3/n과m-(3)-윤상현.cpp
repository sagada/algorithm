#include<iostream>
#include<vector>

using namespace std;

int a,b;
int s[11];
bool c[11];

void go(int index, int arr[], int n,  int k)
{
    if(index == k)
    {
        for (int i = 0; i < k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        
        return;
    }
    
    for(int i = 1; i <= n; i++)
    {
//        if(c[i]) continue;
//        c[i] = true;
        s[index] = i;
        go(index + 1, arr, n, k);
//        c[i] = false;
    }
}

int main()
{
    cin >> a >> b;
    
    go(0, s, a, b);
}
