// {{{RME classifier 'Logical View::Timer'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Timer.h"
#endif

#include <RTSystem/TestComponent.h>
#include <Timer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_Timer_init( const RTObject_class * type, Timer * target )
{
	(void)new( target ) Timer;
}

static void rtg_Timer_copy( const RTObject_class * type, Timer * target, const Timer * source )
{
	(void)new( target ) Timer( *source );
}

static void rtg_Timer_destroy( const RTObject_class * type, Timer * target )
{
	target->~Timer();
}

const RTObject_class RTType_Timer =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "Timer"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( Timer )
  , (RTInitFunction)rtg_Timer_init
  , (RTCopyFunction)rtg_Timer_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_Timer_destroy
  , 1
  , Timer::rtg_Timer_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Timer::Timer( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Timer::~Timer( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Timer::Timer( const Timer & rtg_arg )
	: TimerID( rtg_arg.TimerID )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Timer & Timer::operator=( const Timer & rtg_arg )
{
	if( this != &rtg_arg )
		TimerID = rtg_arg.TimerID;
	return *this;
}
// }}}RME

const RTFieldDescriptor Timer::rtg_Timer_fields[] =
{
	// {{{RME classAttribute 'TimerID'
	{
		"TimerID"
	  , RTOffsetOf( Timer, TimerID )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

#if OBJECT_DECODE
RTTypeInstaller rtg_Timer_installer( RTType_Timer );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
