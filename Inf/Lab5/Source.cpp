#include <iostream>
#include <vector>
#define MAXM 99
#define MAXP 99
#define MAXN 19999
using namespace std;

struct result {
	short n;
	short m;
	short p;
};

int main()
{
	unsigned long  areas;
	int Case = 1;
	unsigned long Max = MAXN*(MAXN - 1) + 2 * MAXM*(MAXM - 1) + 3 * MAXP*(MAXP - 1) + 4 * MAXM*MAXN + 6 * MAXN*MAXP + 6 * MAXM*MAXP;
	cin >> areas;
	while (areas != -1)
	{
		result vResult[50] = { 0,0,0 };
		if (areas == 1)
			cout << "Case " << Case++ << ':' << endl << "0 0 0" << endl;
		else if (areas == 2)
			cout << "Case " << Case++ << ':' << endl << "0 0 1" << endl << "0 1 0" << endl << "1 0 0" << endl;
		else if (areas > Max || areas == 0)
			cout << "Case " << Case++ << ':' << endl << "Impossible." << endl;
		else
		{
			areas = areas - 2;
			int Counter = 0;
			bool FindResult = false;
			for (int p = 0; p <= MAXP; ++p)
			{
				int FirstPart = 3 * p*(p - 1);
				if (FirstPart == areas)
				{
					
					vResult[Counter].p = p;
					++Counter;
					FindResult = true;
					break;
				}
				for (int m = 0; m <= MAXM; ++m)
				{
					int SecondPart = FirstPart + 2 * m*(m - 1) + 6 * m*p;
					if (SecondPart == areas)
					{
						vResult[Counter].m = m;
						vResult[Counter].p = p;
						++Counter;
						FindResult = true;
						break;
					}
					int MinNCount = 1, MaxNCount = MAXN;
					while (MaxNCount >= MinNCount)
					{
						int NCount = ((MinNCount + MaxNCount) / 2);
						long Condition = NCount *(NCount - 1) + 4 * m*NCount + 6 * NCount*p + SecondPart;
						if (Condition < areas)
							MinNCount = NCount + 1;
						else if (Condition > areas)
							MaxNCount = NCount - 1;
						else
						{							
							vResult[Counter].n = NCount;
							vResult[Counter].m = m;
							vResult[Counter].p = p;
							++Counter;
							FindResult = true;
							break;
						}
					}
				}
			}
			for (int i = 0; i < Counter; ++i)
			{
				int j;
				result temp = vResult[i];
				for (j = i - 1; j >= 0 && vResult[j].n + vResult[j].m * MAXN + 1 > temp.n + temp.m * MAXN + 1; --j)
					vResult[j + 1] = vResult[j];
				vResult[j + 1] = temp;
			}
			cout << "Case " << Case++ << ":" << endl;
			for (int i = 0; i <= Counter; ++i)
			{
				if (!FindResult)
					cout << "Impossible." << endl;
				else if (vResult[i].m == 0 && vResult[i].n == 0 && vResult[i].p == 0)
					break;
				else
					cout << vResult[i].m << " " << vResult[i].n << " " << vResult[i].p << endl;
			}
		}
		cin >> areas;
	}
	return 0;
}
