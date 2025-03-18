/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:20:32 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/04 13:20:32 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

// need to add test files to show the program works

void replaceFile(std::string filename, std::string s1, std::string s2) {

	(void)s1;
	(void)s2;

	// open existing file
	std::ifstream fileInput(filename.c_str());
	if (!fileInput) {
		std::cerr << "Error opening file" << filename << std::endl;
		return ;
	}
	
	// create + open new file
	std::string filenameOutput = filename + ".replace";
	std::ofstream fileOutput(filenameOutput.c_str());
	if (!fileOutput) {
		std::cerr << "Error creating output file" << std::endl;
		fileInput.close();
		return ;
	}
	
	// read from existing file
	std::string line;
	while (std::getline(fileInput, line)) {
		// when it encounters s1, replace with s2
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		// write to the new file
		fileOutput << line;
		if (!fileInput.eof())
			fileOutput << std::endl;
	}

	// close existing file
	fileInput.close();
	// close new file
	fileOutput.close();
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "The program needs three arguments" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	replaceFile(filename, s1, s2);
	return 0;
}