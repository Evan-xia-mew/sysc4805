// {{{RME classifier 'Logical View::Test'

#ifndef Test_H
#define Test_H

#ifdef PRAGMA
#pragma interface "Test.h"
#endif

#include <RTSystem/TestComponent.h>

struct Test
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_arm = rtiLast_RTRootProtocol + 1
		  , rti_disarm
		  , rti_resolveAlarm
		};

	protected:
		enum { rtiLast_Test = rti_resolveAlarm };

	public:
		inline RTInSignal arm( void );
		inline RTInSignal disarm( void );
		inline RTInSignal resolveAlarm( void );
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
		enum { rtiLast_Test = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal arm( const int & data );
		inline RTOutSignal disarm( const int & data );
		inline RTOutSignal resolveAlarm( const int & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline Test::Base::Base( void )
	: RTRootProtocol()
{
}

inline Test::Base::~Base( void )
{
}

inline RTInSignal Test::Base::arm( void )
{
	return RTInSignal( this, rti_arm );
}

inline RTInSignal Test::Base::disarm( void )
{
	return RTInSignal( this, rti_disarm );
}

inline RTInSignal Test::Base::resolveAlarm( void )
{
	return RTInSignal( this, rti_resolveAlarm );
}

inline Test::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline Test::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal Test::Conjugate::arm( const int & data )
{
	return RTOutSignal( this, Base::rti_arm, &data, &RTType_int );
}

inline RTOutSignal Test::Conjugate::disarm( const int & data )
{
	return RTOutSignal( this, Base::rti_disarm, &data, &RTType_int );
}

inline RTOutSignal Test::Conjugate::resolveAlarm( const int & data )
{
	return RTOutSignal( this, Base::rti_resolveAlarm, &data, &RTType_int );
}

#endif /* Test_H */

// }}}RME
