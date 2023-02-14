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

#ifndef FT_PACK_H
# define FT_PACK_H

# include <stddef.h>

# include "ft_types.h"

typedef struct s_ft_pack_entry
{
	size_t			length;
	const t_byte	*contents;
}	t_ft_pack_entry;

typedef struct s_ft_pack
{
	size_t					length;
	const t_ft_pack_entry	*entries;
}	t_ft_pack;

t_ft_pack	*ft_pack_deserialize(
				const t_byte *buffer,
				size_t length);
t_err		ft_pack_serialize(
				t_ft_pack *self,
				t_byte **out_buffer,
				size_t *out_length);
t_byte		*ft_pack_get(
				t_ft_pack *self,
				const char *path);
void		*ft_pack_free(
				t_ft_pack *self);

#endif
