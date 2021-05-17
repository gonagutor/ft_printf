/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:17:27 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/10 12:11:35 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/*
** Converts a string to an int and returns it
*/
int				ft_atoi(const char *str);
/*
** Sets every character of the string to \0 up to length
*/
void			ft_bzero(void *s, size_t n);
/*
** Allocates memory to the size specified by count*size
*/
void			*ft_calloc(size_t count, size_t size);
/*
** Checks if character is alphanumeric
*/
int				ft_isalnum(int c);
/*
** Checks if character is alphabetic
*/
int				ft_isalpha(int c);
/*
** Checks if character is ASCII
*/
int				ft_isascii(int c);
/*
** Checks if character is a number
*/
int				ft_isdigit(int c);
/*
** Checks if character is printable
*/
int				ft_isprint(int c);
/*
** Copies a section of the memory on source to another section of the memory
** unless the character c appears on the string or up to n length
*/
void			*ft_memccpy(void *dest, const void *source, int c, size_t n);
/*
** Finds the first ocurrence of the given character in the given string up
** to n bytes
*/
void			*ft_memchr(const void *s, int c, size_t n);
/*
** Compares two string up to n bytes
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);
/*
** Copies a section of the memory up to n bytes long
*/
void			*ft_memcpy(void *dest, const void *src, size_t n);
/*
** Moves a section of the memory to another section up to n bytes.
** The strings may overlap; the copy is always done in a non destructive manner
*/
void			*ft_memmove(void *str1, const void *str2, size_t n);
/*
** Sets n len bytes of the memory to c byte
*/
void			*ft_memset(void *b, int c, size_t len);
/*
** Finds c character on the given string
*/
char			*ft_strchr(const char *str, int c);
/*
** Duplicates the given string and returns a pointer to the result
*/
char			*ft_strdup(char *s1);
/*
** Concatenates two strings up to the given size
*/
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
/*
** Copies the given string to a second string up to the given size
*/
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*
** Returns the lenght of the given string
*/
size_t			ft_strlen(char *str);
/*
** Compares two strings up to n
*/
int				ft_strncmp(char *s1, char *s2, size_t n);
/*
** Locates the second string in the first string up to n size
*/
char			*ft_strnstr(const char *h, const char *n, size_t len);
/*
** Locates a character in the given string
*/
char			*ft_strrchr(const char *str, int c);
/*
** Converts character to lowercase
*/
int				ft_tolower(int c);
/*
** Converts character to uppercase
*/
int				ft_toupper(int c);

/*
** Creates a substring from the given string with len bytes long and returns it
*/
char			*ft_substr(char const *s, unsigned int start, size_t len);
/*
** Creates a new string made by joining the two given strings
*/
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new_list);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_list);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
