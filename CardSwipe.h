// {{{RME classifier 'Logical View::CardSwipe'

#ifndef CardSwipe_H
#define CardSwipe_H

#ifdef PRAGMA
#pragma interface "CardSwipe.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CardInfo.h>

struct CardSwipe
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_cardSwipe = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_CardSwipe = rti_cardSwipe };

	public:
		inline RTInSignal cardSwipe( void );
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
		enum { rtiLast_CardSwipe = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal cardSwipe( const RTTypedValue_CardInfo & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline CardSwipe::Base::Base( void )
	: RTRootProtocol()
{
}

inline CardSwipe::Base::~Base( void )
{
}

inline RTInSignal CardSwipe::Base::cardSwipe( void )
{
	return RTInSignal( this, rti_cardSwipe );
}

inline CardSwipe::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline CardSwipe::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal CardSwipe::Conjugate::cardSwipe( const RTTypedValue_CardInfo & data )
{
	return RTOutSignal( this, Base::rti_cardSwipe, data.data, data.type );
}

#endif /* CardSwipe_H */

// }}}RME
