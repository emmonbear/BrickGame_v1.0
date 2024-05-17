/**
 * @file init_test.c
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief 
 * @version 1.0
 * @date 2024-05-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../main_test.h"

START_TEST(init_game_test) {
  singleton *s = get_instance();
  init_game(s);
  destroy_game(s);
}

START_TEST(double_destroy_game_test) {
  singleton *s = get_instance();
  init_game(s);
  destroy_game(s);
  destroy_game(s);
}

Suite *init_test() {
  Suite *tetris = suite_create("init tests:");

  TCase *tc_init_test = tcase_create("init test");
  tcase_add_test(tc_init_test, init_game_test);
  tcase_add_test(tc_init_test, double_destroy_game_test);
  suite_add_tcase(tetris, tc_init_test);

  return tetris;
}