#include "train_test_workflow.h"

#include <iostream>

#include "util/data_constants.h"
#include "util/data_loader.h"
#include "util/timer.h"

train_test_workflow::train_test_workflow(base_model* model_instance) : 
  base_workflow{model_instance}, rmse{0.0} {}

void train_test_workflow::execute() {
  timer timer;
  std::cout << "Loading training data: " << timer.return_elapsed();
  std::string base_path = "data/um/base.bin";
  auto base_data = new int[BASE_SIZE * COL_SIZE];
  data_loader::load_data(base_path, base_data, BASE_SIZE * COL_SIZE);

  std::cout << "Loading testing data: " << timer.return_elapsed();
  std::string probe_path = "data/um/probe.bin";
  auto probe_data = new int[PROBE_SIZE * COL_SIZE];
  data_loader::load_data(probe_path, probe_data, PROBE_SIZE * COL_SIZE);

  std::cout << "Training model: " << timer.return_elapsed();
  model->train(base_data, BASE_SIZE);
  std::cout << "Testing model: " << timer.return_elapsed();
  rmse = model->test(probe_data, new int[PROBE_SIZE], PROBE_SIZE);

  std::cout << "Completed Workflow: " << timer.return_elapsed();
  std::cout << "RMSE: " << rmse << std::endl;
}