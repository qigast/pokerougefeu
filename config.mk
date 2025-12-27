# Default variables

GAME_VERSION  ?= FIRERED
GAME_REVISION ?= 0
GAME_LANGUAGE ?= FRENCH

# Builds the ROM using a modern compiler
MODERN        ?= 0
# Compares the ROM to a checksum of the original - only makes sense using when non-modern
COMPARE       ?= 0

KEEP_TEMPS    ?= 0

ifeq (modern,$(MAKECMDGOALS))
  MODERN := 1
endif
ifeq (compare,$(MAKECMDGOALS))
  COMPARE := 1
endif

# For gbafix
MAKER_CODE := 01

BUILD_DIR := build

# Version
ifeq ($(GAME_VERSION),FIRERED)
  TITLE       := POKEMON FIRE
  GAME_CODE   := BPR
  BUILD_NAME  := rougefeu
else
ifeq ($(GAME_VERSION),LEAFGREEN)
  TITLE       := POKEMON LEAF
  GAME_CODE   := BPG
  BUILD_NAME  := vertfeuille
else
  $(error unknown version $(GAME_VERSION))
endif
endif

# Revision
ifeq ($(GAME_REVISION),1)
  BUILD_NAME  := $(BUILD_NAME)_rev1
endif

# Modern GCC
ifeq ($(MODERN),1)
  BUILD_NAME := $(BUILD_NAME)_modern
endif

# Language
ifeq ($(GAME_LANGUAGE),FRENCH)
  BUILD_NAME  := $(BUILD_NAME)
  GAME_CODE   := $(GAME_CODE)F
else
$(error unknown language $(GAME_LANGUAGE))
endif
