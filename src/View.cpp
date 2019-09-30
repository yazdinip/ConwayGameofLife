#include "../include/GameState.h"
#include "../include/View.h"

#include <stdexcept>
#include <fstream>
#include <vector>

using namespace std;

StateT initialConfigRead(std::string filename, StateT tempGame){
    vector<char> tempVec;
    ifstream myfile("inputData/" + filename);
    char data;
    while(!myfile.eof()){
        myfile >> data;
        tempVec.push_back(data);
    }
    myfile.close();
    for (int i = 1; i <= BoardSize; i++){
        for (int j = 1; j <= BoardSize; j++){
            if (tempVec.at((i-1)*BoardSize+(j-1)) == 'X'){
                tempGame.changeStatus(Alive, i, j);
            }
            if (tempVec.at((i-1)*BoardSize+(j-1)) == '.'){
                tempGame.changeStatus(Dead, i, j);
            }
        }
    }
    return tempGame;
}

void outputGameTerminal(StateT tempState){
    for (int i = 1; i <= BoardSize; i++){
        for (int j = 1; j <= BoardSize; j++){
            if (tempState.getStatus(i, j) == Dead){
                cout << ".";
            }
            if (tempState.getStatus(i, j) == Alive){
                cout << "X";
            }
        }
        cout << endl;
    }
    cout << endl;   
}

void outputGameText(string filename, StateT tempState){
    ofstream myfile("outputData/" + filename);
    for (int i = 1; i <= BoardSize; i++){
        for (int j = 1; j <= BoardSize; j++){
            if (tempState.getStatus(i, j) == Dead){
                myfile << ".";
            }
            if (tempState.getStatus(i, j) == Alive){
                myfile << "X";
            }
        }
        myfile << endl;
    }
    myfile << endl;  
    myfile.close();
}