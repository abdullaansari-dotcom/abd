#include <stdio.h>

#define SIZE 5

void enqueue(int queue[], int *front, int *rear, int value)
{
	if ((*front == 0 && *rear == SIZE - 1) || (*front == *rear + 1))
	{
		printf("Queue is full.\n");
		return;
	}

	if (*front == -1)
	{
		*front = 0;
	}
	*rear = (*rear + 1) % SIZE;
	queue[*rear] = value;
	printf("Value inserted.\n");
}

void dequeue(int queue[], int *front, int *rear)
{
	if (*front == -1)
	{
		printf("Queue is empty.\n");
		return;
	}

	printf("Deleted value: %d\n", queue[*front]);
	if (*front == *rear)
	{
		*front = -1;
		*rear = -1;
	}
	else
	{
		*front = (*front + 1) % SIZE;
	}
}

void display(const int queue[], int front, int rear)
{
	int i;

	if (front == -1)
	{
		printf("Queue is empty.\n");
		return;
	}

	printf("Queue values: ");
	i = front;
	while (1)
	{
		printf("%d ", queue[i]);
		if (i == rear)
		{
			break;
		}
		i = (i + 1) % SIZE;
	}
	printf("\n");
}

int main(void)
{
	int queue[SIZE];
	int front = -1;
	int rear = -1;
	int choice;
	int value;

	while (1)
	{
		printf("\nCircular Queue Menu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Enter a value: ");
				scanf("%d", &value);
				enqueue(queue, &front, &rear, value);
				break;

			case 2:
				dequeue(queue, &front, &rear);
				break;

			case 3:
				display(queue, front, rear);
				break;

			case 4:
				return 0;

			default:
				printf("Invalid choice. Try again.\n");
		}
	}
}
