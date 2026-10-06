#include "vector_functions.h"

/* Global variables to keep track of how much data moves */
int g_allocations_count = 0;  // number of heap allocations made
int g_copy_count = 0;         // number of Data copies made
int g_move_count = 0;         // number of Data moves made

/*******************************************************************
 * Unlike in C where we call malloc() to put memory on the heap,
 * we use the "new" keyword. And since "new" is an operator, we can
 * override it! In this example we just override it so we can
 * increment the allocation_count variable.
 * Think of all the possibilities!
 *******************************************************************/
void* operator new(size_t size) {
  g_allocations_count++;
  //cout <<"allocating memory on the heap: " << size << endl;
  void* p = malloc(size);
  return p;
}

Data::Data(const Data& other):value(other.value) { 
  g_copy_count++; 
}

Data::Data(Data&& other) : value(other.value) { 
  g_move_count++; 
}

// returns a vector of data with the first N elements
vector<Data> load_data(int N) {
  // init empty vector of Data
  cout << "Starting load_data" << endl;
  vector<Data> values;
  values.reserve(N);  // reserve space for N elements to avoid reallocations

  // add the first N elements to vector
  for (int i = 0; i < N; i++) {
    //cout << "adding item " << i << " to the vector\n";
    values.emplace_back(i);
  }
  cout << "Ending load_data" << endl;
  return values;
}

// pretty prints a vector
void print_vector(const vector<Data>& values) {
  cout << "Vector size: " << values.size() << " elements\n";

  cout << "Elements: [";

  // for every element
  for (int i = 0; i < values.size(); i++) {
    cout << values.at(i).value;

    // print a comma after every value unless it's the last one
    if (i < values.size() - 1)
      cout << ", ";
  }

  cout << "]\n";
}

// returns the average of the elements in the vector
float get_average(const vector<Data>& values) {
  float sum = 0;

  // notice how we also do a const reference for Data here too.
  // if our for loop looked like
  //    for (Data data : values)
  // instead, we would be making a copy of Data each time
  // we iterate through the loop!
  for (const Data& data : values) {
    sum += data.value;
  }

  // cast denominator to float
  return sum / (float)values.size();
}

void print_global_preformance_counts() {
  cout << "Number of Heap allocations      : " << g_allocations_count << endl;
  cout << "Number of times Data was copies : " << g_copy_count << endl;
  cout << "Number of times Data was moved  : " << g_move_count << endl;
}
