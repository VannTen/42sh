SRC = main.c \
	  \
	  $(addprefix ../../srcs/, \
	  \
	  $(addprefix builtin/, \
	  builtin_cd.c \
	  cd_get_options.c \
	  get_physical_path.c \
	  make_logical.c \
	  canonicalize.c \
	  dotdot.c \
	  dup_env_list.c \
	  ) \
	  \
	  $(addprefix execution/, \
	  chdir_error.c \
	  sh_errstr.c \
	  sh_path_error.c \
	  shell_getenv.c \
	  shell_errmsg.c \
	  ) \
	  \
	  env/ft_getenv.c \
	  env/add_variable_to_env.c \
	  env/clear_env_list.c \
	  )

NAME = cd_test

all: $(NAME)

$(NAME): $(SRC) test.h
	clang -I../../includes -I../../libft -I../../grammar_generator/includes -I. -L../../libft -lft -o $(NAME) $(SRC)
