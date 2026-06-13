#include <bits/stdc++.h>
using namespace std;

int a[101][101], vs[101], n;

void DFS(int u)
{
    vs[u] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vs[i] && a[u][i])
        {
            DFS(i);
        }
    }
}

int DTPLT(int skip)
{
    memset(vs, 0, sizeof(vs));
    if (skip >= 1 && skip <= n)
    {
        vs[skip] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vs[i])
        {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    memset(vs, 0, sizeof(vs));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int org = DTPLT(0);
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        int now = DTPLT(i);
        if (now > org)
        {
            res.push_back(i);
        }
    }
    cout << res.size() << "\n";
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << "\n";
}