#include <iostream>
#include <vector>

#include "util/data_constants.h"
#include "util/data_loader.h"
#include "util/timer.h"

int main(int argc, char const *argv[])
{
  timer timer;
  std::cout << "Transforming Raw Data" << std::endl;
  
  auto um_data_path = "raw_data/um/all.dta";
  auto um_index_path = "raw_data/um/all.idx";
  auto um_bin_prefix = "data/um/";
  std::vector<int*> um_datasets;

  auto mu_data_path = "raw_data/mu/all.dta";
  auto mu_index_path = "raw_data/mu/all.idx";
  auto mu_bin_prefix = "data/mu/";
  std::vector<int*> mu_datasets;

  std::vector<std::string> bin_suffixes = {"base.bin", "valid.bin", "hidden.bin", 
    "probe.bin", "qual.bin"};

  data_loader::split_data(um_data_path, um_index_path, um_datasets);
  data_loader::split_data(mu_data_path, mu_index_path, mu_datasets);

  for (auto i = 0; i < bin_suffixes.size(); i++) {
    data_loader::save_data(um_bin_prefix + bin_suffixes[i], um_datasets[i], 
      DATA_SIZES[i] * COL_SIZE);
    data_loader::save_data(mu_bin_prefix + bin_suffixes[i], mu_datasets[i], 
      DATA_SIZES[i] * COL_SIZE);  
  }

  timer.stop();
  timer.duration();
  return 0;
}