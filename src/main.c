/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:30 by nax_lyk           #+#    #+#             */
/*   Updated: 2025/01/05 15:07:23 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_find_min(t_stack *stack)
{
	t_stack		*min;

	min = stack;
	while (stack)
	{
		if (*stack->content < *min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	print_stacks_content(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a && stack_b)
		{
			ft_printf("%d   %d\n", *stack_a->content, *stack_b->content);
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
		else if (stack_a && !stack_b)
		{
			ft_printf("%d   .\n", *stack_a->content);
			stack_a = stack_a->next;
		}
		else
		{
			ft_printf(".   %d\n", *stack_b->content);
			stack_b = stack_b->next;
		}
	}
}

t_stack		*find_closest_smaller(t_stack *node_a, t_stack *stack_b)
{
	t_stack		*closest_smaller;
	t_stack		*tmp;
	int		diff_bw;
	int		tmp_diff_bw;
	
	diff_bw = ft_abs(*node_a->content - *stack_b->content);
	closest_smaller = stack_b;
	tmp = stack_b;
	while (stack_b)
	{
		tmp_diff_bw = ft_abs(*node_a->content - *stack_b->content);
		if (tmp_diff_bw < diff_bw && *stack_b->content < *node_a->content)
		{
			diff_bw = tmp_diff_bw;
			closest_smaller = stack_b;
		}
		stack_b = stack_b->next;
	}
	if (*node_a->content < *closest_smaller->content)
		return (ft_find_max(tmp));
	return (closest_smaller);
}

t_stack		*find_closest_bigger(t_stack *node_b, t_stack *stack_a)
{
	t_stack		*closest_bigger;
	t_stack		*tmp;
	int		diff_bw;
	int		tmp_diff_bw;
	
	diff_bw = 2147483647;
	closest_bigger = stack_a;
	tmp = stack_a;
	while (stack_a)
    {
		if (*stack_a->content > *node_b->content)
		{
		    tmp_diff_bw = *stack_a->content - *node_b->content;
		    if (tmp_diff_bw < diff_bw)
		    {
				diff_bw = tmp_diff_bw;
				closest_bigger = stack_a;
		    }
		}
        stack_a = stack_a->next;
    }
	if (diff_bw == 2147483647)
		return (ft_find_min(tmp));
	return (closest_bigger);
}

int		count_operations(int size, int index, t_stack *node, t_stack *stack_b)
{
	int			nb_operations;
	int			tmp_index;
	t_stack		*closest_smallest;

	nb_operations = 0;
    if (index <= size / 2 + 1)
        nb_operations += index - 1;
    else
        nb_operations += size - index + 1;
	if (!node || !stack_b)
		return (nb_operations);
	closest_smallest = find_closest_smaller(node, stack_b);
	tmp_index = ft_lst_find(stack_b, closest_smallest);
	//if (tmp_index == index || (tmp_index == ft_lstsize(stack_b) && index >= tmp_index))
	//	return (nb_operations);
	nb_operations += count_operations(ft_lstsize(stack_b), tmp_index, NULL, NULL);
	return (nb_operations);
}

t_stack		*find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int			cheapest_operations;
	int			index;
	t_stack		*cheapest_node;
	int			size;

	index = 1;
	size = ft_lstsize(stack_a);
	cheapest_operations = count_operations(size, index, stack_a, stack_b);
	cheapest_node = stack_a;
	printf("%d : %d\n", *stack_a->content, count_operations(size, index, stack_a, stack_b));
	stack_a = stack_a->next;
	while (stack_a)
	{
		index++;
		printf("%d : %d\n", *stack_a->content, count_operations(size, index, stack_a, stack_b));
		if (cheapest_operations > count_operations(size, index, stack_a, stack_b))
		{
			cheapest_operations = count_operations(size, index, stack_a, stack_b);
			cheapest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (cheapest_node);
}

int		bring_target_to_top(t_stack *target, t_stack **stack_b)
{
	int		size_b;
	int		target_i;
	int		operations;

	operations = 0;
	target_i = ft_lst_find(*stack_b, target);
	size_b = ft_lstsize(*stack_b);
	while (target_i != 1)
	{
		if (target_i <= size_b / 2 + 1)
			operations += rab(stack_b, 'b');
		else
			operations += rrab(stack_b, 'b');
		target_i = ft_lst_find(*stack_b, target);
	}
	return (operations);
}

int		bring_cheapest_to_top(t_stack *cheapest, t_stack **stack_b, t_stack **stack_a)
{
	int		cheapest_i;
	int		target_i;
	int		operations;
	int		size_a;

	operations = 0;
	cheapest_i = ft_lst_find(*stack_a, cheapest);
	target_i = ft_lst_find(*stack_b, find_closest_smaller(cheapest, *stack_b));
	size_a = ft_lstsize(*stack_a);
	while (cheapest_i != 1)
	{

		if (cheapest_i <= size_a / 2 + 1)
			operations += rab(stack_a, 'a');
		else
			operations += rrab(stack_a, 'a');
		cheapest_i = ft_lst_find(*stack_a, cheapest);
	}
	operations += bring_target_to_top(find_closest_smaller(cheapest, *stack_b), stack_b);
	operations += pb(stack_a, stack_b);
	return (operations);
}

int		push_back_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*closest_bigger;
	int			operations;
	int			target_i;
	int			size_a;

	operations = 0;
	closest_bigger = find_closest_bigger(*stack_b, *stack_a);
	target_i = ft_lst_find(*stack_a, closest_bigger);
	size_a = ft_lstsize(*stack_a);
	while (target_i != 1)
	{
		if (target_i > size_a / 2 + 1)
			operations += rrab(stack_a, 'a');
		else
			operations += rab(stack_a, 'a');
		target_i = ft_lst_find(*stack_a, closest_bigger);
	}
	operations += pa(stack_a, stack_b);
	return (operations);
}

int		sort_small_stack(t_stack **stack_a)
{
	if (ft_lstsize(*stack_a) == 3)
		return (sort_stack_of_three(stack_a));
	else
		return (swap_top(stack_a, 'a'));
}

int		sort_stack_a(t_stack **stack_a)
{
	int		operations;

	operations = 0;
	while (!is_sorted(*stack_a))
	{
		if (ft_lst_find(*stack_a, ft_find_max(*stack_a)) < ft_lstsize(*stack_a) / 2 + 1)
			operations += rab(stack_a, 'a');
		else
			operations += rrab(stack_a, 'a');
	}
	return (operations);
}

int		turk_algo(t_stack **stack_a, t_stack **stack_b)
{
	int		operations;

	operations = 0;
	if (ft_lstsize(*stack_a) < 4)
		return (sort_small_stack(stack_a));
	else 
	{
		operations += pb(stack_a, stack_b);
		operations += pb(stack_a, stack_b);
		while (ft_lstsize(*stack_a) != 3)
		{
			t_stack		*cheapest = find_cheapest(*stack_a, *stack_b);
			operations += bring_cheapest_to_top(cheapest, stack_b, stack_a);
		}
		operations += sort_stack_of_three(stack_a);
		while (ft_lstsize(*stack_b) != 0)
			operations += push_back_stack_a(stack_a, stack_b);
		sort_stack_a(stack_a);
		
	}
	return (operations);
}

int		numbers_counteur(char **inputs)
{
	int		i;

	i = 0;
	while (inputs[i])
		i++;
	return (i);
}

void	ft_push_swap(char **inputs)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (!check_inputs(inputs))
		return ;
	stack_a = init_stack(inputs);
	stack_b = NULL;
	if (is_sorted(stack_a))
	{
		ft_lstclear(&stack_a, free);
		return ;
	}

	t_stack		*tmp = init_stack(inputs);

	// printf("%d\n", turk_algo(&stack_a, &stack_b));
	printf("\n%d\n", turk_algo(&stack_a, &stack_b));
	printf("\n-----\n");
	print_stacks_content(tmp, stack_b);
	printf("-AFTER-\n");
	print_stacks_content(stack_a, stack_b);
	// int i = 0;
	// while (inputs[i])
	// 	printf("%s ", inputs[i++]);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return ;
}

int		main(__attribute__((unused))int ac, char **av)
{
	//printf("----------------------\n");
	if (ac > 1)
	{
		if (!av[2])
			ft_push_swap(ft_split(av[1], ' '));
		else
			ft_push_swap(&av[1]);
	}
}

/*947 -2831 1563 -892 2156 -1478 2965 -2654 883 -1729 2432 -1965 1547 -2789 1123 -345 2876 -2234 756 -1891 2543 -678 934 -1432 2789 -234 2654 -987 432 -1567 1234 -876 543 -1790 1433 -567 877 -1235 655 -988 1568 -433 790 -1655 235 -1791 989 -544 1877 -236 656 -1988 434 -878 1544 -791 236 -1656 990 -435 1792 -879 545 -1236 878 1434 -792 237 -1878 991 -546 1657 -793 436 -1545 880 -238 1989 -657 437 -1879 794 -548 1237 -881 569 -1435 795 -239 1880 -992 549 -1658 796 -438 1546 -882 240 -1990 658 -439 1881 -797 550 -1238 2998 -2999 1658 -899 2256 -1498 2975 -2668 893 -1739 2442 -1975 1557 -2799 1133 -355 2886 -2244 766 -1901 2553 -688 944 -1442 2799 -244 2664 -997 442 -1577 1244 -886 553 -1800 1443 -577 887 -1245 665 -998 1578 -443 800 -1665 245 1985 1567 -2809 1143 -365 2896 -2254 776 -1911 2563 -698 954 -1452 2809 -254 2674 -1007 452 -1587 1254 -896 563 -1810 1453 -587 897 -1255 675 -1008 1588 -453 810 -1675 255 -1811 1009 -564 1897 -256 676 -2008 454 -898 1564 -811 256 -1676 1010 -455 1812 565 -1256 898 -588 1454 -812 257 -1898 1011 -566 1677 -813 456 -1565 900 -258 2009 -677 457 -1899 814 -568 1257 -901 589 -1455 815 -259 1900 -1012 -1678 816 -458 1566 -902 260 -2010 678 -459 1901 -817 570 -1258 2011 -2012 1678 -919 2276 -1518 2995 -2688 913 -1759 2462 -1995 1577 -2819 1153 -375 2906 -2264 786 -1921 2573 -708 964 -1462 2819 -264 2684 -1017 462 -1597 1264 -906 573 -1820 1463 -597 907 -1265 685 -1018 1598 -463 820 -1685 265 -1821 1019 -574 1907 -266 686 -2018 464 -908 1574 -821 266 -1686 1020 -465 1822 -909 575 -1266 908 -598 1464 -822 267 -1908 1021 -576 1687 -823 466 -1575 910 -268 2019 -687 467 -1909 824 -578 1267 -911 599 -1465 825 -269 1910 -1022 579 -1688 826 -468 1576 -912 270 -2020 688 -469 1911 -827 580 -1268 2021 -2022 1688 -929 2286 -1528 3000 -2698 923 -1769 2472 -2005 1587 -2829 1163 -385 2916 -2274 -1931 2583 -718 974 -1472 2829 -274 2694 -1027 472 -1607 1274 -916 583 -1830 1473 -607 917 -1275 695 -1028 1608 -473 830 -1695 275 -1831 1029 -584 1917 -276 696 -2028 474 -918 1584 -831 276 -1696 1030 -475 1832 585 -1276 918 -608 1474 -832 277 -1918 1031 -586 1697 -833 476 -1585 920 -278 2029 -697 477 -1919 834 1277 -921 609 -1475 835 -279 1920 -1032 -1698 836 -478 1586 -922 280 -2030 698 -479 1921 -837 590 -1278 2031 -2032 1698 -939 2296 -1538 2940 -2708 933 -1779 2482 -2015 1597 -2839 1173 -395 2926 -2284 806 -1941 2593 -728 984 -1482 2839 -284 2704 -1037 482 -1617 1284 -926 593 -1840 1483 -617 927 -1285 705 -1038 1618 -483 840 -1705 285 -1841 1039 -594 1927 -286 706 -2038 484 -928 1594 -841 286 -1706 1040 -485 1842 595 -1286 928 -618 1484 -842 287 -1928*/