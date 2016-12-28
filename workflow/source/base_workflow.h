#pragma once

#include "model/base_model.h"

class base_workflow
{
  protected:
    base_model* model;

  public:
    base_workflow(base_model* model_instance);
    virtual void execute() =0;
};