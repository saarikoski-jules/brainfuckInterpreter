#ifndef INSTRUCTION_CPP
#define INSTRUCTION_CPP

class Instruction {
	public:

	virtual void execute(char* ptr, std::list<Instruction*>::iterator& i) const = 0;
	virtual std::string getType() const = 0;

};

#endif