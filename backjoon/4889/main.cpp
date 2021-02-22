#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

int main()
{
    string str;
    int n = 1;
    while(cin >> str)
    {
        
        if (str[0] == '-')
            break;
    
        stack<char> st;
        int cnt = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '}')
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    st.push('}');
                }
            }
            else{
                st.push(str[i]);
            }
        }
        
        while(!st.empty())
        {
            char t1 = st.top();
            st.pop();
            char t2 = st.top();
            st.pop();
            
            if (t1 == t2)
                cnt++;
            
            else cnt +=2;
        }
        cout << n++ << ". " << cnt << '\n';
    }
}
