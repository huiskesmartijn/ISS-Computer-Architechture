#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <iostream>
#include "registers.h"

using namespace std;

class Instruction
{
	protected:
		int Rd;
		int Rs;
		int Rt;
	public:
		Instruction(int,int,int);
		//virtual void dissassemble()=0;
		virtual int execute(Registers *)=0;



};


class AddInstruction : public Instruction
{
	public:
		AddInstruction(int a, int b, int c) : Instruction(a, b, c) {
			
		};
		int execute(Registers*);
};


class SubInstruction : public Instruction
{
public:
	SubInstruction(int a, int b, int c) : Instruction(a, b, c) {

	};
	int execute(Registers*);
};


class OriInstruction : public Instruction
{
public:
	int execute(Registers*);
	OriInstruction(int a, int b, int c) : Instruction(a, b, c) {

	};
};


class BrneInstruction : public Instruction
{
public:
	int execute(Registers* reg_Pointer) {
		if (Rs != Rd)
		{
			reg_Pointer->setPC(Rt);
		}
		else
		{
			(reg_Pointer->setPC((reg_Pointer->getPC()) + 1));
			
		}
		return reg_Pointer->getPC();
	};
	BrneInstruction(int a, int b, int c) : Instruction(a, b, c) {

	};
};

#endif /* _INSTRUCTION_H_ */
