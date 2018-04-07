// {{{RME classifier 'Logical View::SensorProtocol'

#ifndef SensorProtocol_H
#define SensorProtocol_H

#ifdef PRAGMA
#pragma interface "SensorProtocol.h"
#endif

#include <RTSystem/TestComponent.h>

struct SensorProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_triggered = rtiLast_RTRootProtocol + 1
		  , rti_testFail
		  , rti_testPass
		};

	protected:
		enum { rtiLast_SensorProtocol = rti_testPass };

	public:
		inline RTInSignal triggered( void );
		inline RTInSignal testFail( void );
		inline RTInSignal testPass( void );
		inline RTOutSignal arm( void );
		inline RTOutSignal disarm( void );
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
		};

	protected:
		enum { rtiLast_SensorProtocol = rti_disarm };

	public:
		inline RTInSignal arm( void );
		inline RTInSignal disarm( void );
		inline RTOutSignal triggered( void );
		inline RTOutSignal testFail( void );
		inline RTOutSignal testPass( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline SensorProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline SensorProtocol::Base::~Base( void )
{
}

inline RTInSignal SensorProtocol::Base::triggered( void )
{
	return RTInSignal( this, rti_triggered );
}

inline RTInSignal SensorProtocol::Base::testFail( void )
{
	return RTInSignal( this, rti_testFail );
}

inline RTInSignal SensorProtocol::Base::testPass( void )
{
	return RTInSignal( this, rti_testPass );
}

inline RTOutSignal SensorProtocol::Base::arm( void )
{
	return RTOutSignal( this, Conjugate::rti_arm, (const void *)0, &RTType_void );
}

inline RTOutSignal SensorProtocol::Base::disarm( void )
{
	return RTOutSignal( this, Conjugate::rti_disarm, (const void *)0, &RTType_void );
}

inline SensorProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline SensorProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal SensorProtocol::Conjugate::arm( void )
{
	return RTInSignal( this, rti_arm );
}

inline RTInSignal SensorProtocol::Conjugate::disarm( void )
{
	return RTInSignal( this, rti_disarm );
}

inline RTOutSignal SensorProtocol::Conjugate::triggered( void )
{
	return RTOutSignal( this, Base::rti_triggered, (const void *)0, &RTType_void );
}

inline RTOutSignal SensorProtocol::Conjugate::testFail( void )
{
	return RTOutSignal( this, Base::rti_testFail, (const void *)0, &RTType_void );
}

inline RTOutSignal SensorProtocol::Conjugate::testPass( void )
{
	return RTOutSignal( this, Base::rti_testPass, (const void *)0, &RTType_void );
}

#endif /* SensorProtocol_H */

// }}}RME
