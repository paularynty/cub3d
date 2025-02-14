/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:59:11 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/05/08 10:35:04 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c > 255)
		return (0);
	if (((unsigned char)c >= 65 && (unsigned char)c <= 90)
		|| ((unsigned char)c >= 97 && (unsigned char)c <= 122))
		return (1);
	else
		return (0);
}
