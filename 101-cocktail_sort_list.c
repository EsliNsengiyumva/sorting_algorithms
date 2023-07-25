#include "sort.h"

/**
 * _swap - Swaps two nodes of doubly linked list
 *
 * @node: node base to change
 * @list: double link list head
 *
 * Return: No Return
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *tmp = *node, *tmp2, *tmp3;


	if (!(*node)->prev)
		*list = (*node)->next;

	tmp = tmp3 = *node;
	tmp2 = tmp->next;

	tmp->next = tmp2->next;
	tmp3 = tmp->prev;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;


	if (tmp->next)
		tmp->next->prev = tmp;

	*node = tmp2;

}
/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: head of list to be sortered (Double Linked List)
 *
 * Return: No Return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int c = 0, j = -1, i = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (i >= j)
	{
		j++;
		while (head->next && c != i)
		{
			if (head->j > head->next->j)
			{
				aux = head;
			       _swap(&aux, list);
			       print_list(*list);
			       head = aux;
			}

			c++;
			head = head->next;
		}

		if (j == 0)
			i = c;
		i--;
		while (head->prev && c >= j)
		{
			if (head->j < head->prev->j)
			{
				aux = head->prev;
				_swap(&aux, list);
				print_list(*list);
				head = aux->next;
			}
			c--;
			head = head->prev;
		}
	}
}
