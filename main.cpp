#include <iostream>
#include <fstream>
#include <list>
#include "Instructions.hpp"
#include "InstructionFactory.hpp"

std::list<Instruction*>* getInstructions(std::ifstream& f) {
	std::list<Instruction*>* instructions = new std::list<Instruction*>;
	InstructionFactory factory;
	char c;
	while(true) {
		c = f.get();
		if (f.eof()) {
			break ;
		}
		Instruction* item = factory.newInstruction(c);
		if (item != NULL) {
			instructions->push_back(item);
		}
	}
	return (instructions);
}

void executeProgram(std::list<Instruction*>* instructions) {
	char array[30000] = {0};
	char *ptr = &array[0];
	std::list<Instruction*>::iterator i = instructions->begin();
	while (i != instructions->end()) {
		Instruction* inst = *i;
		inst->execute(ptr, i);
	}
}

void finishProgram(std::list<Instruction*>* instructions) {
	while (instructions->size() != 0) {
		Instruction* cur = instructions->front();
		delete cur;
		instructions->pop_front();
	}
}

int main(int argc, char** argv) {
	std::list<Instruction*>* instructions;
	if (argc != 2) {
		std::cerr << "Please provide path to brainfuck file" << std::endl;
		return (1);
	}
	std::ifstream f;
	f.open(argv[1], std::fstream::in);
	if (f.fail()) {
		std::cerr << "Not a valid file" << std::endl;
		return (1);
	}
	instructions = getInstructions(f);
	f.close();
	executeProgram(instructions);
	finishProgram(instructions);
}