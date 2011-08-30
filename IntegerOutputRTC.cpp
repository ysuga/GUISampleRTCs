// -*- C++ -*-
/*!
 * @file  IntegerOutputRTC.cpp
 * @brief Integer Value Outputting RTC
 * @date $Date$
 *
 * $Id$
 */

#include "IntegerOutputRTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* integeroutputrtc_spec[] =
  {
    "implementation_id", "IntegerOutputRTC",
    "type_name",         "IntegerOutputRTC",
    "description",       "Integer Value Outputting RTC",
    "version",           "1.0.0",
    "vendor",            "ysuga.net",
    "category",          "Experimenta",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug", "debug",
    // Widget
    "conf.__widget__.debug", "text",
    // Constraints
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
IntegerOutputRTC::IntegerOutputRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
IntegerOutputRTC::~IntegerOutputRTC()
{
}



RTC::ReturnCode_t IntegerOutputRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "debug");
  
  // </rtc-template>
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t IntegerOutputRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IntegerOutputRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IntegerOutputRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t IntegerOutputRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t IntegerOutputRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

void setValue(int value);
	
RTC::ReturnCode_t IntegerOutputRTC::onExecute(RTC::UniqueId ec_id)
{
	if(m_inIn.isNew()) {
		m_inIn.read();
		setValue(m_in.data);
	}

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t IntegerOutputRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IntegerOutputRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t IntegerOutputRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t IntegerOutputRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IntegerOutputRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void IntegerOutputRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(integeroutputrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<IntegerOutputRTC>,
                             RTC::Delete<IntegerOutputRTC>);
  }
  
};


