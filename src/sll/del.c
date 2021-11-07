/*
 * sll/del.c
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

#include <stddef.h>
#include <stdlib.h>


void *jk_sll_del(jk_sll_t *sll, size_t n)
{
	if (!sll->nodes || n > sll->nodes - 1) return NULL;

	jk_sll_node_t *prv, *tmp = sll->head;
	void *data;


	if (!n) {
		// special case where
		// we remove the head
		sll->head = tmp->next;
	} else {
		while (n-- && tmp->next) {
			prv = tmp;
			tmp = tmp->next;
		}
		prv->next = tmp->next;

		// we don't want a dangling tail
		// if we're removing the last node
		if (tmp == sll->tail) sll->tail = prv;
	}

	data = tmp->data;
	free(tmp);

	// when there are <= 1 nodes, head and tail point to the same
	// thing: either head or nullptr
	if (--sll->nodes <= 1) {
		sll->tail = sll->head;
	}


	return data;
}
