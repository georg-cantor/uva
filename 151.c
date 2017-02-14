#include <stdio.h>
#include <string.h>
#define maxn 105

int light[maxn];

int serial(int n, int m)
{
    int start = 1;
    for (int i = 1; i <= n; i++)
          {
        light[start] = i;
        int j1=1, j2 = 1;
        do
                    {
            if(light[(start+j2++)%n]==0)
                j1++;
        } while (j1<m);
        start = (start + j2) % n;
           }
    light[n] = light[0];
    for (int i = 1; i < n; i++)
    {
        printf("%d ", light[i]);
    }
    printf("%d\n", light[n]);
}

int main(int argc, char** argv)
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
	    memset(light, 0, sizeof(light));
	    serial(N, 5);
	    serial(N, 7);
	}
	return 0;
}
