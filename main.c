/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:39:02 by sbrynn            #+#    #+#             */
/*   Updated: 2020/09/11 20:53:59 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int gnl(t_read *reader)
{
	char *tmp_1;
	char *tmp_2;

	tmp_1 = NULL;
	tmp_2 = NULL;
	if (reader->line)
	{
		tmp_1 = ft_strjoin(reader->line, ft_strdup("\n"));
		if (reader->global_line)
		{
			tmp_2 = ft_strjoin(reader->global_line, tmp_1);
			free(tmp_1);
			reader->global_line = tmp_2;
		}
		else
			reader->global_line = tmp_1;
		// free(reader->line);
		
	}
	reader->idx = 0;
	return (ft_get_next_line(0,&(reader->line)));
}

int	base_check_room(t_read *reader)
{
	if (reader->line[reader->idx] == 'L')
		return (1);
	if (ft_strchr(reader->line + reader->idx, '-'))
		return (1);
	return (0);
}

// int	add_enter(t_read *reader)
// {
// 	char *tmp;
// 	tmp = ft_strjoin(reader->line, ft_strdup("\n"));
// 	free(reader->line);
// 	reader->line = tmp;
// 	reader->idx++;
// 	return (0);
// }
// int write_coords(t_read *reader, int flag, int x, int y)
// {
// 	t_rooms *curr;
	
// 	curr = reader->rooms;
// 	if (flag == 0)
// 	{
// 		reader->start[0] = x;
// 		reader->start[1] = y;
// 	}
// 	if (flag == 1)
// 	{
// 		reader->end[0] = x;
// 		reader->end[1] = y;
// 	}
// 	else
// 	{
// 		while (curr && curr->next)
// 			curr = curr->next;
// 		if (!curr->room)
// 			return (1);
// 		curr->x = x;
// 		curr->y = y;
// 	}
// 	return (0);
// }

// int	check_coords(t_read *reader, int x, int y)
// {
// 	t_rooms *curr;
	
// 	curr = reader->rooms;
// 	if (reader->start[0] == x && reader->start[1] == y)
// 		return (1);
// 	if (reader->end[0] == x && reader->end[1] == y)
// 		return (1);
// 	while (curr && curr->next)
// 	{
// 		if (curr->x == x && curr->y == y)
// 			return (1);
// 	}
// 	return (0);
// }

// int read_coords(t_read *reader, int flag)
// {
// 	int x;
// 	int y;

// 	x = ft_atoi(reader->line + reader->idx);
// 	if (x == 0 && reader->line[reader->idx + 1] != '0')
// 		return (1);
// 	reader->idx++;
// 	while (reader->line[reader->idx] == ' ')
// 		reader->idx++;
// 	y = ft_atoi(reader->line + reader->idx);
// 	if (y == 0 && reader->line[reader->idx + 1] != '0')
// 		return (1);
// 	if (check_coords(reader, x, y) || write_coords(reader, flag, x, y)) //realize
// 		return (1);
// 	return (0);
// }

// int write_name(t_read *reader, int flag, )

// int read_name(t_read *reader, int flag)
// {
// 	int		i;
// 	char	*name;

// 	i = 0;
// 	if (base_check_room(reader))
// 		return (1);
// 	while (reader->line[reader->idx + i] != ' ')
// 		if (!reader->line[reader->idx + i])
// 			return (1);
// 		i++;
// 	if(!(name = (char*)malloc(sizeof(char)*(i+1))))
// 		return (1);
// 	ft_strncpy(name, reader->line[reader->idx], i);
// 	reader->idx += i;
// 	if (check_name(reader, name) || write_name)//realize
// 		return (1);
// 	if (flag == 0 && !reader->start_name)
// 		reader->start_name = name;
// 	else if (flag == 1 && !reader->end_name)
// 		reader->end_name = name;
// 	else if (flag == 2)
// 	{

// 	}
// 	return (0);
// }
// int	read_start_end(t_read *reader, int flag);
// {
	
	
// 	if (read_coords(reader, flag) || advanced_check_room(reader, flag))
// 		return (1);
// 	return (0);
// }
//shit
int	read_room_content(t_read *reader, t_rooms *room)
{
	int		i;

	i = 0;
	if (base_check_room(reader))
		return (1);
	while (reader->line[reader->idx + i] != ' ')
	{
		if (!reader->line[reader->idx + i])
			return (1);
		i++;
	}
	if(!(room->room = (char*)malloc(sizeof(char)*(i+1))))
		return (1);
	ft_strncpy(room->room, reader->line+reader->idx, i);
	reader->idx += i;
	room->x = ft_atoi(reader->line + reader->idx);
	if (room->x == 0 && reader->line[reader->idx + 1] != '0')
		return (1);
	if (*(reader->line + reader->idx + 1))
	reader->idx++;
	while (reader->line[reader->idx] != ' ')//probeli nepravilno
	{	
		if (!reader->line[reader->idx])
			return (1);
		reader->idx++;
	}
	
	room->y = ft_atoi(reader->line + reader->idx);
	if (room->y == 0 && reader->line[reader->idx + 1] != '0')
		return (1);
	return (0);
}

int	check_room(t_read *reader, t_rooms *room)
{
	t_rooms *curr;
	
	curr = reader->rooms;
	if (reader->start[0] == room->x && reader->start[1] == room->y)
		return (1);
	if (reader->end[0] == room->x && reader->end[1] == room->y)
		return (1);
	if ((reader->start_name && !ft_strcmp(reader->start_name, room->room)) ||\
	(reader->end_name && !ft_strcmp(reader->end_name, room->room)))//lomaetsya
		return (1);
	while (curr && curr->next)
	{
		if (curr->x == room->x && curr->y == room->y)
			return (1);
		if (!ft_strcmp(curr->room, room->room))
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	add_room(t_read *reader, t_rooms *room, int flag)
{
	t_rooms *curr;

	curr = reader->rooms;
	if (flag == 0)
	{
		reader->start_name = room->room;
		reader->start[0] = room->x;
		reader->start[1] = room->y;
		free(room);
	}
	else if (flag == 1)
	{
		reader->end_name = room->room;
		reader->end[0] = room->x;
		reader->end[1] = room->y;
		free(room);
	}
	else
	{
		while (curr && curr->next)
			curr = curr->next;
		if (curr)
			curr->next = room;
		else 
			curr  = room;
	}
	return (0);
}

int	read_room(t_read *reader, int flag)
{
	t_rooms  *room;

	// if (base_check_room(reader))
	// 	return (1);
	room = init_room();
	if (read_room_content(reader, room) ||\
	check_room(reader, room) ||\
	add_room(reader, room, flag))
		return (1);
	// add_enter(reader);
	return (0);
}

int	first_line(t_read *reader)
{
	if (gnl(reader) < 0)
		return (1);
	reader->ant_cnt = ft_atoi(reader->line);
	if (reader->ant_cnt < 1)
		return (1);
	// while(reader->line[reader->idx])
	// 	reader->idx++;
	// add_enter(reader);
	return(0);
}

int	rooms(t_read *reader)
{
	while(gnl(reader))
	{
		if (ft_strcmp(reader->line + reader->idx, "##start") == 0) //##start
		{
			if (reader->start_name)
				return (1);
			// add_enter(reader);
			reader->idx += 7;
			gnl(reader);
			if (read_room(reader, 0))
				return(1);
		}
		else if (ft_strcmp(reader->line + reader->idx, "##end") == 0) //##end
		{
			if (reader->end_name)
				return (1);
			// add_enter(reader);
			reader->idx += 7;
			gnl(reader);
			if (read_room(reader, 1))
				return(1);
		}
		else if(ft_strncmp(reader->line, "#", 1))
		{
			//huinya po chteniu komnat uslovie v linki
			if(read_room(reader, 2))
			{
				if (read_link(reader))
					return (0);
				else
					return (1);
			}
		
		}

	}
	return(0);
}

// int	links(t_read *reader)
// {
	
// }

int	reading(t_read *reader)
{
	// reader = init_read();
	if (first_line(reader) || rooms(reader)) //|| links(reader))
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


	t_read *reader;
	// int i=5;
	// char *line;

	reader = init_read();
	// line = NULL;
	ft_printf("%d\n",reading(reader));
	ft_printf("%s\n", reader->global_line);
	// while(i-- > 0)
	// {
	// 	ft_get_next_line(0, &line);
	// 	ft_printf("%s\n", line);
	// }
	// reader = init_read();
	// first_line(reader);
	// ft_printf("%s", reader->line);
	return(0);
}