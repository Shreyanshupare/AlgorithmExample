#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
};
void create(struct node **);
void reversedisplay(struct node *);
void release(struct node **);
void display(struct node *);
void length();
int main()
{
	struct node *p = NULL;
	struct  node_occur *head = NULL;
	

	printf("Enter data into list\n");
	create(&p);
	printf("Display the node in the  list \n");
	display(p);
	printf("Display the list in reverse \n");
	reversedisplay(p);
	release(&p);
	length();
	return 0;
}
void create(struct node **head)
{
	int c, ch;
	struct node *temp, *rear=NULL;
	do {
		printf("Enter Number: ");
		scanf_s("%d",&c);
		temp = (struct node *) malloc(sizeof(struct node));
		temp->num = c;
		temp->next = NULL;
		if (*head == NULL)
		{
			*head = temp;
		}
		else
		{
			rear->next = temp;
		}
		rear = temp;
		printf("Do you wish to continue [1/0]: ");
		scanf_s("%d",&ch);

	} while (ch != 0);
	

}
void display(struct node *p)
{
	while (p != NULL)
	{
		printf("%d\t", p->num);
		p = p->next;
	}
	printf("\n");
}
void release(struct node **head)
{
	struct node *temp = *head;
	*head = (*head)->next;
	while ((*head) != NULL)
	{
		free(temp);
		temp = *head;
		(*head) = (*head)->next;
	}
}
void reversedisplay(struct node *head)
{
	if (head != NULL)
	{
		reversedisplay(head->next);
		printf("%d",head->num);
	}
}

void length()
{
	char word[20];
	int count;
	int index;
	printf("Enter a word to count it's length: ");
	scanf_s("%s", word);
	
	
	if (word[index] == '\0')
	{
		printf("END");
	}
	printf("The number of characters in %s are %d.\n", word, count);

}

