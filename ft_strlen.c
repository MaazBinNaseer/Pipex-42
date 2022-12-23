/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:10:08 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/11/12 20:57:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strlen() function computes the length of the string s.
	 The strnlen() function attempts to compute the length of s,
	but never scans beyond the first maxlen bytes of s.

RETURN VALUES
     The strlen() function returns the number of characters that 
	 precede the terminating NUL character.
	 The strnlen() function returns either the same result as 
	 strlen() or maxlen, whichever is smaller.
*/

#include "pipex.h"


// int main()
// {
//     char myarray[] = "Welcome";
//     printf ("The value of the string is : %zu\n", ft_strlen(myarray));
//     return (0);
// }