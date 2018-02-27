#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Lib_rules.mk                                       :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/11/02 14:18:27 by mgautier          #+#    #+#             *#
#*   Updated: 2018/01/10 15:16:15 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

.LIBPATTERNS= lib%.a lib%.so
define Lib_rule_specific
$(target).$2: $(objects)
	$(QUIET) $$(LINK_LIB)

$(target): $(target).$2

$(target).$2: include := $(compile_time_include)

$(target).$2: cflags := $(cflags)\
	$(if $(findstring $(shared_lib_suffix),$2),\
	$(shared_lib_compile_flags),$(static_lib_compile_flags))

$(objects): $(obj_dir)%$(obj_suffix):$(src_dir)%$(src_suffix) | $(obj_dir)
	$(QUIET) $$(COMPILE)

endef

define Lib_rule
$(call Lib_rule_specific,$1,$(static_lib_suffix))
vpath $(TARGET_$1).$(static_lib_suffix) $1

endef
#suffix_list$1:= $(suffix_list$1) $(shared_lib_suffix) $(static_lib_suffix)
#$(call Lib_rule_specific,$1,$(shared_lib_suffix))
#vpath $(TARGET$1).$(shared_lib_suffix) $1
