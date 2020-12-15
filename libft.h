/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 20:17:05 by anspirga      #+#    #+#                 */
/*   Updated: 2020/11/08 14:50:51 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_isalpha(int letter);
int		ft_isalnum(int alchar);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_isdigit(int digit);
int		ft_isprint(int letter);
int		ft_isascii(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	ft_bzero(void *str, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *str, int c, size_t len);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif