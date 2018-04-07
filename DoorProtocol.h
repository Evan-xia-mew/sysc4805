// {{{RME classifier 'Logical View::DoorProtocol'

#ifndef DoorProtocol_H
#define DoorProtocol_H

#ifdef PRAGMA
#pragma interface "DoorProtocol.h"
#endif

#include <RTSystem/TestComponent.h>

struct DoorProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_doorOpen = rtiLast_RTRootProtocol + 1
		  , rti_doorClosed
		  , rti_doorHeld1
		  , rti_doorHeld5
		};

	protected:
		enum { rtiLast_DoorProtocol = rti_doorHeld5 };

	public:
		inline RTInSignal doorOpen( void );
		inline RTSymmetricSignal doorClosed( void );
		inline RTInSignal doorHeld1( void );
		inline RTInSignal doorHeld5( void );
		inline RTOutSignal doorUnlock( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum
		{
			rti_doorUnlock = rtiLast_RTRootProtocol + 1
		  , rti_doorClosed
		};

	protected:
		enum { rtiLast_DoorProtocol = rti_doorClosed };

	public:
		inline RTInSignal doorUnlock( void );
		inline RTSymmetricSignal doorClosed( void );
		inline RTOutSignal doorOpen( void );
		inline RTOutSignal doorHeld1( void );
		inline RTOutSignal doorHeld5( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline DoorProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline DoorProtocol::Base::~Base( void )
{
}

inline RTInSignal DoorProtocol::Base::doorOpen( void )
{
	return RTInSignal( this, rti_doorOpen );
}

inline RTSymmetricSignal DoorProtocol::Base::doorClosed( void )
{
	return RTSymmetricSignal( this, rti_doorClosed, Conjugate::rti_doorClosed );
}

inline RTInSignal DoorProtocol::Base::doorHeld1( void )
{
	return RTInSignal( this, rti_doorHeld1 );
}

inline RTInSignal DoorProtocol::Base::doorHeld5( void )
{
	return RTInSignal( this, rti_doorHeld5 );
}

inline RTOutSignal DoorProtocol::Base::doorUnlock( void )
{
	return RTOutSignal( this, Conjugate::rti_doorUnlock, (const void *)0, &RTType_void );
}

inline DoorProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline DoorProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal DoorProtocol::Conjugate::doorUnlock( void )
{
	return RTInSignal( this, rti_doorUnlock );
}

inline RTSymmetricSignal DoorProtocol::Conjugate::doorClosed( void )
{
	return RTSymmetricSignal( this, rti_doorClosed, Base::rti_doorClosed );
}

inline RTOutSignal DoorProtocol::Conjugate::doorOpen( void )
{
	return RTOutSignal( this, Base::rti_doorOpen, (const void *)0, &RTType_void );
}

inline RTOutSignal DoorProtocol::Conjugate::doorHeld1( void )
{
	return RTOutSignal( this, Base::rti_doorHeld1, (const void *)0, &RTType_void );
}

inline RTOutSignal DoorProtocol::Conjugate::doorHeld5( void )
{
	return RTOutSignal( this, Base::rti_doorHeld5, (const void *)0, &RTType_void );
}

#endif /* DoorProtocol_H */

// }}}RME
