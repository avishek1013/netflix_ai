#pragma once

#include <chrono> 
#include <string>

class timer 
{
  private: 
    std::chrono::time_point<std::chrono::high_resolution_clock> begin;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    std::chrono::duration<double> elapsed;

  public:
    timer () {
      begin = std::chrono::high_resolution_clock::now();
    }

    void start() {
      begin = std::chrono::high_resolution_clock::now();
    }

    void stop() {
      end = std::chrono::high_resolution_clock::now();
      elapsed = end - begin;
    }

    void duration() {
      std::cout << elapsed.count() << " seconds" << std::endl;
    }
};