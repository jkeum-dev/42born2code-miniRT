/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:59:51 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/13 00:59:52 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	translate_tr_plus(t_triangle *tr, int axis)
{
	if (axis == X)
	{
		tr->p0.x++;
		tr->p1.x++;
		tr->p2.x++;
	}
	else if (axis == Y)
	{
		tr->p0.y++;
		tr->p1.y++;
		tr->p2.y++;
	}
	else if (axis == Z)
	{
		tr->p0.z++;
		tr->p1.z++;
		tr->p2.z++;
	}
}

void	translate_tr_minus(t_triangle *tr, int axis)
{
	if (axis == X)
	{
		tr->p0.x--;
		tr->p1.x--;
		tr->p2.x--;
	}
	else if (axis == Y)
	{
		tr->p0.y--;
		tr->p1.y--;
		tr->p2.y--;
	}
	else if (axis == Z)
	{
		tr->p0.z--;
		tr->p1.z--;
		tr->p2.z--;
	}
}
