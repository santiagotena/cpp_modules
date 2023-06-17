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
        std::cout << "Error: could not open file." << std::endl;
        return (-1);
    }
    BitcoinExchange exchange("data.csv");
    exchange.convert(argv[1]);
    return (0);
}
