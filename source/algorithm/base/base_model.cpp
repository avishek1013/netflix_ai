#include "base_model.h"

#include <cmath>

#include "util/data_constants.h"

double base_model::test(const int* testing_data, int* predictions, int num_rows) {
  auto rmse = 0.0;
  predict(testing_data, predictions, num_rows);
  for (auto i = 0; i < num_rows; i++) {
    rmse += pow(predictions[i] - testing_data[i*COL_SIZE + COL_SIZE - 1], 2.0);
  }

  return sqrt(rmse / num_rows);
}