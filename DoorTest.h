// {{{RME classifier 'Logical View::DoorTest'

#ifndef DoorTest_H
#define DoorTest_H

#ifdef PRAGMA
#pragma interface "DoorTest.h"
#endif

#include <RTSystem/TestComponent.h>

struct DoorTest
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_doorOpen = rtiLast_RTRootProtocol + 1
		  , rti_doorClose
		};

	protected:
		enum { rtiLast_DoorTest = rti_doorClose };

	public:
		inline RTInSignal doorOpen( void );
		inline RTInSignal doorClose( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );

	protected:
		enum { rtiLast_DoorTest = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal doorOpen( void );
		inline RTOutSignal doorClose( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline DoorTest::Base::Base( void )
	: RTRootProtocol()
{
}

inline DoorTest::Base::~Base( void )
{
}

inline RTInSignal DoorTest::Base::doorOpen( void )
{
	return RTInSignal( this, rti_doorOpen );
}

inline RTInSignal DoorTest::Base::doorClose( void )
{
	return RTInSignal( this, rti_doorClose );
}

inline DoorTest::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline DoorTest::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal DoorTest::Conjugate::doorOpen( void )
{
	return RTOutSignal( this, Base::rti_doorOpen, (const void *)0, &RTType_void );
}

inline RTOutSignal DoorTest::Conjugate::doorClose( void )
{
	return RTOutSignal( this, Base::rti_doorClose, (const void *)0, &RTType_void );
}

#endif /* DoorTest_H */

// }}}RME
