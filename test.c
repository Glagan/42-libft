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

	i = 0;
	while (i < 256) {
		if ((*org)(i) == (*ft)(i)) {
			printf("G");
		} else {
			printf("[%d|%c]", i, i);
		}
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

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	/*
	atoi
	*/
	printf("---atoi---\n");

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
	printf("\n---bzero---\n");

	char *str_bzero_org = NULL;
	char *str_bzero_ft = NULL;
	i = 0;
	while (i < argc) {
		str_bzero_org = strdup(argv[i]);
		str_bzero_ft = strdup(argv[i]);
		bzero(str_bzero_org, 5);
		ft_bzero((void*)str_bzero_ft, 5);
		if (memcmp(str_bzero_org, str_bzero_ft, 5) == 0)
			printf("G");
		else
			printf("[%s|5]", argv[i]);
		free(str_bzero_org);
		free(str_bzero_ft);
		i++;
	}
	printf("\n");

	/*
	calloc
	*/
	printf("\n---calloc---\n");

	ft_calloc(50, sizeof(*str_bzero_ft));
	printf("No seg. fault ?\n");

	/*
	is_
	*/

	printf("\n---isalnum---\n");
	test_char_ft(&isalnum, &ft_isalnum);

	printf("\n---isalpha---\n");
	test_char_ft(&isalpha, &ft_isalpha);

	printf("\n---isascii---\n");
	test_char_ft(&isascii, &ft_isascii);

	printf("\n---isdigit---\n");
	test_char_ft(&isdigit, &ft_isdigit);

	printf("\n---isprint---\n");
	test_char_ft(&isprint, &ft_isprint);

	/*
	itoa
	*/
	printf("\n---itoa---\n");

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
	printf("\n---memccpy---\n");

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
	printf("\n---memchr---\n");

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
	printf("\n---memcmp---\n");

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
	printf("\n---memcpy---\n");

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
	printf("\n---memmove---\n");

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
	printf("\n---memset---\n");

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
	printf("\n---split (e)---\n");

	i = 0;
	while (i < argc) {
		printf(">\"%s\"\n:\"", argv[i]);
		char **splitted = ft_split(argv[i], 'e');
		int j = 0;
		while (splitted[j]) {
			printf("%s", splitted[j]);
			free(splitted[j]);
			if (splitted[++j])
				printf(" ");
		}
		free(splitted);
		printf("\"\n");
		i++;
	}

	/*
	strchr
	*/
	printf("\n---strchr---\n");

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
	printf("\n---strdup---\n");

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
	printf("\n---strjoin---\n");

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
	printf("\n---strlcat---\n");

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
	printf("\n---strlcpy---\n");

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
	printf("\n---strlen---\n");

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
	printf("\n---strmapi---\n");

	char *str_mapi_ft = NULL;
	int j, all_upper;

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
	printf("\n---strncmp---\n");

	i = 0;
	while (i < argc) {
		if (strncmp(argv[i], argv[i], 50) == ft_strncmp(argv[i], argv[i], 50)) {
			printf("G");
		} else {
			printf("[%s|%d|%d]", argv[i], strncmp(argv[i], argv[i], 50), ft_strncmp(argv[i], argv[i], 50));
		}
		if (strncmp(argv[i], argv[argc - 1], 50) == ft_strncmp(argv[i], argv[argc - 1], 50)) {
			printf("G");
		} else {
			printf("[%s|%s|%d|%d]", argv[i], argv[argc - 1], strncmp(argv[i], argv[argc - 1], 50), ft_strncmp(argv[i], argv[argc - 1], 50));
		}
		i++;
	}
	printf("\n");

	/*
	strnstr
	*/
	printf("\n---strnstr---\n");

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
	printf("\n---strrchr---\n");

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
	printf("\n---strtrim (` .+-e`)---\n");

	char *str_trim = NULL;
	i = 0;
	while (i < argc) {
		str_trim = ft_strtrim(argv[i], " .+-e");
		printf(">\"%s\"\n:\"%s\"\n", argv[i], str_trim);
		free(str_trim);
		i++;
	}

	/*
	substr
	*/
	printf("\n---substr---\n");

	char *str_substr = NULL;
	char *str_substr_org = NULL;
	int argv_length;

	str_substr_org = (char*)malloc(sizeof(*str_substr_org) * 500);
	i = 0;
	while (i < argc) {
		argv_length = strlen(argv[i]);

		str_substr = ft_substr(argv[i], 0, 5);
		strncpy(str_substr_org, argv[i], 5);
		if (strcmp(str_substr, str_substr_org) == 0)
			printf("G");
		else
			printf("[%s|%s|%s|0|5]", argv[i], str_substr, str_substr_org);
		free(str_substr);

		str_substr = ft_substr(argv[i], 5, 5);
		if (argv_length > 5)
			strncpy(str_substr_org, argv[i] + 5, 5);
		if (strcmp(str_substr, (argv_length > 5) ? str_substr_org : "") == 0)
			printf("G");
		else
			printf("[%s|%s|%s|5|5]", argv[i], str_substr, str_substr_org);
		free(str_substr);
		i++;
	}
	free(str_substr_org);
	printf("\n");

	/*
	to_
	*/
	printf("\n---tolower---\n");
	test_char_ft(&tolower, &ft_tolower);

	printf("\n---toupper---\n");
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
