// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * sll.h -- singly linked list
 * Copyright (C) 2023  Jacob Koziej <jacobkoziej@gmail.com>
 */

#ifndef LIBJK_SLL_H
#define LIBJK_SLL_H


#include <stddef.h>


#ifdef LIBJK_FRIEND
typedef struct jk_sll_node_s {
	struct jk_sll_node_s *next;
	char                  val[];
} jk_sll_node_t;

typedef struct jk_sll_s {
	jk_sll_node_t *head;
	jk_sll_node_t *tail;
	size_t         val_size;
	size_t         node_count;
} jk_sll_t;
#else
typedef struct jk_sll_s jk_sll_t;
#endif  /* LIBJK_FRIEND */


jk_sll_t *jk_sll_alloc(size_t val_size);
void      jk_sll_free(jk_sll_t *sll);


#endif  /* LIBJK_SLL_H */
