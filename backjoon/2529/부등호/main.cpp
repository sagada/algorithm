#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
bool c[11];
vector<char> vec;
vector<string> result;
bool good(char x, char y, char op)
{
    if(op == '<')
    {
        if(x > y) return false;
    }
    
    if(op == '>')
    {
        if(x < y) return false;
    }
    
    return true;
}

void go(int index, string num)
{
    if (index == n + 1)
    {
        result.push_back(num);
        return;
    }
    
    for (int i = 0; i < 10; i++)
    {
        if (c[i]) continue;
        
        if(index == 0 || good(num[index-1], i + '0', vec[index - 1]))
        {
            c[i] = true;
            go(index + 1, num + to_string(i));
            c[i] = false;
        }
        
        
    }
}

int main()
{
    cin >> n;

    char temp;
    
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        vec.push_back(temp);
    }

    go(0, "");
    
    sort(result.begin(), result.end());
    
    cout << result[result.size()-1] << "\n";
    cout << result[0] << "\n";
    
}
