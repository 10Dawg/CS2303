#ifndef VECTOR_FUNCTIONS_H
#define VECTOR_FUNCTIONS_H

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/* Data class */
class Data {
 public:
  // only thing Data holds
  float value = 0;

  // Constructor with a value
  Data(float val) : value(val) {}

  // Copy constructor: increments global copy count
  Data(const Data& other);

  // Move constructor: increments global move count
  Data(Data&& other);
};

/***************************************************
 * void print_vector
 * Pretty prints a vector of Data
 * This function signature is inefficient!
 *
 * Input: values - vector of Data
 * Returns: void
 ****************************************************/
void print_vector(const vector<Data>& values);

/***************************************************
 * float get_average
 * Calculates the average of values
 * This function signature is inefficient!
 *
 * Input: values - vector of floats
 * Returns: The average of all values in the vector
 ****************************************************/
float get_average(const vector<Data>& values);

/***************************************************
 * vector<Data> load_data
 * Loads the first N numbers into a vector
 *
 * Input: N - number of elements to load into vector
 * Returns: A vector containing the first N integers
 ****************************************************/
vector<Data> load_data(int N);

/***************************************************
 * float print_global_counts
 * Prints global counts:
 *  Number of heap allocations
 *  Number of Data copies made
 *  Number of Data moves made
 *
 * Input: void
 * Returns: void
 ****************************************************/
void print_global_preformance_counts();

#endif  // VECTOR_FUNCTIONS_H
