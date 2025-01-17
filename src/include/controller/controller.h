/**
 * @file controller.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_CONTROLLER_CONTROLLER_H_
#define SRC_INCLUDE_CONTROLLER_CONTROLLER_H_

#include "../interfaces/IModel.h"

namespace s21 {
class Controller {
 public:
  Controller(IModel *model);
  ~Controller();

  void userInput(UserAction_t action, bool hold);
  GameInfo_t updateCurrentState();
  bool game_over();
  stage_t stage();

 private:
  IModel *model_;
};
}  // namespace s21

#endif  // SRC_INCLUDE_CONTROLLER_CONTROLLER_H_
