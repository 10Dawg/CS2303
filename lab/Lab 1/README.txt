File creation program

this program creates multiple files with example text in them.

To compile:
gcc making_files.c -o makeFiles

To run:
./makeFiles in_data.txt
where in_data.txt is a text file where the first value is the integer number of files to create

The program will make a set up output files named out_X.txt where X is 1, 2, 3, etc
out_1.txt will contain the full path to the folder where the program was run
out_2.txt, out_3.txt, etc will contain the text "Example text"
