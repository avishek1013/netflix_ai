#pragma once

#include "algorithm/base_model.h"

class svd_model : public base_model
{
  public:
    void predict(const int* testing_data, int* predictions, int num_rows);
    void train(const int* training_data, int num_rows);
};