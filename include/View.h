#ifndef A3_VIEW_H_
#define A3_VIEW_H_

#include "../include/GameState.h"
#include <vector>
#include <iostream>
#include <string>

StateT initialConfigRead(std::string filename, StateT tempGame);

void outputGameTerminal(StateT tempState);

void outputGameText(std::string filename, StateT tempstate);


#endif