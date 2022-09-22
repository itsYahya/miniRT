#include "raytracer.h"

static t_xs	inters_list2arr(t_list *inters)
{
	t_xs	xs;
	int		lst_size;

	xs = (t_xs){0, NULL};
	lst_size = ft_lstsize(inters);
	if (lst_size > 0)
		xs.inters = malloc(sizeof(t_inter) * ft_lstsize(inters));
	while (inters)
	{
		xs.inters[xs.count++] = *(t_inter *)inters->content;
		inters = inters->next;
	}
	if (xs.count == -1)
		xs.count = 0;
	return (xs);
}

static void	swap_inters(t_inter *i1, t_inter *i2)
{
	t_inter	temp;

	if (!i1 || !i2)
		return;
	temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}

static void	sort_inters(t_xs xs)
{
	int				i;
	int				j;
	int				swapped;

	i = -1;
	while (++i < xs.count - 1)
	{
		swapped = 0;
		j = -1;
		while (++j < xs.count - i - 1)
		{
			if (xs.inters[j].t > xs.inters[j + 1].t)
			{
				swap_inters(xs.inters + j, xs.inters + j + 1);
				swapped = true;
			}
		}
		if (swapped == 0)
			break ;
	}
}

static void	push_intersections(t_list **lst, t_xs xs)
{
	int				i;
	t_inter	*inter;

	i = -1;
	while (++i < xs.count)
	{
		inter = malloc(sizeof(t_inter));
		*inter = xs.inters[i];
		ft_lstadd_back(lst, ft_lstnew(inter));
	}
}

t_xs	intersect_scene(t_scene scene, t_ray ray)
{
	t_list		*objs;
	t_object	*object;
	t_xs		xs;
	t_list		*lst;

	objs = scene.objects;
	lst = NULL;
	while (objs)
	{
		object = ((t_object *)objs->content);
		if (! object)
			return (printf("null object [intersect world]"), (t_xs){0, NULL});
		xs = intersect(*object, ray);
		if (xs.count > 0)
			push_intersections(&lst, xs);
		destroy_inters(&xs);
		objs = objs->next;
	}
	xs = inters_list2arr(lst);
	sort_inters(xs);
	ft_lstclear(&lst, free);
	return (xs);
}
