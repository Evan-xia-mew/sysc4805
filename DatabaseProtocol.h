// {{{RME classifier 'Logical View::DatabaseProtocol'

#ifndef DatabaseProtocol_H
#define DatabaseProtocol_H

#ifdef PRAGMA
#pragma interface "DatabaseProtocol.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CardInfo.h>

struct DatabaseProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_cardIn = rtiLast_RTRootProtocol + 1
		  , rti_event
		  , rti_zone
		  , rti_viewEvents
		};

	protected:
		enum { rtiLast_DatabaseProtocol = rti_viewEvents };

	public:
		inline RTInSignal cardIn( void );
		inline RTInSignal event( void );
		inline RTInSignal zone( void );
		inline RTInSignal viewEvents( void );
		inline RTOutSignal validCard( const RTTypedValue_CardInfo & data );
		inline RTOutSignal invalidCard( const RTTypedValue_CardInfo & data );
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
			rti_validCard = rtiLast_RTRootProtocol + 1
		  , rti_invalidCard
		};

	protected:
		enum { rtiLast_DatabaseProtocol = rti_invalidCard };

	public:
		inline RTInSignal validCard( void );
		inline RTInSignal invalidCard( void );
		inline RTOutSignal cardIn( const RTTypedValue_CardInfo & data );
		inline RTOutSignal event( const int & data );
		inline RTOutSignal zone( void );
		inline RTOutSignal viewEvents( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline DatabaseProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline DatabaseProtocol::Base::~Base( void )
{
}

inline RTInSignal DatabaseProtocol::Base::cardIn( void )
{
	return RTInSignal( this, rti_cardIn );
}

inline RTInSignal DatabaseProtocol::Base::event( void )
{
	return RTInSignal( this, rti_event );
}

inline RTInSignal DatabaseProtocol::Base::zone( void )
{
	return RTInSignal( this, rti_zone );
}

inline RTInSignal DatabaseProtocol::Base::viewEvents( void )
{
	return RTInSignal( this, rti_viewEvents );
}

inline RTOutSignal DatabaseProtocol::Base::validCard( const RTTypedValue_CardInfo & data )
{
	return RTOutSignal( this, Conjugate::rti_validCard, data.data, data.type );
}

inline RTOutSignal DatabaseProtocol::Base::invalidCard( const RTTypedValue_CardInfo & data )
{
	return RTOutSignal( this, Conjugate::rti_invalidCard, data.data, data.type );
}

inline DatabaseProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline DatabaseProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal DatabaseProtocol::Conjugate::validCard( void )
{
	return RTInSignal( this, rti_validCard );
}

inline RTInSignal DatabaseProtocol::Conjugate::invalidCard( void )
{
	return RTInSignal( this, rti_invalidCard );
}

inline RTOutSignal DatabaseProtocol::Conjugate::cardIn( const RTTypedValue_CardInfo & data )
{
	return RTOutSignal( this, Base::rti_cardIn, data.data, data.type );
}

inline RTOutSignal DatabaseProtocol::Conjugate::event( const int & data )
{
	return RTOutSignal( this, Base::rti_event, &data, &RTType_int );
}

inline RTOutSignal DatabaseProtocol::Conjugate::zone( void )
{
	return RTOutSignal( this, Base::rti_zone, (const void *)0, &RTType_void );
}

inline RTOutSignal DatabaseProtocol::Conjugate::viewEvents( void )
{
	return RTOutSignal( this, Base::rti_viewEvents, (const void *)0, &RTType_void );
}

#endif /* DatabaseProtocol_H */

// }}}RME
