#include <cstdio>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];
int tmp[MAX_SIZE];
int N;

void merge(int f, int m, int t)
{
	int i = f, j = m + 1;
	int index = f;

	while (1)
	{
		if (arr[i] < arr[j])
			tmp[index++] = arr[i++];
		else
			tmp[index++] = arr[j++];

		if (i == m + 1) {
			for (int k = j; k <= t; k++)
				tmp[index++] = arr[k];
			break;
		}

		if (j == t + 1) {
			for (int k = i; k <= m; k++)
				tmp[index++] = arr[k];
			break;
		}
	}

	for (int k = f; k <= t; k++)
		arr[k] = tmp[k];
}

void merge_sort(int f, int t)
{
	if (f < t)
	{
		int m = (f + t) / 2;

		merge_sort(f, m);
		merge_sort(m + 1, t);

		merge(f, m, t);
	}
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	merge_sort(0, N - 1);

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}
