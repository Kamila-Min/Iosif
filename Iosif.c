#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <string.h>
#include <malloc.h>

struct IOSIF
{
	int x;
	IOSIF* next, * prev;
};

IOSIF* CreateIosifList(IOSIF*& head, int n);

int DeleteIosifItem(IOSIF*& current, int m);

int Iosif(int n, int m);

int main()
{
	int m = 0, n = 0;

	printf(" Enter n, m \n");
	scanf("%d, %d", &n, &m);

	int k = 0;

	k = Iosif(n, m);

	printf("%d", k);

	printf("\n");

	return 0;
}

IOSIF* CreateIosifList(IOSIF*& head, int n)
{
	int i = 0;
	IOSIF* p, * q;
	for (i = 0; i < n; i++)
	{
		p = (struct IOSIF*)calloc(n, sizeof(struct IOSIF));

		p->x = i + 1;

		if (i == 0)
		{
			head = p;
			p->next = p;
			p->prev = p;
		}
		else {
			q->next = p;
			p->prev = q;
		}
		q = p;
	} 

	p->next = head;

	head->prev = p;

	return head;
}

int DeleteIosifItem(IOSIF*& current, int m)
{
	IOSIF* p = current; int i;
	for (i = 1; i < m; i++) 
		p = p->next;

	p->prev->next = p->next;

	p->next->prev = p->prev;

	i = p->x;

	current = p->next;

	free(p);

	return i;
}

int Iosif(int n, int m)
{
	int i = 0, j = 0, k = 0;

	IOSIF* p;

	CreateIosifList(p, n);

	i = 0;
	k = n;

	while (k > 1)
	{
		i++;
		if (i == m)
		{
			j = DeleteIosifItem(p, m);
			i = 0;
			k--;
		}
	} 

	return p->x;
} 
