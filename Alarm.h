// {{{RME classifier 'Logical View::Alarm'

#ifndef Alarm_H
#define Alarm_H

#ifdef PRAGMA
#pragma interface "Alarm.h"
#endif

#include <RTSystem/TestComponent.h>
#include <AlarmProtocol.h>
class DeviceInfo;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Alarm;

#define SUPER RTActor
class Alarm_Actor : public RTActor
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
	// {{{RME classAttribute 'BreakAlarms'
	bool BreakAlarms;
	// }}}RME

protected:
	// {{{RME port 'AlarmPort'
	AlarmProtocol::Conjugate AlarmPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	Alarm_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Alarm_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:armed:J58B8820B0367:triggerAlarm'
	INLINE_METHODS void transition2_triggerAlarm( const void * rtdata, AlarmProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:testPassed:False'
	INLINE_METHODS void transition4_False( const void * rtdata, AlarmProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:triggered:J58DD5B270033:clearAlarm'
	INLINE_METHODS void transition7_clearAlarm( const void * rtdata, AlarmProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain3_selfTest( void );

protected:
	// {{{RME choicePoint ':TOP:testPassed'
	INLINE_METHODS int choicePoint1_testPassed( const void * rtdata, AlarmProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain5_True( void );
	INLINE_CHAINS void chain4_False( void );
	INLINE_CHAINS void chain6_disarm( void );
	INLINE_CHAINS void chain2_triggerAlarm( void );
	INLINE_CHAINS void chain7_clearAlarm( void );

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
	static const RTFieldDescriptor rtg_Alarm_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Alarm_H */

// }}}RME
