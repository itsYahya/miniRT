#ifndef TIMER_H
# define TIMER_H

# include "mutils.h"
# include "list.h"
# include <stdio.h>

void	startTimer(const char *key);
void	endTimer(const char *key);
void	clearTimer();

#endif
