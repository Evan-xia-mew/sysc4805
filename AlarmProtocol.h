// {{{RME classifier 'Logical View::AlarmProtocol'

#ifndef AlarmProtocol_H
#define AlarmProtocol_H

#ifdef PRAGMA
#pragma interface "AlarmProtocol.h"
#endif

#include <RTSystem/TestComponent.h>

struct AlarmProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_testFail = rtiLast_RTRootProtocol + 1
		  , rti_testPass
		};

	protected:
		enum { rtiLast_AlarmProtocol = rti_testPass };

	public:
		inline RTInSignal testFail( void );
		inline RTInSignal testPass( void );
		inline RTOutSignal arm( void );
		inline RTOutSignal disarm( void );
		inline RTOutSignal activateAlarm( void );
		inline RTOutSignal deactivateAlarm( void );
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
			rti_arm = rtiLast_RTRootProtocol + 1
		  , rti_disarm
		  , rti_activateAlarm
		  , rti_deactivateAlarm
		};

	protected:
		enum { rtiLast_AlarmProtocol = rti_deactivateAlarm };

	public:
		inline RTInSignal arm( void );
		inline RTInSignal disarm( void );
		inline RTInSignal activateAlarm( void );
		inline RTInSignal deactivateAlarm( void );
		inline RTOutSignal testFail( void );
		inline RTOutSignal testPass( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline AlarmProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline AlarmProtocol::Base::~Base( void )
{
}

inline RTInSignal AlarmProtocol::Base::testFail( void )
{
	return RTInSignal( this, rti_testFail );
}

inline RTInSignal AlarmProtocol::Base::testPass( void )
{
	return RTInSignal( this, rti_testPass );
}

inline RTOutSignal AlarmProtocol::Base::arm( void )
{
	return RTOutSignal( this, Conjugate::rti_arm, (const void *)0, &RTType_void );
}

inline RTOutSignal AlarmProtocol::Base::disarm( void )
{
	return RTOutSignal( this, Conjugate::rti_disarm, (const void *)0, &RTType_void );
}

inline RTOutSignal AlarmProtocol::Base::activateAlarm( void )
{
	return RTOutSignal( this, Conjugate::rti_activateAlarm, (const void *)0, &RTType_void );
}

inline RTOutSignal AlarmProtocol::Base::deactivateAlarm( void )
{
	return RTOutSignal( this, Conjugate::rti_deactivateAlarm, (const void *)0, &RTType_void );
}

inline AlarmProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline AlarmProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal AlarmProtocol::Conjugate::arm( void )
{
	return RTInSignal( this, rti_arm );
}

inline RTInSignal AlarmProtocol::Conjugate::disarm( void )
{
	return RTInSignal( this, rti_disarm );
}

inline RTInSignal AlarmProtocol::Conjugate::activateAlarm( void )
{
	return RTInSignal( this, rti_activateAlarm );
}

inline RTInSignal AlarmProtocol::Conjugate::deactivateAlarm( void )
{
	return RTInSignal( this, rti_deactivateAlarm );
}

inline RTOutSignal AlarmProtocol::Conjugate::testFail( void )
{
	return RTOutSignal( this, Base::rti_testFail, (const void *)0, &RTType_void );
}

inline RTOutSignal AlarmProtocol::Conjugate::testPass( void )
{
	return RTOutSignal( this, Base::rti_testPass, (const void *)0, &RTType_void );
}

#endif /* AlarmProtocol_H */

// }}}RME
