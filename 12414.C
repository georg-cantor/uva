#include <cstdio>
#include <cstring>

using namespace std;

char ins[15];
int init[100];

void convert(int ST)
{
	int temp = 0;
	int st;
	memset(init, -1, sizeof(init));
	for (int i = 0; i < strlen(ins); i++)
	{
		char tt[10] = {'\0'};
		int  ss = 0;
		st = ST + (ins[i]-'A');
		while (st)
		{
			tt[ss++] = st%10 + '0';
			st = st/10;
		}
		for (int j = ss-1; j >=0; j--)
		{
			init[temp++]=tt[j] - '0';
		}
	}

	for (int i = 0; i < temp - 3; i++)
	{
		for (int j = 0; j <temp; j++)
			init[j] = (init[j]+init[j+1])%10;
		init[temp-1-i] = -1;
	}
}

int main()
{
	while (scanf("%s", ins))
	{
		int seed;
		int yes = 0;
		for (seed = 1; seed <= 10000; seed++)
		{
			convert(seed);
			if (init[0] == 1 && init[1] == 0 && init[2] == 0)
			{
				yes = 1;
				break;
			}
		}
		if (yes)
			printf("%d", seed);
		else
			printf(":(");
		printf("\n");
	}
	return 0;
}