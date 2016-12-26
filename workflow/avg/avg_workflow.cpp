#include <iostream>

#include "algorithm/avg.h"
#include "util/data_constants.h"
#include "util/data_loader.h"
#include "util/timer.h"

int main(int argc, char const *argv[])
{
  timer timer;
  std::cout << "Loading training data: " << timer.return_elapsed();
  std::string base_path = "data/um/base.bin";
  auto base_data = new int[BASE_SIZE * COL_SIZE];
  data_loader::load_data(base_path, base_data, BASE_SIZE * COL_SIZE);

  std::cout << "Loading testing data: " << timer.return_elapsed();
  std::string probe_path = "data/um/probe.bin";
  auto probe_data = new int[PROBE_SIZE * COL_SIZE];
  data_loader::load_data(probe_path, probe_data, PROBE_SIZE * COL_SIZE);

  auto avg_model = new avg;
  std::cout << "Training model: " << timer.return_elapsed();
  avg_model->train(base_data, BASE_SIZE);
  std::cout << "Testing model: " << timer.return_elapsed();
  auto rmse = avg_model->test(probe_data, new int[PROBE_SIZE], PROBE_SIZE);

  std::cout << "Completed Workflow: " << timer.return_elapsed();
  std::cout << "RMSE: " << rmse << std::endl;
  return 0;
}