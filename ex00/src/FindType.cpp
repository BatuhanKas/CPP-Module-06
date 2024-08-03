/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FindType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:49:50 by bkas              #+#    #+#             */
/*   Updated: 2024/08/03 15:39:52 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/ScalarConverter.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

eType ScalarConverter::findType(const string lit) {
    if (isOneChar(lit))
        return ONECHAR;
    else if (isChar(lit))
        return CHAR;
    return ERROR;
    // return DOUBLE;
    // return ONECHAR;
}

/* *************************** [v] FIND TYPE [v] *************************** */
