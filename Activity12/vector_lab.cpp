#include "vector_functions.h"

/*
 * Compile with the following command:
 * g++ vector_functions.cpp vector_lab.cpp -o vector_lab
 */
int main(int argc, char* argv[]) {
  // check for the correct number of command line arguments
  if (argc < 2) {
    cerr << "Must include number of values to add to vector!\n";
    cerr << "Correct usage: " << argv[0] << " <num values>\n";
    return -1;
  }

  // number of values from command line args
  int num_vals = atoi(argv[1]);

  // init Data vector
  vector<Data> values = load_data(num_vals);

  // print contents of vector
  print_vector(values);

  // calculate the average value and print
  float thisAv = get_average(values);
  cout << "Your average is " <<  thisAv << "." << endl;

  // print global performance counts
  print_global_preformance_counts();

  return 0;
}
