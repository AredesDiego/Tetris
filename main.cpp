#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <cstdio>
#include <iostream>



double lastUpdateTime = 0;

bool EvenTriggered(double interval)
{
    double currenTime = GetTime();
    if(currenTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currenTime;
        return true;
    }
    return false;
}

//****************************************************int main()****************************************************************************
int main () 
{
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    //****************************************************while()****************************************************************************
    while(!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if(EvenTriggered(0.2))//velocidad de caida de los bloques
        {
            game.MoveBlockDown();
        }
        
        BeginDrawing();
        //*******************************************Interface***************************************
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, LightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, LightBlue);
        game.Draw();
        //*****************************************************************************************
        EndDrawing();
    }
    //******************************************************************************************************************************************

    CloseWindow();
    return 0;
}
//***************************************************************************************************************************************
