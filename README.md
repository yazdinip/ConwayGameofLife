# ConwayGameofLife
a Simulation of Conway's Game of Life written in C++, including the specification and the report. 

Conway's Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how the game moves from one state to another. There are a set of rules that can take the game from one state to another, by determining the future state of a single cell based on its current state of the neighbours. Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:
- Any live cell with fewer than two live neighbours dies, as if by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
In this project we will use True or False to represent the state of each cell based on being 'Alive' or 'Dead'.

This project only provides the back-end processing and the framework for the game, meaning that the initial states are provided through a text file and the program will carry on from the initial state and write the state of the game to a separate text file after each iteration. 

Next steps would include linking the back-end to a front-end GUI library where we can continously see each state of the game. 

Sample Input: <br />
`.....` <br />
`.....` <br />
`.XXX.` <br />
`.....` <br />
`.....` <br />

Sample Output (1st Iteration): <br />
`.....` <br />
`..X..` <br />
`..X..` <br />
`..X..` <br />
`.....` <br />

Sample Output (2nd Iteration): <br />
`.....` <br />
`.....` <br />
`.XXX.` <br />
`.....` <br />
`.....` <br />



