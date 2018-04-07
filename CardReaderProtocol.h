// {{{RME classifier 'Logical View::CardReaderProtocol'

#ifndef CardReaderProtocol_H
#define CardReaderProtocol_H

#ifdef PRAGMA
#pragma interface "CardReaderProtocol.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CardInfo.h>

struct CardReaderProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_cardIn = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_CardReaderProtocol = rti_cardIn };

	public:
		inline RTInSignal cardIn( void );
		inline RTOutSignal cardValid( void );
		inline RTOutSignal cardInvalid( void );
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
			rti_cardValid = rtiLast_RTRootProtocol + 1
		  , rti_cardInvalid
		};

	protected:
		enum { rtiLast_CardReaderProtocol = rti_cardInvalid };

	public:
		inline RTInSignal cardValid( void );
		inline RTInSignal cardInvalid( void );
		inline RTOutSignal cardIn( const RTTypedValue_CardInfo & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline CardReaderProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline CardReaderProtocol::Base::~Base( void )
{
}

inline RTInSignal CardReaderProtocol::Base::cardIn( void )
{
	return RTInSignal( this, rti_cardIn );
}

inline RTOutSignal CardReaderProtocol::Base::cardValid( void )
{
	return RTOutSignal( this, Conjugate::rti_cardValid, (const void *)0, &RTType_void );
}

inline RTOutSignal CardReaderProtocol::Base::cardInvalid( void )
{
	return RTOutSignal( this, Conjugate::rti_cardInvalid, (const void *)0, &RTType_void );
}

inline CardReaderProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline CardReaderProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal CardReaderProtocol::Conjugate::cardValid( void )
{
	return RTInSignal( this, rti_cardValid );
}

inline RTInSignal CardReaderProtocol::Conjugate::cardInvalid( void )
{
	return RTInSignal( this, rti_cardInvalid );
}

inline RTOutSignal CardReaderProtocol::Conjugate::cardIn( const RTTypedValue_CardInfo & data )
{
	return RTOutSignal( this, Base::rti_cardIn, data.data, data.type );
}

#endif /* CardReaderProtocol_H */

// }}}RME
