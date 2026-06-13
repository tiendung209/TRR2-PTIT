#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int a[105][105];
int vs[105];
int n, s, t;

struct Edge
{
    int u;
    int v;
};

vector<Edge> T;

void TreeDFS(int u)
{
    vs[u] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (vs[i] == 0 && a[u][i] == 1)
        {
            Edge e;
            if (u < i)
            {
                e.u = u;
                e.v = i;
            }
            else
            {
                e.u = i;
                e.v = u;
            }
            T.push_back(e);
            TreeDFS(i);
        }
    }
}

void TreeBFS(int start)
{
    queue<int> q;
    vs[start] = 1; // Danh dau dinh bat dau da duoc tham
    q.push(start); // Dua dinh bat dau vao hang doi

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            // Neu co canh noi tu u den i va i chua duoc tham
            if (a[u][i] == 1 && vs[i] == 0)
            {
                vs[i] = 1;
                Edge e;
                // Luu dinh nho hon truoc, dinh lon hon sau
                if (u < i)
                {
                    e.u = u;
                    e.v = i;
                }
                else
                {
                    e.u = i;
                    e.v = u;
                }
                T.push_back(e);
                q.push(i);
            }
        }
    }
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> t >> n >> s))
        return 0;

    memset(vs, 0, sizeof(vs));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    if (t == 1)
    {
        TreeDFS(s);
    }
    else if (t == 2)
    {
        TreeBFS(s);
    }

    // Kiem tra xem co tim duoc cay khung hay khong
    if (T.size() == n - 1)
    {
        cout << n - 1 << "\n";
        for (int i = 0; i < T.size(); i++)
        {
            cout << T[i].u << " " << T[i].v << "\n";
        }
    }
    else
    {
        cout << 0 << "\n";
    }
    return 0;
}