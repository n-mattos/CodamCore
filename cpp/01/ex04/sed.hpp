/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:34:59 by nmattos-          #+#    #+#             */
/*   Updated: 2025/04/14 10:59:12 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_SED
# define H_SED

#include <iostream>
#include <fstream>

#define ERROR_ARG "Invalid number of arguments given."
#define ERROR_FILE "Couldn't open given file."
#define USAGE "./sed <filename> <to_replace> <replacement>"

#define FILENAME 1
#define TO_REPLACE 2
#define REPLACEMENT 3

int	sed(int argc, char *argv[]);

#endif