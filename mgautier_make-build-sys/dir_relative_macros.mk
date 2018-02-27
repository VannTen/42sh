#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   dir_relative_macros.mk                             :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/10/19 17:20:13 by mgautier          #+#    #+#             *#
#*   Updated: 2018/01/10 15:20:27 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

include $(makefiles_dir)/lib_utility_macros.mk

# Macros
# These macros are all relative to the the directory, which is the $1 argument
# They should be used inside a macro expanded by $call, or directly with it

target = $1$(TARGET_$1)
intermediate_target = $1$(if $(findstring lib,$(TARGET_$1)),,lib)$(TARGET_$1).a
ext_dependencies = $(intermediate_target)\
				   $(foreach sub,$(COMPONENTS_$1), $(call ext_dependencies,$(sub)))
all_includes = $(INC_DIR_$1) $(foreach sub,$(SUBDIRS_$1),\
			   $(call all_includes,$(sub)))
compile_time_include = $(foreach inc_dir, $(all_includes), -iquote$(inc_dir))

objects = $(patsubst %$(src_suffix),$(obj_dir)%$(obj_suffix),$(SRC_$1))

# $1 : dir name in uppercase
define define_dir_macro
$(call lower_case,$1) = $$1$$($1_$$1)$$(if $$(strip $$($1_$$1)),/)

endef

specific_sub_dirs := OBJ_DIR SRC_DIR INC_DIR

$(eval $(foreach spec_sub_dir,\
	$(specific_sub_dirs),\
	$(call define_dir_macro,$(spec_sub_dir))))
