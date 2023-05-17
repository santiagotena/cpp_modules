/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:16:04 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/17 16:54:51 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

#define ERR_ARGC 		"Error: Wrong number of arguments.\nProvide <filename> <string1> <string2>"
#define	ERR_EMPTY_PARAM "Error: No empty parameters allowed"
#define ERR_IN_FILE		"Error: In file error"
#define ERR_OUT_FILE	"Error: Out file error"	

void	createOutputFile(std::string fileName, std::string& content) {
	fileName.append(".replace");
	std::ofstream	outFile(fileName);
	outFile << content;
	outFile.close();
	return ;
}

void	replaceInContent(	std::string& content, 
							std::string oldString, 
							std::string newString
						) {
	size_t index;
	
	index = content.find(oldString);
	while (index != std::string::npos)
	{
		content.erase(index, oldString.length());
		content.insert(index, newString);
		index = content.find(oldString);
	}
	return ;
}

std::string	createContent(std::ifstream &inFile) {
	std::string	output;
	std::string	buffer;

	while (inFile.good())
	{
		std::getline(inFile, buffer);
		output.append(buffer);
		output.append("\n");
	}
	output.pop_back();
	inFile.close();
	return (output);
}

bool	isInFileValid(std::ifstream& inFile) {
	
	if (!inFile.is_open())
	{
		std::cout << ERR_IN_FILE << std::endl;
		inFile.close();
		return (-1);
	}
	
	return (true);
}

bool	isInputValid(int argc, char **argv) {
	std::string		fileName;
	std::string		oldString;
	std::string		newString;

	if (argc != 4) {
		std::cout << ERR_ARGC << std::endl;
		return (false);
	}
	fileName = argv[1];
	oldString = argv[2];
	newString = argv[3];
	if (fileName.empty() || oldString.empty() || newString.empty())
	{
		std::cout << ERR_EMPTY_PARAM << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv) {
	
	std::string		fileName;
	std::string		oldString;
	std::string		newString;
	std::string		content;

	if (!isInputValid(argc, argv))
		return (-1);
	fileName = argv[1];
	oldString = argv[2];
	newString = argv[3];
	std::ifstream	inFile(fileName);
	if (!isInFileValid(inFile))
		return (-1);
	content = createContent(inFile); 
	replaceInContent(content, oldString, newString);
	createOutputFile(fileName, content);
	return (0);
}
