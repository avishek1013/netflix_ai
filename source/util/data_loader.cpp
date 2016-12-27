#include "data_loader.h"

#include <cstdio>

#include "util/data_constants.h"

void data_loader::load_data(const std::string& data_filename, int* data, int length) {
  auto data_fp = fopen(data_filename.c_str(), "rb");
  fread(data, sizeof(int), length, data_fp);
  fclose(data_fp);
}

void data_loader::save_data(const std::string& data_filename, const int* data, 
  int length) {

  auto data_fp = fopen(data_filename.c_str(), "wb");
  fwrite(data, sizeof(int), length, data_fp);
  fclose(data_fp);
}

void data_loader::split_data(const std::string& data_filename, 
  const std::string& index_filename,
  std::vector<int*>& datasets) {

  auto base = new int[BASE_SIZE * COL_SIZE];
  auto valid = new int[VALID_SIZE * COL_SIZE]; 
  auto hidden = new int[HIDDEN_SIZE * COL_SIZE];
  auto probe = new int[PROBE_SIZE * COL_SIZE]; 
  auto qual = new int[QUAL_SIZE * COL_SIZE];
  datasets = {base, valid, hidden, probe, qual};

  auto data_fp = fopen(data_filename.c_str(), "r");
  auto index_fp = fopen(index_filename.c_str(), "r");

  int user_id, movie_id, date, rating, index;
  int base_offset = 0, valid_offset = 0, hidden_offset = 0, 
    probe_offset = 0, qual_offset = 0;
  std::vector<int> offsets = {base_offset, valid_offset, hidden_offset, 
    probe_offset, qual_offset};

  while (fscanf(index_fp, "%d", &index) != EOF) {
    fscanf(data_fp, "%d %d %d %d", &user_id, &movie_id, &date, &rating);

    --index;
    datasets[index][offsets[index]] = user_id;
    datasets[index][offsets[index] + 1] = movie_id;
    datasets[index][offsets[index] + 2] = date;
    datasets[index][offsets[index] + 3] = rating;
    offsets[index] += 4;
  }
}