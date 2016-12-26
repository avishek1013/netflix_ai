#pragma once

#include "algorithm/base_model.h"

class avg : public base_model
{
  private:
    double average = 0.0;

  public:
    void predict(const int* testing_data, int* predictions, int num_rows);
    void train(const int* training_data, int num_rows);
};