#ifndef _REGISTERS_H_
#define _REGISTERS_H_

class Registers
{
	//make private int for each register and a function with can return the value of every int, (NVM NOT SAFE!)or alternatively make an array using a pointer and make a function that correctly can return the ith value of the array corresponding to register i.
	private:
		int regData[32];
		int PC;

	public:
		Registers();
		void setRegister(int regNum, int value);
		int getRegister(int regNum);
		void setPC(int value);
		int getPC();
		void print();

};

#endif	/* _REGISTERS_H_ */
