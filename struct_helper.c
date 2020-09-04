/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 16:06:34 by sbrynn            #+#    #+#             */
/*   Updated: 2020/09/04 21:43:55 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_rooms *init_room()
{
	t_rooms *head;

	if (!(head = (t_rooms*)malloc(sizeof(t_rooms*))))
		return NULL;
	head->room = NULL;
	head->x = -1;
	head->y = -1;
	head->next = NULL;

	return head;
}

t_rooms	*add_room(t_rooms *head)
{
	t_rooms *curr;

	curr = head;
	while(curr && curr->next)
	{
		curr = curr->next;
	}
	curr->next = init_room();
	return curr->next;
}

void	free_rooms(t_rooms *head)
{
	t_rooms *curr;
	while(head && head->next)
	{	
		curr = head->next;
		free(head->room);
		free(head);
		head = curr;
	}
	free(head);	
}

t_cnct *init_cnct()
{
	t_cnct *head;

	if (!(head = (t_cnct*)malloc(sizeof(t_cnct*))))
		return NULL;
	head->frm=-1;
	head->to = -1;
	head->next = NULL;

	return head;
}

t_cnct	*add_cnct(t_cnct *head)
{
	t_cnct *curr;

	curr = head;
	while(curr && curr->next)
	{
		curr = curr->next;
	}
	curr->next = init_cnct();
	return curr->next;
}

void	free_cnct(t_cnct *head)
{
	t_cnct *curr;
	while(head && head->next)
	{	
		curr = head->next;
		free(head);
		head = curr;
	}
	free(head);	
}

t_read *init_read()
{
	t_read *head;

	if (!(head = (t_read*)malloc(sizeof(t_read*))))
		return NULL;
	head->ant_cnt=-1;
	head->start[0] = -1;
	head->start[1] = -1;
	head->start_name = NULL;
	head->end[0] = -1;
	head->end[1] = -1;
	head->end_name = NULL;
	head->connect_cnt = 0;
	head->room_cnt = 0;
	head->rooms = NULL;
	head->conect = NULL;
	head->line = NULL;
	head->idx = 0;
	return head;
}

void	free_read(t_read *head)
{
	free_rooms(head->rooms);
	free_cnct(head->conect);
	free(head->line);
	free(head);
}

// //---------------------
// t_text *init_text()
// {
// 	t_text *head;

// 	if (!(head = (t_text*)malloc(sizeof(t_text*))))
// 		return NULL;
// 	head->next = NULL;

// 	return head;
// }

// t_text	*add_text(t_text *head)
// {
// 	t_text *curr;

// 	curr = head;
// 	while(curr && curr->next)
// 	{
// 		curr = curr->next;
// 	}
// 	curr->next = init_text();
// 	return curr->next;
// }

// void	free_text(t_text *head)
// {
// 	t_text *curr;
// 	while(head && head->next)
// 	{	
// 		curr = head->next;
// 		free(head->line);
// 		free(head);
// 		head = curr;
// 	}
// 	free(head);	
// }
