#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index index of a dlistint_t
 *                            linked list.
 * @head: Pointer to a pointer to the head of the doubly linked list.
 * @index: Index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		if (*head != NULL)
		{
			*head = (*head)->next;
			if (*head != NULL)
				(*head)->prev = NULL;
			free(current);
			return (1);
		}
		return (-1);
	}

	while (index > 0 && current != NULL)
	{
		current = current->next;
		index--;
	}

	if (current == NULL)
		return (-1);

	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);

	return (1);
}


