/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:41:21 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/09/20 17:35:18 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "libft.h"
# include <stdbool.h>

/**
 * Dynamic vector data sturcture that can hold any type of data and manipulate
 * it effiecently
 * 
 * @param memory Array that holds the data.
 * @param elem_size The size of the elements
 * @param alloc_size Holds the size of the allocated memory
 * @param len Holds the actual length of the data.
 */
typedef struct s_vec
{
	unsigned char	*memory;
	size_t			elem_size;
	size_t			alloc_size;
	size_t			len;
}	t_vec;

/**
 * Initializes the vector.
 * 
 * @param[out] dst Vector to initialize.
 * @param[in] init_len Initial length.
 * @param[in] elem_size Size of the elements stored.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_new(t_vec *dst, size_t init_len, size_t elem_size);

/**
 * Frees the vectors memory and zeroes the structure.
 * 
 * @param[out] src Vector to free.
 */
void	vec_free(t_vec *src);

/**
 * Takes a pointer to a memory area and copies it to the new vector `dst`
 * 
 * @param[out] dst The new uninitialized vector.
 * @param[in] src Pointer to a memory area.
 * @param[in] len The length of the memory area.
 * @param[in] elem_size The size of the element in the memory area.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_from(t_vec *dst, void *src, size_t len, size_t elem_size);

/**
 * Copies at most as many bytes as are available in the `dst` vector.
 * 
 * @param[out] dst The vector to copy to.
 * @param[in] src The vector to copy from.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_copy(t_vec *dst, t_vec *src);

/**
 * Resizes the vector.
 * 
 * @param[out] src The vector to resize.
 * @param[in] target_size The desired size of the vector.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_resize(t_vec *src, size_t target_size);

/**
 * Pushes an element to the end of the vector.
 * 
 * @param[out] dst The vector to push the element to.
 * @param[in] src The element to push.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_push(t_vec *dst, void *src);

/**
 * Removes the last element of the vector and copies it into `dst`.
 * 
 * @param[out] dst The memory where the element will be copied.
 * @param[out] src The vector remove the element from.
 * 
 * @returns 1 on success and -1 on error
 */
int		vec_pop(void *dst, t_vec *src);

/**
 * Returns an opaque handle to the element at `index`.
 * 
 * @param[in] src The vector from which to return an element.
 * @param[in] index The index of the element.
 * 
 * @returns An opaque handle to the element at `index`.
 */
void	*vec_get(t_vec *src, size_t index);

/**
 * Inserts a new element at any position in the vector without overwriting
 * existing elements.
 * 
 * @param[out] dst Vector to insert the element to.
 * @param[in] src The element to insert.
 * @param[in] index The index of the position in the vector where the element
 * will be inserted.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_insert(t_vec *dst, void *src, size_t index);

/**
 * Removec an element from any position in the vector without overwriting
 * existing elements.
 * 
 * @param[out] src The vector to remove the element from.
 * @param[in] index The index of the element.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_remove(t_vec *src, size_t index);

/**
 * Appends the vector `src` to `dst`.
 * 
 * @param[out] dst The vector to which `src` will be appended.
 * @param[in] src The vector to append.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_append(t_vec *dst, t_vec *src);

/**
 * Prepends the vector `src` to `dst`.
 * 
 * @param[out] dst The vector to which `src` will be prepended.
 * @param[in] src The vector to prepend.
 * 
 * @returns 1 on success and -1 on error. 
 */
int		vec_prepend(t_vec *dst, t_vec *src);

/**
 * Applies the function `f` to each element in the vector.
 * 
 * @param[out] src The vector to apply the function to.
 * @param[in] f The function to apply.
 */
void	vec_iter(t_vec *src, void (*f)(void *));

/**
 * Applies the function `f` to a copy of each element in `src`
 * the copied element will be added to vector `dst`.
 * 
 * @param[out] dst The vector where the element will be stored after applying
 * the function `f`.
 * @param[in] src The vector to apply the function to.
 * @param[in] f The function to apply.
 */
void	vec_map(t_vec *dst, t_vec *src, void (*f)(void *));

/**
 * Applies the function `f` to a copy of each element in `src`
 * the copied element will be added to vector `dst` if `true`
 * is returned from `f`.
 * 
 * @param[out] dst The vector where the element will be stored after applying
 * the function `f`.
 * @param[in] src The vector to apply the function to.
 * @param[in] f The function to apply.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_filter(t_vec *dst, t_vec *src, bool (*f)(void *));

/**
 * Applies the function `f` to each element in the vector. The function takes
 * `acc` as it's first argument.
 * 
 * @param[in] acc The first argument to function `f`
 * @param[out] src The vector to apply the function to.
 * @param[in] f The function to apply.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_reduce(void *acc, t_vec *src, void (*f)(void *, void *));

/**
 * Sorts the elements in the vector from smallest to the largest using the
 * function `f`.
 * 
 * @param[out] src The vector to sort.
 * @param[in] f A function determining order and equality between two elements
 * passed as parameters.
 * 
 * @returns 1 on success and -1 on error.
 */
int		vec_sort(t_vec *src, int (*f)(void *, void *));

#endif
