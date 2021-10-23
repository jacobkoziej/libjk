/*
 * sll/init.c -- jk_sll_init() tests
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

#include "test.h"
#include "wrap_calloc.h"


static void test_calloc_fail(void **state)
{
	(void) state;
	jk_sll_t *sll = NULL;


	g_wrap_calloc_fail = 0;
	sll = jk_sll_init();
	assert_null(sll);
}


int main(void)
{
	static const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_calloc_fail),
	};


	return cmocka_run_group_tests(tests, NULL, NULL);
}
