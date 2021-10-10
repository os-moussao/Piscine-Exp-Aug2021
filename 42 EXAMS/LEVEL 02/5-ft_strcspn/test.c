/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:22:03 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:22:06 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int main () {
   int len;
   const char str1[] = "ABCDEF4960910";
   const char str2[] = "xAh";

   len = strspn(str1, str2);

   printf("First matched character is at %d\n", len);
   
   return(0);
}
