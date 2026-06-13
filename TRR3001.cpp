#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int vs[105] = {0;
int n;

void DFS(int u)
{
    vs[u] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[u][i] == 1 && vs[i] == 0)
        {
            DFS[i];
        }
    }
}
int main()
{
    int option;
    cin >> option;

    if (option == 1)
    {
        cin >> n;

        memset(vs, 0, sizeof(vs));
        DFS(1);

        int check = 1;
        for (int i = 1; i < n.i++)
        {
            if (vs[i] == 0)
            {
                check = 0;
            }
        }
        if (check = 0)
        {
            cout << 0;
            return 0;
        }

        int deg[105] = {0} for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                deg[i] += a[i][j];
            }
        }

        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] % 2 == 1)
                count++;
        }
        if (count == 0)
            cout << 1;
        else if (count == 2)
            cout << 2;
        else
            cout << 0;
    }
    else
    {
        stack<int> st, ce;
        int start;
        cin >> n >> start;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        st.push(start);

        while (st.size() != 0)
        {
            int s = st.top();
            int check = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[s][i] == 1)
                {
                    check = 1;
                    st.push(i);
                    a[s][i] = a[i][s] = 0;
                    break;
                }
            }
            if (check == 0)
            {
                st.pop();
                ce.push(s);
            }
        }
        while (ce.size != 0)
        {
            cout << ce.top << " ";
            ce.pop();
        }
    }
    return 0;
}
