#pragma once
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <raylib.h>
#include "colors.h"

class grid {
public:
	grid();
	void initialize();
	void print();
	void draw();
	bool is_cell_outside(int Row, int Column);
	bool is_cell_empty(int Row, int Column);
	int clear_full_rows();
	int Grid[20][10];
private:
	int NumRows, NumCols, CellSize;
	std::vector<Color> Colors;
	bool is_row_full(int Row);
	void clear_row(int Row);
	void move_row_down(int Row, int NumRows);
};

#endif // !GRID_H