#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"

# define NBR(x)		printf("%d", x); fflush(0);
# define DONE		printf("..DONE\n");

void print_list(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst) {
		printf("%zu:%s\n", i, lst->content);
		lst = lst->next;
		i++;
	}
	printf("\n");
}

void print_list_elt(void *content)
{
	printf("\t%s\n", content);
}

void *upper_lst(void *content)
{
	size_t	i;
	char	*str;

	str = ft_strdup((char*)content);
	i = 0;
	while(str[i]) {
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int	compare_list(char const *fct, t_list *list, char **strs, int limit, int length)
{
	int	i;
	int	correct;

	i = 0;
	correct = 0;
	while ((limit < 0 || i < limit) && i < length && list)
	{
		if (strcmp(list->content, strs[i]))
			printf("%s: Expected `%s` got `%s`\n", fct, strs[i], list->content);
		else
			correct++;
		i++;
		list = list->next;
	}
	if ((limit < 0 && correct == length) || (correct == limit))
		printf("%s: All good\n", fct);
	return (1);
}

int main(int argc, char const *argv[])
{
	int		i;
	int		correct;
	char	*strs[3];
	char	*upper[3];

	(void) argc;
	(void) argv;

	printf("---Bonus---\n\n");

	strs[0] = strdup("opppoppop");
	strs[1] = strdup("okokokok");
	strs[2] = strdup("wqqwqwwqqw");

	upper[0] = strdup("OPPPOPPOP");
	upper[1] = strdup("OKOKOKOK");
	upper[2] = strdup("WQQWQWWQQW");

	t_list *first = ft_lstnew(strs[1]);
	t_list **list = &first;

	compare_list("ft_lstnew", first, strs + 1, 1, 3);
	if (first->next)
		printf("ft_lstnew: Invalid next element !\n");

	ft_lstadd_back(list, ft_lstnew(strs[2]));
	compare_list("ft_lstadd_back", first, strs + 1, 2, 3);

	ft_lstadd_front(list, ft_lstnew(strs[0]));
	compare_list("ft_lstadd_front", first, strs, 3, 3);

	i = ft_lstsize(*list);
	if (i == 3)
		printf("ft_lstsize: All good\n");
	else
		printf("ft_lstsize: Expected `%d` got `%d`\n", 3, i);

	t_list	*last = ft_lstlast(*list);
	if (!last)
		printf("ft_lstlast: Returned nothing !\n");
	else
	{
		if (strcmp(last->content, strs[2]))
			printf("ft_lstlast: Expected `%s` got `%s`\n", last->content, strs[2]);
		else
			printf("ft_lstlast: All good\n");
	}

	printf("ft_lstiter:\n");
	ft_lstiter(*list, &print_list_elt);

	t_list	*list_copy = ft_lstmap(first, &upper_lst, &free);
	compare_list("ft_lstmap", list_copy, upper, 3, 3);

	printf("ft_lstclear: ");
	ft_lstclear(list, &free);
	ft_lstclear(&list_copy, &free);
	printf("All good\n");

	t_list *empty = NULL;

	strs[0] = strdup("opppoppop");
	ft_lstadd_front(&empty, ft_lstnew(strs[0]));
	compare_list("ft_lstadd_front (empty)", empty, strs, 1, 3);
	ft_lstclear(&empty, &free);

	strs[0] = strdup("opppoppop");
	ft_lstadd_back(&empty, ft_lstnew(strs[0]));
	compare_list("ft_lstadd_back (empty)", empty, strs, 1, 3);
	ft_lstclear(&empty, &free);

	printf("\nSeg. fault tests (?)\n");
	printf(":lst_addback\n"); NBR(1)
	ft_lstadd_back(NULL, NULL); NBR(2)
	ft_lstadd_back(&empty, NULL); DONE

	printf(":lst_addfront\n"); NBR(1)
	ft_lstadd_front(NULL, NULL); NBR(2)
	ft_lstadd_front(&empty, NULL); DONE

	printf(":lstclear\n"); NBR(1)
	ft_lstclear(NULL, NULL); NBR(2)
	ft_lstclear(&empty, NULL); NBR(3)
	ft_lstclear(&empty, NULL); NBR(4)
	ft_lstclear(&empty, &free); DONE

	printf(":lstdelone\n"); NBR(1)
	ft_lstdelone(NULL, NULL); NBR(2)
	ft_lstdelone(NULL, &free); NBR(3)
	ft_lstdelone(empty, NULL); DONE

	printf(":lstiter\n"); NBR(1)
	ft_lstiter(NULL, NULL); NBR(2)
	ft_lstiter(NULL, &print_list_elt); NBR(3)
	ft_lstiter(empty, NULL); NBR(4)
	ft_lstiter(empty, &print_list_elt); DONE

	printf(":lstlast\n"); NBR(1)
	ft_lstlast(NULL); NBR(2)
	ft_lstlast(empty); DONE

	printf(":lstmap\n"); NBR(1)
	ft_lstmap(NULL, NULL, NULL); NBR(2)
	ft_lstmap(NULL, NULL, &free); NBR(3)
	ft_lstmap(NULL, &upper_lst, NULL); NBR(4)
	ft_lstmap(NULL, &upper_lst, &free); NBR(5)
	ft_lstmap(empty, NULL, NULL); NBR(6)
	ft_lstmap(empty, &upper_lst, NULL); NBR(7)
	ft_lstmap(empty, &upper_lst, &free); DONE

	return (0);
}
