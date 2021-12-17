/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:55:01 by sakim             #+#    #+#             */
/*   Updated: 2021/12/18 01:23:59 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H

# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define BIGGER 1
# define SMALLER -1
# define I 2
# define NUM 1
# define B 1
# define R 2
# define RR 4
# define S 8
# define P 16
# define MASK1 6
# define SS 32
# define RRR 64
# define RRRR 128
# define INIT 256
# define FINISH 512
# define SET 512
# define GET 256
# define NUMBER 128
# define REINVOKED 8192
# define FAILA -2
# define FAIL -1
# define SUCCESS 0
# define TERM_C 0
# define FALSE 0
# define NILL 0
# define NUM 1
# define CHECKDUP 1
# define TRUE 1
# define PLUS 2
# define MINUS 4
# define LEVEL_WHILE 5
# define ALPHB 8
# define DEC 10
# define ALPHS 16
# define MIN 2
# define MAX 1
# define ABSMINUS 4
# define ABSMIN 8
# define ABSSUM 16
# define ABS 32
# define GETB 4096
# define VAL 1024
# define BUFFER_SIZE 10
# define ERR -1
# define DEL 10
# define OCP 1
# define UNOCP 0
# define EOFF 0
# define READ 1
# define TRUE 1
# define FALSE 0

typedef struct s_dlist
{
	int			size;
	char		data[BUFFER_SIZE];
	void		*next;
}				t_node;

typedef struct s_list
{
	char		ocp;
	int			fd;
	int			size;
	t_node		origin;
	t_node		*current;
}				t_list;

void	clean(t_list *mylist);
int		setlist(t_list *mylist, int size, int off);
int		check(int fd, t_list *mylist);
int		linecheck(t_list *mylist);
int		get_next_line(int fd, char **line);
int		lnk(t_list *mylist, char **line);
int		ft_check(char c, int sign);
int		ft_checknum_form(const char **str);
int		*ft_atoi(const char *str, int s);
int		ft_checkdup(int *p, int size);
int		*ft_getintlist(const char **args, int size, int check);
int		ft_while(const char **str, char toig, int toreturn);
int		*ft_error(void *p);
char	*ft_join(char *str1, char *str2);
int		ft_include(char *str, char c);
int		ft_selecti(int a, int b, int c);
int		*ft_selectp(int *a, int *b, int c);
char	**ft_split(char *str, char deli);
int		ft_strcmp(const char *str1, const char *str2);
void	ft_rotate(int *i, int size, int p);
int		ft_swap(int *a, int *b);
int		ft_which(int *a, int *b, int cmd, int n);
int		ft_pushswap(int *a, int *b, int size);
void	ft_result(int n);
int		ft_v(int type, int value);
int		ft_roll(int x);
void	ft_bingle(int *a, int *b, int c, int d);
int		ft_pivot(int *a, int *b, int size, int off);
int		ft_splitsize(char *str, char deli);
int		ft_strlen(char *str, char deli);
int		ft_cmdset(char *cmd);
int		ft_cmd(int *a, int *b, int cmd, int size);
char	*ft_strcpy(char *str, int size);
void	ft_order(int *a, int size);
void	ft_printf(char *str, int fd);
void	ft_trim(char *str);
int		ft_square(int a);
void	ft_multiplecmd(int *a, int *b, int n);
void	ft_words(int cmd);
int		ft_sp(int *a, int b, int c);
int		ft_leastop(int rota, int rotb, int *l);
int		ft_find(int *a, int val);
int		ft_validate(int *a, int i, int n);
int		ft_checkarray(int *a, int val, int flag);
void	ft_search(int *a, int *b);
int		*ft_free0(void *p);
int		ft_free(char **str, int n);
int		ft_count(char **c);
int		ft_get(int a, int b, int flag);
#endif
