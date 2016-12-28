#pragma once

class base_model
{
  public:
    virtual void predict(const int* testing_data, int* predictions, int num_rows) =0;
    double test(const int* testing_data, int* predictions, int num_rows);
    virtual void train(const int* training_data, int num_rows) =0;
};