#include "grid.h"
#include "colors.h"

grid::grid() {
	NumRows = 20;
	NumCols = 10;
	CellSize = 30;
	initialize();
	Colors = get_cell_colors();
}

void grid::initialize() {
	for (int Row = 0; Row < NumRows; Row++) {
		for (int Column = 0; Column < NumCols; Column++) {
			Grid[Row][Column] = 0;
		}
	}
}

void grid::print()
{
	for (int Row = 0; Row < NumRows; Row++) {
		for (int Column = 0; Column < NumCols; Column++) {
			std::cout << Grid[Row][Column] << "";
		}
		std::cout << std::endl;
	}
}

void grid::draw() {
	for (int Row = 0; Row < NumRows; Row++) {
		for (int Column = 0; Column < NumCols; Column++) {
			int CellValue = Grid[Row][Column];
			DrawRectangle(Column * CellSize + 11, Row * CellSize + 11, CellSize - 1, CellSize - 1, Colors[CellValue]);
		}
	}
}

bool grid::is_cell_outside(int Row, int Column) {
	if (Row >= 0 && Row < NumRows && Column >= 0 && Column < NumCols) {
		return false;
	}
	return true;
}

bool grid::is_cell_empty(int Row, int Column) {
	if (Grid[Row][Column] == 0) {
		return true;
	}
	return false;
}

int grid::clear_full_rows() {
	int Completed = 0;
	for (int Row = NumRows - 1; Row >= 0; Row--) {
		if (is_row_full(Row)) {
			clear_row(Row);
			Completed++;
		}
		else if (Completed > 0) {
			move_row_down(Row, Completed);
		}
	}
	return Completed;
}

bool grid::is_row_full(int Row) {
	for (int Column = 0; Column < NumCols; Column++) {
		if (Grid[Row][Column] == 0) {
			return false;
		}
	}
	return true;
}

void grid::clear_row(int Row) {
	for (int Column = 0; Column < NumCols; Column++) {
		Grid[Row][Column] = 0;
	}
}

void grid::move_row_down(int Row, int NumRows) {
	for (int Column = 0; Column < NumCols; Column++) {
		Grid[Row + NumRows][Column] = Grid[Row][Column];
		Grid[Row][Column] = 0;
	}
}

