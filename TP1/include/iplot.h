#ifndef TP1_IPLOT_H
#define TP1_IPLOT_H

#define COMMAND_FILE_NAME "commandes.gp"

void create_command_file(float range);

void create_child(float range);

void gnuplot_exec();

void wait_parent();

#endif
