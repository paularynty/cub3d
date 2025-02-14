/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:12:19 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/09/23 12:24:10 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define MAX_FD 1024
# define HEX_BASE "0123456789abcdef"
# define OCTAL_BASE "01234567"
# define BINARY_BASE "01"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/******************************************************************************/
/*                                                                            */
/*                            GET_NEXT_LINE FUNCTIONS                         */
/*                                                                            */
/******************************************************************************/

/**
 * Reads a line from the given file descriptor.
 * 
 * 
 * @param[in] fd The file descriptor containing the file to read.
 * 
 * @returns An allocated string containing the line or NULL when reached
 * the end of file or in case of an error.
 */
char	*get_next_line(int fd);

/**
 * Locates the first occurance of a newline character.
 * 
 * @param[in] str The string from which to search.
 * 
 * @returns The number of characters that precede the newline character
 * or the number of characters that precede the NULL-terminating character
 * if a newline character does not occur in the string.
 */
size_t	ft_strlen_nl(const char *str);

/******************************************************************************/
/*                                                                            */
/*                            FT_PRINTF FUNCTIONS                             */
/*                                                                            */
/******************************************************************************/

/**
 * Writes the formatted string to the standard output.
 * 
 * @param[in] str The string including the formats.
 * 
 * @returns the number of characters written or -1 in case of an error
 */
int		ft_printf(const char *str, ...);

/**
 * Writes a character to the standard output.
 * 
 * @param[in] c The character to write.
 * 
 * @returns 1 on success and -1 on an error.
 */
int		ft_putchar(char c);

/**
 * Converts an integer into characters and writes it on the standard output.
 * 
 * @param n The integer to convert.
 * 
 * @returns the number of characters written or -1 in case of an error.
 */
int		ft_putdecimal(int n);

/**
 * Writes a string on the standard output.
 * 
 * @param[in] s The string to write.
 * 
 * @returns the number of characters written or -1 in case of an error.
 */
int		ft_putstr(char *s);

/**
 * Converts an unsigned integer into characters and writes it to 
 * the standard output.
 * 
 * @param[in] n The unsigned integer to convert.
 * 
 * @returns the number of characters written or -1 in case of an error.
 */
int		ft_putunsign(unsigned int n);

/**
 * Converts an unsigned integer into hexadecimal representation 
 * in the given format and writes it to the standard output.
 * 
 * @param[in] n The unsigned integer to convert
 * @param[in] format The format to convert to.
 * 
 * @returns the number of characters written or -1 in case of an error.
 */
int		ft_printhex(unsigned int n, char format);

/**
 * Writes the address of the given pointer to the standard output.
 * 
 * @param ptr The pointer to write the address of.
 * 
 * @returns the number of characters written or -1 in case of an error.
 */
int		ft_putaddress(void *ptr);

/******************************************************************************/
/*                                                                            */
/*                            MANDATORY FUNCTIONS                             */
/*                                                                            */
/******************************************************************************/

/**
 * Writes `n` zeroed bytes to the string.
 * 
 * @param[out] str The string to write to.
 * @param[in] n The number of bytes to write.
 */
void	ft_bzero(void *str, size_t n);

/**
 * Tests if the given character is a alphabetical character or 
 * a decimal character.
 * 
 * @param[in] c The character to test.
 * 
 * @returns 0 if the character tests false and non-zero if
 * the character tests true.
 */
int		ft_isalnum(int c);

/**
 * Tests for any alphabetical characters.
 * 
 * @param[in] c The character to test.
 * 
 * @returns 0 if the character tests false and non-zero if
 * the character tests true.
 */
int		ft_isalpha(int c);

/**
 * Tests for an ASCII character.
 * 
 * @param[in] c The character to test.
 * 
 * @returns 0 if the character tests false and non-zero if
 * the character tests true.
 */
int		ft_isascii(int c);

/**
 * Tests for a decimal character.
 * 
 * @param[in] c The character to test.
 * 
 * @returns 0 if the character tests false and non-zero if
 * the character tests true.
 */
int		ft_isdigit(int c);

/**
 * Tests for any printable character in the ASCII table.
 * 
 * @param[in] c The character to test.
 * 
 * @returns 0 if the character tests false and non-zero if
 * the character tests true.
 */
int		ft_isprint(int c);

