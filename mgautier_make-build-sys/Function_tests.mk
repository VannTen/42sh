#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Function_tests.mk                                  :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/11/08 15:53:16 by mgautier          #+#    #+#             *#
#*   Updated: 2017/11/08 16:24:32 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

# Define rules for functional test (aka, tests that use the directory TARGET
# and checks that it behaves according to its specifications)

# For convenience, functional test will for now use the same test directory as
# unit tests
# TODO(eventually): change to a specific test directory for function tests
test_func_dir = $(test_src_dir)


# Functional test are assumed to use a scripted language, so there is no rule to
# generate
local_variables_list_functional_test :=\
	TEST_LIST

# Useful macros

test_list = $(patsubst %,$(test_func_dir)/%,$(TEST_LIST$1))
test_check = $(patsubst %,%.last,$(test_list))

# The test pattern execute the first dependencies of the rule (the test) with
# the target as first argument, and the static test files as next parameters 
# those contained in the STATIC_TEST_FILES in Srcs.mk of the local directory.
define Function_tests

$(test_check):$(test_func_dir)/%.last:$(test_func_dir)/%\
	$(target) $(static_test_files)
	$(QUIET) $$(RUN_TEST)

function_test_$1: $(test_check)

.PHONY: function_test_$1

endef
