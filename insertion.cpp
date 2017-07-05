#include <cstdio>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];
int N;

void insertion_sort()
{
	int tmp, index;

	for (int i = 1; i < N; i++) {
		index = i;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[index]) {
				tmp = arr[j];
				arr[j] = arr[index];
				arr[index] = tmp;
			}
			index = j;
		}
	}
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	insertion_sort();

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}
