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

#ifndef O_BASIC_FS_H
# define O_BASIC_FS_H

# include <stddef.h>

# include "ft_types.h"

typedef struct s_o_basic_fs
{
	const struct s_o_basic_fs_vtable *const	v;
}	t_o_basic_fs;

typedef struct s_o_basic_fs_file
{
	const struct s_o_basic_fs_file_vtable *const	v;
}	t_o_basic_fs_file;

typedef void					(*const t_o_basic_fs_v_unsafe_dispose)(
									t_o_basic_fs *self);
typedef t_err					(*const t_o_basic_fs_v_close)(
									t_o_basic_fs *self);
typedef t_err					(*const t_o_basic_fs_v_flush)(
									t_o_basic_fs *self);
typedef t_o_basic_fs_file		*(*const t_o_basic_fs_v_open_file)(
									t_o_basic_fs *self,
									const char *path);
typedef struct s_o_basic_fs_vtable
{
	const t_o_basic_fs_v_unsafe_dispose	unsafe_dispose;
	const t_o_basic_fs_v_close			close;
	const t_o_basic_fs_v_flush			flush;
	const t_o_basic_fs_v_open_file		open_file;
}	t_o_basic_fs_vtable;

typedef void					(*const t_o_basic_fs_file_v_unsafe_dispose)(
									t_o_basic_fs_file *self);
typedef t_err					(*const t_o_basic_fs_file_v_close)(
									t_o_basic_fs_file *self);
typedef t_err					(*const t_o_basic_fs_file_v_flush)(
									t_o_basic_fs_file *self);
typedef t_err					(*const t_o_basic_fs_file_v_read)(
									t_o_basic_fs_file *self,
									t_byte *buffer,
									size_t length,
									size_t *optional_out_read_size);
typedef t_err					(*const t_o_basic_fs_file_v_read_all)(
									t_o_basic_fs_file *self,
									t_byte *buffer,
									size_t length,
									size_t *optional_out_read_size);
typedef t_err					(*const t_o_basic_fs_file_v_write)(
									t_o_basic_fs_file *self,
									const t_byte *buffer,
									size_t length,
									size_t *out_wrote_size);

typedef struct s_o_basic_fs_file_vtable
{
	const t_o_basic_fs_file_v_unsafe_dispose	unsafe_dispose;
	const t_o_basic_fs_file_v_close				close;
	const t_o_basic_fs_file_v_flush				flush;
	const t_o_basic_fs_file_v_read				read;
	const t_o_basic_fs_file_v_read_all			read_all;
	const t_o_basic_fs_file_v_write				write;
}	t_o_basic_fs_file_vtable;

#endif
