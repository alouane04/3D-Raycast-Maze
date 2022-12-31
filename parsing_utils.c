#include "cube3D.h"

void free_input(t_input *input)
{
    if(input->no)
        free(input->no);
    if(input->so)
        free(input->so);
    if(input->we)
        free(input->we);
    if(input->ea)
        free(input->ea);
    if(input->f)
        free(input->f);
    if(input->c)
        free(input->c);
}

void	init_input(t_input	*input)
{
	input->no = NULL;
	input->so = NULL;
	input->ea = NULL;
	input->we = NULL;
	input->f = NULL;
	input->c = NULL;
	input->map = NULL;
}
