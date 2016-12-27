#pragma once

#include "workflow/base_workflow.h"

class train_test_workflow : base_workflow
{
  private:
    double rmse;

  public:
    train_test_workflow(base_model* model_instance);
    
    void execute();
};