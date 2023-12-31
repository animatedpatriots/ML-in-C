#ifndef NN_H_
#define NN_H_

#include <stddef.h>
#include <stdio.h>


// float m[] = {0, 1, 0, 1};
// Mat m = {.rows = 2, .cols = 2, es = d};
#ifndef NN_MALLOC
#include <stdlib.h>
#define NN_MALLOC malloc
#endif //NN_MALLOC

#ifndef NN_ASSERT
#include <assert.h>
#define NN_ASSERT assert
#endif //NN_ASSERT

typedef struct {
  size_t rows;
  size_t cols;
  float *es;
} Mat;
#define MAT_AT(m, i, j) (m).es[(i)*(m).cols + (j)]


#endif // NN_H_

#ifdef NN_IMPLEMENTATION
Mat mat_alloc(size_t rows, size_t cols){
  Mat m;
  m.rows = rows;
  m.cols = cols;
  m.es = NN_MALLOC(sizeof(*m.es)*rows*cols);
  NN_ASSERT(m.es != NULL);
  return m;
};

void mat_dot(Mat dst, Mat a, Mat b){
  (void) dst;
  (void) a;
  (void) b;
};
void mat_sum(Mat dst, Mat a, Mat b){
  (void) dst;
  (void) a;
};

void mat_print(Mat m){
  for (size_t i = 0; i < m.rows; ++i){
    for (size_t j = 0; j < m.cols; ++j){
      printf("%f ", MAT_AT(m, i, j));
    }
    printf("\n");
  }
  (void) m;
};


#endif // NN_IMPLEMENTATION
