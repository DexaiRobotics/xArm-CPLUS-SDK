/*
# Software License Agreement (MIT License)
#
# Copyright (c) 2019, UFACTORY, Inc.
# All rights reserved.
#
# Author: Vinman <vinman.wen@ufactory.cc> <vinman.cub@gmail.com>
*/

#include "xarm/wrapper/xarm_api.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Please enter IP address\n");
    return 0;
  }
  std::string port(argv[1]);

  XArmAPI *arm = new XArmAPI(port);
  sleep_milliseconds(1000);

  if (arm->warn_code != 0) arm->clean_warn();
  if (arm->error_code != 0) arm->clean_error();

  int ret;
  printf("set IO1 high level\n");
  ret = arm->set_tgpio_digital(0, 1);
  sleep_milliseconds(2000);
  printf("set IO2 high level\n");
  ret = arm->set_tgpio_digital(1, 1);
  sleep_milliseconds(2000);
  printf("set IO1 low level\n");
  ret = arm->set_tgpio_digital(0, 0);
  sleep_milliseconds(2000);
  printf("set IO2 low level\n");
  ret = arm->set_tgpio_digital(1, 0);
  sleep_milliseconds(2000);

  return 0;
}