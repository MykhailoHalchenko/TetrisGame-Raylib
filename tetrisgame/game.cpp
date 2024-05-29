#include "game.h"

game::game() {
	Grid = grid();
	Blocks = get_all_blocks();
	CurrentBlock = get_random_block();
	NextBlock = get_random_block();
	GameOver = false;
	Score = 0;
}

block game::get_random_block() {
	if (Blocks.empty()) {
		Blocks = get_all_blocks();
	}
	int RandIndex = rand() % Blocks.size();
	block block = Blocks[RandIndex];
	Blocks.erase(Blocks.begin() + RandIndex);
	return block;
}

std::vector<block> game::get_all_blocks() {
	return { iblock(), jblock(), oblock(), sblock(), tblock(), zblock() };
}

void game::draw() {
	Grid.draw();
	CurrentBlock.draw(11, 11);
	switch (NextBlock.Id) {
	case 3:
		NextBlock.draw(255, 290);
		break;
	case 4:
		NextBlock.draw(255, 280);
		break;
	default:
		NextBlock.draw(270, 270);
		break;
	}
}

void game::handle_input() {
	int KeyPressed = GetKeyPressed();

	if (GameOver && KeyPressed != 0) {
		GameOver = false;
		reset();
	}
	switch (KeyPressed) {
	case KEY_LEFT:
		move_block_left();
		break;

	case KEY_RIGHT:
		move_block_right();
		break;

	case KEY_DOWN:
		move_block_down();
		update_score(0, 1);
		break;

	case KEY_R:
		rotate_block();
		break;
	}
}

void game::move_block_left() {
	if (!GameOver) {
		CurrentBlock.move(0, -1);
		if (is_block_outside() || block_fits() == false) {
			CurrentBlock.move(0, 1);
		}
	}
}

void game::move_block_right() {
	if (!GameOver) {
		CurrentBlock.move(0, 1);
		if (is_block_outside() || block_fits() == false) {
			CurrentBlock.move(0, -1);
		}
	}
}

void game::move_block_down() {
	if (!GameOver) {
		CurrentBlock.move(1, 0);
		if (is_block_outside() || block_fits() == false) {
			CurrentBlock.move(-1, 0);
			lock_block();
		}
	}
}

bool game::is_block_outside() {
	std::vector<position> Tiles = CurrentBlock.get_cell_positions();
	for (position item : Tiles) {
		if (Grid.is_cell_outside(item.Row, item.Column)) {
			return true;
		}
	}
	return false;
}

void game::reset()
{
	Grid.initialize();
	Blocks = get_all_blocks();
	CurrentBlock = get_random_block();
	NextBlock = get_random_block();
	Score = 0;
}

void game::rotate_block() {
	if (!GameOver) {
		CurrentBlock.rotate();
		if (is_block_outside() || block_fits() == false) {
			CurrentBlock.undo_rotation();
		}
	}
}

void game::lock_block() {
	std::vector<position> Tiles = CurrentBlock.get_cell_positions();
	for (position item : Tiles) {
		Grid.Grid[item.Row][item.Column] = CurrentBlock.Id;
	}
	CurrentBlock = NextBlock;
	if (block_fits() == false) {
		GameOver = true;
	}
	NextBlock = get_random_block();
	int RowsCleared = Grid.clear_full_rows();
	update_score(RowsCleared, 0);
}

bool game::block_fits() {
	std::vector<position> Tiles = CurrentBlock.get_cell_positions();
	for (position item : Tiles) {
		if (Grid.is_cell_empty(item.Row, item.Column) == false) {
			return false;
		}
	}
	return true;
}

void game::update_score(int LinesCleared, int MoveDownPoints) {
	switch (LinesCleared) {
	case 1:
		Score += 100;
		break;
	case 2:
		Score += 300;
		break;
	case 3:
		Score += 500;
		break;
	default:
		break;
	}
	Score += MoveDownPoints;
}
