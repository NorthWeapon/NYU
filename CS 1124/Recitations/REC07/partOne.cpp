#include <iostream>
<<<<<<< HEAD
#include <string>
#include <vector>
using namespace std;

class Instrument
{
protected:
	string name, pitch;

public:
	virtual void makeSound() const = 0;
};


void Instrument::makeSound() const
{
	cout << "This is a generic instrument" << endl;
}


class Brass : public Instrument
{
protected:
	unsigned size;

public:
	Brass(unsigned x) : size(x) {};

    void makeSound() const
	{
		cout << "This is a brass instrument" << endl;
		cout << "To make a sound... blow on a mouthpiece of size " << size << endl;
	}
};

class String : public Instrument
{
protected:
	unsigned size;

public:
	String(unsigned x) : size(x) {}

	virtual void makeSound() const
	{
		cout << "This is a string instrument" << endl;
		cout << "To make a sound... bow a string with pitch " << size << endl;
	}
};

class Percussion : public Instrument
{
public:

	virtual void makeSound() const
	{
		cout << "This is a percussion instrument" << endl;
		cout << "To make a sound... hit me!" << endl;
	}
};

class Violin : public String
{
public:
	Violin(unsigned x) : String(x) {};
};

class Trombone : public Brass
{
public:
	Trombone(unsigned x) : Brass(x) {};
};

class Cello : public Brass
{
private:
public:
	Cello(unsigned x) : Brass(x) {};
};

class Cymbal : public Percussion
{
private:
public:
};

class Trumpet : public Brass
{
private:
public:
	Trumpet(unsigned x) : Brass(x) {};
};

class Drum : public Percussion
{
private:
public:
};

class Orch
{
private:
public:
	void addPlayer(Musician person)
	{

	}
	void play()
	{

	}

};

class MILL
{
private:
	vector<Instrument*> instruments;

public:
	void receiveInstr(Instrument& x)
	{
		x.makeSound();
		for (int index = 0; index < instruments.size() - 1; index++)
		{
			if (instruments[index] == NULL)
			{
				instruments[index] = &x;
			}
		}
	}
	Instrument* loanOut()
	{
		for (int index = 0; index < instruments.size() - 1; index++)
		{
			if (instruments[index] != NULL)
			{
				Instrument* nullVar = instruments[index];
				instruments[index] = NULL;
				return(nullVar);
			}
			while (index == instruments.size - 1)
			{
				if (instruments[index] == NULL)
				{
					return NULL;
				}
			}
		}
	}
	void dailyTestPlay()
	{

	}
};

class Musician 
{
private:
	Instrument* instr;

public:
	Musician() : instr( NULL ) {}

	void acceptInstr( Instrument & i ) { instr = &i; }
	Instrument* giveBackInstr( ) 
	{ 
=======
using namespace std;

class Musician {
public:
	Musician() : instr( NULL ) {}
	void acceptInstr( Instrument & i ) { instr = &i; }
	Instrument* giveBackInstr( ) { 
>>>>>>> origin/master
		Instrument* tmp(instr); 
		instr = NULL;
		return tmp;
	}
<<<<<<< HEAD
	void giveBackInstr() const
	{

	}
	void testPlay() const 
	{
=======
	void testPlay() const {
>>>>>>> origin/master
		if( instr )
			instr->makeSound(); 
		else
			cerr << "have no instr\n";
	}
<<<<<<< HEAD
};

int partOne()
{
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12) ;
    Violin violin(567) ;
  
    MILL mill;

    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
  
    cout << "Daily test -----------------------------------------------------\n";
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
  
    cout << "Define some Musicians-------------------------------------------\n";
    Musician j;
    Musician jj;
    Musician q;
  	
    cout << "TESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
    q.testPlay();	
    cout << endl;
    q.acceptInstr( *mill.loanOut() );
    cout << endl;
    q.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
  
    cout << endl << endl;
  
    q.testPlay();	
    cout << endl;
    mill.receiveInstr( *q.giveBackInstr() );
    j.acceptInstr( *mill.loanOut() );
    q.acceptInstr( *mill.loanOut() );
    cout << endl;
    q.testPlay();
    cout << endl;
    j.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
  
    cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";
  
    // fifth
    mill.receiveInstr( *q.giveBackInstr() );
    cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
    mill.receiveInstr( *j.giveBackInstr() );

  
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
  
    cout << endl;
}

// PART TWO
int partTwo()
{
	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;

	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();
}

int main()
{

}
=======
private:
	Instrument* instr;
};


// PART ONE
int main()
{

  // cout << "Define some instruments ----------------------------------------\n";
  // Drum drum;
  // Cello cello(673);
  // Cymbal cymbal;
  // Trombone tbone( 4 );
  // Trumpet trpt( 12 ) ;
  // Violin violin( 567 ) ;
  
  // // use the debugger to look at the mill
  // cout << "Define the MILL ------------------------------------------------\n";
  // MILL mill;
  
  // cout << "Put the instruments into the MILL ------------------------------\n";
  // mill.receiveInstr( trpt );
  // mill.receiveInstr( violin );
  // mill.receiveInstr( tbone );
  // mill.receiveInstr( drum );
  // mill.receiveInstr( cello );
  // mill.receiveInstr( cymbal );
  
  // cout << "Daily test -----------------------------------------------------\n";
  // cout << endl;
  // cout << "dailyTestPlay()" << endl;
  // mill.dailyTestPlay();
  // cout << endl;
  
  // cout << "Define some Musicians-------------------------------------------\n";
  // Musician j;
  // Musician jj;
  // Musician q;
  	
  // cout << "TESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
  // q.testPlay();	
  // cout << endl;
  // q.acceptInstr( *mill.loanOut() );
  // cout << endl;
  // q.testPlay();
  // cout << endl;
  // cout << "dailyTestPlay()" << endl;
  // mill.dailyTestPlay();
  
  // cout << endl << endl;
  
  // q.testPlay();	
  // cout << endl;
  // mill.receiveInstr( *q.giveBackInstr() );
  // j.acceptInstr( *mill.loanOut() );
  // q.acceptInstr( *mill.loanOut() );
  // cout << endl;
  // q.testPlay();
  // cout << endl;
  // j.testPlay();
  // cout << endl;
  // cout << "dailyTestPlay()" << endl;
  // mill.dailyTestPlay();
  
  // cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";
  
  // // fifth
  // mill.receiveInstr( *q.giveBackInstr() );
  // cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
  // mill.receiveInstr( *j.giveBackInstr() );

  
  // cout << endl;
  // cout << "dailyTestPlay()" << endl;
  // mill.dailyTestPlay();
  // cout << endl;
  
  // cout << endl;
}

>>>>>>> origin/master
