#include "simulator.h"
#include "program.h"
#include "registers.h"
#include "instruction.h"

//void loadProgram (Program *program)
//{
//	program->appendInstruction (new OriInstruction (1, 0, 12));
//	program->appendInstruction (new OriInstruction (2, 0, 4));
//	program->appendInstruction (new OriInstruction (3, 0, 1));
//	program->appendInstruction (new AddInstruction (4, 4, 1));
//	program->appendInstruction (new SubInstruction (2, 2, 3));
//	program->appendInstruction (new BrneInstruction (2, 0, -3));
//}


int main (void)
{
	/*Registers *registers	= new Registers ();
	Program	*program	= new Program ();

	loadProgram (program);

	Simulator theSimulator = Simulator (registers, program);

	theSimulator.ui ();

	return 0;*/

	Registers myRegisters;
	myRegisters.setRegister(0, 0);
	myRegisters.setRegister(1, 0);
	myRegisters.setPC(100);
	BrneInstruction instruction1(1,0,50);
	instruction1.execute(&myRegisters);
	myRegisters.print();
	cout << myRegisters.getPC() << endl;
}
