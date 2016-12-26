#include "avg.h"

#include "util/data_constants.h"

void avg::predict(const int* testing_data, int* predictions, int num_rows) {
  for (auto i = 0; i < num_rows; i++) {
    predictions[i] = average;
  }
}

void avg::train(const int* training_data, int num_rows) {
  auto avg = 0.0;
  for (auto i = 0; i < num_rows; i++) {
    avg += training_data[i*COL_SIZE + RATING_IND];
  }

  average = avg / num_rows;
}

