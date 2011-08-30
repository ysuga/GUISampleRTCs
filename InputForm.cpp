
static bool updateFlag = false;
static int value;

#include "InputForm.h"

void StartForm() {
	::Application::Run(gcnew IntegerInputRTCComp::InputForm());
}

bool isUpdated() {
	return updateFlag;
}

int getValue() {
	updateFlag = false;
	return value;
}