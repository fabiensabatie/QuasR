# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#              #
#    Updated: 2018/10/28 17:05:13 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

# ------------------------------------------------------------------------------
# Configuration
# ------------------------------------------------------------------------------

ifeq ($(HOSTTYPE),)
  HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

MAKE_DEPS = Makefile

CC=gcc
LD=gcc
LDFLAGS = -shared
CFLAGS = -fPIC

ifneq ($(DEBUG),)
  CONFIG = debug
  CFLAGS += -g3 -O0
  ifneq ($(ASAN),)
  	CFLAGS += -fsanitize=address
  	LDFLAGS += -fsanitize=address
  	TARGET_SUFFIX = .san
  else
    TARGET_SUFFIX = .dev
  endif
else
  CONFIG = release
  CFLAGS += -flto -Ofast -Wall -Werror -Wextra
  LDFLAGS += -flto
endif

BUILD_DIR = build
BUILD_PATH := $(BUILD_DIR)/$(CONFIG)

# ------------------------------------------------------------------------------
# libft
# ------------------------------------------------------------------------------

LIBFT_LIB=libft/libft.a

$(LIBFT_LIB):
	@$(MAKE) -C $(dir $@)

MAKE_DEPS += $(LIBFT_LIB)
CFLAGS += -Ilibft/include
LDFLAGS += -Llibft -lft

# ------------------------------------------------------------------------------
# Sources & Target
# ------------------------------------------------------------------------------

TARGET = libft_malloc

INCLUDE = include

include src/makefile.mk
MAKE_DEPS += src/makefile.mk

TARGET_BIN := $(TARGET)_$(HOSTTYPE)$(TARGET_SUFFIX).so
all: $(TARGET_BIN)

# ------------------------------------------------------------------------------
# Rules
# ------------------------------------------------------------------------------

V ?= @

-include $(addprefix $(BUILD_PATH)/,$(SRC:.c=.d))

$(BUILD_PATH)/%.o: %.c $(MAKE_DEPS)
	@echo "  CC      $(notdir $<)"
	@mkdir -p $(dir $@)
	$(V)$(CC) $< -c $(CFLAGS) $(addprefix -I,$(INCLUDE)) \
		$(addprefix -D,$(DEFINE)) -MMD -MF $(@:.o=.d) -o $@

$(TARGET_BIN): $(addprefix $(BUILD_PATH)/,$(SRC:.c=.o))
	@echo "  LD      $(notdir $@)"
	$(V)$(LD) $^ $(LDFLAGS) $(addprefix -l,$(LDLIBS)) -shared -o $@
	@ln -sf $(TARGET_BIN) libft_malloc.so

clean:
	@$(RM) -rf $(BUILD_DIR)

fclean: clean
	@$(RM) -f $(TARGET_BIN)

re: fclean all

norm:
	@norminette $(shell echo "{include,src}/**.[ch]")