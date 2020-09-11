/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:46:59 by sbrynn            #+#    #+#             */
/*   Updated: 2020/09/11 19:59:13 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
#define LEMIN_H
#include <string.h>
#include <stdlib.h>
#include "lib/includes/header.h"

typedef struct 		s_rooms
{
	char			*room;
	int				x;
	int				y;
	int				cnt;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_cnct
{
	struct s_rooms	*frm;
	struct s_rooms	*to;
	struct s_cnct	*next;
}					t_cnct;


typedef struct 		s_read
{
	int				ant_cnt;
	char			*start_name;
	char			*end_name;
	int				start[2];
	int				end[2];
	int				connect_cnt;
	int				room_cnt;
	t_rooms			*rooms;
	t_cnct			*conect;
	int				idx;
	char			*line;
	char			*global_line;
}					t_read;

t_read *init_read();
void	free_read(t_read *head);
t_rooms *init_room();
// t_rooms	*add_room(t_rooms *head);
void	free_rooms(t_rooms *head);
t_cnct *init_cnct();
t_cnct	*add_cnct(t_cnct *head);
void	free_cnct(t_cnct *head);

// typedef	struct		s_text
// {
// 	char			*line;
// 	struct s_text	*next;
// }					t_text;
#endif

/*
чекать на старт и энд надо
*/