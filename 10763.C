#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int origin[500001];
int target[500001];

int main()
{
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d", &origin[i], &target[i]);
		if (n%2)
		{
			printf("NO\n");
			continue;
		}
		sort(origin, origin+n);
		sort(target, target+n);
		int yes = 1;
		for (int i = 0; i < n; i++)
		{
			if (origin[i] != target[i])
				yes = 0;
		}

		if (yes)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}