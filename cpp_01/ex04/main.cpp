/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:16:04 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/17 11:41:40 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
// #include <string>

#define ERR_ARGC 		"Error: Wrong number of arguments.\nProvide <filename> <string1> <string2>"
#define	ERR_EMPTY_PARAM "Error: No empty parameters allowed"
#define ERR_IN_FILE		"Error: In file error"
#define ERR_OUT_FILE	"Error: Out file error"	


std::string	createContent(std::ifstream &inFile) {
	std::string	output;
	std::string	buffer;

	while (inFile.good())
	{
		std::getline(inFile, buffer);
		output.append(buffer);
		output.append("\n");
	}
	return (output);
}

int	main(int argc, char **argv) {
	
	std::string		fileName;
	std::string		oldString;
	std::string		newString;
	std::string		content;

	if (argc != 4) {
		std::cout << ERR_ARGC << std::endl;
		return (-1);
	}
	fileName = argv[1];
	oldString = argv[2];
	newString = argv[3];
	if (fileName.empty() || oldString.empty() || newString.empty())
	{
		std::cout << ERR_EMPTY_PARAM << std::endl;
		return (-1);
	}
	std::ifstream	inFile(fileName);
	if (!inFile.is_open())
	{
		std::cout << ERR_IN_FILE << std::endl;
		return (-1);
	}
	content = createContent(inFile); 

	size_t index;
	index = content.find(oldString);
	while (index != std::string::npos)
	{
		content.erase(index, oldString.length());
		content.insert(index, newString);
		index = content.find(oldString);
	}
	
	fileName.append(".replace");
	std::ofstream	outFile(fileName);
	outFile << content;

	inFile.close();
	outFile.close();
	return (0);
}