#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Config.mk                                          :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/10/19 15:26:46 by mgautier          #+#    #+#             *#
#*   Updated: 2017/12/13 17:08:51 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SHELL = /bin/bash
DEBUGGER := lldb
CC := gcc
AR := ar
LD := ld
MKDIR := mkdir
RMDIR := rmdir
SED := sed
LN := ln -f
TOUCH := touch
RANLIB := ranlib

FILE_CHAR_RANGE := a-z0-9._
STANDARD = c11

SYSTEM = $(shell uname)

# Compiler flags
ERROR_FLAGS := -Wall -Wextra -Werror -std=$(STANDARD) -pedantic-errors
DEBUG_FLAGS := -g3 -fsanitize=undefined -fsanitize=address -fno-omit-frame-pointer
SYNTAX_FLAGS := -fsyntax-only -ferror-limit=0
OPTI_CFLAGS := -flto -Ofast
OPTI_LDFLAGS := -flto
PROFILE_FLAGS :=
CFLAGS := $(CFLAGS) $(ERROR_FLAGS)
ARFLAGS = rc

# OS dependendant flags 
ifeq ($(SYSTEM),Linux)
	ARFLAGS += -U
shared_flag := -shared
else
	shared_flag := -dynamiclib
endif



# Language settings
#
obj_suffix := .o
src_suffix := .c
shared_lib_suffix := so
static_lib_suffix := a
shared_lib_compile_flags := -fpic


# Makefile defaults
#

# Run command silently by default.
QUIET := @
