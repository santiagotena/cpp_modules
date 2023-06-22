/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:35 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:36 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool    isInputSizeRight(int argc) {
    if (argc == 2)
        return (true);
    std::cout << ERR_ARGC << std::endl << INPUT_EXAMPLE << std::endl;
    return (false);

}

int main(int argc, char *argv[]) {
    if (!isInputSizeRight(argc))
        return (-1);
    RPN rpn;
    rpn.calculate(argv[1]);
    return (0);
}
