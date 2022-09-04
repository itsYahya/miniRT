#include "timer.h"
#include <sys/time.h>

static double	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
}

typedef struct s_timer t_timer;
struct s_timer
{
	const char	*key;
	double	start;
};

static t_list	*timers = NULL;

static t_timer* ft_get_timer_by_key(const char *key)
{
	t_list	*list;

	list = timers;
	while (list)
	{
		if (ft_strcmp(((t_timer*)list->content)->key, key) == 0)
			return (list->content);
		list = list->next;
	}
	return (NULL);
}

void	startTimer(const char *key)
{
	t_timer *t;

	t_timer *s = ft_get_timer_by_key(key);
	if (! s)
		t = malloc(sizeof(t_timer));
	else
		t = s;
	t->key = key;
	t->start = ft_get_time();
	ft_lstadd_back(&timers, ft_lstnew(t, -1));
}

void	endTimer(const char *key)
{
	double now = ft_get_time();
	t_timer	*t = ft_get_timer_by_key(key);
	if (t)
		printf("%s: %.3fms\n", key, now - t->start);
}

void	clearTimer()
{
	ft_lstclear(&timers, free);
}
