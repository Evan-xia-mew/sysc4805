// {{{RME classifier 'Logical View::CCAlarmProtocol'

#ifndef CCAlarmProtocol_H
#define CCAlarmProtocol_H

#ifdef PRAGMA
#pragma interface "CCAlarmProtocol.h"
#endif

#include <RTSystem/TestComponent.h>

struct CCAlarmProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_addAlarm = rtiLast_RTRootProtocol + 1
		  , rti_activateCCAlarm
		  , rti_deactivateCCAlarm
		};

	protected:
		enum { rtiLast_CCAlarmProtocol = rti_deactivateCCAlarm };

	public:
		inline RTSymmetricSignal addAlarm( void );
		inline RTSymmetricSignal activateCCAlarm( void );
		inline RTSymmetricSignal deactivateCCAlarm( void );
		inline RTOutSignal viewAlarms( void );
		inline RTOutSignal resolveAlarm( const int & data );
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
			rti_activateCCAlarm = rtiLast_RTRootProtocol + 1
		  , rti_deactivateCCAlarm
		  , rti_viewAlarms
		  , rti_addAlarm
		  , rti_resolveAlarm
		};

	protected:
		enum { rtiLast_CCAlarmProtocol = rti_resolveAlarm };

	public:
		inline RTSymmetricSignal activateCCAlarm( void );
		inline RTSymmetricSignal deactivateCCAlarm( void );
		inline RTInSignal viewAlarms( void );
		inline RTSymmetricSignal addAlarm( void );
		inline RTInSignal resolveAlarm( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline CCAlarmProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline CCAlarmProtocol::Base::~Base( void )
{
}

inline RTSymmetricSignal CCAlarmProtocol::Base::addAlarm( void )
{
	return RTSymmetricSignal( this, rti_addAlarm, Conjugate::rti_addAlarm );
}

inline RTSymmetricSignal CCAlarmProtocol::Base::activateCCAlarm( void )
{
	return RTSymmetricSignal( this, rti_activateCCAlarm, Conjugate::rti_activateCCAlarm );
}

inline RTSymmetricSignal CCAlarmProtocol::Base::deactivateCCAlarm( void )
{
	return RTSymmetricSignal( this, rti_deactivateCCAlarm, Conjugate::rti_deactivateCCAlarm );
}

inline RTOutSignal CCAlarmProtocol::Base::viewAlarms( void )
{
	return RTOutSignal( this, Conjugate::rti_viewAlarms, (const void *)0, &RTType_void );
}

inline RTOutSignal CCAlarmProtocol::Base::resolveAlarm( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_resolveAlarm, &data, &RTType_int );
}

inline CCAlarmProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline CCAlarmProtocol::Conjugate::~Conjugate( void )
{
}

inline RTSymmetricSignal CCAlarmProtocol::Conjugate::activateCCAlarm( void )
{
	return RTSymmetricSignal( this, rti_activateCCAlarm, Base::rti_activateCCAlarm );
}

inline RTSymmetricSignal CCAlarmProtocol::Conjugate::deactivateCCAlarm( void )
{
	return RTSymmetricSignal( this, rti_deactivateCCAlarm, Base::rti_deactivateCCAlarm );
}

inline RTInSignal CCAlarmProtocol::Conjugate::viewAlarms( void )
{
	return RTInSignal( this, rti_viewAlarms );
}

inline RTSymmetricSignal CCAlarmProtocol::Conjugate::addAlarm( void )
{
	return RTSymmetricSignal( this, rti_addAlarm, Base::rti_addAlarm );
}

inline RTInSignal CCAlarmProtocol::Conjugate::resolveAlarm( void )
{
	return RTInSignal( this, rti_resolveAlarm );
}

#endif /* CCAlarmProtocol_H */

// }}}RME
