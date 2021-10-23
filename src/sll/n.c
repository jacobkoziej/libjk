/*
 * sll/n.c
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

#include <errno.h>
#include <stddef.h>


void *jk_sll_n(jk_sll_t *list, int n)
{
	if (!list || n < 0 || n > list->nodes - 1) {
		errno = EINVAL;
		return NULL;
	}

	if (!list->head) return NULL;


	jk_sll_node_t *tmp = list->head;
	while (n--) tmp = tmp->next;


	return tmp->data;
}
