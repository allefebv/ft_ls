/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:37:07 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 14:47:19 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
void				*ft_memalloc(size_t len);
void				ft_memdel(void **as);

void				ft_bzero(void *s, size_t len);

size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t len);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strnchr(const char *s, int c, int n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrnchr(const char *s, int c, int n);
char				*ft_strstr(const char *s, const char *needle);
char				*ft_strnstr(const char *s, const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
void				ft_strdel(char **as);
void				ft_sstrdel(char **s, int len);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrev(char *s);
char				*ft_strnjoin(char const *s1, char const *s2, size_t len);
char				*ft_strextend(char *s1, char const *s2);
char				*ft_strnextend(char *s1, char const *s2, size_t len);
char				*ft_strupcase(char *str);

char				*ft_itoa(int n);
char				*ft_itoa_base(unsigned long long n, int base);
int					ft_atoi(const char *s);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lst_end(t_list *start);
t_list				*ft_lst_find_prev(t_list *lst, t_list *elem);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *elem);
void				ft_lstadd_end(t_list **alst, t_list *elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstprint_int(t_list *lst);
void				ft_lstprint_str(t_list *lst);
int					ft_lst_size(t_list *lst);
int					ft_lst_n_size(t_list *lst, t_list *end);
int					ft_lst_is_inlist(t_list *list, t_list *elem);
int					ft_lst_is_sorted(t_list *lst);

int					ft_power(int nb, int pwr);
size_t				ft_nblen(int n);
void				ft_sort(int *tab, size_t len);

int					get_next_line(const int fd, char **line);
int					ft_printf(char *format, ...);

#endif
