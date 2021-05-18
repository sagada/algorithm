#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int dist[201][201];
int nextArr[201][201];

const int inf = 99999999;

int main()
{
    int n, m;
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = inf;
            nextArr[i][j] = -1;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        dist[a][b] = c;
        dist[b][a] = c;
        nextArr[a][b] = b;
        nextArr[b][a] = a;
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
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == inf)
            {
                cout << "- ";
            }
            else if (i == j)
            {
                cout << "- ";
            }
            else
            {
                cout << nextArr[i][j] << " ";
            }
        }
        cout << "\n";
    }
}


