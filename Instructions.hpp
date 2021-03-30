#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include <list>
#include "Instruction.hpp"

class IncrementPtr: public Instruction {
	void execute(char* ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class DecrementPtr: public Instruction {
	void execute(char* ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class IncrementByte: public Instruction {
	void execute(char* ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class DecrementByte: public Instruction {
	void execute(char* ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class OutputByte: public Instruction {
	void execute(char* ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class StoreByte: public Instruction {
	void execute(char* ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class JumpForwardIf: public Instruction {
	void execute(char* ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class JumpBackIf: public Instruction {
	void execute(char* ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

#endif