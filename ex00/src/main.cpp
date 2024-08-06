/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:37:19 by bkas              #+#    #+#             */
/*   Updated: 2024/08/06 17:01:21 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Wrong Argument!" << endl;
        return 0;
    }
    ScalarConverter::convert(argv[1]);
}
