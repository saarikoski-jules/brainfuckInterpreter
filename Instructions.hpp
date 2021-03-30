#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include <list>
#include "Instruction.hpp"

class IncrementPtr: public Instruction {
	public:
	~IncrementPtr() {};
	void execute(char*& ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class DecrementPtr: public Instruction {
	public:
	~DecrementPtr() {};
	void execute(char*& ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class IncrementByte: public Instruction {
	public:
	~IncrementByte() {};
	void execute(char*& ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class DecrementByte: public Instruction {
	public:
	~DecrementByte() {};
	void execute(char*& ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class OutputByte: public Instruction {
	public:
	~OutputByte() {};
	void execute(char*& ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class StoreByte: public Instruction {
	public:
	~StoreByte() {};
	void execute(char*& ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class JumpForwardIf: public Instruction {
	public:
	~JumpForwardIf() {};
	void execute(char*& ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

class JumpBackIf: public Instruction {
	public:
	~JumpBackIf() {};
	void execute(char*& ptr, std::list<Instruction*>::iterator& i) const;
	std::string getType() const;
};

#endif