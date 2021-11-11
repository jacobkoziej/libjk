/*
 * sll/clear.c
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


void jk_sll_clear(jk_sll_t *restrict sll, void (*free_data) (void *ptr))
{
	jk_sll_node_t *tmp;


	if (free_data) {
		while (sll->head) {
			tmp = sll->head;
			free_data(tmp->data);
			sll->head = tmp->next;
			free(tmp);
		}
	} else {
		while (sll->head) {
			tmp = sll->head;
			sll->head = tmp->next;
			free(tmp);
		}
	}

	sll->head = sll->tail = NULL;
	sll->nodes = 0;
}
