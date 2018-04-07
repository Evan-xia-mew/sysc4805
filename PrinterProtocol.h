// {{{RME classifier 'Logical View::PrinterProtocol'

#ifndef PrinterProtocol_H
#define PrinterProtocol_H

#ifdef PRAGMA
#pragma interface "PrinterProtocol.h"
#endif

#include <RTSystem/TestComponent.h>

struct PrinterProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_printEvent = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_PrinterProtocol = rti_printEvent };

	public:
		inline RTInSignal printEvent( void );
		inline RTOutSignal printEvent( const int & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum { rti_printEvent = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_PrinterProtocol = rti_printEvent };

	public:
		inline RTInSignal printEvent( void );
		inline RTOutSignal printEvent( const int & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline PrinterProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline PrinterProtocol::Base::~Base( void )
{
}

inline RTInSignal PrinterProtocol::Base::printEvent( void )
{
	return RTInSignal( this, rti_printEvent );
}

inline RTOutSignal PrinterProtocol::Base::printEvent( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_printEvent, &data, &RTType_int );
}

inline PrinterProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline PrinterProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal PrinterProtocol::Conjugate::printEvent( void )
{
	return RTInSignal( this, rti_printEvent );
}

inline RTOutSignal PrinterProtocol::Conjugate::printEvent( const int & data )
{
	return RTOutSignal( this, Base::rti_printEvent, &data, &RTType_int );
}

#endif /* PrinterProtocol_H */

// }}}RME
