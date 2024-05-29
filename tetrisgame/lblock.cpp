#include "lblock.h"

lblock::lblock()
{
	Id = 1;
	Cells[0] = { position(0, 2), position(1, 0), position(1, 1), position(1, 2) };
	Cells[1] = { position(0, 1), position(1, 1), position(2, 1), position(2, 2) };
	Cells[2] = { position(1, 0), position(1, 1), position(1, 2), position(2, 0) };
	Cells[3] = { position(0, 0), position(0, 1), position(1, 1), position(2, 1) };
	move(0, 3);
}

jblock::jblock()
{
	Id = 2;
	Cells[0] = { position(0, 0), position(1, 0), position(1, 1), position(1, 2) };
	Cells[1] = { position(0, 1), position(0, 2), position(1, 1), position(2, 1) };
	Cells[2] = { position(1, 0), position(1, 1), position(1, 2), position(2, 2) };
	Cells[3] = { position(0, 1), position(1, 1), position(2, 0), position(2, 1) };
	move(0, 3);
}

iblock::iblock()
{
	Id = 3;
	Cells[0] = { position(1, 0), position(1, 1), position(1, 2), position(1, 3) };
	Cells[1] = { position(0, 2), position(1, 2), position(2, 2), position(3, 2) };
	Cells[2] = { position(2, 0), position(2, 1), position(2, 2), position(2, 3) };
	Cells[3] = { position(0, 1), position(1, 1), position(2, 1), position(3, 1) };
	move(-1, 3);
}

oblock::oblock()
{
	Id = 4;
	Cells[0] = { position(0, 0), position(0, 1), position(1, 0), position(1, 1) };
	move(0, 4);
}

sblock::sblock()
{
	Id = 5;
	Cells[0] = { position(0, 1), position(0, 2), position(1, 0), position(1, 1) };
	Cells[1] = { position(0, 1), position(1, 1), position(1, 2), position(2, 2) };
	Cells[2] = { position(1, 1), position(1, 2), position(2, 0), position(2, 1) };
	Cells[3] = { position(0, 0), position(1, 0), position(1, 1), position(2, 1) };
	move(0, 3);
}

tblock::tblock()
{
	Id = 6;
	Cells[0] = { position(0, 1), position(1, 0), position(1, 1), position(1, 2) };
	Cells[1] = { position(0, 1), position(1, 1), position(2, 1), position(1, 2) };
	Cells[2] = { position(1, 0), position(1, 1), position(1, 2), position(2, 1) };
	Cells[3] = { position(0, 1), position(1, 0), position(1, 1), position(2, 1) };
	move(0, 3);
}

zblock::zblock()
{
	Id = 7;
	Cells[0] = { position(0, 0), position(0, 1), position(1, 1), position(1, 2) };
	Cells[1] = { position(0, 2), position(1, 1), position(1, 2), position(2, 1) };
	Cells[2] = { position(1, 0), position(1, 1), position(2, 1), position(2, 2) };
	Cells[3] = { position(0, 1), position(1, 0), position(1, 1), position(2, 0) };
	move(0, 3);
}
