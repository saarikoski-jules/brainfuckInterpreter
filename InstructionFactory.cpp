#include "InstructionFactory.hpp"

#include <stddef.h>

Instruction* InstructionFactory::newIncrementPtr() const {
	return (new IncrementPtr);
}

Instruction* InstructionFactory::newDecrementPtr() const {
	return (new DecrementPtr);
}

Instruction* InstructionFactory::newIncrementByte() const {
	return (new IncrementByte);
}

Instruction* InstructionFactory::newDecrementByte() const {
	return (new DecrementByte);
}

Instruction* InstructionFactory::newOutputByte() const {
	return (new OutputByte);
}

Instruction* InstructionFactory::newStoreByte() const {
	return (new StoreByte);
}

Instruction* InstructionFactory::newJumpBackIf() const {
	return (new JumpBackIf);
}

Instruction* InstructionFactory::newJumpForwardIf() const {
	return (new JumpForwardIf);
}

Instruction* InstructionFactory::newInstruction(const char c) const {
	Instruction* (InstructionFactory::*inst[8])() const = {
		&InstructionFactory::newIncrementPtr,
		&InstructionFactory::newDecrementPtr,
		&InstructionFactory::newIncrementByte,
		&InstructionFactory::newDecrementByte,
		&InstructionFactory::newOutputByte,
		&InstructionFactory::newStoreByte,
		&InstructionFactory::newJumpForwardIf,
		&InstructionFactory::newJumpBackIf
	};

	const char types[9] = "><+-.,[]";

	for (unsigned int i = 0; i < 8; i++) {
		if (c == types[i]) {
			return ((this->*inst[i])());
		}
	}
	return (NULL);
}