#include "../include/Game.h"
#include <raylib.h>
#include <assert.h>

Game::Game(int width, int height, std::string title){
    assert(!GetWindowHandle());
    SetTargetFPS(70); 
    InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept{
    assert(GetWindowHandle());
    CloseWindow();
}

bool Game::GameShouldClose() const{
    return WindowShouldClose();
}

void Game::Tick(){
    Update();
    BeginDrawing();
    Draw();
    EndDrawing();
}

void Game::Draw(){
    ClearBackground(RAYWHITE);
    DrawText(TextFormat("Fps: %i",GetFPS()), 10, 10 , 30, LIGHTGRAY);
}

void Game::Update(){
}