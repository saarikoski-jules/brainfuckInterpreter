#include <iostream>
#include <fstream>
// #include <queue>
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
		std::cout << c;
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
	std::cout << "execute" << std::endl;
	std::list<Instruction*>::iterator i = instructions->begin();
	while (i != instructions->end()) {
		Instruction* inst = *i;
		inst->execute(ptr, i);
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
	instructions = getInstructions(f);
	f.close();
	executeProgram(instructions);
}