#pragma once

#include <string>
#include <vector>

class data_loader
{
  public:
    static void load_data(const std::string& data_filename, int* data, int length);
    static void save_data(const std::string& data_filename, const int* data, int length);
    static void split_data(const std::string& data_filename, 
      const std::string& index_filename,
      std::vector<int*>& datasets);
};