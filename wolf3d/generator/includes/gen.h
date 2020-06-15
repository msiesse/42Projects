/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:32:23 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/28 10:30:55 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEN_H
# define GEN_H

/*
** Libraries
*/

/*
** MACROS
*/

/*
** Errors inputs
*/

# define ERR_MEM 1
# define ERR_CHAR 2
# define ERR_BDR 3
# define ERR_MISS_NAME 4
# define BDR_MAX 200
# define BDR_MIN 3
# define ANG_MAX 359

/*
** Errors create
*/

# define ERR_FD -1
# define ERR_WDIM 1
# define ERR_WMAP 2
# define ERR_WPANGLE 3

/*
** Coordinates
*/

# define X 0
# define Y 1

/*
** Shells transform
*/

# define RED "\033[31m"
# define BOLD "\033[1m"
# define DEFAULT "\033[0m"

/*
** Typedefs/structs/unions
*/

typedef struct		s_data
{
	char			dim[2][4];
	int				nb_dim[2];
	char			pos[2][6];
	int				nb_pos[2];
	char			angle[4];
	int				nb_angle;
	int				density;
	int				fd;
}					t_data;

/*
** FUNCTIONS
*/

/*
** get entry
*/

int					get_chars(char *nb, int size);
int					get_dim(t_data *data);
int					get_pos(t_data *data);
int					get_angle(t_data *data);
int					get_density(t_data *data);

/*
** map
*/

int					create_file(char *name);
int					create_map(t_data *data);
int					write_pos_angle(t_data *data);
int					not_player(t_data *data, int i, int j);

/*
** utilities
*/

int					manage_error(const char *str, int err_num);

#endif
