/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:02:38 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/30 12:25:57 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <errno.h>

# define ERR_BAD_SRC_FILE			"{9}Err{0} : Can't read source file"
# define ERR_DIR					"{9}Err{0} : Directories are not allowed"
# define ERR_NOEXT					"{9}Err{0} : Extension .s is missing"
# define ERR_NOT_S					"{9}Err{0} : File extension is not .s"
# define ERR_EMPTY_FILE				"{9}Err{0} : File is empty"
# define ERR_CHAMP_NAME_TOO_LONG	"{9}Err{0} : Champion name too long"
# define ERR_CHAMP_COMMENT_TOO_LONG	"{9}Err{0} : Champion comment too long"
# define ERR_NOCHAMP_NAME			"{9}Err{0} : Can't get champion name"
# define ERR_NOCHAMP_COMMENT		"{9}Err{0} : Can't get champion comment"
# define MULT_ARGS					"{9}Err{0} : Only one arg allowed"
# define ERR_SYNTAX_ERROR_BNAME		"{9}Err{0} : Syntax error before the name"
# define ERR_SYNTAX_ERROR_ANAME		"{9}Err{0} : Syntax error after the name"
# define ERR_SYNTAX_ERROR_BCOMMENT	"{9}Err{0} : Syntax error before comment"
# define ERR_SYNTAX_ERROR_ACOMMENT	"{9}Err{0} : Syntax error after comment"

#endif
