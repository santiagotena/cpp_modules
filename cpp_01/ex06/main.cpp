/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:46:17 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/17 17:23:55 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define ERR_ARGC 		"Error: Wrong number of arguments."


int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << ERR_ARGC << std::endl;
		return (-1);
	}
	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}