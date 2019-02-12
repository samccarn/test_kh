#include "testKHApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<testKHApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

testKHApp::testKHApp(InputParameters parameters) : MooseApp(parameters)
{
  testKHApp::registerAll(_factory, _action_factory, _syntax);
}

testKHApp::~testKHApp() {}

void
testKHApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"testKHApp"});
  Registry::registerActionsTo(af, {"testKHApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
testKHApp::registerApps()
{
  registerApp(testKHApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
testKHApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testKHApp::registerAll(f, af, s);
}
extern "C" void
testKHApp__registerApps()
{
  testKHApp::registerApps();
}
