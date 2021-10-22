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

if not get_option('unit_tests').disabled() and cmocka_dep.found()
        libjk_tests = {
        }
        test_sources = [
                'wrap_calloc.c',
                'wrap_free.c',
                'wrap_malloc.c',
        ]

        foreach test_name, test_args : libjk_tests
                test_exe = executable(
                        test_name,
                        dependencies : cmocka_dep,
                        include_directories : libjk_incdir,
                        link_args : test_args.get('link_args', []),
                        sources : [
                                libjk_sources,
                                test_name + '.c',
                                test_sources,
                        ],
                )

                test(test_name, test_exe)
        endforeach
endif
