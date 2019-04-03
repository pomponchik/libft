/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:15:36 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/20 18:28:25 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void sort_quick_helper(void *begin, void *end, )
void		ft_sort_quick(void *a, size_t size, size_t amount, int (*f)(void *, void *))
{
	void *pivot;
	void *begin;
	void *end;

printf("in: %s %lu %lu \n", (char *)a, size, amount);
	if (!a || !f || amount <= 1 || !size)
		return ;
	pivot = ft_jump_pointer_to_n(a, amount * size);
	begin = a;
	end = pivot;
	while (begin < end)
	{
		//printf("j1\n");
		while (f(begin, pivot) < 0)
		{
			//printf("j2\n");
			begin = ft_jump_pointer_to_n(begin, size);
		}
		while (f(end, pivot) > 0)
		{
			//printf("j3\n");
			end = ft_jump_pointer_to_n(end, (int)size * -1);
		}
		if (f(begin, end) > 0)
		{
			//printf("j4\n");
			ft_swap_n_bytes(begin, end, size);
			begin = ft_jump_pointer_to_n(begin, size);
			end = ft_jump_pointer_to_n(end, (int)size * -1);
		}
		else
			break ;
	}
	//printf("j5\n");
	//printf("%s\n", (char *)a);
	pivot = ft_jump_pointer_to_n(a, (amount * size / 2) + 1);
	if (amount / 2)
		ft_sort_quick(a, size, amount / 2, f);
	if (amount - (amount / 2))
		ft_sort_quick(pivot, size, amount - (amount / 2), f);















	// void	*temp;
	// size_t	index;
	//
	// if (!a || !f || amount <= 1 || !size)
	// 	return ;
	// temp = ft_jump_pointer_to_n(a, size * (amount / 2));
	// index = 0;
	// if (f(a, temp - size) < 0)
	// 	ft_swap_n_bytes(a, temp - size, size);
	// while (index != amount / 2)
	// {
	// 	temp = ft_jump_pointer_to_n(a, size * index);
	// 	if (f(a, temp) > 0)
	// 		ft_swap_n_bytes(a, temp, size);
	// 	index++;
	// }
	// temp = ft_jump_pointer_to_n(a, size * (amount / 2));
	// if (f(a, temp) > 0)
	// 	ft_swap_n_bytes(a, temp, size);
	// while (index != amount)
	// {
	// 	temp = ft_jump_pointer_to_n(a, size * index);
	// 	if (f(a, temp) < 0)
	// 		ft_swap_n_bytes(a, temp, size);
	// 	index++;
	// }
	// ft_sort_quick(a, size, amount / 2, f);
	// temp = ft_jump_pointer_to_n(a, size * (amount / 2));
	// ft_sort_quick(temp, size, amount - (amount / 2), f);
}


// void sort(, int b0, int e0)
// (void *a, size_t size, size_t amount, int (*f)(void *, void *))
// {
// 	void *pivot;
// 	void *begin;
// 	void *end;
//
// 	pivot = ft_jump_pointer_to_n(a, amount * size);
// 	begin = a;
// 	end = pivot;
// 	while (begin < end)
// 	{
// 		while (f(begin, pivot) < 0)
// 			begin = ft_jump_pointer_to_n(begin, size);
// 		while (f(end, pivot) > 0)
// 			end = ft_jump_pointer_to_n(end, (int)size * -1);
// 	}
// 	pivot = ft_jump_pointer_to_n(a, (amount * size / 2) + 1);
// 	if (amount / 2)
// 		ft_sort_quick(a, size, amount / 2, f);
// 	if (amount - (amount / 2))
// 		ft_sort_quick(pivot, amount - (amount / 2), f);
// }
//

// void sort(vector<int> &v, int b0, int e0)
// {
//     auto d = v[e0];
//     auto b = b0;
//     auto e = e0;
//     do
//     {
//         while (v[b] < d)
//             ++b;
//         while (v[e] > d)
//             --e;
//         if (b <= e)
//         {
//             swap(v[b], v[e]);
//             ++b;
//             --e;
//         }
//     } while (b <= e);
//     if (e > b0)
//         sort(v, b0, e);
//     if (b < e0)
//         sort(v, b, e0);
// }
