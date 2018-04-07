// {{{RME classifier 'Logical View::LocalController'

#ifndef LocalController_H
#define LocalController_H

#ifdef PRAGMA
#pragma interface "LocalController.h"
#endif

#include <RTSystem/TestComponent.h>
#include <AlarmProtocol.h>
#include <CardReaderProtocol.h>
#include <Control.h>
#include <DoorProtocol.h>
#include <SensorProtocol.h>
#include <Test.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass LocalController;

#define SUPER RTActor
class LocalController_Actor : public RTActor
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

protected:
	// {{{RME capsuleRole 'doorStateR1'
	RTActorRef doorStateR1;
	// }}}RME
	// {{{RME capsuleRole 'cardReaderR1'
	RTActorRef cardReaderR1;
	// }}}RME
	// {{{RME capsuleRole 'sensorR1'
	RTActorRef sensorR1;
	// }}}RME
	// {{{RME capsuleRole 'alarmR1'
	RTActorRef alarmR1;
	// }}}RME
	// {{{RME port 'DoorPort'
	DoorProtocol::Base DoorPort;
	// }}}RME
	// {{{RME port 'SensorPort'
	SensorProtocol::Base SensorPort;
	// }}}RME
	// {{{RME port 'ControlPort'
	Control::Conjugate ControlPort;
	// }}}RME
	// {{{RME port 'ReaderPort'
	CardReaderProtocol::Base ReaderPort;
	// }}}RME
	// {{{RME port 'AlarmPort'
	AlarmProtocol::Base AlarmPort;
	// }}}RME
	// {{{RME port 'LocalTest'
	Test::Base LocalTest;
	// }}}RME
	// {{{RME port 'timing'
	Timing::Base timing;
	// }}}RME

public:
	LocalController_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~LocalController_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:idleArmed:J58B888EE011B:disarm'
	INLINE_METHODS void transition2_disarm( const void * rtdata, Control::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idleDisarmed:J58B8A7CE0251:arm'
	INLINE_METHODS void transition3_arm( const void * rtdata, Control::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idleArmed:J58B8A7D30076:testFail'
	INLINE_METHODS void transition4_testFail( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idleDisarmed:J58B8AB5501C2:cardInDisarmed'
	INLINE_METHODS void transition8_cardInDisarmed( const CardInfo * rtdata, CardReaderProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idleArmed:J58B8AB5B016B:cardInArmed'
	INLINE_METHODS void transition10_cardInArmed( const CardInfo * rtdata, CardReaderProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:alarmTriggered:J58B9B7ED03CD:alarmResolve'
	INLINE_METHODS void transition12_alarmResolve( const void * rtdata, Control::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idleArmed:J58DD2E0F01BD:sensorTriggered'
	INLINE_METHODS void transition14_sensorTriggered( const void * rtdata, SensorProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Delay:J58DD2E120063:turnOnAlarm'
	INLINE_METHODS void transition15_turnOnAlarm( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Delay:J58DD31E900F6:disarmed'
	INLINE_METHODS void transition16_disarmed( const void * rtdata, Control::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:cardSwipe:securityViolation:J58B885D90270:fiveMinutes'
	INLINE_METHODS void transition17_fiveMinutes( const void * rtdata, DoorProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:cardSwipe:doorOpen:J58B885D60300:oneMinute'
	INLINE_METHODS void transition18_oneMinute( const void * rtdata, DoorProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:cardSwipe:doorUnlock:J58B8794E00F7:timerStart'
	INLINE_METHODS void transition19_timerStart( const void * rtdata, DoorProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:cardSwipe:waitDisarmed:J58B88577006B:cardValid'
	INLINE_METHODS void transition20_cardValid( const CardInfo * rtdata, Control::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:cardSwipe:securityAlarm:J58B880400383:alarmResolved'
	INLINE_METHODS void transition21_alarmResolved( const void * rtdata, Control::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:cardSwipe:securityViolation:J58B8863B03CA:doorClosed1'
	INLINE_METHODS void transition22_doorClosed1( const void * rtdata, DoorProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:cardSwipe:doorOpen:J58B8B035005E:doorClosed'
	INLINE_METHODS void transition25_doorClosed( const void * rtdata, DoorProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:cardSwipe:waitArmed:J58B9B8830025:cardValid'
	INLINE_METHODS void transition28_cardValid( const CardInfo * rtdata, Control::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain3_arm( void );
	INLINE_CHAINS void chain8_cardInDisarmed( void );
	INLINE_CHAINS void chain14_sensorTriggered( void );
	INLINE_CHAINS void chain4_testFail( void );
	INLINE_CHAINS void chain2_disarm( void );
	INLINE_CHAINS void chain10_cardInArmed( void );
	INLINE_CHAINS void chain12_alarmResolve( void );
	INLINE_CHAINS void chain21_alarmResolved( void );
	INLINE_CHAINS void chain22_doorClosed1( void );
	INLINE_CHAINS void chain17_fiveMinutes( void );
	INLINE_CHAINS void chain25_doorClosed( void );
	INLINE_CHAINS void chain18_oneMinute( void );
	INLINE_CHAINS void chain19_timerStart( void );
	INLINE_CHAINS void chain29_timeout( void );
	INLINE_CHAINS void chain20_cardValid( void );
	INLINE_CHAINS void chain24_invDisarmed( void );
	INLINE_CHAINS void chain28_cardValid( void );
	INLINE_CHAINS void chain26_invArmed( void );
	INLINE_CHAINS void chain16_disarmed( void );
	INLINE_CHAINS void chain15_turnOnAlarm( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTComponentDescriptor rtg_capsule_roles[];
	static const RTPortDescriptor rtg_ports[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* LocalController_H */

// }}}RME
