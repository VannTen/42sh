#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Dir_traversal.mk                                   :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/10/31 12:38:44 by mgautier          #+#    #+#             *#
#*   Updated: 2018/01/10 14:59:58 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

# Apply one function on a whole subtree of source directories.
# Each directories has for child the directories listed in the SUBDIRS
# variable in the Srcs.mk file in that directory.
#
# This functions should be explicity called with the call built-in.
#
# 1 : Root source directory
# 2 : Functions to be applied. Used one parameter, the directory full path
#
# Nota bene : use with the functions 'define_local_variables' Dir_traversal shall
# call it on the current directory (the parameter $1) before exploring the subdirs,
# since the SUBDIRS variable is populated by define local_variables.
# That is the reason to use a pre-order traversal on the source tree.

define	Dir_traversal
$(call $2,$1)
$(foreach sub,$(SUBDIRS_$1),$(call $0,$1$(sub)/,$2))
endef

# Take an ordered list of function to apply on the src_tree.
# Apply each function on the while tree before applying the other
#
# $1 : source tree root directory
# $2 : function list

define	Apply_to_src_tree
$(foreach function,$2,$(call Dir_traversal,$1,$(function)))
endef

