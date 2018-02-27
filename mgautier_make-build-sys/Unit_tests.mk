#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Unit_tests.mk                                      :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/11/03 14:51:37 by mgautier          #+#    #+#             *#
#*   Updated: 2018/01/10 15:08:32 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

# This file define rules that allow to accomplish unit test (could be at the
# same time as compilation, or separately)
# Their should be one test by source file (this is under the assumptions that
# most files defines a quite independant functionnality).
# However, it is possible to have functionnality which uses others, and so the 
# test should also link against the directory library (->intermediate target)

# For each source file, one phony rule to test it.
# For each directory, one phony rule to test all source files.
# For each invocation of make, one phony rule to test all source files of all
# directory.
#
# Includes a switch to enable or disable test locally (when they have not be
# written yet)

local_variables_list_unit_test :=\
	TEST_DIR\
	TEST_SRC_DIR\
	DONT_TEST\
	TEST_SUP\
	STATIC_TEST_FILES


# All needed variables

to_test = $(filter-out $(DONT_TEST_$1),$(SRC_$1) $(TEST_SUP_$1))
tests = $(patsubst %$(src_suffix),$(test_bin_dir)/%.last,$(to_test))
test = test_$1
test_exes = $(patsubst %$(src_suffix),$(test_bin_dir)/%,$(to_test))
test_files = $(patsubst %,$(test_src_dir)/%,$(SRC_$1))
test_obj_files = $(patsubst %,%$(obj_suffix),$(test_exes))
static_test_files = $(patsubst %,$(test_src_dir)/%,$(STATIC_TEST_FILES_$1))

test_bin_dir = $1$(TEST_DIR_$1)
test_src_dir = $1$(TEST_SRC_DIR_$1)

# Recipes
define RUN_TEST
$(if $(findstring $(CURDIR),$<),,./)$^
$(TOUCH) $@
endef

define BUILD_TEST
$(CC) $(cflags) $(CFLAGS) $(LDFLAGS) $^ -o $@
endef

define COMPILE_TEST
$(CC) $(cflags) $(cppflags) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $< -c -o $@
endef

# Main rule, applied by directory

Unit_tests = $(if $(TEST_DIR_$1),$(Unit_tests_intern))

define Unit_tests_intern

.PHONY: $(test)

$(test): $(tests)

$(tests): include := $(compile_time_include)

$(tests):$(test_bin_dir)/%.last:$(test_bin_dir)/% $(static_test_files)
	$(QUIET) $$(RUN_TEST)

$(test_exes):\
	$(test_bin_dir)/%:\
	 $(test_bin_dir)/%$(obj_suffix)\
	 $(ext_dependencies) $(patsubst lib%,-l%,$(LIBRARIES_$1)) | $(test_bin_dir)
	$(QUIET) $$(BUILD_TEST)

$(test_obj_files):$(test_bin_dir)/%$(obj_suffix):$(test_src_dir)/%$(src_suffix)\
	| $(test_bin_dir)
	$(QUIET) $$(COMPILE_TEST)

endef
