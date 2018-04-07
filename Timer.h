// {{{RME classifier 'Logical View::Timer'

#ifndef Timer_H
#define Timer_H

#ifdef PRAGMA
#pragma interface "Timer.h"
#endif

#include <RTSystem/TestComponent.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_Timer;

class Timer
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
	// {{{RME classAttribute 'TimerID'
	RTTimerId TimerID;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Timer( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Timer( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	Timer( const Timer & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	Timer & operator=( const Timer & rtg_arg );
	// }}}RME
	static const RTFieldDescriptor rtg_Timer_fields[];
};

struct RTTypedValue_Timer
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_Timer( const Timer & rtg_value )
		: data( &rtg_value ), type( &RTType_Timer )
	{
	}
	inline RTTypedValue_Timer( const Timer & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_Timer( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Timer_H */

// }}}RME
