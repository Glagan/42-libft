#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "libft.h"

void test_char_ft(int (*org)(int), int (*ft)(int)) {
	int	i;

	printf("[int|unsigned char]\n");
	i = 0;
	while (i < 256) {
		if ((*org)(i) == (*ft)(i))
			printf("G");
		else
			printf("[%d|%c]", i, i);
		i++;
	}
	printf("\n");
}

char strupper_and_one(unsigned int idx, char c) {
	if (idx == 0) {
		return ('1');
	}
	return (ft_toupper(c));
}

int	min(int a, int b) {
	return ((a < b) ? a : b);
}

int	max(int a, int b) {
	return ((a > b) ? a : b);
}

int	same_sign(int a, int b) {
	return ((a < 0 && b < 0) || (a > 0 && b > 0));
}

int	_c_in_set(char c, char const *set) {
	int	i;

	i = 0;
	while (set[i])
		if ((unsigned char)set[i++] == (unsigned char)c)
			return (1);
	return (0);
}

int main(int argc, char const *argv[])
{
	int	j;
	(void) argc;
	(void) argv;

	/*
	atoi
	*/
	printf("---atoi---[string|atoi|yours]\n");

	int i = 1;
	while (i < argc) {
		if (atoi(argv[i]) == ft_atoi((char*) argv[i])) {
			printf("G");
		} else {
			printf("[%s|%d|%d]", argv[i], atoi(argv[i]), ft_atoi((char*) argv[i]));
		}
		i++;
	}
	printf("\n");

	/*
	bzero
	*/
	printf("\n---bzero---[string|length]\n");

	char *str_bzero_org = NULL;
	char *str_bzero_ft = NULL;
	int	min_length;

	i = 0;
	while (i < argc) {
		str_bzero_org = strdup(argv[i]);
		str_bzero_ft = strdup(argv[i]);
		min_length = min(strlen(argv[i]), 5);
		bzero(str_bzero_org, min_length);
		ft_bzero((void*)str_bzero_ft, min_length);
		if (memcmp(str_bzero_org, str_bzero_ft, min_length) == 0)
			printf("G");
		else
			printf("[%s|%d]", argv[i], min_length);
		free(str_bzero_org);
		free(str_bzero_ft);
		i++;
	}
	printf("\n");

	/*
	calloc
	*/
	printf("\n---calloc---[string|checked|length]\n");

	char	*str_calloc = NULL;
	int		length = 0;

	i = 0;
	while (i < argc) {
		length = strlen(argv[i]) + 1;
		str_calloc = (char*)ft_calloc(length, sizeof(*str_calloc));
		if (str_calloc)
		{
			j = 0;
			while (j < length)
				if (str_calloc[j++])
					break ;
			if (j == length)
				printf("G");
			else
				printf("[content:%s:%d/%d]", argv[i], j, length);
			free(str_calloc);
		}
		else
			printf("[malloc:%s:%d]", argv[i], length);
		str_calloc = NULL;
		i++;
	}
	printf("\n");

	/*
	is_
	*/

	printf("\n---isalnum---");
	test_char_ft(&isalnum, &ft_isalnum);

	printf("\n---isalpha---");
	test_char_ft(&isalpha, &ft_isalpha);

	printf("\n---isascii---");
	test_char_ft(&isascii, &ft_isascii);

	printf("\n---isdigit---");
	test_char_ft(&isdigit, &ft_isdigit);

	printf("\n---isprint---");
	test_char_ft(&isprint, &ft_isprint);

	/*
	itoa
	*/
	printf("\n---itoa---[number|sprintf|yours]\n");

	long	test_itoa[50] = { 0, 1, -1, 12, 21, -21, -12, 2147483999, -2147483999, 123456, -123456, 2147483648, -2147483648, 2147483647, -2147483647 };
	i = 0;
	char *str_itoa = NULL;
	char str2[50] = "";
	while (i < 50) {
		sprintf(str2, "%d", (int)test_itoa[i]);
		str_itoa = ft_itoa((int)test_itoa[i]);
		if (strcmp(str2, str_itoa) == 0) {
			printf("G");
		} else {
			printf("[%d|%s|%s]", (int)test_itoa[i], str2, str_itoa);
		}
		i++;
		free(str_itoa);
	}
	printf("\n");

	/*
	memccpy
	*/
	printf("\n---memccpy---[string|memccpy|yours]\n");

	int memccpy_length = 0;
	char	str_dest[250] = "";
	char	str_ft_dest[250] = "";
	i = 0;
	while (i < argc) {
		memccpy_length = strlen(argv[i]);
		memccpy(str_dest, argv[i], 'c', memccpy_length);
		ft_memccpy(str_ft_dest, argv[i], 'c', memccpy_length);
		if (strcmp(str_dest, str_ft_dest) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_dest, str_ft_dest);
		}
		i++;
	}
	printf("\n");

	/*
	memchr
	*/
	printf("\n---memchr---[string|memchr|yours]\n");

	i = 0;
	while (i < argc) {
		if (memchr(argv[i], 'c', 50) == ft_memchr(argv[i], 'c', 50)) {
			printf("G");
		} else {
			printf("[%s|%p|%p]", argv[i], memchr(argv[i], 'c', 50), ft_memchr(argv[i], 'c', 50));
		}
		i++;
	}
	printf("\n");

	/*
	memcmp
	*/
	printf("\n---memcmp---[string|comparison|memcmp|yours]\n");

	i = 0;
	while (i < argc) {
		if (memcmp(argv[i], argv[i], 50) == ft_memcmp(argv[i], argv[i], 50)) {
			printf("G");
		} else {
			printf("[%s|%d|%d]", argv[i], memcmp(argv[i], argv[i], 50), ft_memcmp(argv[i], argv[i], 50));
		}
		if (memcmp(argv[i], argv[argc - 1], 50) == ft_memcmp(argv[i], argv[argc - 1], 50)) {
			printf("G");
		} else {
			printf("[%s|%s|%d|%d]", argv[i], argv[argc - 1], memcmp(argv[i], argv[argc - 1], 50), ft_memcmp(argv[i], argv[argc - 1], 50));
		}
		i++;
	}
	printf("\n");

	/*
	memcpy
	*/
	printf("\n---memcpy---[string|memcpy|yours]\n");

	int memcpy_length = 0;
	i = 0;
	while (i < argc) {
		memcpy_length = strlen(argv[i]);
		memcpy(str_dest, argv[i], memcpy_length);
		ft_memcpy(str_ft_dest, argv[i], memcpy_length);
		if (strcmp(str_dest, str_ft_dest) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_dest, str_ft_dest);
		}
		i++;
	}
	printf("\n");

	/*
	memmove
	*/
	printf("\n---memmove---[string|memmove|yours]\n");

	int memmove_length = 0;
	i = 0;
	while (i < argc) {
		memmove_length = strlen(argv[i]);
		memmove(str_dest, argv[i], memmove_length);
		ft_memmove(str_ft_dest, argv[i], memmove_length);
		if (strcmp(str_dest, str_ft_dest) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_dest, str_ft_dest);
		}
		i++;
	}
	printf("\n");

	/*
	memset
	*/
	printf("\n---memset---[char|memset|yours]\n");

	i = 0;
	while (i < argc) {
		memset(str_dest, argv[i][0], 50);
		ft_memset(str_ft_dest, argv[i][0], 50);
		if (strcmp(str_dest, str_ft_dest) == 0) {
			printf("G");
		} else {
			printf("[%c|%s|%s]", argv[i][0], str_dest, str_ft_dest);
		}
		i++;
	}
	printf("\n");

	/*
	split
	*/
	printf("\n---split (`e.wu-+ `)---[char|string][length|split_length|sep_count|string]\n");

	char to_split[10] = {'e', '.', 'w', 'u', '-', '+', ' ', '0', '2', '1'};
	char **splitted = NULL;
	int	k, l;
	int	out_length, total_length, sep_count;

	i = 0;
	while (i < argc) {
		k = 0;
		while (k < (int)sizeof(to_split))
		{
			splitted = ft_split(argv[i], to_split[k]);
			if (splitted)
			{
				out_length = strlen(argv[i]);
				sep_count = 0;
				l = 0;
				while (argv[i][l])
					if (argv[i][l++] == to_split[k])
						sep_count++;
				total_length = 0;
				j = 0;
				while (splitted[j])
				{
					total_length += strlen(splitted[j]);
					if (strchr(splitted[j], to_split[k]))
						printf("[remaining:%c|%s]", to_split[k], splitted[j]);
					else
						printf("G");
					free(splitted[j]);
					j++;
				}
				free(splitted);
				if (out_length != (total_length + sep_count))
					printf("[missing:%d|%d|%d|%s]", out_length, total_length, sep_count, argv[i]);
				else
					printf("G");
			}
			else
				printf("[malloc:%s]", argv[i]);
			k++;
		}
		i++;
	}
	printf("\n");

	/*
	strchr
	*/
	printf("\n---strchr---[string|strchr|yours]\n");

	i = 0;
	while (i < argc) {
		if (strchr(argv[i], 'c') == ft_strchr(argv[i], 'c')) {
			printf("G");
		} else {
			printf("[%s|%p|%p]", argv[i], strchr(argv[i], 'c'), ft_strchr(argv[i], 'c'));
		}
		i++;
	}
	printf("\n");

	/*
	strdup
	*/
	printf("\n---strdup---[string|strdup|yours]\n");

	char	*str_dup_org = NULL;
	char	*str_dup_ft = NULL;
	i = 0;
	while (i < argc) {
		str_dup_org = strdup(argv[i]);
		str_dup_ft = ft_strdup(argv[i]);
		if (strcmp(str_dup_org, str_dup_ft) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_dup_org, str_dup_ft);
		}
		free(str_dup_org);
		free(str_dup_ft);
		i++;
	}
	printf("\n");

	/*
	strjoin
	*/
	printf("\n---strjoin---[string|asprintf|yours]\n");

	char	*str_join_org = NULL;
	char	*str_join_ft = NULL;
	i = 0;
	while (i < argc) {
		asprintf(&str_join_org, "%s%s", argv[i], argv[0]);
		str_join_ft = ft_strjoin(argv[i], argv[0]);
		if (strcmp(str_join_org, str_join_ft) == 0) {
			printf("G");
		} else {
			printf("[%s%s|%s|%s]", argv[i], argv[0], str_join_org, str_join_ft);
		}
		free(str_join_org);
		free(str_join_ft);
		i++;
	}
	printf("\n");

	/*
	strlcat
	*/
	printf("\n---strlcat---[string|strlcat|yours]\n");

	char str_lcat_org[2550] = "";
	int res_org = 0;
	char str_lcat_ft[2550] = "";
	int res_ft = 0;

	i = 0;
	while (i < argc) {
		res_org = strlcat(str_lcat_org, argv[i], 5);
		res_ft = ft_strlcat(str_lcat_ft, argv[i], 5);
		if (strcmp(str_lcat_org, str_lcat_ft) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_lcat_org, str_lcat_ft);
		}
		if (res_org == res_ft) {
			printf("G");
		} else {
			printf("[%s|%d|%d]", argv[i], res_org, res_ft);
		}
		i++;
	}
	printf("\n");

	/*
	strlcpy
	*/
	printf("\n---strlcpy---[string|strlcpy|yours]\n");

	char str_lcpy_org[2550] = "";
	char str_lcpy_ft[2550] = "";

	i = 0;
	while (i < argc) {
		res_org = strlcpy(str_lcpy_org, argv[i], 5);
		res_ft = ft_strlcpy(str_lcpy_ft, argv[i], 5);
		if (strcmp(str_lcpy_org, str_lcpy_ft) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_join_org, str_join_ft);
		}
		if (res_org == res_ft) {
			printf("G");
		} else {
			printf("[%s|%d|%d]", argv[i], res_org, res_ft);
		}
		i++;
	}
	printf("\n");

	/*
	strlen
	*/
	printf("\n---strlen---[string|strlen|yours]\n");

	i = 0;
	while (i < argc) {
		if (strlen(argv[i]) == ft_strlen(argv[i])) {
			printf("G");
		} else {
			printf("[%s|%zu|%zu]", argv[i], strlen(argv[i]), ft_strlen(argv[i]));
		}
		i++;
	}
	printf("\n");

	/*
	strmapi
	*/
	printf("\n---strmapi---[string|yours]\n");

	char *str_mapi_ft = NULL;
	int all_upper;

	i = 0;
	while (i < argc) {
		str_mapi_ft = ft_strmapi(argv[i], &strupper_and_one);
		all_upper = 1;
		j = 0;
		while (str_mapi_ft[j])
		{
			if (islower(str_mapi_ft[j++]))
			{
				all_upper = 0;
				break ;
			}
		}
		if ((str_mapi_ft[0] == '1' || strlen(str_mapi_ft) == 0) && all_upper)
			printf("G");
		else
			printf("[%s|%s]", argv[i], str_mapi_ft);
		i++;
	}
	printf("\n");

	/*
	strncmp
	*/
	printf("\n---strncmp---[string|strncmp|yours]\n");
	int	ncmp_ret;
	int	nft_cmp_ret;

	i = 0;
	while (i < argc) {
		ncmp_ret = strncmp(argv[i], argv[i], 50);
		nft_cmp_ret = ft_strncmp(argv[i], argv[i], 50);
		if (ncmp_ret == nft_cmp_ret || same_sign(ncmp_ret, nft_cmp_ret)) {
			printf("G");
		} else {
			printf("[%s|%d|%d]", argv[i], ncmp_ret, nft_cmp_ret);
		}

		ncmp_ret = strncmp(argv[i], argv[argc - 1], 50);
		nft_cmp_ret = ft_strncmp(argv[i], argv[argc - 1], 50);
		if (ncmp_ret == nft_cmp_ret || same_sign(ncmp_ret, nft_cmp_ret)) {
			printf("G");
		} else {
			printf("[%s|%s|%d|%d]", argv[i], argv[argc - 1], ncmp_ret, nft_cmp_ret);
		}
		i++;
	}
	printf("\n");

	/*
	strnstr
	*/
	printf("\n---strnstr---[string|strnstr|yours]\n");

	i = 0;
	while (i < argc) {
		if (strnstr(argv[i], argv[i], 50) == ft_strnstr(argv[i], argv[i], 50)) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], strnstr(argv[i], argv[i], 50), ft_strnstr(argv[i], argv[i], 50));
		}
		if (strnstr(argv[i], argv[argc - 1], 50) == ft_strnstr(argv[i], argv[argc - 1], 50)) {
			printf("G");
		} else {
			printf("[%s|%s|%s|%s]", argv[i], argv[argc - 1], strnstr(argv[i], argv[argc - 1], 50), ft_strnstr(argv[i], argv[argc - 1], 50));
		}
		if (strnstr(argv[i], "e", 50) == ft_strnstr(argv[i], "e", 50)) {
			printf("G");
		} else {
			printf("[%s|e|%s|%s]", argv[i], strnstr(argv[i], argv[argc - 1], 50), ft_strnstr(argv[i], argv[argc - 1], 50));
		}
		if (strnstr(argv[i], "e", 0) == ft_strnstr(argv[i], "e", 0)) {
			printf("G");
		} else {
			printf("[%s|e|%s|%s]", argv[i], strnstr(argv[i], argv[argc - 1], 50), ft_strnstr(argv[i], argv[argc - 1], 50));
		}
		i++;
	}
	printf("\n");

	/*
	strrchr
	*/
	printf("\n---strrchr---[string|strrchr|yours]\n");

	i = 0;
	while (i < argc) {
		if (strrchr(argv[i], 'c') == ft_strrchr(argv[i], 'c')) {
			printf("G");
		} else {
			printf("[%s|%p|%p]", argv[i], strrchr(argv[i], 'c'), ft_strrchr(argv[i], 'c'));
		}
		i++;
	}
	printf("\n");

	/*
	strtrim
	*/
	printf("\n---strtrim (` .+-e`)---[where|string|yours]\n");

	char set[10] = " .+-e";
	char *str_trim = NULL;

	i = 0;
	while (i < argc) {
		str_trim = ft_strtrim(argv[i], " .+-e");
		if (str_trim)
		{
			j = 0;
			while (argv[i][j] && _c_in_set(argv[i][j], set))
				j++;
			if (argv[i][j] == str_trim[0])
				printf("G");
			else
				printf("[start|%s|%s]", argv[i], str_trim);

			j = max(0, strlen(argv[i]) - 1);
			while (j >= 0 && _c_in_set(argv[i][j], set))
				j--;
			if (argv[i][j] == str_trim[max(0, strlen(str_trim) - 1)])
				printf("G");
			else
				printf("[end|%s|%s]", argv[i], str_trim);
			free(str_trim);
			i++;
		}
		else
			printf("[malloc:%s]", argv[i]);
	}
	printf("\n");

	/*
	substr
	*/
	printf("\n---substr---[original|yours|strncpy|start|length]\n");

	char *str_substr = NULL;
	char *str_substr_org = NULL;
	int argv_length;

	str_substr_org = (char*)malloc(sizeof(*str_substr_org) * 500);
	i = 0;
	while (i < argc) {
		argv_length = strlen(argv[i]);
		min_length = min(argv_length, 5);
		str_substr = ft_substr(argv[i], 0, min_length);
		strncpy(str_substr_org, argv[i], min_length);
		str_substr_org[min_length] = 0;
		if (strcmp(str_substr, str_substr_org) == 0)
			printf("G");
		else
			printf("[%s|%s|%s|0|%d]", argv[i], str_substr, str_substr_org, min_length);
		free(str_substr);
		if (min_length > 5)
		{
			min_length = min(argv_length, 10);
			str_substr = ft_substr(argv[i], 5, min_length);
			strncpy(str_substr_org, argv[i] + 5, min_length);
			str_substr_org[5 + min_length] = 0;
			if (strcmp(str_substr, str_substr_org) == 0)
				printf("G");
			else
				printf("[%s|%s|%s|5|%d]", argv[i], str_substr, str_substr_org, min_length);
			free(str_substr);
		}
		i++;
	}
	free(str_substr_org);
	printf("\n");

	/*
	to_
	*/
	printf("\n---tolower---");
	test_char_ft(&tolower, &ft_tolower);

	printf("\n---toupper---");
	test_char_ft(&toupper, &ft_toupper);

	/*
	ft_*_fd
	*/
	printf("\n---fd_functions---\n");

	int	fd = open("test_user_fd", O_RDWR | O_TRUNC | O_CREAT);
	if (fd < 0) {
		printf("open error %d %s\n", errno, strerror(errno));
	} else {
		printf("Writing... left column is expected.\n");
		ft_putchar_fd('1', fd);
		ft_putstr_fd("23456789", fd);
		ft_putendl_fd("abcdef", fd);
		ft_putnbr_fd(123456789, fd);
		ft_putnbr_fd(1, fd);
		ft_putnbr_fd(-123456789, fd);
		ft_putnbr_fd(-1, fd);
		ft_putnbr_fd(0, fd);
		ft_putnbr_fd(-0, fd);
		ft_putendl_fd("", fd);
		ft_putnbr_fd((int)2147483648, fd);
		ft_putnbr_fd((int)2147483649, fd);
		ft_putendl_fd("", fd);
		ft_putnbr_fd((int)-2147483648, fd);
		ft_putnbr_fd((int)-2147483649, fd);
		ft_putnbr_fd(-0, fd);
		ft_putstr_fd("", fd);
		ft_putendl_fd("", fd);
		ft_putchar_fd('@', fd);
		ft_putchar_fd('\\', fd);
		ft_putchar_fd('\%', fd);
		ft_putchar_fd('$', fd);
	}
	close(fd);

	return (0);
}
