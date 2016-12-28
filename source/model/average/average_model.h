#pragma once

#include "model/base_model.h"

class average_model : public base_model
{
  private:
    double average;

  public:
    average_model();

    void predict(const int* testing_data, int* predictions, int num_rows);
    void train(const int* training_data, int num_rows);
};