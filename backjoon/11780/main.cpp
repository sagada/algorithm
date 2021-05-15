#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int dist[101][101];
int nextArr[101][101];
const int inf = 99999999;

void path(int from, int to)
{
    
    if (nextArr[from][to] == -1)
    {
        cout << "0\n";
        return ;
    }
    
    queue<int> q;
    q.push(from);
    
    while(from != to)
    {
        from = nextArr[from][to];
       
        q.push(from);
    }
    
    cout << q.size() << " ";
   
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    
}

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = inf;
            nextArr[i][j] = -1;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (dist[a][b] > c)
        {
            dist[a][b] = c;
            nextArr[a][b] = b;
        }
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nextArr[i][j] = nextArr[i][k];
                }
            }
        }
    }
//    cout << "Next 출력\n\n\n";
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            cout << nextArr[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "Next 출력\n\n\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == inf || i == j)
            {
                cout << "0\n";
            }
            else
            {
                path(i, j);
            }
        }
    }
    
}


