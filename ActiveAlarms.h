// {{{RME classifier 'Logical View::ActiveAlarms'

#ifndef ActiveAlarms_H
#define ActiveAlarms_H

#ifdef PRAGMA
#pragma interface "ActiveAlarms.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CCAlarmProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ActiveAlarms;

#define SUPER RTActor
class ActiveAlarms_Actor : public RTActor
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
	// {{{RME classAttribute 'ActiveList'
	int ActiveList;
	// }}}RME

protected:
	// {{{RME port 'ActiveAlarmsPort'
	CCAlarmProtocol::Conjugate ActiveAlarmsPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	ActiveAlarms_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ActiveAlarms_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:noActiveAlarms:J58B8951E006B:addEvent'
	INLINE_METHODS void transition2_addEvent( const void * rtdata, CCAlarmProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:activeAlarms:J58DD4852022D:addEvent'
	INLINE_METHODS void transition3_addEvent( const void * rtdata, CCAlarmProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:activeAlarms:J58DD48130151:eventCleared'
	INLINE_METHODS void transition4_eventCleared( const int * rtdata, CCAlarmProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CP1:True'
	INLINE_METHODS void transition5_True( const int * rtdata, CCAlarmProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:activeAlarms:J58DD5E590044:viewActiveAlarms'
	INLINE_METHODS void transition7_viewActiveAlarms( const void * rtdata, CCAlarmProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_addEvent( void );
	INLINE_CHAINS void chain7_viewActiveAlarms( void );
	INLINE_CHAINS void chain3_addEvent( void );
	INLINE_CHAINS void chain4_eventCleared( void );

protected:
	// {{{RME choicePoint ':TOP:CP1'
	INLINE_METHODS int choicePoint1_CP1( const int * rtdata, CCAlarmProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain5_True( void );
	INLINE_CHAINS void chain6_False( void );

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
	static const RTFieldDescriptor rtg_ActiveAlarms_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ActiveAlarms_H */

// }}}RME
