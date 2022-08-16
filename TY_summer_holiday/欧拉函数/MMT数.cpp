#include <cstdio>
#include <cstdlib>

using namespace std;

int phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        return ans / n * (n - 1);
    return ans;
}

int main()
{
    int n;

    scanf("%d", &n);

    int ans = n - phi(n);
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (i * i != n)
                ans -= 2;
            else
                --ans;
        }
    }
    printf("%d", ans - 1);
    // system("pause");
    return 0;
}