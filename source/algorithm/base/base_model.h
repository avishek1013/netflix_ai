#pragma once

#include <armadillo>

class base_model
{
  public:
    virtual void train(arma::mat& training_data) =0;
    virtual void predict(arma::mat& testing_data) = 0;
};