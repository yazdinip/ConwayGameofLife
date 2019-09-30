#include "../catch/catch.h"
#include "../include/GameState.h"
#include "../include/View.h"
#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;


TEST_CASE("Test for GameState", "[StateT]"){
    StateT testGame;

    SECTION("getStatus, Default Constructor"){
        for (int i = 1 ; i <= BoardSize; i++){
            for (int j = 1; j <= BoardSize; j++){
                REQUIRE(!testGame.getStatus(i, j));
            }
        }
    }
    SECTION("getStatus - Exception"){
        REQUIRE_THROWS_AS(testGame.getStatus(0, 0), out_of_range);
        REQUIRE_THROWS_AS(testGame.getStatus(BoardEdgeSize - 1, BoardEdgeSize - 1), out_of_range);
        REQUIRE_THROWS_AS(testGame.getStatus(BoardEdgeSize, BoardEdgeSize), out_of_range);
    }
    SECTION("changeStatus"){
        REQUIRE(!testGame.getStatus(1, 1));
        testGame.changeStatus(Alive, 1, 1);
        REQUIRE(testGame.getStatus(1, 1));
        REQUIRE(!testGame.getStatus(5, 7));
        testGame.changeStatus(Alive, 5, 7);
        REQUIRE(testGame.getStatus(5, 7));
    }
    SECTION("ChangeStatus - Exception"){
        REQUIRE_THROWS_AS(testGame.changeStatus(Alive, 0, 0), out_of_range);
        REQUIRE_THROWS_AS(testGame.changeStatus(Dead, BoardEdgeSize, BoardEdgeSize), out_of_range);
    }

    SECTION("count"){
        REQUIRE(testGame.count(Dead) == BoardSize * BoardSize);
        testGame.changeStatus(Alive, 1, 1);
        REQUIRE(testGame.count(Alive) == 1);
        REQUIRE(testGame.count(Dead) == BoardSize * BoardSize - 1);
    }
    SECTION("updateGame - Blinker"){
        testGame.changeStatus(Alive, 5, 5);
        testGame.changeStatus(Alive, 5, 6);
        testGame.changeStatus(Alive, 5, 4);
        testGame.updateGame();
        REQUIRE(testGame.getStatus(5, 5));
        REQUIRE(testGame.getStatus(4, 5));
        REQUIRE(testGame.getStatus(6, 5));
        testGame.updateGame();
        REQUIRE(testGame.getStatus(5, 5));
        REQUIRE(testGame.getStatus(5, 6));
        REQUIRE(testGame.getStatus(5, 4));
    }

    SECTION("updateGame - Beacon"){
        testGame.changeStatus(Alive, 2, 2);
        testGame.changeStatus(Alive, 2, 3);
        testGame.changeStatus(Alive, 3, 2);
        testGame.changeStatus(Alive, 3, 3);
        testGame.changeStatus(Alive, 4, 4);
        testGame.changeStatus(Alive, 4, 5);
        testGame.changeStatus(Alive, 5, 4);
        testGame.changeStatus(Alive, 5, 5);
        testGame.updateGame();
        REQUIRE(testGame.getStatus(2, 2));
        REQUIRE(testGame.getStatus(2, 3));
        REQUIRE(testGame.getStatus(3, 2));
        REQUIRE(!testGame.getStatus(3, 3));
        REQUIRE(!testGame.getStatus(4, 4));
        REQUIRE(testGame.getStatus(4, 5));
        REQUIRE(testGame.getStatus(5, 4));
        REQUIRE(testGame.getStatus(5, 5));
        testGame.updateGame();
        REQUIRE(testGame.getStatus(2, 2));
        REQUIRE(testGame.getStatus(2, 3));
        REQUIRE(testGame.getStatus(3, 2));
        REQUIRE(testGame.getStatus(3, 3));
        REQUIRE(testGame.getStatus(4, 4));
        REQUIRE(testGame.getStatus(4, 5));
        REQUIRE(testGame.getStatus(5, 4));
        REQUIRE(testGame.getStatus(5, 5));
    }

    SECTION("is_there_change"){
        testGame.changeStatus(Alive, 2, 2);
        testGame.changeStatus(Alive, 2, 3);
        testGame.changeStatus(Alive, 3, 2);
        testGame.changeStatus(Alive, 3, 3);
        testGame.changeStatus(Alive, 5, 4);
        testGame.changeStatus(Alive, 5, 5);
        testGame.changeStatus(Alive, 6, 4);
        testGame.changeStatus(Alive, 6, 5);
        REQUIRE(!testGame.is_there_change());
    }

    SECTION("gameReset"){
        testGame.changeStatus(Alive, 2, 2);
        testGame.changeStatus(Alive, 2, 3);
        testGame.changeStatus(Alive, 3, 2);
        REQUIRE(testGame.getStatus(2,2));
        REQUIRE(testGame.getStatus(2,3));
        REQUIRE(testGame.getStatus(3,2));
        testGame.gameReset();
        REQUIRE(!testGame.getStatus(2,2));
        REQUIRE(!testGame.getStatus(2,3));
        REQUIRE(!testGame.getStatus(3,2));
        for (int i = 1 ; i <= BoardSize; i++){
            for (int j = 1; j <= BoardSize; j++){
                REQUIRE(!testGame.getStatus(i, j));
            }
        }
    }

}
