#include "algorithm/movie_avg.h"
#include "workflow/train_test_workflow.h"

int main(int argc, char const *argv[])
{
  auto avg_workflow = new train_test_workflow(new movie_avg);
  avg_workflow->execute();
  return 0;
}