/**
 * Locates the first occurance of `c` in the string `s`.
 * 
 * @param[in] s The string to search from.
 * @param[in] c The byte value to search.
 * @param[in] n The amount of bytes to search.
 * 
 * @returns a pointer to the located character or NULL if
 * the character does not
 * appear within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * Compares byte string `s1` against byte string `s2`.
 * 
 * @param[in] s1 The string to compare against.
 * @param[in] s2 The string to compare.
 * @param[in] n The amount of bytes to compare.
 * 
 * @returns 0 if the stings are identical, otherwise returns the difference
 * between the first two differing bytes.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * Copies `n` bytes from memory area `src` to `dst`.
 * 
 * @param[out] dst The memory area to copy to.
 * @param[in] src The memory area to copy from.
 * @param[in] n The amount of bytes to copy.
 * 
 * @returns the original value of `dst`.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * Copies `len` bytes from memory area `src` to `dst`.
 * 
 * @param[out] dst The memory area to copy to.
 * @param[in] src The memory area to copy from.
 * @param[in] len The length of memory area `src`.
 * 
 * @returns the original value of `dst`.
 */
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * Writes `len` bytes of value `c` to the memory area `str`.
 * 
 * @param[out] str The memory area to write to.
 * @param[in] c The byte value to write.
 * @param[in] len The amount of bytes to write.
 * 
 * @returns the memory area `str`.
 */
void	*ft_memset(void *str, int c, size_t len);

/**
 * Locates the first occurance of `c` in the string `s`.
 * 
 * @param[in] s The string to search from.
 * @param[in] c The character to search.
 * 
 * @returns a pointer to the located occurance or NULL if the character
 * does not appear in the string.
 */
char	*ft_strchr(const char *s, int c);

/**
 * Appends the string `src` to the end of the string `dst`
 * and NULL-terminate the result.
 * 
 * @param[out] dst The string to append to.
 * @param[in] src The string to copy from.
 * @param[in] dstsize The size of `dst`.
 * 
 * @returns the total length of the string it tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * Copies up to `dstsize -1` characters from the string `src`
 * to the string `dst` and NULL-terminates the result.
 * 
 * @param[out] dst The string to copy to.
 * @param[in] src The string to copy from.
 * @param[in] dstsize The amount of bytes to copy.
 * 
 * @returns the total length of the string it tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * Computes the length of the given string.
 * 
 * @param[in] str The string to compute.
 * 
 * @returns the number of characters that precede the
 * terminating NULL character.
 */
size_t	ft_strlen(const char *str);

/**
 * Compares the string s1 against the string s2.
 * 
 * @param[in] s1 The string to compare against.
 * @param[in] s2 The string to compare.
 * @param[in] n The amount of bytes to compare.
 * 
 * @returns 0 if the two strings are identical, otherwise returns the difference
 * between the first two differinng bytes.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * Locates the last occurance of `c` in the string `s`.
 * 
 * @param[in] s The string to search from.
 * @param[in] c The character to search.
 * 
 * @returns a pointer to the located character or NULL if the character does not
 * appear within `n` bytes.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * Converts an uppercase letter to the corresponding lowercase letter.
 * 
 * @param[in] c The uppercase letter to convert.
 * 
 * @returns If the argument is an uppercase letter the function returns the 
 * corresponding lowercase letter if there is one.
 * Otherwise it returns the argument unchanged.
 */
int		ft_tolower(int c);

/**
 * Converts a lowercase letter to the corresponding uppercase letter.
 * 
 * @param[in] c The lowercase letter to convert.
 * 
 * @returns If the argument is a lowercase letter the function returns the
 * corresponding uppercase letter if there is one.
 * Otherwise it returns the argument unchanged.
 */
int		ft_toupper(int c);

/**
 * Locates the first occurance of the string `needle` in the string `haystack`.
 * 
 * @param[in] haystack The string to search from.
 * @param[in] needle The string to search.
 * @param[in] len The amount of bytes to search.
 * 
 * @returns If `needle` is empty `haystack` is returned. If `needle`
 * occurs nowhere in `haystack`, NULL is returned. Otherwise a pointer
 * to the first character of the first occurance of `needle` is returned.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * Converts the initial portion of the string `str` into integer representation.
 * 
 * @param[in] str The string to convert.
 * 
 * @returns The integer representation of `str`.
 */
int		ft_atoi(const char *str);

/**
 * Converts the initial portion of the string `str` into long representation.
 * 
 * @param[in] str The string to convert.
 * 
 * @returns The long representation of `str`.
 */
long	ft_atol(const char *str);

/**
 * Converts the initial portion of the string `str` (which base can be in any
 * base) into integer representation.
 * 
 * @param[in] str The string to convert.
 * @param[in] base An integer representing the length of the base.
 * 
 * @returns The integer representation of `str`.
 */
int		ft_atoi_base(const char *str, int base);

/**
 * Contiguously allocates enough space for `count` objects
 * that are `size` bytes of memory.
 * 
 * @param[in] count The amount of bytes to allocate.
 * @param[in] size The size of the bytes to allocate for.
 * 
 * @returns A pointer to the allocated memory.
 */
