/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:36 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:37 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << ERR_ARGC << std::endl;
        return (-1);
    }
    try {
        BitcoinExchange exchange("data.csv");
        exchange.convert(argv[1]);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
