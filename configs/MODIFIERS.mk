
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

FRAMEWORKS_DIR	:=	$(CURDIR)/libraries/libftsdl/frameworks
$(info $(FRAMEWORKS_DIR))

ifeq ($(OS_DETECT),$(OS_LINUX))
	CLEAR = clear && printf "\e[3J"
# 	COMPILE_APP_RULE	+=	-lX11 -pthread -lm
	COMPILE_APP_RULE	+=	-lX11 -pthread -lm -lSDL2 -lSDL2_image -lSDL2_ttf
# 	COMPILE_APP_RULE	+=	-fopenmp
# 	COMPILE_OBJ_RULE	+=	-fopenmp
	COMPILE_APP_RULE	+=	-mavx -mavx2 -mfma -mprefetchwt1 -mprfchw \
							-mno-sse \
							-mno-sse2 \
							-mno-sse3 \
							-mno-sse4 -mno-sse4.1 -mno-sse4.2 -mno-sse4a \
							-mno-ssse3
	COMPILE_OBJ_RULE	+=	-mavx -mavx2 -mfma -mprefetchwt1 -mprfchw \
							-mno-sse \
							-mno-sse2 \
							-mno-sse3 \
							-mno-sse4 -mno-sse4.1 -mno-sse4.2 -mno-sse4a \
							-mno-ssse3




else ifeq ($(OS_DETECT),$(OS_OSX))
	CLEAR = clear && printf "\e[3J"
# 	COMPILE_APP_RULE	+=	-framework MetalKit -framework Metal -framework cocoa

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