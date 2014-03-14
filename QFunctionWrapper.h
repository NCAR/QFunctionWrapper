/*
 * QFunctionWrapper.h
 *
 *  Created on: Mar 14, 2014
 *      Author: burghart
 */

#ifndef QFUNCTIONWRAPPER_H_
#define QFUNCTIONWRAPPER_H_

#include <QObject>

/// @brief This class simply provides a wrapper for a static function so that
/// it can be treated as a Qt slot. This class becomes obsolete with Qt 5,
/// where signals can be connected directly to static functions.
class QFunctionWrapper: public QObject {
    Q_OBJECT
public slots:
    /// The slot which causes a call to the function being wrapped.
    void callFunction();
public:
    typedef void(*functionPtr)();
    /// Instantiate a QFunctionWrapper around the given function.
    /// @param func the static function to be wrapped
    QFunctionWrapper(functionPtr func);
    virtual ~QFunctionWrapper();
private:
    functionPtr _func;
};

#endif /* QFUNCTIONWRAPPER_H_ */
