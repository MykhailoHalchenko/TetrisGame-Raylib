#include "block.h"

block::block() {
	CellSize = 30;
	RotationState = 0;
	Colors = get_cell_colors();
	RowOffset = 0;
	ColumnOffset = 0;
}

void block::draw(int OffsetX, int OffsetY) {
	std::vector<position> Tiles = get_cell_positions();
	for (position item: Tiles) {
		DrawRectangle(item.Column * CellSize + OffsetX, item.Row * CellSize + OffsetY, CellSize - 1, CellSize - 1, Colors[Id]);
	}
}

void block::move(int Rows, int Columns) {
	RowOffset += Rows;
	ColumnOffset += Columns;
}

std::vector<position> block::get_cell_positions() {
	std::vector<position> Tiles = Cells[RotationState];
	std::vector<position> MovedTiles;
	for (position item : Tiles) {
		position NewPos = position(item.Row + RowOffset, item.Column + ColumnOffset);
		MovedTiles.push_back(NewPos);
	}
	return MovedTiles;
}

void block::rotate() {
	RotationState++;
	if (RotationState == (int)Cells.size()) {
		RotationState = 0;
	}
}

void block::undo_rotation()
{
	RotationState--;
	if (RotationState == -1) {
		RotationState = Cells.size() - 1;
	}
}


