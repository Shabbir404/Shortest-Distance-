#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e, q;
    cin >> n >> e;
    long long adjM[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adjM[i][j] = 0;

            else
                adjM[i][j] = LLONG_MAX;
        }
    }

    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        adjM[a][b] = min(adjM[a][b], c);
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adjM[i][k] != LLONG_MAX && adjM[k][j] != LLONG_MAX && adjM[i][k] + adjM[k][j] < adjM[i][j])
                {
                    adjM[i][j] = adjM[i][k] + adjM[k][j];
                }
            }
        }
    }
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        s--;
        d--;
        if (adjM[s][d] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adjM[s][d] << endl;
    }

    return 0;
}
