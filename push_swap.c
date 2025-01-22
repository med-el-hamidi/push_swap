#include "push_swap.h"

static void	handle_input(int ac, char **av);
static void	handle_occurence(t_list *a);
void merge(t_list **a, t_list **b, int p, int q, int r);
void mergeSort(t_list **a, t_list **b, int l, int r);
static void	error_msg(void );

static void	_f(void )
{
	system ("leaks push_swap");
}

void _print(t_list *a, t_list *b)
{
	printf("%11s	%11s\n", "_____", "_____");
	while (a || b)
	{
		if (a)
			printf("%11d	", a->nbr);
		else
			printf("%11c	", ' ');

		if (b)
			printf("%11d", b->nbr);
		else
			printf("%11c", ' ');
		printf("\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	printf("%11s	%11s\n", "_____", "_____");
	printf("%11c	%11c\n", 'a', 'b');
	printf("\n\n\n");
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*node;
	int	i;

	if (argc < 2)
		return (EXIT_INVALID_INPUT);
	handle_input(argc, argv);
	if (argc == 2)
		return (EXIT_SUCCESS);
	i = 0;
	a = ft_lstnew(atoi(argv[i + 1]));
	if (!a)
		return (EXIT_FAILURE);
	while (++i < argc-1)
	{
		node = ft_lstnew(atoi(argv[i + 1]));
		if (!node)
		{
			ft_lstclear(&a);
			return (EXIT_FAILURE);
		}
		ft_lstadd_back(&a, node);
	}
	handle_occurence(a);
	b = NULL;
	_print(a, b);
	mergeSort(&a, &b, 0, argc-1);
	_print(a, b);
	ft_lstclear(&a);
	_print(a, b);
	atexit(_f);
	return (EXIT_SUCCESS);
}

static void	handle_input(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	int		flag;
	char	arg[12];
	int		is_int;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		k = 0;
		flag = 0;
		ft_bzero(arg, 12);
		if (av[i][j] == '-' || av[i][j] == '+')
			arg[k++] = av[i][j++];
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				error_msg();
				exit (EXIT_INVALID_INPUT);
			}
			if (!flag && av[i][j] != '0')
				flag = 1;
			if (flag)
			{
				arg[k++] = av[i][j];
				if (k > 11)
					break ;
			}
			j++;
		}
		if (!flag && av[i][j - 1] == '0')
			is_int = 1;
		else if (k == 1 && (arg[0] == '+' || arg[0] == '-'))
			is_int = 0;
		else if (k > 11)
			is_int = 0;
		else if (k == 11 && ((arg[0] == '+' && ft_strncmp(arg, "+2147483647", k) > 0)
				|| (arg[0] == '-' && ft_strncmp(arg, "-2147483648", k) > 0)))
			is_int = 0;
		else if (k == 10 && ft_strncmp(arg, "2147483647", k) > 0)
			is_int = 0;
		else
			is_int = 1;
		if (!is_int)
		{
			error_msg();
			exit (EXIT_INVALID_INPUT);
		}
	}
}

static void	handle_occurence(t_list *a)
{
	t_list	*ptr;
	t_list	*ptr_k;

	ptr = a;
	while (ptr)
	{
		ptr_k = ptr->next;
		while (ptr_k)
		{
			if (ptr->nbr == ptr_k->nbr)
			{
				ft_lstclear(&a);
				error_msg();
				exit (EXIT_INVALID_INPUT);
			}
			ptr_k = ptr_k->next;
		}
		ptr = ptr->next;
	}
}

// Merge two subarrays L and M into arr
void merge(t_list **a, t_list **b, int p, int q, int r)
{

  // Create L ← A[p..q] and M ← A[q+1..r]
	int	i;
	int	j;
	int	k;
	int	n1;
	int	n2;

	n1 = q - p + 1;
	n2 = r - q;

	i = 0;
	while (i < n1)
	{
		if (i >= p)
		{
			push(b, a);
			ft_printf("pb\n");
		}
		rotate(a);
		ft_printf("ra\n");
		i++;
	}

	// for (int j = 0; j < n2; j++)
	// 	M[j] = arr[q + 1 + j];

	// Maintain current index of sub-arrays and main array
	i = 0;
	j = 0;
	k = p;
	int flag_r;

	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]

	while (*a && *b && i < n1 && j < n2)
  	{
		flag_r = 0;
		if ((*a)->nbr <= (*b)->nbr)
		{
			push(a, b);
			ft_printf("pa\n");
			rotate(b);
			ft_printf("rb\n");
			flag_r = 1;
			j++;
    	}
		else
		{
      		rotate(a);
			ft_printf("ra\n");
			i++;
		}
		rotate(a);
		if (flag_r)
			ft_printf("rr\n");
		else
			ft_printf("ra\n");
    	k++;
	}
	// while (i < n1 && j < n2) {
	// 	if (L[i] <= M[j]) {
	// 	arr[k] = L[i];
	// 	i++;
	// 	} else {
	// 	arr[k] = M[j];
	// 	j++;
	// 	}
	// 	k++;
	// }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
	while (i < n2)
	{
		push(a, b);
		ft_printf("pa\n");
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
		j++;
		k++;
	}
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(t_list **a, t_list **b, int l, int r)
{
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(a, b, l, m);
    mergeSort(a, b, m + 1, r);

    // Merge the sorted subarrays
    merge(a, b, l, m, r);
  }
}

static void	error_msg(void )
{
	ft_printf("Error\n");
}
