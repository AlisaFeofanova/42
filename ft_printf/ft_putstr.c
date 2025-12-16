/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:39:41 by alfeofan          #+#    #+#             */
/*   Updated: 2025/10/16 14:59:40 by alfeofan         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
/*
#include <stdio.h>

int main(void)
{
    int ret;

    printf("=== TESTING ft_putstr ===\n\n");

    // Test 1: Normal string
    printf("Test 1: Normal string\n");
    printf("Expected: Hello, World!\n");
    ret = ft_putstr("Hello, World!");
    printf("\nReturn value: %d\n\n", ret);

    // Test 2: Empty string
    printf("Test 2: Empty string\n");
    printf("Expected: (nothing)\n");
    ret = ft_putstr("");
    printf("\nReturn value: %d\n\n", ret);

    // Test 3: NULL pointer
    printf("Test 3: NULL pointer\n");
    printf("Expected: (null) or nothing\n");
    ret = ft_putstr(NULL);
    printf("\nReturn value: %d\n\n", ret);

    // Test 4: String with special characters
    printf("Test 4: Special characters\n");
    printf("Expected: Tab:\\t Newline:\\n Quote:\\\"\n");
    ret = ft_putstr("Tab:\t Newline:\n Quote:\"");
    printf("\nReturn value: %d\n\n", ret);

    // Test 5: Long string
    printf("Test 5: Long string\n");
    printf("Expected: This is a very long string to test 
if ft_putstr can handle longer text without any issues!\n");
    ret = ft_putstr("This is a very long string to test if ft_putstr 
can handle longer text without any issues!");
    printf("\nReturn value: %d\n\n", ret);

    // Test 6: String with numbers
    printf("Test 6: String with numbers\n");
    printf("Expected: 1234567890\n");
    ret = ft_putstr("1234567890");
    printf("\nReturn value: %d\n\n", ret);

    // Test 7: String with only spaces
    printf("Test 7: Only spaces\n");
    printf("Expected: '     ' (5 spaces)\n");
    ret = ft_putstr("     ");
    printf("\nReturn value: %d\n\n", ret);

    // Test 8: Single character string
    printf("Test 8: Single character\n");
    printf("Expected: A\n");
    ret = ft_putstr("A");
    printf("\nReturn value: %d\n\n", ret);

    // Test 9: String with all printable ASCII
    printf("Test 9: Printable ASCII characters\n");
    printf("Expected: !\"#$%%&'()*+,-./0123456789:;<=>?@ABCDEFGHI
JKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\n");
    ret = ft_putstr("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJK
LMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    printf("\nReturn value: %d\n\n", ret);

    // Test 10: Multiple consecutive calls
    printf("Test 10: Multiple consecutive calls\n");
    printf("Expected: HelloWorldTest\n");
    ret = ft_putstr("Hello");
    ret += ft_putstr("World");
    ret += ft_putstr("Test");
    printf("\nTotal return value: %d\n\n", ret);

    return (0);
}
*/
