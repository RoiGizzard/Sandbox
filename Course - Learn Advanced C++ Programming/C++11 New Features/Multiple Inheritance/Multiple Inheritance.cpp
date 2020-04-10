#include <iostream>

class MusicalInstrument
{
public:
	virtual void play()
	{
		std::cout << "Playing instrument..." << std::endl;
	}

	virtual void reset()
	{
		std::cout << "Resetting instrument..." << std::endl;
	}
};

class Machine
{
public:
	virtual void start()
	{
		std::cout << "Start machine..." << std::endl;
	}

	virtual void reset()
	{
		std::cout << "Resetting machine..." << std::endl;
	}
};

class Synthesizer : public Machine, public MusicalInstrument
{

};

int main()
{
	Synthesizer *synth = new Synthesizer();

	synth->play();
	synth->start();
	synth->MusicalInstrument::reset();
	synth->Machine::reset();

	delete synth;

    std::cout << "Hello World!\n";
}
