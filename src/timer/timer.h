#ifndef TIMER_H
# define TIMER_H

# include "utils.h"
# include "list.h"
# include <stdio.h>

void	start_timer(const char *key);
void	end_timer(const char *key);
void	destroy_timer();

#endif
