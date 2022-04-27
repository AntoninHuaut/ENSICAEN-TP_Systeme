#ifndef TP2_SIN_COS_G_H
#define TP2_SIN_COS_G_H

#define SIN_FILE_NAME "sinus.txt"
#define COS_FILE_NAME "cosinus.txt"

#define SIN_COMMAND_FILE_NAME "commandes_sinus.gp"
#define COS_COMMAND_FILE_NAME "commandes_cosinus.gp"

void create_command_file(char* title,
                         char* gnuplotFileName,
                         char* dataFileName);

void gnuplot_exec(char* gnuplotFileName);

void write_sin_value(int angle, double value);

void write_cos_value(int angle, double value);

void write_value(char* fileName, int angle, double value);

#endif
