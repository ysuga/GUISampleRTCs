// -*- C++ -*-
/*!
 * @file  IntegerInputRTC.cpp
 * @brief Integer Value Inputting RTC
 * @date $Date$
 *
 * $Id$
 */

#include "IntegerInputRTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* integerinputrtc_spec[] =
  {
    "implementation_id", "IntegerInputRTC",
    "type_name",         "IntegerInputRTC",
    "description",       "Integer Value Inputting RTC",
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
IntegerInputRTC::IntegerInputRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_outOut("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
IntegerInputRTC::~IntegerInputRTC()
{
}



RTC::ReturnCode_t IntegerInputRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("out", m_outOut);
  
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
RTC::ReturnCode_t IntegerInputRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IntegerInputRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IntegerInputRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t IntegerInputRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t IntegerInputRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/**
 * CLRマネージ部分との接続用関数の宣言
 * 本体はInputForm.cppに記述されています．
 */
bool isUpdated();

int getValue();

RTC::ReturnCode_t IntegerInputRTC::onExecute(RTC::UniqueId ec_id)
{
	if(isUpdated()) {
		int value = getValue();
		this->m_out.data = value;
		m_outOut.write();
	}
	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t IntegerInputRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IntegerInputRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t IntegerInputRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t IntegerInputRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IntegerInputRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void IntegerInputRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(integerinputrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<IntegerInputRTC>,
                             RTC::Delete<IntegerInputRTC>);
  }
  
};


