#include <cstdio>
#include <cstring>

using namespace std;

int print[105];

int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		memset(print, 0, sizeof(print));
		int serial, focus, last = 0, bigger = 0, equal = 0;
		scanf("%d%d", &serial, &focus);
		for (int i = 0; i < serial; i++)
			scanf("%d", &print[i]);
		for (int i = 0; i< serial; i++)
		{
			if (print[i] > print[focus])
			{
				bigger++;
				print[i] = 0;
				last = i;
			}
		}
		last = (last+1)%serial;

		while (last%serial != focus && print[last%serial]==print[focus])
		{
			equal++;
			last++;
		}
		printf("%d\n", bigger+equal+1);
	}
	return 0;
}