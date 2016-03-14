#include <iostream>
#include <math.h>

using namespace std;
inline long double PowerSum(int, int, int);
void printf(long double, int);
int main()
{
	int l, h, k, n = 1;
	while (true)
	{
		cin >> l;
		if (l == -1) break;
		cin >> h >> k;
		printf(PowerSum(l, h, k), n);
		++n;
	}
	return 0;
}

long double PowerSum(int l, int h, int k)
{
	long double sum = 0;
	while (l <= h)
	{
		sum += pow(l, k);
		++l;
	}
	return sum;
}

void printf(long double ans, int tr)
{
	int n = 0 ;
	//DIVIDE AND CONQUER (FASTEST ALIVE)
	while(ans >= 1)
	{
		if (ans >= 10000) {
			if (ans >= 10000000) {
				if (ans >= 100000000) {
					if (ans >= 1000000000) {
						n += 10;
						ans /= 10000000000;
						continue;
					}
					n += 9;
					ans /= 1000000000;
					continue;
				}
				n += 8;
				ans /= 100000000;
				continue;
			}
			if (ans >= 100000) {
				if (ans >= 1000000) {
					n += 7;
					ans /= 10000000;
					continue;
				}
				n += 6;
				ans /= 1000000;
				continue;
			}
			n += 5;
			ans /= 100000;
			continue;
		}
		if (ans >= 100) {
			if (ans >= 1000) {
				n += 4;
				ans /= 10000;
				continue;
			}
			n += 3;
			ans /= 1000;
			continue;
		}
		if (ans >= 10) {
			n += 2;
			ans /= 100;
			continue;
		}
		n += 1;
		ans /= 10;
	}
	printf("Case %04d: %.6lfe%010d\n", tr, ans, n);
}
