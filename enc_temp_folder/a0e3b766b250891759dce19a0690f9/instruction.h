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
		virtual void disassemble()=0;
		virtual int execute(Registers *)=0;



};


class AddInstruction : public Instruction
{
	public:
		AddInstruction(int a, int b, int c) : Instruction(a, b, c) {
			
		};
		int execute(Registers* reg_Pointer) {
			reg_Pointer->setRegister(Rd, reg_Pointer->getRegister(Rs) + reg_Pointer->getRegister(Rt));
			reg_Pointer->setPC((reg_Pointer->getPC()) + 1);
			return reg_Pointer->getPC();
		};
		void disassemble() {
			cout << "add	" << "$" << Rd << "," << "$" << Rs << "," << "$" << Rt << endl;
		}
};


class SubInstruction : public Instruction
{
public:
	SubInstruction(int a, int b, int c) : Instruction(a, b, c) {

	};
	int execute(Registers* reg_Pointer) {
		reg_Pointer->setRegister(Rd, reg_Pointer->getRegister(Rs) - reg_Pointer->getRegister(Rt));
		reg_Pointer->setPC((reg_Pointer->getPC()) + 1);
		return reg_Pointer->getPC();
	};
	void disassemble() {
		cout << "sub	" << "$" << Rd << "," << "$" << Rs << "," << "$" << Rt << endl;
	}
};


class OriInstruction : public Instruction
{
public:
	int execute(Registers* reg_Pointer) {
		reg_Pointer->setRegister(Rd, reg_Pointer->getRegister(Rs) | Rt);
		reg_Pointer->setPC((reg_Pointer->getPC()) + 1);
		return reg_Pointer->getPC();
	};
	OriInstruction(int a, int b, int c) : Instruction(a, b, c) {

	};
	void disassemble() {
		cout << "ori	" << "$" << Rd << "," << "$" << Rs << "," << Rt << endl;
	}
};


class BrneInstruction : public Instruction
{
public:
	int execute(Registers* reg_Pointer) {
		if (reg_Pointer->getRegister(Rs) != reg_Pointer->getRegister(Rd))
		{
			reg_Pointer->setPC((reg_Pointer -> getPC()) + Rt);
		}
		else
		{
			(reg_Pointer->setPC((reg_Pointer->getPC()) + 1));
			
		}
		return reg_Pointer->getPC();
	};
	BrneInstruction(int a, int b, int c) : Instruction(a, b, c) {

	};
	void disassemble() {
		cout << "brne	" << "$" << Rd << "," << "$" << Rs << "," << Rt << endl;
	}
};

#endif /* _INSTRUCTION_H_ */
