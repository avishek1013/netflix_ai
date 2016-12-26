#pragma once

#include <vector>

// Number of rows in corresponding data sets
const int ALL_SIZE = 102416306;
const int BASE_SIZE = 94362233;
const int VALID_SIZE = 1965045;
const int HIDDEN_SIZE = 1964391;
const int PROBE_SIZE = 1374739;
const int QUAL_SIZE = 2749898;

// Number of columns in all data sets
const int COL_SIZE = 4;

// User and movie data
const int USER_SIZE = 458293;
const int MOVIE_SIZE = 17770;

const int USER_IND = 0;
const int MOVIE_IND = 1;
const int DATE_IND = 2;
const int RATING_IND = 3;

// Vector of data sizes
const std::vector<int> DATA_SIZES = {BASE_SIZE, VALID_SIZE, HIDDEN_SIZE, 
  PROBE_SIZE, QUAL_SIZE};

