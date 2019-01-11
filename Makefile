##
## Makefile for RaceDriver
##
## Made by Maxime Martens
##

SRCDIR = src

BINDIR = bin

LIBDIR = thirdparty

##

CMAKE = cmake

CXX = g++

RM = rm -rf

CXXFLAGS	= -std=c++17 -ggdb -W -Wall -Wpedantic -Iinclude
CXXFLAGS += -I$(LIBDIR) -I$(LIBDIR)/json/include/ -I$(LIBDIR)/pugixml/src/ -I$(LIBDIR)/lua/
CXXFLAGS += -I$(LIBDIR)/omniunit/include/omniunit/ -I$(LIBDIR)/sol2/

LDFLAGS		= -L$(LIBDIR)/lua/ -llua
# -static-libgcc

ifeq ($(OS),Windows_NT)
	MAKE = mingw32-make
	LDFLAGS += -L$(LIBDIR)/pdcurses/wincon/ -lpdcurses
	LDFLAGS += -L$(LIBDIR)/curl/lib/ -lcurl
else
	MAKE = make
	LDFLAGS += -lncurses
endif

NAME = $(BINDIR)/Racedriver

SRCS = 	$(SRCDIR)/Game.cpp									\
				$(SRCDIR)/Menu.cpp									\
				$(SRCDIR)/MenuItem.cpp							\
				$(SRCDIR)/DataFile.cpp							\
				$(SRCDIR)/ScriptEngine.cpp					\
				$(SRCDIR)/Utils.cpp									\
				$(SRCDIR)/Track.cpp									\
				$(SRCDIR)/Race.cpp									\
				$(SRCDIR)/main.cpp									\
				$(SRCDIR)/menus.cpp									\
				$(SRCDIR)/menusPrincipaux.cpp				\
				$(SRCDIR)/Engine.cpp								\
				$(SRCDIR)/Tires.cpp									\
				$(SRCDIR)/Profile.cpp								\
				$(SRCDIR)/sousMenus.cpp							\
				$(SRCDIR)/Garage.cpp								\
				$(SRCDIR)/Spoiler.cpp								\
				$(SRCDIR)/Terminal.cpp							\
				$(SRCDIR)/Car.cpp										\
				$(SRCDIR)/Accident.cpp							\
				$(LIBDIR)/pugixml/src/pugixml.cpp		\
				$(LIBDIR)/sha/sha.cpp

OBJS = $(SRCS:.cpp=.o)

#Rules

all: racedriver

ifeq ($(OS),Windows_NT)
deps:
	cd $(LIBDIR)/pdcurses/wincon/ && $(MAKE) DLL=Y
	cd $(LIBDIR)/curl/ && $(MAKE) --file=Makefile.dist mingw32
	cd $(LIBDIR)/lua/ && $(MAKE) mingw
else
deps:
	cd $(LIBDIR)/lua/ && $(MAKE) linux
endif

racedriver:	deps $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
