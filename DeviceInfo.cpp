// {{{RME classifier 'Logical View::DeviceInfo'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DeviceInfo.h"
#endif

#include <RTSystem/TestComponent.h>
#include <DeviceInfo.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_DeviceInfo_init( const RTObject_class * type, DeviceInfo * target )
{
	(void)new( target ) DeviceInfo;
}

static void rtg_DeviceInfo_copy( const RTObject_class * type, DeviceInfo * target, const DeviceInfo * source )
{
	(void)new( target ) DeviceInfo( *source );
}

static void rtg_DeviceInfo_destroy( const RTObject_class * type, DeviceInfo * target )
{
	target->~DeviceInfo();
}

const RTObject_class RTType_DeviceInfo =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "DeviceInfo"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( DeviceInfo )
  , (RTInitFunction)rtg_DeviceInfo_init
  , (RTCopyFunction)rtg_DeviceInfo_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_DeviceInfo_destroy
  , 2
  , DeviceInfo::rtg_DeviceInfo_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
DeviceInfo::DeviceInfo( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
DeviceInfo::~DeviceInfo( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
DeviceInfo::DeviceInfo( const DeviceInfo & rtg_arg )
	: Zone( rtg_arg.Zone )
	, DeviceID( rtg_arg.DeviceID )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
DeviceInfo & DeviceInfo::operator=( const DeviceInfo & rtg_arg )
{
	if( this != &rtg_arg )
	{
		Zone = rtg_arg.Zone;
		DeviceID = rtg_arg.DeviceID;
	}
	return *this;
}
// }}}RME

const RTFieldDescriptor DeviceInfo::rtg_DeviceInfo_fields[] =
{
	// {{{RME classAttribute 'Zone'
	{
		"Zone"
	  , RTOffsetOf( DeviceInfo, Zone )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'DeviceID'
  , {
		"DeviceID"
	  , RTOffsetOf( DeviceInfo, DeviceID )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

#if OBJECT_DECODE
RTTypeInstaller rtg_DeviceInfo_installer( RTType_DeviceInfo );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
