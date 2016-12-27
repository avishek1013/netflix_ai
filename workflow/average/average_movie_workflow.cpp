#include "algorithm/average_movie_model.h"
#include "workflow/train_test_workflow.h"

int main(int argc, char const *argv[])
{
  auto average_movie_workflow = new train_test_workflow(new average_movie_model);
  average_movie_workflow->execute();
  return 0;
}