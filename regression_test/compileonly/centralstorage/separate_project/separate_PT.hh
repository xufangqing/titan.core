/******************************************************************************
 * Copyright (c) 2000-2020 Ericsson Telecom AB
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
 *
 * Contributors:
 *   Balasko, Jeno
 *   Delic, Adam
 *   Lovassy, Arpad
 *   Szabados, Kristof
 *
 ******************************************************************************/
// This Test Port skeleton header file was generated by the
// TTCN-3 Compiler of the TTCN-3 Test Executor version 1.6.pl3
// for Kristof Szabados (ekrisza@balisea) on Wed Nov  9 10:02:40 2005


// You may modify this file. Add your attributes and prototypes of your
// member functions here.

#ifndef separate__PT_HH
#define separate__PT_HH

#include "separate_ttcn.hh"

namespace separate__ttcn {

class separate__PT : public separate__PT_BASE {
public:
	separate__PT(const char *par_port_name = NULL);
	~separate__PT();

	void set_parameter(const char *parameter_name,
		const char *parameter_value);

	void Event_Handler(const fd_set *read_fds,
		const fd_set *write_fds, const fd_set *error_fds,
		double time_since_last_call);

protected:
	void user_map(const char *system_port);
	void user_unmap(const char *system_port);

	void user_start();
	void user_stop();

	void outgoing_send(const CHARSTRING& send_par);
};

}

#endif
