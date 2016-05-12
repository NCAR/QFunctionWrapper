// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
/*
 * QFunctionWrapper.h
 *
 *  Created on: Mar 14, 2014
 *      Author: burghart
 */

#ifndef QFUNCTIONWRAPPER_H_
#define QFUNCTIONWRAPPER_H_

#include <QObject>

/// @brief This class simply provides a wrapper for a zero-argument static
/// function so that it can be treated as a Qt slot. This class becomes obsolete
/// with Qt 5, where signals can be connected directly to static functions.
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
