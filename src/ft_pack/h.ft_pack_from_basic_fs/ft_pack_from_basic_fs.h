/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PACK_FROM_BASIC_FS_H
# define FT_PACK_FROM_BASIC_FS_H

# include "ft_pack.h"

# include "ft_types.h"
# include "o_basic_fs.h"

typedef t_err	(*const t_ft_pack_from_basic_fs_on_error)(
					void *context,
					const char *path);

typedef struct s_ft_pack_from_basic_fs_options
{
	void								*context;
	t_ft_pack_from_basic_fs_on_error	error;
}	t_ft_pack_from_basic_fs_options;

t_ft_pack	*ft_pack_from_basic_fs(
				t_o_basic_fs *fs,
				size_t count,
				const char *const *paths);

#endif
