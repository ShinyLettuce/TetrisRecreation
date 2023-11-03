# Jacob_Assignment_1

Programming with C/C++ 4: Computer Games in 2D 5SD814 54825 HT2023
Jacob Engelhardt

Tetris programmed for the individual assignment in "Programming with C/C++ 4: Computer Games in 2D".
This application is a Tetris clone inspired by Tetris for the Gameboy. It has 4 Game states including the collision test screen. The remaining are the main menu state, the main game state and the high score screen

HOW TO PLAY: 

To play, you press x on the main menu.
In the game, you play using the side arrow keys to move left and right.
Press the down arrow key to fast drop.
Press c and x to rotate your piece right and left respectively.
Get points from filling out horizontal lines to clear them. Clearing more lines at once gives more points.
The game is lost once a new spawning piece is blocked from spawning.

HIGH SCORE: 

To submit a high score you must type three characters and press enter. Then you'll see if you made it on the top 5 list.

COLLISSION: 

To test the different collisions, you press one of the keys between 1-4 and use your mouse to drag the primitives.


GENERAL INFO OF PROJECT LAYOUT: 

|game_state.h and .cpp|
This is where the current game state is controlled. Contains a struct with a stack of gamestates, the one on top determines the behavior in game_state's update function. This struct also contains the high score list, the game and the collision screen so that it can draw and update different ones depending on game state.

|level.h and .cpp|
Where the main game is being controlled. Level contains the grid system that the game is played on along with general information such as score and game logic variables. This is where piece movement and collisions happen along with any changes to the grid such as locking down pieces or clearing lines. It also contains the tetromino_controller.

|tetromino_controller.h and .cpp|
Contains the info regarding the dynamic tetromino pieces such as the one the player is able to move as well as the upcoming piece. This is where player input is taken as well as the logic for rotating pieces, randomly assigning pieces and rendering dynamic pieces.

|tetromino.h|
Contains a struct with all reference arrays of every piece.

|collision.h and .cpp|
All the logic for collision testing. Changes state of test scenario with button presses 1-4.

|math_util.h and .cpp|
contains one function used in piece rotation so that negative input from rotation wraps around to a valid orientation number.

|high_score.h and .cpp|
Contains the list of highscores read to from file at the start of the application. Controls all behavior of the high score screen.
