#pragma once

#include "model/base_model.h"
#include "util/data_constants.h"

class average_movie_model : public base_model
{
  private:
    double* averages;

  public:
    average_movie_model();
    ~average_movie_model();
    
    void predict(const int* testing_data, int* predictions, int num_rows);
    void train(const int* training_data, int num_rows);
};