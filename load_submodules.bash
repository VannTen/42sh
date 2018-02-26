#!/bin/bash
git submodule update --init &&
git -C grammar_generator submodule init &&
git -C libft submodule init &&

for config_path in .git/modules/{grammar_generator,libft}/config;
do
	cat $config_path | sed 's/url = git@github\.com:/url = https:\/\/github.com\//g' >new_config &&
	mv -f new_config $config_path ;
done &&

git -C grammar_generator submodule update &&
git -C libft submodule update &&
git -C grammar_generator/libft submodule init &&

for config_path in .git/modules/grammar_generator/modules/libft/config;
do
	cat $config_path | sed 's/url = git@github\.com:/url = https:\/\/github.com\//g' >new_config &&
	mv -f new_config $config_path ;
done &&

git -C grammar_generator/libft submodule update &&

for buildsys in {grammar_generator{,/libft},libft}/make-build-system;
do
	cat ${buildsys}/Config.mk | sed 's/^\(CFLAGS :=.*\)$(DEBUG_FLAGS)/\1/g' >new_Config.mk &&
	mv -f new_Config.mk ${buildsys}/Config.mk ;
done ;
