#include <cstdio>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];
int N;

void bubble_sort()
{
	int tmp;

	for (int i = 0; i < N - 1; i++) {
		for (int j = N - 1; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	bubble_sort();

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}
