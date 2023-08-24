#include "monty.h"

/**
 * check_if_num - function that checks if number
 * @str: char pointer
 * Return: 0 or 1
 */
int check_if_num(char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

/**
 * push - this function prints items in the ds
 * @stack: ds
 * @line_number: line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack)
		exit(EXIT_FAILURE);
	if (!(check_if_num(global_variables.argv)))
	{
		printf("L%u: usage: push integer\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		printf("Error: malloc failed\n");
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	if (global_variables.data_struct == 0)
		stacker(stack, node);
	else
		queuer(stack, node);
}

/**
 * pall - function that prints items in the ds
 * @stack: ds
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void) (line_number);

	if (!*stack)
		return;
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
