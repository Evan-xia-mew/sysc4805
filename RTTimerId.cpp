// {{{RME classifier 'Logical View::RTTimerId'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "RTTimerId.h"
#endif

#include <RTSystem/TestComponent.h>
#include <RTTimerId.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_RTTimerId_init( const RTObject_class * type, RTTimerId * target )
{
	(void)new( target ) RTTimerId;
}

static void rtg_RTTimerId_copy( const RTObject_class * type, RTTimerId * target, const RTTimerId * source )
{
	(void)new( target ) RTTimerId( *source );
}

static void rtg_RTTimerId_destroy( const RTObject_class * type, RTTimerId * target )
{
	target->~RTTimerId();
}

const RTObject_class RTType_RTTimerId =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "RTTimerId"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( RTTimerId )
  , (RTInitFunction)rtg_RTTimerId_init
  , (RTCopyFunction)rtg_RTTimerId_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_RTTimerId_destroy
  , 1
  , RTTimerId::rtg_RTTimerId_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
RTTimerId::RTTimerId( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
RTTimerId::~RTTimerId( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
RTTimerId::RTTimerId( const RTTimerId & rtg_arg )
	: TimerID( rtg_arg.TimerID )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
RTTimerId & RTTimerId::operator=( const RTTimerId & rtg_arg )
{
	if( this != &rtg_arg )
		TimerID = rtg_arg.TimerID;
	return *this;
}
// }}}RME

const RTFieldDescriptor RTTimerId::rtg_RTTimerId_fields[] =
{
	// {{{RME classAttribute 'TimerID'
	{
		"TimerID"
	  , RTOffsetOf( RTTimerId, TimerID )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_RTTimerId
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

#if OBJECT_DECODE
RTTypeInstaller rtg_RTTimerId_installer( RTType_RTTimerId );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
