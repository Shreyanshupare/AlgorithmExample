#include <stdio.h>
#include <stdlib.h>
struct node {
	int num;
	struct node *next;
};

void create(struct node **);
void tocircular(struct node **);
void release(struct node **);
void display(struct node *);

int main()
{
	struct node *p = NULL;
	int result, count;

	printf("Enter data into the list\n");
	create(&p);
	tocircular(&p);
	printf("Circular list generated\n");
	display(p);
	release(&p);

	return 0;
}

void tocircular(struct node **p)
{
	struct node *rear;

	rear = *p;
	while (rear->next != NULL)
	{
		rear = rear->next;
	}
	rear->next = *p;
}
void create(struct node **head)
{
	int c, ch;
	struct node *temp;

}
