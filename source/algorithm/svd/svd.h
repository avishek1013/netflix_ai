#pragma once

#include <armadillo>

#include "algorithm/base_model.h"

class svd : public base_model
{
  public:
    void train(arma::mat& training_data);
    void predict(arma::mat& testing_data);
};