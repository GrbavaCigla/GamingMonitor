#ifndef SSHWRAP_H
#define SSHWRAP_H

#include <libssh/libssh.h>
#include <algorithm>
#include <iostream>


std::string send_command(ssh_session, std::string);

ssh_session establish_session(std::string, std::string, std::string, int);
#endif
