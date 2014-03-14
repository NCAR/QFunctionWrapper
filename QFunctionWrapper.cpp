/*
 * QFunctionWrapper.cpp
 *
 *  Created on: Mar 14, 2014
 *      Author: burghart
 */

#include "QFunctionWrapper.h"

QFunctionWrapper::QFunctionWrapper(functionPtr func) : _func(func) {}

QFunctionWrapper::~QFunctionWrapper() {
}

void
QFunctionWrapper::callFunction() {
    // Just call the wrapped function
    _func();
}
