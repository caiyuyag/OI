#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 1e5 + 10;

int prime[N], phi[N];
bool is_prime[1000010];

void euler(int n)
{
    is_prime[1] = true;
    phi[1] = 1;
    int cnt = 0;

    for (size_t i = 2; i <= n; ++i)
    {
        if (!is_prime[i])
        {
            prime[++cnt] = i;
            phi[i] = i - 1;
        }
        for (size_t j = 1; j <= cnt && prime[j] * i <= n; ++j)
        {
            is_prime[i * prime[j]] = true;
            
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
    int n, ans = 3;

    scanf("%d", &n);

    if (n == 1)
    {
        puts("0");
        return 0;
    }

    euler(n);
    for (size_t i = 2; i < n; ++i)
        ans += phi[i] * 2;
    
    printf("%d", ans);

    system("pause");
    return 0;
}