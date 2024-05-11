/**
 * @file figure_generator.c
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-05-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/figures.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void copy_next_to_current(singleton *s) {
  for (size_t i = 0; i < TETROMINO_SIZE; i++) {
    for (size_t j = 0; j < TETROMINO_SIZE; j++) {
      s->figure.current_figure[i][j] = s->game_info->next[i][j];
    }
  }
  s->figure.current_color = s->figure.next_color;
}

static void clear_next(singleton *s) {
  for (size_t i = 0; i < TETROMINO_SIZE; i++) {
    for (size_t j = 0; j < TETROMINO_SIZE; j++) {
      s->game_info->next[i][j] = 0;
    }
  }
}

void generate_new_figure(singleton *s) {
  clear_next(s);
  int tmp = rand() % NUM_TETROMINOS;
  s->figure.next_color = tmp + 1;
  s->figure.type = tmp;
  s->figure.rotation = 0;
  s->figure.x = 3;
  s->figure.y = 0;

  switch (s->figure.type) {
    case TET_I:
      s->game_info->next[0][0] = s->game_info->next[0][1] =
          s->game_info->next[0][2] = s->game_info->next[0][3] =
              s->figure.next_color;
      break;

    case TET_Z:
      s->game_info->next[0][0] = s->game_info->next[0][1] =
          s->game_info->next[1][1] = s->game_info->next[1][2] =
              s->figure.next_color;
      break;

    case TET_S:
      s->game_info->next[0][1] = s->game_info->next[0][2] =
          s->game_info->next[1][0] = s->game_info->next[1][1] =
              s->figure.next_color;
      break;

    case TET_T:
      s->game_info->next[0][1] = s->game_info->next[1][0] =
          s->game_info->next[1][1] = s->game_info->next[1][2] =
              s->figure.next_color;
      break;

    case TET_L:
      s->game_info->next[0][0] = s->game_info->next[0][1] =
          s->game_info->next[0][2] = s->game_info->next[1][2] =
              s->figure.next_color;
      break;

    case TET_J:
      s->game_info->next[0][0] = s->game_info->next[0][1] =
          s->game_info->next[0][2] = s->game_info->next[1][0] =
              s->figure.next_color;
      break;

    case TET_O:
      s->game_info->next[0][0] = s->game_info->next[0][1] =
          s->game_info->next[1][0] = s->game_info->next[1][1] =
              s->figure.next_color;
      break;
  }
  copy_next_to_current(s);
}