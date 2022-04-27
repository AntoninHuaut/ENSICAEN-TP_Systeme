#include "../include/sin_cos_g.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_command_file(char* title,
                         char* gnuplotFileName,
                         char* dataFileName) {
  FILE* fp;
  fp = fopen(gnuplotFileName, "w+");

  fprintf(fp, "set samples 360\n");
  fprintf(fp, "set title \"%s\"\n", title);
  fprintf(fp, "set xlabel \"Angle\"\n");
  fprintf(fp, "set ylabel \"Valeur\"\n");
  fprintf(fp, "set border\n");
  fprintf(fp, "set grid\n");
  fprintf(fp, "plot \"%s\" using 1:2 smooth csplines\n", dataFileName);

  fclose(fp);
}

void gnuplot_exec(char* gnuplotFileName) {
  int gnuStatus;

  gnuStatus = execlp("gnuplot", "gnuplot", "-persist", gnuplotFileName, NULL);
  if (gnuStatus < 0) {
    perror("Error GNUPlot\n");
    exit(EXIT_FAILURE);
  }
}

void write_sin_value(int angle, double value) {
  write_value(SIN_FILE_NAME, angle, value);
}

void write_cos_value(int angle, double value) {
  write_value(COS_FILE_NAME, angle, value);
}

void write_value(char* fileName, int angle, double value) {
  FILE* fp;

  if (angle == 0) {
    fp = fopen(fileName, "w");
  } else {
    fp = fopen(fileName, "a");
  }

  fprintf(fp, "%d %lf\n", angle, value);
  fclose(fp);
}
