#include <cstdio>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];
int N;

void selection_sort()
{
	int min_index;
	int tmp;

	for (int i = 0; i < N - 1; i++) {
		min_index = i;
		for (int j = i; j < N; j++) {
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		tmp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = tmp;
	}
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	selection_sort();

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}