void	*ft_calloc(size_t count, size_t size);

/**
 * Allocates sufficient memory for a copy of the string `s1` and does the copy.
 * 
 * @param[in] s1 The string to copy.
 * 
 * @returns A pointer to the new string.
 */
char	*ft_strdup(const char *s1);

/**
 * Allocates and creates a substring from the string `s`.
 * 
 * @param[in] s The string to create a substring from.
 * @param[in] start The starting from which to create the substring.
 * @param[in] len The number of bytes to copy.
 * 
 * @returns The substring or NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * Allocates and creates a new string, which is the result of 
 * the concatenation of `s1` and `s2`.
 * 
 * @param[in] s1 The first string to append.
 * @param[in] s2 The second string to append.
 * 
 * @returns The new string or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * Allocates and creates a copy of `s1` with the characters specified in `set`
 * removed from the beginning and the end of the string.
 * 
 * @param[in] s1 The string to copy.
 * @param[in] set The character to remove.
 * 
 * @returns The trimmed string or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * Allocates and creates an array of strings obtained by splitting
 * the string `s` using the character `c` as a delimiter and
 * NULL terminates the array.
 * 
 * @param[in] s The string to split.
 * @param[in] c The delimiter.
 * 
 * @returns The array of new strings resulting from the split
 * or NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * Allocates and creates a string representing the integer `n`.
 * 
 * @param[in] n The integer to convert.
 * 
 * @returns The string representing the integer or NULL if the allocation fails.
 */
char	*ft_itoa(int n);

/**
 * Applies the function `f` to each character of the string `s`, and passing its
 * first index as argument to allocate and create a new string resulting from
 * the successive applications of `f`
 * 
 * @param[in] s The string to apply the function `f` to.
 * @param[in] f The function to apply to each character of string `s`.
 * 
 * @returns The string created from the successive applications of `f`
 * or NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * Applies the function `f` to each character of the string `s`, passing its
 * index as first argument.
 * 
 * @param[out] s The string to apply the function `f` to.
 * @param[in] f The function to apply to each character of string `s`.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * Outputs the character `c` to the given file descriptor.
 * 
 * @param[in] c The character to output.
 * @param[in] fd The file descriptor to output to.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * Outputs the string `s` to the given file descriptor.
 * 
 * @param[in] s The string to output.
 * @param[in] fd The file descriptor to output to.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * Outputs the string `s` to the given file descriptor followed by a newline.
 * 
 * @param[in] s The string to output.
 * @param[in] fd The file descriptor to output to.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * Outputs the integer `n` to the given file descriptor.
 * 
 * @param[in] n The integer to output.
 * @param[in] fd The file descriptor to output to.
 */
void	ft_putnbr_fd(int n, int fd);

/******************************************************************************/
/*                                                                            */
/*                               BONUS FUNCTIONS                              */
/*                                                                            */
/******************************************************************************/

/**
 * List structure that can contain any type of data.
 * @param content The content of the current node of the list.
 * @param next A pointer to the next node of the list.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * Allocates a new node. The member variable `content` is initialized
 * with the value of the parameter `content`.
 * The variable `next` is initialized NULL.
 * 
 * @param[in] content The content to be set in the `content` variable
 * of the node.
 * 
 * @returns The new node or NULL if the allocation fails.
 */
t_list	*ft_lstnew(void *content);

/**
 * Adds the node `new` at the beginning of the list.
 * 
 * @param[out] lst The list to add the node to.
 * @param[in] new The new node to add to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * Counts the number of nodes in a list.
 * 
 * @param[in] lst The list to count the nodes from.
 * 
 * @returns The length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * Locates the last node of the list.
 * 
 * @param[in] lst The list to iterate through.
 * 
 * @returns The last node of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * Adds the node `new` to the end of the list.
 * 
 * @param[out] lst The list to add the node to.
 * @param[in] new The node to add to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * Frees the memory of the nodes content using
 * the function `del` and frees the node.
 * 
 * @param[out] lst The list pointing to a specific node.
 * @param[in] del The function to apply.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * Deletes and frees the given node and ecery successor of that node,
 * using the function `del`
 * 
 * @param[out] lst The list pointing to a specific node.
 * @param[in] del The function to apply.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * Iterates the list and applies the function `f` on the content of each node.
 * 
 * @param[out] lst The list pointing to a specific node.
 * @param[in] f The function to apply.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Iterates the list and applies the function `f` on the content of each node.
 * Creates a new list resulting of the successive applications of the
 * function `f`
 * 
 * @param[in] lst The list to iterate through.
 * @param[in] f The function to apply on success.
 * @param[in] del The function to apply on failure.
 * 
 * @returns The new list or NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif