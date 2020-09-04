/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:39:02 by sbrynn            #+#    #+#             */
/*   Updated: 2020/09/04 22:38:19 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	read_start(t_read *reader)
{
	
	return (0);
}

int	add_enter(t_read *reader)
{
	char *tmp;
	tmp = ft_strjoin(reader->line, ft_strdup("\n"));
	free(reader->line);
	reader->line = tmp;
	reader->idx++;
	return (0);
}

int	first_line(t_read *reader)
{
	if (ft_get_next_line(0, &(reader->line)) < 0)
		return (1);
	reader->ant_cnt = ft_atoi(reader->line);
	if (reader->ant_cnt < 1)
		return (1);
	while(reader->line[reader->idx])
		reader->idx++;
	add_enter(reader);
	return(0);
}

int	rooms(t_read *reader)
{
	while( ft_get_next_line(0, reader->line))
	{
		if (ft_strcmp(reader->line + reader->idx, "##start") == 0) //##start
		{
			add_enter(reader);
			reader->idx += 7;
			ft_get_next_line(0,reader->line);
			if (read_start(reader))
				return(1);
		}
		else if (ft_strcmp(line, "##end", 5) == 0) //##end
		{
			add_enter(reader);
			reader->idx += 7;
			ft_get_next_line(0,reader->line);
			if (read_end(reader))
				return(1);
		}
		else if(ft_strncmp(line, "#", 1))
		{
			//huinya po chteniu komnat
			if(read_room_link(reader) == 2)
				return (0);
		
		}

	}
	return(0);
}

int	links(t_read *reader)
{
	
}

int	reading(t_read *reader)
{
	reader = init_read();
	if (first_line(reader) || rooms(reader) || links(reader))
		return(1);
	return(0);
}

int	main()
{
	// t_bogdan *bogdan;
	// t_ravil	 *ravil;

	// reading(bogdan);
	// printing(bogdan);
	// copying(bogdan, ravil);
	// freeing(bogdan);


	// t_read *reader;
	// reader = init_read();
	// first_line(reader);
	// ft_printf("%s", reader->line);
	return(0);
}