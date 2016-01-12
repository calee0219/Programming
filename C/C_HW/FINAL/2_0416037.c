#include <stdio.h>

struct matrix {int a, b, c, d};
int F(int n);
struct matrix pow(struct matrix M, int n);
struct matrix mul(struct matrix m1, struct matrix m2);

int main(void)
{
    int n;
	for (n=0;n<=16;n++) printf("%u ",F(n));
	printf("\n");
}

int F(int n)
{
    struct matrix M;
    M.a = 0; M.b = 1; M.c = 1; M.d = 1;
	M = pow(M, n);
	return M.b;
}

struct matrix pow(struct matrix M, int n)
{
	if(n == 0)
    {
        struct matrix tmp;
        tmp.a = 1; tmp.b = 0; tmp.c = 0; tmp.d = 1;
        return tmp;
    }
    if(n & 1)
        return mul(M, pow(M, n-1));
    else
        return pow(mul(M, M), n/2);
}

struct matrix mul(struct matrix m1, struct matrix m2)
{
	struct matrix ans;
	ans.a = m1.a * m2.a + m1.b * m2.c;
	ans.b = m1.a * m2.b + m1.b * m2.d;
	ans.c = m1.c * m2.a + m1.d * m2.c;
	ans.d = m1.c * m2.b + m1.d * m2.d;
	return ans;
}
