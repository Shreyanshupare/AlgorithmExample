#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node *prev;
	int n;
	struct node *next;
}*h,*temp,*temp1,*temp2,*temp4;

void insert1();
void insert2();
void insert3();
void traversebeg();
void traverseend();
void sort();
void search();
void update();
void delete1();

int count = 0;
void main()
{
   
}
void create()
{
	int data;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\n Enter value of node : ");
	scanf_s("%d",&data);
	temp->n = data;
	count++;

}
//for beginning
void insert1()
{
	if (h == NULL)
	{
		create();
		h = temp;
		temp1 = h;
	}
	else
	{
		create();
		temp->next = h;
		h->prev = temp;
		h = temp;
    }
}

//for end
void insert2()
{
	if (h == NULL)
	{
		create();
		h = temp;
		temp1 = h;
	}
	else
	{
		create();
		temp1->next = temp;
		temp->prev = temp1;
		temp1 = temp;
	}
}

//any position
void insert3()
{
	int pos,i = 2;

	printf("\n enter position to be inserted : ");
	scanf_s("%d",&pos);
	temp2 = h;

	if ((pos < 1) || (pos >= count + 1))
	{
		printf("\n Position out of range to insert");
		return;
	}
	if ((h == NULL) && (pos != 1))
	{
		printf("\n Empty list can not insert other then first position");
		return;
	}
	if ((h == NULL) && (pos == 1))
	{
		create();
		h = temp;
		temp1 = h;
		return;
	}
	else
	{
		while (i < pos)
		{
			temp2 = temp2->next;
			i++;
		}
		create();
		temp->prev = temp2;
		temp->next = temp2->next;
		temp2->next->prev = temp;
		temp2->next = temp;
	}

}
void delete1()
{
	int i = 1, pos;

	printf("\n Enter position to be deleted : ");
	scanf("%d", &pos);
	temp2 = h;

	if ((pos < 1) || (pos >= count + 1))
	{
		printf("\n Error : Position out of range to delete");
		return;
	}
	if (h == NULL)
	{
		printf("\n Error : Empty list no elements to delete");
		return;
	}
	else
	{
		while (i < pos)
		{
			temp2 = temp2->next;
			i++;
		}
		if (i == 1)
		{
			if (temp2->next == NULL)
			{
				printf("Node deleted from list");
				free(temp2);
				temp2 = h = NULL;
				return;
			}
		}
		if (temp2->next == NULL)
		{
			temp2->prev->next = NULL;
			free(temp2);
			printf("Node deleted from list");
			return;
		}
		temp2->next->prev = temp2->prev;
		if (i != 1)
			temp2->prev->next = temp2->next;   
		if (i == 1)
			h = temp2->next;
		printf("\n Node deleted");
		free(temp2);
	}
	count--;
}
void traversebeg()
{
	temp2 = h;

	if (temp2 == NULL)
	{
		printf("List empty to display \n");
		return;
	}
	printf("\n Linked list elements from begining : ");

	while (temp2->next != NULL)
	{
		printf(" %d ", temp2->n);
		temp2 = temp2->next;
	}
	printf(" %d ", temp2->n);
}

/*  traverse from end recursively */
void traverseend (int i)
{
	if (temp2 != NULL)
	{
		i = temp2->n;
		temp2 = temp2->next;
		traverseend(i);
		printf(" %d ", i);
	}
}
void search()
{
	int data, count = 0;
	temp2 = h;

	if (temp2 == NULL)
	{
		printf("\n Error : List empty to search for data");
		return;
	}
	printf("\n Enter value to search : ");
	scanf("%d", &data);
	while (temp2 != NULL)
	{
		if (temp2->n == data)
		{
			printf("\n Data found in %d position", count + 1);
			return;
		}
		else
			temp2 = temp2->next;
		count++;
	}
	printf("\n Error : %d not found in list", data);
}
