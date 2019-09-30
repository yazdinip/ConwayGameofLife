#ifndef A3_GAME_STATE_H_
#define A3_GAME_STATE_H_

#include <vector>

enum CellT:bool{Alive = true, Dead = false};

#define BoardEdgeSize 12

#define BoardSize 10

typedef std::vector<std::vector<CellT>> GameStateT;


class StateT {
    public:
        StateT();
        CellT getStatus(int i, int j);
        void changeStatus(CellT c, int i, int j);
        int count(CellT c);
        void updateGame();
        bool is_there_change();
        void gameReset();
    private:
        GameStateT GameBoard;
        int countAliveNeighbour( int i, int j, GameStateT tempGame);
        bool updateCell(int i, int j, GameStateT tempGame);
        bool init_check();
        GameStateT getBoard();
        GameStateT init_2d(int size, CellT c);
        bool invalidPos(int i, int j);
};

#endif