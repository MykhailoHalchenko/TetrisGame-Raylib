#include <raylib.h>
#include <iostream>
#include "colors.h"
#include "game.h"

double LasetUpdatedTime = 0;

bool event_triggered(double Interval) {
	double CurrentTime = GetTime();
	if (CurrentTime - LasetUpdatedTime >= Interval) {
		LasetUpdatedTime = CurrentTime;
		return true;
	}
	return false;
}

int main() {
	InitWindow(500, 620, "Tetris Game");
	SetTargetFPS(60);

	Font font = LoadFontEx("fonts\PublicPixel.ttf", 64, 0, 0);

	game Game = game();
	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(DarkBlue);
		Game.draw();
		if (event_triggered(0.2)) {
			Game.move_block_down();
		}
		Game.handle_input();
		DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 375, 175 }, 38, 2, WHITE);
		if (Game.GameOver) {
			DrawTextEx(font, "Game Over!", { 320, 450 }, 38, 2, WHITE);
		}
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, LightBlue);
		char ScoreText[10];
		sprintf_s(ScoreText, sizeof(ScoreText), "%d", Game.Score);
		Vector2 TextSize = MeasureTextEx(font, ScoreText, 38, 2);
		DrawTextEx(font, ScoreText, { 320 + (170 - TextSize.x) / 2, 65}, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, LightBlue);
		EndDrawing();
	}

	CloseWindow();
}