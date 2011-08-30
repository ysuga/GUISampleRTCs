static bool updateFlag = false;
static int g_value;

static int counter;

bool isUpdated() {
	return updateFlag;
}

int getValue() {
	updateFlag = false;
	return g_value;
}

#include "OutputForm.h"



void StartForm() {
	::Application::Run(gcnew IntegerOutputRTCComp::OutputForm());
}



void setValue(int value) {
	g_value = value;
	updateFlag = true;
}

