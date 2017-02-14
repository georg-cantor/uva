#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> remain;
vector<int> discard;

void operate()
{
	discard.push_back(remain.back());
	remain.pop_back();
	remain.insert(remain.begin(), remain.back());
	remain.pop_back();
}

int main()
{
	int n;
	while (cin>>n)
	{
		remain.clear();
		discard.clear();
		vector<int>::iterator iter;
		if (n == 0)
			break;
		if (n == 1)
		{
			printf("Discarded cards:\n");
			printf("Remaining card: 1\n");
			continue;
		}
		for (int i = n; i > 0; i--)
			remain.push_back(i);
		for (int i = 0; i < n-1; i++)
			operate();
		printf("Discarded cards: ");
		for (iter = discard.begin(); iter != discard.end() -1; iter++)
			printf("%d, ", *iter);
		printf("%d\n", *iter);
		printf("Remaining card: %d\n", remain.front());
	}
	return 0;
}