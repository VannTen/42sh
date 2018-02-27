#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Standard_targets.mk                                :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/10/31 15:04:08 by mgautier          #+#    #+#             *#
#*   Updated: 2018/01/10 17:08:19 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

# This file provide the standard targets expected by the avarage make user.
# It also establish all as the default goal when no target is specified on the
# command line.

standard_targets := all clean fclean re

all: $(call target,$(srcdir)) ## Build the default target for that directory

all_of = $(foreach macro,$1,$(call $(macro),$2))\
		 $(foreach sub,$(SUBDIRS_$2),$(call $0,$1,$2$(sub)/))
inter_or_lib = $1$(if $(findstring lib,$(TARGET_$1)),,lib)$(TARGET_$1).a

clean: ## Clean object files
	$(QUIET) $(RM) $(call all_of,objects test_obj_files,$(srcdir))

fclean: clean ## Same as clean, but also clean the targets
	$(QUIET) $(RM) $(call all_of,inter_or_lib,$(srcdir)) $(call target,$(srcdir))

re: fclean all ## Redo a clean build (unsafe with --jobs)

all_test = $(test) function_test_$1

check: $(call all_test,$(srcdir)) ## Perform unit tests on $(srcdir)(current or specified on command line)

check-all: $(call all_of,all_test,$(srcdir)) ## Perform unit tests on $(srcdir) all its subrepos

# WARNING : The 're' rules will break on a parallel build, since make will
# attempt to do 'fclean' and 'all' at the same time, effectively building and
# erasing at the same time.
#
# But anyway, doing 'clean' builds is only the consequence of broken Makefiles
# which cannot provide correct incremental builds. So it is perfectly obvious
# that no one will need that rule when using that beautiful, perfect Makefile.
# Isn't it ?

.PHONY: $(standard_targets)
.DEFAULT_GOAL := all

## Help target, print informations about each standard target
##  (credit for that shell command goes to Brikou Carre)
## https://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
help: ## Print this help
	$(QUIET)grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(makefiles_dir)/Standard_targets.mk\
		| awk 'BEGIN {FS = ":.*?## "};\
		{printf "\033[36m%-30s\033[0m \n%s\n", $$1, $$2}' | fold -w $$(tput cols) -s
