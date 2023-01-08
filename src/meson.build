# SPDX-License-Identifier: GPL-3.0-or-later
#
# Copyright (C) 2023  Jacob Koziej <jacobkoziej@gmail.com>

libjk_sources = files(
        'sll.c',
)


library(
        'jk',
        c_args              : '-DLIBJK_FRIEND',
        include_directories : libjk_incdir,
        sources             : libjk_sources,
)
