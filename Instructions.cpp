#include "Instructions.hpp"
#include <iostream>

void IncrementPtr::execute(char*& ptr, std::list<Instruction*>::iterator& i) const {
	ptr++;
	i++;
}

std::string IncrementPtr::getType() const {
	return (">");
}

void DecrementPtr::execute(char*& ptr, std::list<Instruction*>::iterator& i) const {
	ptr--;
	i++;
}

std::string DecrementPtr::getType() const {
	return ("<");
}

void IncrementByte::execute(char*& ptr, std::list<Instruction*>::iterator& i) const {
	(*ptr)++;
	i++;
}

std::string IncrementByte::getType() const {
	return ("+");
}

void DecrementByte::execute(char*& ptr, std::list<Instruction*>::iterator& i) const {
	(*ptr)--;
	i++;
}

std::string DecrementByte::getType() const {
	return ("-");
}

void OutputByte::execute(char*& ptr, std::list<Instruction*>::iterator& i) const {
	std::cout << *ptr;
	i++;
}

std::string OutputByte::getType() const {
	return (".");
}

void StoreByte::execute(char*& ptr, std::list<Instruction*>::iterator& i) const {
	*ptr = getchar();
	i++;
}

std::string StoreByte::getType() const {
	return (",");
}

void JumpForwardIf::execute(char*& ptr, std::list<Instruction*>::iterator& i) const {
	int braces = 0;

	if (*ptr == 0) {
		while (true) {
			i++;
			if ((*i)->getType() == "]") {
				if (braces == 0) {
					i++;
					return;
				}
				braces--;
			}
			if ((*i)->getType() == "[") {
				braces++;
			}
		}
	}
	i++;
}

std::string JumpForwardIf::getType() const {
	return ("[");
}

void JumpBackIf::execute(char*& ptr, std::list<Instruction*>::iterator& i) const {
	int braces = 0;

	if (*ptr != 0) {
		while (true) {
			i--;
			if ((*i)->getType() == "[") {
				if (braces == 0) {
					i++;
					return;
				}
				braces--;
			}
			if ((*i)->getType() == "]") {
				braces++;
			}
		}
	}
	i++;
}

std::string JumpBackIf::getType() const {
	return ("]");
}
