#include "binary_trees.h"
#include <stdlib.h>

void free_queue(lorder_queue_t *head);
lorder_queue_t *create_queue(binary_tree_t *node);
void enqueue(lorder_queue_t *head, lorder_queue_t **tail,
		const binary_tree_t *node, void (*func)(int));
void dequeue(lorder_queue_t **head);

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	lorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	tail = create_queue((binary_tree_t *)tree);
	head = tail;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		enqueue(head, &tail, head->node, func);
		dequeue(&head);

	}
}

/**
 * create_queue - Creates a queue
 *
 * @node: A pointer to a node.
 *
 * Return: A pointer to a queue, NULL if queue not created
 */
lorder_queue_t *create_queue(binary_tree_t *node)
{
	lorder_queue_t *qu;

	qu = malloc(sizeof(lorder_queue_t));
	if (qu == NULL)
		return (NULL);

	qu->node = node;
	qu->next = NULL;

	return (qu);
}

/**
 * enqueue - Creates a queue
 *
 * @head: A pointer to the first item.
 * @tail: A pointer queue's tail.
 * @node: A pointer to a node entering the queue.
 * @func: A pointer to a function calling on @node.
 */
void enqueue(lorder_queue_t *head, lorder_queue_t **tail,
		const binary_tree_t *node, void (*func)(int))
{
	lorder_queue_t  *qu;

	if (!head || !node)
		exit(1);

	func(node->n);

	if (node->left)
	{
		qu = create_queue(node->left);
		if (qu == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = qu;
		*tail = qu;
	}
	if (node->right)
	{
		qu = create_queue(node->right);
		if (qu == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = qu;
		*tail = qu;
	}
}

/**
 * dequeue - Deletes the head of lorder_queue_t queue.
 * @head: A pointer to queue's head.
 */
void dequeue(lorder_queue_t **head)
{
	lorder_queue_t  *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * free_queue - Frees lorder_queue_t queue and its elements.
 * @head: A pointer to queue's head.
 */
void free_queue(lorder_queue_t *head)
{
	lorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
