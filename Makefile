NAME = ResetDatensenSoftwareTimeTrial
SRC = ./src
LIB = ./lib
BIN = ./bin
COM = g++
EXE = $(BIN)/$(NAME).exe
SRC_ENTRY = $(SRC)/$(NAME).cpp
RM = Remove-Item -Force

all: build

build:
	$(COM) $(SRC_ENTRY) -o $(EXE)

clean:
	$(RM) $(EXE)
