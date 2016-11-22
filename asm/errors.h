/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:02:38 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/22 10:53:31 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <errno.h>

# define	ERR_BAD_SRC_FILE			"{9}Error{0} : Can't read source file"
# define	ERR_DIR						"{9}Error{0} : Directories are not allowed"
# define	ERR_NOEXT					"{9}Error{0} : Extension .s is missing (NOEXT)"
# define	ERR_NOT_S					"{9}Error{0} : File extension is not .s"
# define	ERR_EMPTY_FILE				"{9}Error{0} : File is empty"
# define	ERR_CHAMP_NAME_TOO_LONG		"{9}Error{0} : Champion name too long (Max length 128)" // TODO NAME_LENGTH
# define	ERR_CHAMP_COMMENT_TOO_LONG	"{9}Error{0} : Champion comment too long (Max length 2048)" // TODO COMMENT_LENGTH
# define	ERR_NOCHAMP_NAME			"{9}Error{0} : Can't get champion name" // TODO COMMENT_LENGTH
# define	MULT_ARGS					"{9}Error{0} : Only one arg allowed" // TODO COMMENT_LENGTH
# define	SYNTAX_ERROR_NAME			"{9}Error{0} : Syntax error after the name"

#endif
