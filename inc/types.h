/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:23:19 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 17:23:28 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_type
{
	E_AMBLIGHTNING = 'A',
	E_CAMERA = 'C',
	E_LIGHT = 'L',
	E_SPHERE = 'S',
	E_PLANE = 'P',
	E_CYLINDER = 'Y',
	E_CONE = 'O',
	E_INVALID = '0',
	E_NEWLINE = '\n'
}	t_type;

#endif
