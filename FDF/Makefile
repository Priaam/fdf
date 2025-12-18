NAME        = fdf

# --- CHEMINS (PATHS) ---
SRCS_DIR = srcs/
OBJS_DIR = objs/
MLX_PATH    = libs/minilibx-linux
LIBFT_PATH  = libs/Libft
INCLUDES_DIR = include/

# --- SOURCES ET OBJETS ---
SRCS        = fdf.c fdf_mlx_functions.c fdf_map_functions.c fdf_map_functions2.c fdf_draw_map.c fdf_utils.c
SRCS_FILES 	= $(addprefix $(SRCS_DIR), $(SRCS))
OBJS        = $(SRCS:.c=.o)
OBJS_FILES 	= $(addprefix $(OBJS_DIR), $(OBJS))

# --- COMPILATEUR ET FLAGS ---
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# --- INCLUDES (-I) ---
INCLUDES 	= -I$(INCLUDES_DIR) -I$(LIBFT_PATH)/include -I$(MLX_PATH)

# --- LIBRAIRIES (-L et -l) ---
MLX_FLAGS   = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

# --- RÈGLE PRINCIPALE ---
all: $(NAME)

# La règle de l'exécutable
$(NAME): $(OBJS_DIR) $(OBJS_FILES) # S'assure que le dossier et TOUS les chemins complets sont des dépendances
	@echo "Compilation de la Libft..."
	@make -C $(LIBFT_PATH)
	@echo "Compilation de la MLX..."
	@make -C $(MLX_PATH)
	@echo "Création de l'exécutable $(NAME)..."
	$(CC) $(OBJS_FILES) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

# --- RÈGLE POUR CRÉER LE DOSSIER OBJS ---
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# --- RÈGLE DE COMPILATION DES .c en .o (avec chemins) ---
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(OBJS_DIR)
	@echo "  -> Compiling $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# --- RÈGLES DE NETTOYAGE ---
clean:
	@echo "Nettoyage des fichiers objets..."
	rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_PATH) clean
	@echo "Nettoyage terminé."

fclean: clean
	@echo "Nettoyage de l'exécutable..."
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX_PATH) clean # Nettoyer le .a de la MLX
	@echo "Nettoyage complet terminé."

re: fclean all

.PHONY: all clean fclean re