#ifndef INSTRUCTIONFACTORY_HPP
#define INSTRUCTIONFACTORY_HPP

#include "Instructions.hpp"

class InstructionFactory {
	private:
	public:

	Instruction* newIncrementPtr() const;
	Instruction* newDecrementPtr() const;
	Instruction* newIncrementByte() const;
	Instruction* newDecrementByte() const;
	Instruction* newOutputByte() const;
	Instruction* newStoreByte() const;
	Instruction* newJumpForwardIf() const;
	Instruction* newJumpBackIf() const;


	Instruction* newInstruction(const char c) const;
};

#endif