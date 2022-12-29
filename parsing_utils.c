#include "cube3D.h"

void free_ip(t_input *input)
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