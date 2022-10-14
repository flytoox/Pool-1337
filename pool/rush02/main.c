
#include "utils.h"
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define BUFF_SIZE 10000
char    g_buff[BUFF_SIZE];

int handle_args(int ac, char **av, char **ref, char **input_nb)
{
    if (ac == 2)
    {
        *ref = "numbers.dict";
        *input_nb = av[1];
        return (1);
    }
    else if (ac == 3)
    {
        *ref = av[1];
        *input_nb = av[2];
        return (1);
    }
    return (0);
}

t_dict  *create_dict(int fd, char **arr)
{
    ssize_t bytes;
    char    *lines;
    char    line[1000];
    int     i;
    int     number_of_lignes;

    bytes = read(fd,g_buff,BUFF_SIZE);
    lines = malloc(sizeof(char) * (bytes + 1));
    number_of_lignes = 0;
    i = 0;
    while (i < bytes)
    {
        lines[i] = g_buff[i];
        if (lines[i] == '\n')
            number_of_lignes++;
        i++;
    }
    lines[i] = 0;
    arr = ft_split(lines,"\n");
    return (ft_map(arr,number_of_lignes + 1));
}



int main(int ac, char **av)
{
    char    *ref_dict;
    char    *input_nb;
    int     fd;
    char    **arr;
    t_dict  *dict;

    if (handle_args(ac,av,&ref_dict,&input_nb))
    {
        fd = open(ref_dict,O_RDONLY);
        if (fd == -1)
        {
            ft_putstr("Error\n");
            return (0);
        }
        dict = create_dict(fd,arr);
        print_number(dict,input_nb);
        close(fd);
    }
 
    return 0;
}
