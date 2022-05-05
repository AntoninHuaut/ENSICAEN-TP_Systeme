/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Unix System Programming
 * Chapter "Threads"
 *
 * 2016 Alain Lebret (alain.lebret@ensicaen.fr)
 */
#ifndef MATRIX_H
#define MATRIX_H

#define NB_THREAD 8

#define SIZE 3000
#define PRINT 0

typedef struct matrix {
  unsigned int rows;
  unsigned int columns;
  double** matrix;
} matrix_t;

/* Mono thread functions */
void mono_thread(matrix_t* m1, matrix_t* m2);
matrix_t* product_matrix(matrix_t* m1, matrix_t* m2);
double product_case(int r, int c, matrix_t* m1, matrix_t* m2);

typedef struct args_t {
  int quadrant;
  matrix_t* m1;
  matrix_t* m2;
  matrix_t* answer;
} args_t;

void* thread_calcul(void* args);
void multi_thread(matrix_t* m1, matrix_t* m2);

/* Utils matrix functions */
void print_matrix(matrix_t* m);
matrix_t* init_matrix(unsigned int rows, unsigned int columns, int fill);
void fill_matrix(matrix_t* m);
double** alloc_matrix(unsigned int rows, unsigned int columns);
void free_matrix(double** matrix);

#endif /* MATRIX_H */
