/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:31:08 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/16 11:17:35 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	you_win(void)
{
	ft_printf("YOU WIN");
	exit(1);
}

void	you_lose(int res)
{
	if (res == 'E')
		ft_printf("you need to have just one end! ");
	if (res == 'C')
		ft_printf("you need to have at least one collectible! ");
	if (res == 'P')
		ft_printf("you need to have just one start! ");
	if (res == 'T')
		ft_printf("invalide path!");
	if (res == 'L')
		ft_printf("YOU DEATH!");
	if (res == 'N')
		ft_printf("check your file name!");
	if (res == 'Q')
		ft_printf("check map!");
	if (res == 'W')
		ft_printf("ERROR!");
	exit(0);
}
