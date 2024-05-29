#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class block {
public:
	block();
	void draw(int OffsetX, int OffsetY);
	void move(int Rows, int Columns);
	int Id;
	std::map<int, std::vector<position>> Cells;
	std::vector<position> get_cell_positions();
	void rotate();
	void undo_rotation();
private:
	int CellSize;
	int RotationState;
	std::vector<Color> Colors;
	int RowOffset, ColumnOffset;
};

#endif // !BLOCK_H

