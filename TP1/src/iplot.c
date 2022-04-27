#include "../include/iplot.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void create_command_file(float range) {
  FILE* fp;
  fp = fopen(COMMAND_FILE_NAME, "w+");

  fprintf(fp, "set samples 500\n");
  fprintf(fp, "set title \"GNUPlot\"\n");
  fprintf(fp, "set xlabel \"x\"\n");
  fprintf(fp, "set ylabel \"sin(x)/x\"\n");
  fprintf(fp, "set xrange [-%f:%f]\n", range, range);
  fprintf(fp, "set border\n");
  fprintf(fp, "set grid\n");
  fprintf(fp, "plot sin(x)/x\n");

  fclose(fp);
}

void create_child(float range) {
  int pid;

  create_command_file(range);
  pid = fork();
  if (pid < 0) {
    perror("Error");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    // Fils
    gnuplot_exec();
  } else {
    // Père
    wait_parent();
  }
}

void gnuplot_exec() {
  int gnuStatus;

  sleep(1);
  gnuStatus = execlp("gnuplot", "gnuplot", "-persist", COMMAND_FILE_NAME, NULL);
  if (gnuStatus < 0) {
    perror("Error GNUPlot\n");
    exit(EXIT_FAILURE);
  }
}

void wait_parent() {
  int waitStatus;
  printf("Waiting child...\n");
  wait(&waitStatus);
  printf("Child exit status: %d\n", waitStatus);
}