#include "instruction.h"


//int AddInstruction::execute(Registers* register_pointer)
//{
//	return ((register_pointer->getPC())+1);
//}
//int SubInstruction::execute(Registers* register_pointer)
//{
//	return ((register_pointer->getPC())+1);
//}
//int OriInstruction::execute(Registers* register_pointer)
//{
//	return ((register_pointer->getPC()) + 1);
//}
//int BrneInstruction::execute(Registers* register_pointer)
//{
//	return ((register_pointer->getPC()) + 1);
//}

Instruction::Instruction(int input_Rd, int input_Rs, int input_Rt)
{
	Rd = input_Rd;
	Rs = input_Rs;
	Rt = input_Rt;
}
