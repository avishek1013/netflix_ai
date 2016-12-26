#include "movie_avg.h"

#include <algorithm>

void movie_avg::predict(const int* testing_data, int* predictions, int num_rows) {
  for (auto i = 0; i < num_rows; i++) {
    auto ind = testing_data[i*COL_SIZE + MOVIE_IND] - 1;
    predictions[i] = averages[ind];
  }
}

void movie_avg::train(const int* training_data, int num_rows) {
  auto counts = new int[MOVIE_SIZE];
  std::fill(averages, averages + MOVIE_SIZE, 0.0);
  std::fill(counts, counts + MOVIE_SIZE, 0);
  for (auto i = 0; i < num_rows; i++) {
    auto ind = training_data[i*COL_SIZE + MOVIE_IND] - 1;
    averages[ind] += training_data[i*COL_SIZE + RATING_IND];
    counts[ind] += 1;
  }

  for (auto i = 0; i < MOVIE_SIZE; i++) {
    if (counts[i] != 0)
      averages[i] /= counts[i];
  }
}

