#include <iostream>
#include "registers.h"

using namespace std;

Registers::Registers()
{
	for (int i = 0; i < 32; i++)
	{
		regData[i] = 0;
	}
	PC = 0;
	
}

void Registers::setRegister(int regNum, int value)
{
	if (regNum != 0)
	{
		if (regNum <32 && regNum >0)
		{
			regData[regNum] = value;
		}
		else
		{
			cout << "You're trying to write to register " << regNum << " which is out of bounds" << endl;
		}
		
	}
	
}

int Registers::getRegister(int regNum)
{
	return regData[regNum];
}

void Registers::setPC(int value)
{
	PC = value;
}

int Registers::getPC()
{
	return PC;
}

void Registers::print()
{
	cout << "Program counter: "<< PC<< endl;
	cout << "Register values:" << endl;
	for (int i = 0; i < 32; i++)
	{
		cout << "Reg " << i <<": "<< regData[i] << endl;
	}
}


