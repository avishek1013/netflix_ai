#pragma once

#include "algorithm/base_model.h"
#include "util/data_constants.h"

class movie_avg : public base_model
{
  private:
    double* averages = new double[MOVIE_SIZE];

  public:
    void predict(const int* testing_data, int* predictions, int num_rows);
    void train(const int* training_data, int num_rows);
};