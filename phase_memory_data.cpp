/*
 * Allocate a memory of 256 kB = 2^18.
 * Save ASCII values of characters in memory.
 * Each character occupies 1 byte.
 * Phase 0: Save 1 byte = (2^0) of data at a time in first file.
 * Phase 1: Save 2 bytes = (2^1) of data at a time in second file.
 * ...
 * Phase 18: Save 2^18 bytes i.e., whole memory data at once in eighteenth file.
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

		file_name = file_array[phase];

		// Open file in append mode
		myfile.open(file_name, std::ios_base::app);

		// Set the clock
		std::clock_t c_start = std::clock();

		// Loop through each memory bytes and increment by phase_value
		for (memory = 1; memory <= max_memory; memory = memory + phase_value) {

			for (count = 1; count <= file_count; count++) {

				// Write memory data to files
				myfile.write (memory_array, phase_value);

			}

		}

		// Set the clock at the end of each phase
		std::clock_t c_end = std::clock();

		myfile.close();

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
