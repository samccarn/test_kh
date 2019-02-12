//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "testKHTestApp.h"
#include "testKHApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<testKHTestApp>()
{
  InputParameters params = validParams<testKHApp>();
  return params;
}

testKHTestApp::testKHTestApp(InputParameters parameters) : MooseApp(parameters)
{
  testKHTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

testKHTestApp::~testKHTestApp() {}

void
testKHTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  testKHApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"testKHTestApp"});
    Registry::registerActionsTo(af, {"testKHTestApp"});
  }
}

void
testKHTestApp::registerApps()
{
  registerApp(testKHApp);
  registerApp(testKHTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
testKHTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testKHTestApp::registerAll(f, af, s);
}
extern "C" void
testKHTestApp__registerApps()
{
  testKHTestApp::registerApps();
}
