#include <cstdio>
#include <cmath>

int main()
{
	int l, h, k = 0, n = 1, pw;
	double sum = 0, pwmax;

	while(true)
	{
		scanf("%d %d %d", &l, &h, &k);
		if (l == -1) break;
		pwmax = k * log10(double(h));
		pw = pwmax;
		sum = pow(10.0, pwmax - pw);

		while (l < h)
		{
			sum += pow(10.0, k * log10(double(l)) - pw);
			++l;
		}

		while (sum >= 1) {
			sum /= 10;
			pw++;
		}

		if (h == 0) {
			sum = 0;
			pw = 1;
		}

		printf("Case %04d: %.6lfe%010d\n", n, sum, pw);
		++n;
	}
	return 0;
}
