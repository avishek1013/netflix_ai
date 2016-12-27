#include "average_model.h"

#include "util/data_constants.h"

average_model::average_model() : average{0.0} {}

void average_model::predict(const int* testing_data, int* predictions, int num_rows) {
  for (auto i = 0; i < num_rows; i++) {
    predictions[i] = average;
  }
}

void average_model::train(const int* training_data, int num_rows) {
  auto avg = 0.0;
  for (auto i = 0; i < num_rows; i++) {
    avg += training_data[i*COL_SIZE + RATING_IND];
  }

  average = avg / num_rows;
}

