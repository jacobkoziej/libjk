/*
 * sll/free.c
 * Copyright (C) 2021  Jacob Koziej <jacobkoziej@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <jk/sll.h>
#include "sll.h"

#include <stdlib.h>


void jk_sll_free(jk_sll_t *list, void (*free_data) (void *ptr))
{
	if (!list) return;

	jk_sll_node_t *tmp;


	while (list->head) {
		tmp = list->head;
		if (free_data) free_data(tmp->data);
		list->head = tmp->next;
		free(tmp);
	}

	free(list);
}
