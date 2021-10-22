/*
 * wrap_realloc.c -- wrap realloc()
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

#include "wrap_realloc.h"

#include "test.h"


int g_wrap_realloc_fail = WRAP_REALLOC_FAIL_NEVER;


void *__wrap_realloc(void *ptr, size_t size)
{
	if (g_wrap_realloc_fail <= WRAP_REALLOC_FAIL_ALWAYS)
		return NULL;

	if (g_wrap_realloc_fail == WRAP_REALLOC_FAIL_NEVER)
		return test_realloc(ptr, size);

	return (g_wrap_realloc_fail--) ? test_realloc(ptr, size) : NULL;
}
