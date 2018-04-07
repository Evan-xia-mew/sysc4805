// {{{RME classifier 'Logical View::SensorTest'

#ifndef SensorTest_H
#define SensorTest_H

#ifdef PRAGMA
#pragma interface "SensorTest.h"
#endif

#include <RTSystem/TestComponent.h>

struct SensorTest
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_TriggerSensor = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_SensorTest = rti_TriggerSensor };

	public:
		inline RTInSignal TriggerSensor( void );
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
		enum { rtiLast_SensorTest = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal TriggerSensor( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline SensorTest::Base::Base( void )
	: RTRootProtocol()
{
}

inline SensorTest::Base::~Base( void )
{
}

inline RTInSignal SensorTest::Base::TriggerSensor( void )
{
	return RTInSignal( this, rti_TriggerSensor );
}

inline SensorTest::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline SensorTest::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal SensorTest::Conjugate::TriggerSensor( void )
{
	return RTOutSignal( this, Base::rti_TriggerSensor, (const void *)0, &RTType_void );
}

#endif /* SensorTest_H */

// }}}RME
