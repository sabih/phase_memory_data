Experiment
----------
1. Create 18 files.

2. Allocate memory of size 256 kB = 2^18 and fill the memory with ASCII codes of characters.

3. Write memory data to each of the 18 files as per the following criteria:
    Phase 0 (2^0):
        Write first byte of data from memory to each of the 18 files.
        Write second byte of data from memory to each of the 18 files and so on till all the memory data is written.
    Phase 1 (2^1):
        Write first 2 bytes of data from memory to each of the 18 files.
        Write next 2 bytes of data from memory to each of the 18 files and so on till all the memory data is written.
    Phase 18 (2^18):
        Write 256 kB i.e., whole data at once in all the 18 files.

4. Find the time taken for each phase and plot in graph.
