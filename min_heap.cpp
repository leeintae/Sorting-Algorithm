#include <cstdio>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];
int N;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node MinHeap[1000000];
int cnt = 0;

void swap_in_min_heap(int child, int parent)
{
	int tmp = MinHeap[child].data;
	MinHeap[child].data = MinHeap[parent].data;
	MinHeap[parent].data = tmp;
}

void add_to_min_heap(int var)
{
	if (cnt == 0) {
		MinHeap[cnt].data = var;
		cnt++;
	}
	else {
		MinHeap[cnt].data = var;

		if (MinHeap[(cnt - 1) / 2].left == NULL)
			MinHeap[(cnt - 1) / 2].left = &MinHeap[cnt];
		else
			MinHeap[(cnt - 1) / 2].right = &MinHeap[cnt];

		cnt++;
	}

	int cur = cnt;

	while (MinHeap[cur - 1].data < MinHeap[(cur / 2) - 1].data && cur > 1)
	{
		swap_in_min_heap(cur - 1, (cur / 2) - 1);
		cur = cur / 2;
	}
}

int remove_from_min_heap()
{
	int return_value = MinHeap[0].data;

	MinHeap[0].data = MinHeap[cnt - 1].data;

	if (cnt % 2 == 0)
		MinHeap[(cnt / 2) - 1].left = NULL;
	else
		MinHeap[(cnt / 2) - 1].right = NULL;


	cnt--;

	int cur = 0;

	while (((MinHeap[cur].left != NULL) && (MinHeap[cur].data > MinHeap[cur].left->data))
		|| ((MinHeap[cur].right != NULL) && (MinHeap[cur].data > MinHeap[cur].right->data))) {
		if (MinHeap[cur].left == NULL) {
			swap_in_min_heap(cur, (cur * 2) + 2);
			cur = (cur * 2) + 2;
		}else if (MinHeap[cur].right == NULL) {
			swap_in_min_heap(cur, (cur * 2) + 1);
			cur = (cur * 2) + 1;
		}else if (MinHeap[cur].left->data < MinHeap[cur].right->data) {
			swap_in_min_heap(cur, (cur * 2) + 1);
			cur = (cur * 2) + 1;
		}else {
			swap_in_min_heap(cur, (cur * 2) + 2);
			cur = (cur * 2) + 2;
		}
	}

	return return_value;
}

void min_heap_sort()
{
	for (int i = 0; i < N; i++)
		add_to_min_heap(arr[i]);

	for (int i = 0; i < N; i++)
		arr[i] = remove_from_min_heap();
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	min_heap_sort();

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}
