/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:44:20 by ariahi            #+#    #+#             */
/*   Updated: 2022/12/28 10:44:26 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int main(int ac, char **av)
{
    
    int fd = open("map.cub", O_RDWR);

    printf("%d\n", fd);
}