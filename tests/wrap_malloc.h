/*
 * wrap_malloc.h -- wrap malloc()
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

#ifndef LIBJK_TESTS_WRAP_MALLOC_H_
#define LIBJK_TESTS_WRAP_MALLOC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>


#define WRAP_MALLOC_FAIL_NEVER  (-1)
#define WRAP_MALLOC_FAIL_ALWAYS (-2)


extern int g_wrap_malloc_fail;


void *__wrap_malloc(size_t size);


#ifdef __cplusplus
}
#endif

#endif /* LIBJK_TESTS_WRAP_MALLOC_H_ */
