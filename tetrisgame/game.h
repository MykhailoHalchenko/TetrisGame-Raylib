#pragma once
#include "grid.h"
#include "lblock.h"
#include <random>
class game
{
public:
	game();
	grid Grid;
	block get_random_block();
	std::vector<block> get_all_blocks();
	void draw();
	void handle_input();
	void move_block_left();
	void move_block_right();
	void move_block_down();
	bool GameOver;
	int Score;
private:
	bool is_block_outside();
	void reset();
	void rotate_block();
	void lock_block();
	bool block_fits();
	void update_score(int LinesCleared, int MoveDownPoints);
	std::vector<block> Blocks;
	block CurrentBlock;
	block NextBlock;
};

