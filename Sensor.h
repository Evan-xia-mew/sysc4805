// {{{RME classifier 'Logical View::Sensor'

#ifndef Sensor_H
#define Sensor_H

#ifdef PRAGMA
#pragma interface "Sensor.h"
#endif

#include <RTSystem/TestComponent.h>
#include <SensorProtocol.h>
#include <SensorTest.h>
class DeviceInfo;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Sensor;

#define SUPER RTActor
class Sensor_Actor : public RTActor
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME
	// {{{RME classAttribute 'BreakSensors'
	bool BreakSensors;
	// }}}RME

protected:
	// {{{RME port 'SensorPort'
	SensorProtocol::Conjugate SensorPort;
	// }}}RME
	// {{{RME port 'SensorTest'
	SensorTest::Base SensorTest;
	// }}}RME

public:
	Sensor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Sensor_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:testPassed:False'
	INLINE_METHODS void transition3_False( const void * rtdata, SensorProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:armed:J58B88D610111:tripped'
	INLINE_METHODS void transition6_tripped( const void * rtdata, SensorTest::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_selfTest( void );

protected:
	// {{{RME choicePoint ':TOP:testPassed'
	INLINE_METHODS int choicePoint1_testPassed( const void * rtdata, SensorProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain4_True( void );
	INLINE_CHAINS void chain3_False( void );
	INLINE_CHAINS void chain5_disarm( void );
	INLINE_CHAINS void chain6_tripped( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];

public:
	static const RTFieldDescriptor rtg_Sensor_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Sensor_H */

// }}}RME
