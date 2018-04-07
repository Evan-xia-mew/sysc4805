// {{{RME classifier 'Logical View::ControlCenter'

#ifndef ControlCenter_H
#define ControlCenter_H

#ifdef PRAGMA
#pragma interface "ControlCenter.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CCAlarmProtocol.h>
#include <Control.h>
#include <DatabaseProtocol.h>
#include <PrinterProtocol.h>
#include <Test.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ControlCenter;

#define SUPER RTActor
class ControlCenter_Actor : public RTActor
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
	// {{{RME capsuleRole 'alarmR1'
	RTActorRef alarmR1;
	// }}}RME
	// {{{RME capsuleRole 'LocalControllerR1'
	RTActorRef LocalControllerR1;
	// }}}RME
	// {{{RME capsuleRole 'printerR1'
	RTActorRef printerR1;
	// }}}RME
	// {{{RME capsuleRole 'activeAlarmsR1'
	RTActorRef activeAlarmsR1;
	// }}}RME
	// {{{RME capsuleRole 'databaseR1'
	RTActorRef databaseR1;
	// }}}RME
	// {{{RME port 'DatabasePort'
	DatabaseProtocol::Conjugate DatabasePort;
	// }}}RME
	// {{{RME port 'PrinterPort'
	PrinterProtocol::Base PrinterPort;
	// }}}RME
	// {{{RME port 'ControlPort'
	Control::Base ControlPort;
	// }}}RME
	// {{{RME port 'InterfacePort'
	Test::Base InterfacePort;
	// }}}RME
	// {{{RME port 'ActiveAlarmsPort'
	CCAlarmProtocol::Base ActiveAlarmsPort;
	// }}}RME
	// {{{RME port 'CCAlarmPort'
	CCAlarmProtocol::Base CCAlarmPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	ControlCenter_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ControlCenter_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:idle:J58B891450108:cardSwipe'
	INLINE_METHODS void transition2_cardSwipe( const CardInfo * rtdata, Control::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58B893C50331:clearActiveAlarm'
	INLINE_METHODS void transition3_clearActiveAlarm( const int * rtdata, Test::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58DAABB30290:secViolation'
	INLINE_METHODS void transition4_secViolation( const void * rtdata, Control::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58B8946700E1:armZone'
	INLINE_METHODS void transition5_armZone( const int * rtdata, Test::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58B8946D023E:disarmZone'
	INLINE_METHODS void transition6_disarmZone( const int * rtdata, Test::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58B8C1E70309:cardVerify'
	INLINE_METHODS void transition7_cardVerify( const CardInfo * rtdata, DatabaseProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58D9907B000D:repairNeeded'
	INLINE_METHODS void transition8_repairNeeded( const void * rtdata, Control::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58DAABFF0054:secAlarm'
	INLINE_METHODS void transition9_secAlarm( const void * rtdata, Control::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58DD4684028C:activateCCAlarm'
	INLINE_METHODS void transition10_activateCCAlarm( const void * rtdata, CCAlarmProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:idle:J58DD469A02AC:clearCCAlarm'
	INLINE_METHODS void transition11_clearCCAlarm( const void * rtdata, CCAlarmProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain7_cardVerify( void );
	INLINE_CHAINS void chain2_cardSwipe( void );
	INLINE_CHAINS void chain9_secAlarm( void );
	INLINE_CHAINS void chain8_repairNeeded( void );
	INLINE_CHAINS void chain4_secViolation( void );
	INLINE_CHAINS void chain5_armZone( void );
	INLINE_CHAINS void chain6_disarmZone( void );
	INLINE_CHAINS void chain3_clearActiveAlarm( void );
	INLINE_CHAINS void chain10_activateCCAlarm( void );
	INLINE_CHAINS void chain11_clearCCAlarm( void );

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

#endif /* ControlCenter_H */

// }}}RME
