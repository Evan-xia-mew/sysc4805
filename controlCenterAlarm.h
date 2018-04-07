// {{{RME classifier 'Logical View::controlCenterAlarm'

#ifndef controlCenterAlarm_H
#define controlCenterAlarm_H

#ifdef PRAGMA
#pragma interface "controlCenterAlarm.h"
#endif

#include <RTSystem/TestComponent.h>
#include <CCAlarmProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass controlCenterAlarm;

#define SUPER RTActor
class controlCenterAlarm_Actor : public RTActor
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
	// {{{RME port 'CCAlarmPort'
	CCAlarmProtocol::Conjugate CCAlarmPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	controlCenterAlarm_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~controlCenterAlarm_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:idle:J58B88DFB033A:activated'
	INLINE_METHODS void transition2_activated( const void * rtdata, CCAlarmProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:active:J58B88DFE025A:cleared'
	INLINE_METHODS void transition3_cleared( const void * rtdata, CCAlarmProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_activated( void );
	INLINE_CHAINS void chain3_cleared( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* controlCenterAlarm_H */

// }}}RME
