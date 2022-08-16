#include <cstdio>

using namespace std;

const int N = 1e6 + 10;
const int N_10 = 1e6;

int prime[N], phi[N], vis[N];

void euler()
{
    int cnt = 0;
    for (int i = 2; i <= N_10; ++i)
    {
        if (!vis[N])
        {
            prime[++cnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 2; i * prime[j] <= N && j <= cnt; ++j)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j])
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            else
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}

int main()
{
    euler();
    int n;

    scanf("%d", &n);

    long long ans = n - phi[n];
    for (int i = 1; i <= n; ++i)
    {
        if (!(n % i))
        {
            if (i * i != n)
                ans -= 2;
            else
                --ans;
        }
    }
    printf("%lld", ans - 1);
    return 0;
}