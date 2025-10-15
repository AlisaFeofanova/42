/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:44 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/10 20:04:49 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
The malloc(), calloc(), valloc(), realloc(), 
and reallocf() functions allocate memory.  The
     allocated memory is aligned such that
 it can be used for any data type, including AltiVec- and
     SSE-related types.  The aligned_alloc() 
function allocates memory with the requested alignment.
     The free() function frees allocations that
 were created via the preceding allocation functions.
The calloc() function contiguously allocates enough 
space for count objects that are size bytes
     of memory each and returns a pointer to the
 allocated memory.  The allocated memory is filled
     with bytes of value zero.

If successful, calloc(), malloc(), realloc(),
 reallocf(), valloc(), and aligned_alloc()
     functions return a pointer to allocated memory. 
 If there is an error, they return a NULL
     pointer and set errno to ENOMEM.
*/
#include "libft.h"

unsigned char	*malloc_check(unsigned char *ptr)
{
	if (!ptr)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	unsigned char	*ptr;
	size_t			i;

	if (count == 0 || size == 0)
	{
		ptr = malloc(1);
		return (malloc_check(ptr));
	}
	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (malloc_check(ptr));
	i = 0;
	while (i < total_size)
		ptr[i++] = 0;
	return ((void *)ptr);
}
/*
#include <stdio.h>

int main(void)
{
    int *arr = calloc(0, sizeof(int)); 
    if (!arr)
     {
        perror("ft_strdup failed");
        return (1);
    }

    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    free(arr);
    return (0);
}
*/
