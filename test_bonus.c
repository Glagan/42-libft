#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"

void print_list(t_list *lst) {
	size_t	i;

	i = 0;
	while (lst) {
		printf("%zu:%s\n", i, lst->content);
		lst = lst->next;
		i++;
	}
	printf("\n");
}

void print_list_elt(void *content) {
	printf("%s\n", content);
}

void *upper_lst(void *content) {
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

/**
 * gcc -I. -L. -lft test_bonus.c -o ejwheuieruweurwhrui && ./ejwheuieruweurwhrui
 */
int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	printf("\n---bonus---\n");

	char	*middle = strdup("okokokok");
	char	*first_str = strdup("opppoppop");
	char	*last = strdup("wqqwqwwqqw");

	t_list *first = ft_lstnew(middle);
	t_list **list = &first;

	printf("Expect 1 element\n");
	print_list(*list);

	ft_lstadd_back(list, ft_lstnew(last));
	printf("Expect 2 elements, wqqwqwwqqw last\n");
	print_list(*list);

	ft_lstadd_front(list, ft_lstnew(first_str));
	printf("Expect 3 elements, opppoppop first\n");
	print_list(*list);

	printf("List size: %d (3)\n", ft_lstsize(*list));
	printf("Last element %s (wqqwqwwqqw)\n\n", ft_lstlast(*list)->content);

	printf("ft_lstiter with print_list_elt\n");
	ft_lstiter(*list, &print_list_elt);
	printf("\n");

	t_list	*list_copy = ft_lstmap(first, &upper_lst);
	printf("UPPER list with lstmap\n");
	print_list(list_copy);

	ft_lstclear(list, &free);
	ft_lstclear(&list_copy, &free);

	t_list *empty = NULL;

	first_str = strdup("opppoppop");
	printf("Adding one element to empty list (front)\n");
	ft_lstadd_front(&empty, ft_lstnew(first_str));
	printf("Expect 1 element\n");
	print_list(empty);
	ft_lstclear(&empty, &free);

	first_str = strdup("opppoppop");
	printf("Adding one element to empty list (back)\n");
	ft_lstadd_back(&empty, ft_lstnew(first_str));
	printf("Expect 1 element\n");
	print_list(empty);
	ft_lstclear(&empty, &free);

	return (0);
}
