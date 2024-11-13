/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:10:53 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 15:11:29 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Check which of the three values is the median
 */
static int	choose_pivot(int *arr, int left, int right)
{
	int	middle;
	int	a;
	int	b;
	int	c;

	middle = (right - left) / 2 + left;
	a = arr[left];
	b = arr[middle];
	c = arr[right];
	if ((a <= b) && (b <= c))
		return (middle);
	if ((a <= c) && (c <= b))
		return (right);
	if ((b <= a) && (a <= c))
		return (left);
	if ((b <= c) && (c <= a))
		return (right);
	if ((c <= a) && (a <= b))
		return (left);
	return (middle);
}

/*	Apply the quicksort algorithm to the given array
 */
void	quicksort(int *arr, int left, int right)
{
	int	pivot;
	int	pivotvalue;
	int	item_l;
	int	item_r;

	if (left >= right)
		return ;
	pivot = choose_pivot(arr, left, right);
	swap(arr, pivot, right);
	pivotvalue = right;
	item_l = left;
	item_r = right - 1;
	while (item_l <= item_r)
	{
		while (arr[item_l] <= arr[pivotvalue] && item_l < right)
			item_l++;
		while (item_r >= 0 && arr[item_r] >= arr[pivotvalue] && item_r >= left)
			item_r--;
		if (item_l <= item_r)
			swap(arr, item_l, item_r);
	}
	swap(arr, item_l, pivotvalue);
	pivot = item_l;
	quicksort(arr, pivot + 1, right);
	quicksort(arr, left, pivot);
}
