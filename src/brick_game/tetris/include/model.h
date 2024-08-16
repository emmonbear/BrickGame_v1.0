/**
 * @file model.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Tetris game model header file
 * @version 1.0
 * @date 2024-08-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MODEL_H
#define MODEL_H

#include <stdbool.h>

#include "../../../common/include/common.h"

/// @brief Number of lines on Field
#define HEIGHT 20

/// @brief Number of columns on Field
#define WIDTH 10

/// @brief The size of the tetromino
#define TETROMINO_SIZE 4

/// @brief Number of states of a finite state machine
#define NUM_STAGES 7

/// @brief Number of levels
#define MAX_LEVEL 10

/// @brief Amount of experience required to increase the level
#define SCORE_PER_LEVEL 600

/// @brief Enumeration representing the different types of tetrominoes in the
/// game.
typedef enum {
  TET_I,  ///< The "I" shaped tetromino, consisting of four blocks in a straight
          ///< line.
  TET_Z,  ///< The "Z" shaped tetromino, consisting of three blocks in a zigzag
          ///< pattern and one block on the side.
  TET_S,  ///< The "S" shaped tetromino, consisting of three blocks in a zigzag
          ///< pattern and one block on the opposite side.
  TET_T,  ///< The "T" shaped tetromino, consisting of three blocks in a
          ///< straight line and one block perpendicular to the middle block.
  TET_L,  ///< The "L" shaped tetromino, consisting of three blocks in a
          ///< straight line and one block perpendicular to the end block.
  TET_J,  ///< The "J" shaped tetromino, consisting of three blocks in a
          ///< straight line and one block perpendicular to the opposite end
          ///< block.
  TET_O,  ///< The "O" shaped tetromino, consisting of four blocks arranged in a
          ///< 2x2 square.
  NONE    ///< Represents the absence of tetrominoes, used to initialise a piece
          ///< in the initial game state
} type_t;

/**
 * @brief Represents the state and attributes of a tetromino figure in the game.
 *
 * This structure stores the details about the current and next tetromino
 * figures, including their types, positions, colors, and shapes. It also holds
 * the shape of the current figure after rotation.
 */
typedef struct {
  type_t next_type;      ///< The type of the next tetromino figure.
  type_t current_type;   ///< The type of the current tetromino figure.
  int x, y;              ///< The x and y coordinates of the top left corner of
                         ///< the current tetromino figure on the game board.
  int next_color;        ///< The color index of the next tetromino figure.
  int current_color;     ///< The color index of the current tetromino figure.
  int **current_figure;  ///< A 2D array representing the shape of the current
                         ///< tetromino figure.
  int **rotated_figure;  ///< A 2D array representing the shape of the current
                         ///< tetromino figure after rotation.
} figure_t;

/**
 * @brief Enumeration of user actions
 *
 * @details
 *
 * This enumeration represents all possible actions that a user can take while
 * playing the game. These actions include starting the game, pausing the game,
 * terminating the game, moving the current block left, moving the current block
 * right, rotating the current block clockwise, moving the current block down,
 * and performing an "action" (such as triggering a hard drop or activating a
 * special ability).
 */
typedef enum {
  Start,      ///< Start the game
  Pause,      ///< Pause the game
  Terminate,  ///< Terminate the game
  Left,       ///< Move the current tetromino to the left
  Right,      ///< Move the current tetromino to the right
  Up,         ///< is not used in this project
  Down,       ///< Move the current tetromino down
  Action,     ///< rotate the current tetromino
  None        ///< No action
} UserAction_t;

/// @brief Enumeration of states of a Finite-state machine
typedef enum {
  START,  ///< the state in which the game waits for the player to press the
          ///< ready to play button
  SPAWN,  ///< the state the game switches to when creating the next block and
          ///< selecting the next block to be spawned
  SHIFTING,   ///< the state to which the game switches after the timer expires.
              ///< In this state the current block moves down one level
  MOVING,     ///< basic game state with user input processing - rotating
              ///< blocks/moving blocks horizontally
  PAUSE,      ///< the state in which the game is paused
  ATTACHING,  ///< the state the game goes to after the current block "touches"
              ///< the already fallen blocks or the ground. If a filled line is
              ///< formed, it is destroyed and the remaining blocks are shifted
              ///< down. If a block is stopped in the topmost row, the game goes
              ///< to the state "game over"
  GAME_OVER,  ///< the state that characterizes the end of the game
} stage_t;

/**
 * @brief Represents the model of the game, containing game information and the
 * current figure.
 *
 * This structure holds the core data required to manage the game's state,
 * including the game's overall information and the details of the current
 * figure being manipulated.
 */
typedef struct {
  GameInfo_t game_info;  ///< Pointer to the game's information
  figure_t figure;       ///< Information about figures
  int timer;            ///< The game timer for managing game speed or intervals
  bool game_over;       ///< Flag indicating whether the game is over
  UserAction_t action;  ///< The current user action (e.g., start, pause, move)
  stage_t stage;        ///< The current stage or level of the game
} Model_t;

#endif  // MODEL_H
