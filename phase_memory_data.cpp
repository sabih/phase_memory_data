/*
 * 1. Create 18 files.
 *
 * 2. Allocate memory of size 256 kB = 2^18 and fill the memory with ASCII codes of characters.
 *
 * 3. Write memory data to each of the 18 files as per the following criteria:
 *    Phase 0 (2^0):
 *         Write first byte of data from memory to each of the 18 files.
 *         Write second byte of data from memory to each of the 18 files and so on till all the memory data is written.
 *    Phase 1 (2^1):
 *         Write first 2 bytes of data from memory to each of the 18 files.
 *         Write next 2 bytes of data from memory to each of the 18 files and so on till all the memory data is written.
 *    Phase 18 (2^18):
 *         Write 256 kB i.e., whole data at once in all the 18 files.
 *
 * 4. Find the time taken for each phase and plot in graph.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <math.h>
#include <vector>

using namespace std;

int main() {

	int count = 1,
		file_count = 18,
		phase_count = 18,
		memory = 1,
		max_memory = 256 * 1024,
		phase = 0,
		phase_value;

	float time = 0;

	string file_name;

	vector<string> file_array;

	// Create "phase_time.txt" to store time taken by each phase
	std::ofstream outfile("phase_time.txt");

	// Create number of files needed
	for (count; count <= file_count; count++) {

		file_name = (count < 10) ? "0" + std::to_string(count) + ".txt" : std::to_string(count) + ".txt";

		// Store file names in file_array
		file_array.push_back(file_name);

		// Create file to store memory data
		std::ofstream outfile(file_name);

	}

	// Allocate a memory of 256 kB
	char * memory_array;
	memory_array = new char[max_memory];

	// Fill memory for each byte with ASCII values
	for (memory; memory <= max_memory; memory++) {

		memory_array[memory] = char(memory);

	}

	std::ofstream myfile;

	// Loop through each phase as per exponent
	for (phase; phase <= phase_count; phase++) {

		// phase = 1, 2, 4, 8, ... (No. of bytes of memory to be written in files at a time)
		phase_value = pow(2, phase);

		// Set the clock
		std::clock_t c_start = std::clock();

		// Loop through each memory bytes and increment by phase_value
		for (memory = 1; memory <= max_memory; memory = memory + phase_value) {

			// This loop will open all 18 files one by one and write data as per phase_value
			// If phase_value = 1, then 1 byte of data will be written in all the files
			// Once 1 byte of data is written in all files it will move to parent loop increment memory value by 1,
			// check if memory <=  max_memory, then again continue to write next byte of data in all files
			for (count = 0; count < file_count; count++) {

				file_name = file_array[count];

				// Open file in append mode
				myfile.open(file_name, std::ios_base::app);

				// Write memory data to files
				myfile.write (memory_array, phase_value);

				// Close the file
				myfile.close();

			}

		}

		// Set the clock at the end of each phase
		std::clock_t c_end = std::clock();

		// Time taken for each phase in microsecond
		time = (c_end - c_start) / (CLOCKS_PER_SEC / 1000000);

		myfile.open("phase_time.txt", std::ios_base::app);
		myfile << "Phase " << phase << ": " << time << " μs" << endl;
		myfile.close();

	}

	// Deallocate the memory/memory_array created
	delete [] memory_array;

	return 0;

}
