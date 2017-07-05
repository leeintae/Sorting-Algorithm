#include <cstdio>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];
int N;

void quick_sort(int f, int t)
{
	if (t - f <= 0)
		return;

	int i = f + 1, j = t;

	while (1) {
		while (arr[i] < arr[f]) {
			i++;
		}
		while (arr[f] < arr[j]) {
			j--;
		}

		if (j < i) {
			int tmp = arr[j];
			arr[j] = arr[f];
			arr[f] = tmp;
			break;
		}
		else if (i == j) {
			break;
		}
		else {
			int tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}

	quick_sort(f, j - 1);
	quick_sort(j + 1, t);
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	quick_sort(0, N - 1);

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}
