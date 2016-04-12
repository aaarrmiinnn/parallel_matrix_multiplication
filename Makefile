# THIS MAKE FILE WILL CREATE EXECUTABLES OF BOTH TILE-BASED AND REGULAR ROW-BASED MATRIX MULTIPLICATOS
all:
	g++ mm_regular_row.c -fopenmp -o mm_regular_row
	g++ mm_tile.c -fopenmp -o mm_tile
	
