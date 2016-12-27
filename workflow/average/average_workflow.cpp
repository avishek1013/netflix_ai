#include "algorithm/average_model.h"
#include "workflow/train_test_workflow.h"

int main(int argc, char const *argv[])
{
  auto average_workflow = new train_test_workflow(new average_model);
  average_workflow->execute();
  return 0;
}