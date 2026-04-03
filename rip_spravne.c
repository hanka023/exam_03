/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_spravne.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:40:55 by galauren          #+#    #+#             */
/*   Updated: 2026/04/03 22:03:33 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	recursive_remove_opening_parenthesis(char *str, int index)
{
	int balance;

	if (!str[index])
		return (0);
	balance = recursive_remove_opening_parenthesis(str, index + 1);
	if (str[index] == ')')
		++balance;
	else if (str[index] == '(')
	{
		if (balance == 0)
			str[index] = ' ';
		else
			--balance;
	}
	return (balance);
}

int	recursive_remove_closing_parenthesis(char *str, int index, int balance)
{
	if (!str[index])
		return (0);
	if (str[index] == '(')
		++balance;
	else if (str[index] == ')')
	{
		if (balance == 0)
			str[index] = ' ';
		else
			--balance;
	}
	recursive_remove_closing_parenthesis(str, index + 1, balance);
	return (0);
}

void	rip(char *str)
{
	recursive_remove_opening_parenthesis(str, 0);
	recursive_remove_closing_parenthesis(str, 0, 0);
	puts(str);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	rip(av[1]);
}