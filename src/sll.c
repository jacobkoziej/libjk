// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * sll.c -- singly linked list
 * Copyright (C) 2023  Jacob Koziej <jacobkoziej@gmail.com>
 */

#include <jk/sll.h>

#include <stddef.h>
#include <stdlib.h>


jk_sll_t *jk_sll_alloc(size_t val_size)
{
	if (!val_size) return NULL;

	jk_sll_t *sll = calloc(1, sizeof(jk_sll_t));
	if (!sll) return NULL;

	sll->val_size = val_size;

	return sll;
}
