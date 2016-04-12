PARALLEL OPENMP IMPLEMENTATION OF TILE AND ROW BASED MATRIX MULTIPLICATION.
BY: ARMIN MEHRABIAN
PARALLEL COMPUTER ARCHITECTURE CLASS
FINAL PROJECT 1


In order to fully run the project,

	- Following  files must be placed within the same folder,
		. "mm_tile.c"
		. "mm_regular_row.c"
		.  Makefile
		.  script.sh 

	- Create binaries using the "Makefile"
	
	- Script file "script.sh" executes both of the tiled and regular row based matrix multiplication for a hardwired matrix sizes of A=10x20 B=20x10
	
	- "mm_tile" implementation takes 4 input argument namely,
			 1. Number of rows in matrix A
			 2. Number of columns in matrix A
			 3. Number of columns in matrix B
			 4. Tile size

	 - "mm_regular_row" implementation takes 4 input argument namely,
                         1. Number of rows in matrix A 
                         2. Number of columns in matrix A 
                         3. Number of columns in matrix B 
                         4. Block size (number of element each thread is being assigned).

NOTE: The size of input matrices can be modified by changing the three input arguments.
