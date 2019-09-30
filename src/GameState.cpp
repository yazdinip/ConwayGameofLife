#include "../include/GameState.h"

#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

StateT::StateT(){
    this->GameBoard = init_2d(BoardEdgeSize, Dead);
}

CellT StateT::getStatus(int i, int j){
    if (invalidPos(i, j)){
        throw out_of_range("Indices start from 1 up to " + BoardSize);
    }
    return GameBoard.at(i).at(j);
}

void StateT::changeStatus(CellT c, int i, int j){
    if (invalidPos(i, j)){
        throw out_of_range("The indices start from 1 up to " + BoardSize);
    }
    GameBoard.at(i).at(j) = c;
}

int StateT::count(CellT c){
    int count = 0;
    for (int i = 1; i <= BoardSize; i++){
        for (int j = 1; j <= BoardSize; j++){
            if (GameBoard.at(i).at(j) == c){
                count++;
            }
        }
    }
    return count;
}

void StateT::updateGame(){
    if (!init_check()){
        throw invalid_argument("Game is not initalized correctly");
    }
    GameStateT tempGame = getBoard();
    for (int i = 1; i <= BoardSize; i++){
        for (int j = 1; j <= BoardSize; j++){
            StateT::updateCell(i, j, tempGame);
        }
    }
}

bool StateT::is_there_change(){
    bool accum = true;
    GameStateT temp = GameBoard;
    updateGame();
    for (int i = 1; i <= BoardSize; i++){
        for (int j = 1; j <= BoardSize; j++){
            accum = accum && temp.at(i).at(j) != GameBoard.at(i).at(j);
        }
    }
    GameBoard = temp;
    return accum;
}

void StateT::gameReset(){
    GameBoard = GameStateT(BoardEdgeSize, vector<CellT>(BoardEdgeSize, Dead));
}

int StateT::countAliveNeighbour(int i, int j, GameStateT tempGame){
    int count = 0;
    if (tempGame.at(i-1).at(j-1) == Alive){
        count++;
    }
    if (tempGame.at(i-1).at(j) == Alive){
        count++;
    }
    if (tempGame.at(i-1).at(j+1) == Alive){
        count++;
    }
    if (tempGame.at(i).at(j-1) == Alive){
        count++;
    }
    if (tempGame.at(i).at(j+1) == Alive){
        count++;
    }
    if (tempGame.at(i+1).at(j-1) == Alive){
        count++;
    }
    if (tempGame.at(i+1).at(j) == Alive){
        count++;
    }
    if (tempGame.at(i+1).at(j+1) == Alive){
        count++;
    }
    return count;
}

bool StateT::updateCell(int i, int j, GameStateT tempGame){
    int count = countAliveNeighbour(i, j, tempGame);
    if (tempGame.at(i).at(j) == Alive && count < 2){
        GameBoard.at(i).at(j) = Dead;
    }
    else if (tempGame.at(i).at(j) == Alive && (count == 2 || count == 3)){
        GameBoard.at(i).at(j) = Alive;
    }
    else if (tempGame.at(i).at(j) == Alive && count > 3){
        GameBoard.at(i).at(j) = Dead;
    } 
    else if (tempGame.at(i).at(j) == Dead && count == 3){
        GameBoard.at(i).at(j) = Alive;
    }
    return  GameBoard.at(i).at(j);
}

GameStateT StateT::getBoard(){
    return GameBoard;
}

bool StateT::init_check(){
    return (count(Dead) + count(Alive)) == (BoardSize * BoardSize);
}

GameStateT StateT::init_2d(int size, CellT c){
    return GameStateT(size, vector<CellT>(size, c));
}

bool StateT::invalidPos(int i, int j){
    return  (!(0 < i && i <= BoardSize) ||  !(0 < j && j <= BoardSize));
}
