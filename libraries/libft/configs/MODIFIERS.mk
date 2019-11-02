
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
ifeq ($(OS_DETECT),$(OS_LINUX))
	CLEAR = clear && printf "\e[3J"
else ifeq ($(OS_DETECT),$(OS_OSX))
	CLEAR = clear && printf "\e[3J"
else ifeq ($(OS_DETECT),$(OS_WINDOWS))
	CLEAR = clean"
endif
