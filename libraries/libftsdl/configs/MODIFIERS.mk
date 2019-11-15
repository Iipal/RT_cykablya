
#
# PROJ_CC
# DB
#
# FLAG
# BUILD
#
# COMPILE_APP_RULE
# COMPILE_OBJ_RULE
#
# ASAN
# P_FUNCTION 
#

#
# Konsole clear routine - clear && echo -en "\e[3J"
# Otherwise try "reset" or use whatever u want
#

FRAMEWORKS_DIR	:=	$(CURDIR)/frameworks
$(info $(FRAMEWORKS_DIR))

ifeq ($(OS_DETECT),$(OS_LINUX))
	CLEAR = clear && printf "\e[3J"
	COMPILE_APP_RULE	+=	-lX11 -pthread -lm -lSDL2 -lSDL2_image -lSDL2_ttf
else ifeq ($(OS_DETECT),$(OS_OSX))
	CLEAR = clear && printf "\e[3J"

	COMPILE_OBJ_RULE	+=	-I $(FRAMEWORKS_DIR)/SDL2.framework/Headers \
							-I $(FRAMEWORKS_DIR)/SDL2_image.framework/Headers \
							-I $(FRAMEWORKS_DIR)/SDL2_ttf.framework/Headers \
							-F $(FRAMEWORKS_DIR)

	COMPILE_APP_RULE	+=	-rpath $(FRAMEWORKS_DIR) \
							-framework SDL2 \
							-framework SDL2_image \
							-framework SDL2_ttf \
							-framework OpenGL \
							-framework AppKit

else ifeq ($(OS_DETECT),$(OS_WINDOWS))
	CLEAR = clean"
	COMPILE_APP_RULE	+=	-lgdi32
endif