#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 1024

int t[MAX];

void shifttable(char p[])
{
	int i, j, m = strlen(p);
	for (i = 0; i < MAX; i++)
		t[i] = m;
	for (j = 0; j < m - 1; j++)
		t[p[j]] = m - 1 - j;
}

int horspool(char src[], char p[])
{
	int i, j, m, n;
	n = strlen(src);
	m = strlen(p);
	printf("\nLength of text = %d", n);
	printf("\nLength of pattern = %d", m);
	i = m - 1;
	while (i < n)
	{
		j = 0;
		while ((j < m) && (p[m - 1 - j] == src[i - j]))
			j++;
		if (j == m)
			return (i - m + 1);
		else
			i += t[src[i]];
	}

	return -1;
}

int main()
{
	char src[MAX], p[MAX];
	int pos;

	printf("Enter the text in which pattern is to be searched: ");
	gets(src);

	printf("Enter the pattern to be searched: ");
	gets(p);

	clock_t st = clock();
	shifttable(p);
	pos = horspool(src, p);
	clock_t et = clock();

	if (pos >= 0)
		printf("\n\nThe desired pattern was found starting from position %d", pos + 1);
	else
		printf("\n\nThe pattern was not found in the given text");

	double time_taken = (double)(et - st) / CLOCKS_PER_SEC;
	printf("\nTime taken to execute is %lf\n", time_taken);
	return 0;
}
