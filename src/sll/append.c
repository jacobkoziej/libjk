/*
 * sll/append.c
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


int jk_sll_append(jk_sll_t *sll, void *data)
{
	jk_sll_node_t *n = calloc(1, sizeof(jk_sll_node_t));
	if (!n) return -1;


	n->data = data;

	if (!sll->head) {
		sll->head = n;
		sll->tail = n;


		return ++sll->nodes;
	}

	sll->tail = sll->tail->next = n;


	return ++sll->nodes;
}
