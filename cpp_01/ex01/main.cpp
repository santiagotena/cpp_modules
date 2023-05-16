/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:21:58 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/16 15:26:16 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

# define ERR_ARGC "Error: Argument can only be a single positive integer"
# define ERR_NB_OUT_BOUNDS "Error: Number is out of bounds"
# define ERR_NOT_A_NUMBER "Error: Input is not a number"
# define ERR_NEGATIVE_NB "Error: Number is negative"

bool isInputValid(int argc, char **argv) {
	int		size;
	
	size = 0;
	if (argc != 2) {
		std::cout << ERR_ARGC << std::endl;
		return (false);
	}
	try {
		size = std::stoi(argv[1]);
	}
	catch (std::out_of_range) {
		std::cout << ERR_NB_OUT_BOUNDS << std::endl;
		return (false);
	}
	catch (std::invalid_argument) {
		std::cout << ERR_NOT_A_NUMBER << std::endl;
		return (false);
	}
	if (size <= 0) {
		std::cout << ERR_NEGATIVE_NB << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv) {
	int		size;
	Zombie	*horde;

	if (!isInputValid(argc, argv))
		return (-1);
	size = std::stoi(argv[1]);
	horde = zombieHorde(size, "Max");
	for (int i = 0; i < size; i++)
		horde[i].announceIndex(i);
	delete [] horde;
	return (0);
}
