CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -Werror=vla -MMD

OBJECTS = mainfiles/main.o mainfiles/TextDisplay.o mainfiles/MoveControl.o mainfiles/cell.o mainfiles/CellObject.o mainfiles/chamber.o mainfiles/ChamberVal.o mainfiles/floor.o character/Character.o character/MakeCharacter.o character/enemy/Elf.o character/enemy/Dwarf.o character/enemy/Orc.o character/enemy/Human.o character/enemy/Halfling.o character/enemy/Merchant.o character/enemy/Dragon.o character/enemy/enemy.o character/player/drow.o character/player/goblin.o character/player/vampire.o character/player/troll.o character/player/shade.o character/player/player.o item/Item.o item/MakeItem.o item/potion/BA.o item/potion/BD.o item/potion/PH.o item/potion/Potion.o item/potion/RH.o item/potion/WA.o item/potion/WD.o item/treasure/DragonHoard.o item/treasure/MerchantHoard.o item/treasure/NormalHoard.o item/treasure/SmallHoard.o item/treasure/Treasure.o floor/Floortiles.o floor/door.o floor/dotground.o floor/empty.o floor/horizonWall.o floor/passage.o floor/stair.o floor/verticalWall.o floor/MakeFloor.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} -lncurses

-include ${DEPENDS}

.PHONY : clean
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
