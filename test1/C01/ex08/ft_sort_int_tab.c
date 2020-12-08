/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:47:49 by sakim             #+#    #+#             */
/*   Updated: 2020/12/01 20:12:20 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	change(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	feevot;

	if (size < 2)
		return ;
	feevot = *(tab + size / 2);
	i = 0;
	j = size - 1;
	while (i < j)
	{
		while (*(tab + i) < feevot)
			i++;
		while (*(tab + j) > feevot)
			j--;
		change(tab + i, tab + j);
	}
	quick_sort(tab, i);
	quick_sort(tab + i + 1, size - i - 1);
}

void	ft_sort_int_tab(int *tab, int size)
{
	quick_sort(tab, size);
	return ;
}
