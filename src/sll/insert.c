/*
 * sll/insert.c
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


size_t jk_sll_insert(jk_sll_t *restrict sll, void *data, size_t n)
{
	jk_sll_node_t *tmp = calloc(1, sizeof(jk_sll_node_t));
	if (!tmp) return 0;


	tmp->data = data;

	if (!sll->nodes) {
		sll->head = sll->tail = tmp;
		return ++sll->nodes;
	}

	if (!n) {
		tmp->next = sll->head;
		sll->head = tmp;
		return ++sll->nodes;
	}

	if (n >= sll->nodes - 1) {
		sll->tail = sll->tail->next = tmp;
		return ++sll->nodes;
	}

	jk_sll_node_t *tracer = sll->head;
	--n;  // we want to stop right before the insertion point
	while (n--) tracer = tracer->next;
	tmp->next = tracer->next;
	tracer->next = tmp;


	return ++sll->nodes;
}
