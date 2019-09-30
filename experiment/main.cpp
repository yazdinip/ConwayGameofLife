#include <iostream>
#include "../include/GameState.h"
#include "../include/View.h"
#include <fstream>

using namespace std;

int main() {
    StateT temp;
    temp = initialConfigRead("test.txt", temp);
    outputGameTerminal(temp);
    cout << temp.getStatus(3,2);
    temp.updateGame();
}

