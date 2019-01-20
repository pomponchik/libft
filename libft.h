/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 21:20:15 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/05 21:50:41 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putnbr(int n);
void				ft_lst_strdel(t_list *alst, t_list *first);
float				ft_root(float num, unsigned int root_index);
long int			ft_maxmin(char *type, char *maxmin);
size_t				ft_numch(char *str, char ch);
char				*ft_letter_replacement(char *str, char previous, char new);
void				ft_print_two_dimensional_array(char **str);
void				ft_putnbr_fd(int n, int fd);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int ch);
int					ft_isalpha(int ch);
int					ft_isascii(int ch);
int					ft_isdigit(int ch);
int					ft_isprint(int ch);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *d, const void *s, int ch, size_t c);
void				*ft_memchr(const void *buffer, int ch, size_t count);
int					ft_memcmp(const void *mem1, const void *mem2, size_t n);
void				*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *source, size_t count);
void				*ft_memset(void *destination, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strchr(const char *string, int symbol);
void				ft_strclr(char *s);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strcpy(char *str1, const char *str2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *str1, const char *str2, size_t num);
size_t				ft_strlen(const char *string);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *str1, const char *str2, size_t num);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
char				*ft_strncpy(char *dest, const char *source, size_t count);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
char				*ft_strrchr(const char *string, int symbol);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int ch);
int					ft_toupper(int ch);

#endif
