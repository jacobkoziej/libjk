# meson.build
# Copyright (C) 2021  Jacob Koziej <jacobkoziej@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

libjk_tests = {
        'sll/init' : {
                'link_args' : [
                        '-Wl,-wrap=calloc',
                ],
        },
}

wrap_sources = [
        'wrap_calloc.c',
        'wrap_free.c',
        'wrap_malloc.c',
        'wrap_realloc.c',
]

libjk_tests_incdir = include_directories('.')


if not get_option('unit_tests').disabled() and cmocka_dep.found()

        foreach test_name, test_args : libjk_tests
                test_exe = executable(
                        'test_' + test_name.underscorify(),
                        dependencies : cmocka_dep,
                        include_directories : [
                                libjk_incdir,
                                libjk_tests_incdir,
                        ],
                        link_args : test_args.get('link_args', []),
                        sources : [
                                libjk_sources,
                                test_name + '.c',
                                wrap_sources,
                        ],
                )

                test(test_name, test_exe)
        endforeach
endif
