#include "algorithm/avg.h"
#include "workflow/train_test_workflow.h"

int main(int argc, char const *argv[])
{
  auto movie_avg_workflow = new train_test_workflow(new movie_avg);
  movie_avg_workflow->execute();
  return 0;
}