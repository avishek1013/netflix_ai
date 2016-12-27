#include <iostream>

#include "algorithm/svd.h"
#include "util/data_constants.h"
#include "util/data_loader.h"
#include "util/timer.h"

int main(int argc, char const *argv[])
{
  timer timer;
  std::string data_path = "data/um/base.bin";
  auto base_data = new int[BASE_SIZE * COL_SIZE];
  data_loader::load_data(data_path, base_data, BASE_SIZE * COL_SIZE);

  timer.stop();
  timer.duration();
  return 0;
}