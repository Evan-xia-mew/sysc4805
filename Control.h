// {{{RME classifier 'Logical View::Control'

#ifndef Control_H
#define Control_H

#ifdef PRAGMA
#pragma interface "Control.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CardInfo.h>

struct Control
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_cardIn = rtiLast_RTRootProtocol + 1
		  , rti_sensorTriggered
		  , rti_needRepair
		  , rti_doorHeld1
		  , rti_doorHeld5
		};

	protected:
		enum { rtiLast_Control = rti_doorHeld5 };

	public:
		inline RTInSignal cardIn( void );
		inline RTInSignal sensorTriggered( void );
		inline RTInSignal needRepair( void );
		inline RTInSignal doorHeld1( void );
		inline RTInSignal doorHeld5( void );
		inline RTOutSignal disarmZone( void );
		inline RTOutSignal armZone( void );
		inline RTOutSignal cardValid( const RTTypedValue_CardInfo & data );
		inline RTOutSignal resolveAlarm( void );
		inline RTOutSignal cardInvalid( const RTTypedValue_CardInfo & data );
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
			rti_disarmZone = rtiLast_RTRootProtocol + 1
		  , rti_armZone
		  , rti_cardValid
		  , rti_resolveAlarm
		  , rti_cardInvalid
		};

	protected:
		enum { rtiLast_Control = rti_cardInvalid };

	public:
		inline RTInSignal disarmZone( void );
		inline RTInSignal armZone( void );
		inline RTInSignal cardValid( void );
		inline RTInSignal resolveAlarm( void );
		inline RTInSignal cardInvalid( void );
		inline RTOutSignal cardIn( const RTTypedValue_CardInfo & data );
		inline RTOutSignal sensorTriggered( void );
		inline RTOutSignal needRepair( void );
		inline RTOutSignal doorHeld1( void );
		inline RTOutSignal doorHeld5( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline Control::Base::Base( void )
	: RTRootProtocol()
{
}

inline Control::Base::~Base( void )
{
}

inline RTInSignal Control::Base::cardIn( void )
{
	return RTInSignal( this, rti_cardIn );
}

inline RTInSignal Control::Base::sensorTriggered( void )
{
	return RTInSignal( this, rti_sensorTriggered );
}

inline RTInSignal Control::Base::needRepair( void )
{
	return RTInSignal( this, rti_needRepair );
}

inline RTInSignal Control::Base::doorHeld1( void )
{
	return RTInSignal( this, rti_doorHeld1 );
}

inline RTInSignal Control::Base::doorHeld5( void )
{
	return RTInSignal( this, rti_doorHeld5 );
}

inline RTOutSignal Control::Base::disarmZone( void )
{
	return RTOutSignal( this, Conjugate::rti_disarmZone, (const void *)0, &RTType_void );
}

inline RTOutSignal Control::Base::armZone( void )
{
	return RTOutSignal( this, Conjugate::rti_armZone, (const void *)0, &RTType_void );
}

inline RTOutSignal Control::Base::cardValid( const RTTypedValue_CardInfo & data )
{
	return RTOutSignal( this, Conjugate::rti_cardValid, data.data, data.type );
}

inline RTOutSignal Control::Base::resolveAlarm( void )
{
	return RTOutSignal( this, Conjugate::rti_resolveAlarm, (const void *)0, &RTType_void );
}

inline RTOutSignal Control::Base::cardInvalid( const RTTypedValue_CardInfo & data )
{
	return RTOutSignal( this, Conjugate::rti_cardInvalid, data.data, data.type );
}

inline Control::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline Control::Conjugate::~Conjugate( void )
{
}

inline RTInSignal Control::Conjugate::disarmZone( void )
{
	return RTInSignal( this, rti_disarmZone );
}

inline RTInSignal Control::Conjugate::armZone( void )
{
	return RTInSignal( this, rti_armZone );
}

inline RTInSignal Control::Conjugate::cardValid( void )
{
	return RTInSignal( this, rti_cardValid );
}

inline RTInSignal Control::Conjugate::resolveAlarm( void )
{
	return RTInSignal( this, rti_resolveAlarm );
}

inline RTInSignal Control::Conjugate::cardInvalid( void )
{
	return RTInSignal( this, rti_cardInvalid );
}

inline RTOutSignal Control::Conjugate::cardIn( const RTTypedValue_CardInfo & data )
{
	return RTOutSignal( this, Base::rti_cardIn, data.data, data.type );
}

inline RTOutSignal Control::Conjugate::sensorTriggered( void )
{
	return RTOutSignal( this, Base::rti_sensorTriggered, (const void *)0, &RTType_void );
}

inline RTOutSignal Control::Conjugate::needRepair( void )
{
	return RTOutSignal( this, Base::rti_needRepair, (const void *)0, &RTType_void );
}

inline RTOutSignal Control::Conjugate::doorHeld1( void )
{
	return RTOutSignal( this, Base::rti_doorHeld1, (const void *)0, &RTType_void );
}

inline RTOutSignal Control::Conjugate::doorHeld5( void )
{
	return RTOutSignal( this, Base::rti_doorHeld5, (const void *)0, &RTType_void );
}

#endif /* Control_H */

// }}}RME
