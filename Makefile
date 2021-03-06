include $(CURDIR)/configs/common_variables.mk
include $(CURDIR)/configs/functions.mk

include $(CURDIR)/configs/detect_os.mk
include $(CURDIR)/configs/preparation.mk
include $(CURDIR)/configs/libraries_processing.mk

include $(CURDIR)/configs/process_flag_rules.mk
include $(CURDIR)/configs/create_compile_rules.mk

include $(CURDIR)/configs/MODIFIERS.mk

.PHONY: all
all: $(CLEAR)
ifneq ($(LIBS_NAMES),$(error))
	@$(MAKE_LIBS)
endif
	@$(MAKE) $(NAME) --no-print-directory

.PRECIOUS: $(OBJECTS_DIR)/. $(OBJECTS_DIR)%/.

$(OBJECTS_DIR)/.:
	@$(MKDIR) $@

$(OBJECTS_DIR)%/.:
	@$(MKDIR) $@

.SECONDEXPANSION:

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c | $$(@D)/.
	@$(info [COMPILING]$(tab)$(subst $(SOURCES_DIR),,$<))
	@$(PROJ_CC) $(COMPILE_OBJ_RULE) -c $< -o $@

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.s | $$(@D)/.
	@$(info [COMPILING]$(tab)$(subst $(SOURCES_DIR),,$<))
	@$(PROJ_CC) $(COMPILE_OBJ_RULE) -Wno-unused-command-line-argument -c $< -o $@

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.m | $$(@D)/.
	@$(info [COMPILING]$(tab)$(subst $(SOURCES_DIR),,$<))
	@$(PROJ_CC) $(COMPILE_OBJ_RULE) -c $< -o $@

ifdef CLEAR
$(CLEAR):
	@$(CLEAR)
endif

STATUS:
	@$(info [$@])
	@$(info $(tab)created:$(NAME))
	@$(info $(tab)compiler:$(PROJ_CC))
	@$(info $(tab)flags:$(FLAG))

$(NAME):
	@$(info [CREATING]	$@	[$(BUILD)-$(FLAG)])
	@$(MAKE) -j $(OBJECTS) --no-print-directory
ifneq (,$(ASM_OBJECTS))
	@$(MAKE) -j $(ASM_OBJECTS) --no-print-directory
endif
ifneq (,$(OBC_OBJECTS))
	@$(MAKE) -j $(OBC_OBJECTS) --no-print-directory
endif
	@$(MAKE) -q STATUS --no-print-directory
ifeq ($(LIB_DETECT).a,$(NAME))
	@$(AR) $(AR_FLAGS) $@ $(OBJECTS) $(ASM_OBJECTS)
else
	@$(PROJ_CC) $(OBJECTS) $(ASM_OBJECTS) $(OBC_OBJECTS) $(COMPILE_APP_RULE) -o $@
endif
ifeq ($(LIB_DETECT),$(error))
ifeq (PROFILE,$(findstring PROFILE,$(strip $(FLAG))))
	@./$(NAME) > $(P_OUT) $(P_OUT_FLAGS)
	@$(PROF) $(PROF_FLAGS) $@
endif
endif

.PHONY: clean
clean:
	@$(info [REMOVING] $(OBJECTS_DIR))
	@$(RMDIR) $(OBJECTS_DIR)

.PHONY: fclean
fclean: clean
	@$(info [REMOVING] $(NAME))
	@$(RMFILE) $(NAME)

.PHONY: re
re:
ifdef CLEAR
	@$(CLEAR)
endif
	@$(info [REWORKING])
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: re_libs
re_libs:
	@$(RE_LIBS)

.PHONY: fclean_libs
fclean_libs:
	@$(FCLEAN_LIBS)

.PHONY: re_all
re_all:
	@$(MAKE) -j re_libs --no-print-directory
	@$(MAKE) re --no-print-directory

.PHONY: fclean_all
fclean_all:
	@$(MAKE) -j fclean_libs --no-print-directory
	@$(MAKE) fclean
