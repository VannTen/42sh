#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   main_makefile_user_template.mk                     :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/11/05 14:05:22 by mgautier          #+#    #+#             *#
#*   Updated: 2017/11/05 14:16:34 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

#
# Template of the makefile user shall copy in the directory where make is
# invoked.
# Alternatively, make can be aliased to 'make
# makefiles_dir=/absolute/path/of/makefiles/dir'

makefiles_dir := .
include $(makefiles_dir)/Makefile
