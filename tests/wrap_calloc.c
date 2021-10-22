/*
 * wrap_calloc.c -- wrap calloc()
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

#include "wrap_calloc.h"

#include "test.h"


int g_wrap_calloc_fail = WRAP_CALLOC_FAIL_NEVER;


void *__wrap_calloc(size_t nmemb, size_t size)
{
	if (g_wrap_calloc_fail <= WRAP_CALLOC_FAIL_ALWAYS)
		return NULL;

	if (g_wrap_calloc_fail == WRAP_CALLOC_FAIL_NEVER)
		return test_calloc(nmemb, size);

	return (g_wrap_calloc_fail--) ? test_calloc(nmemb, size) : NULL;
}
