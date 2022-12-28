#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct s_input{
    char	*no;
    char	*so;
    char	*ea;
	char	*we;
	char	*f;
	char	*c;
	t_list *map;
} t_input;

#endif