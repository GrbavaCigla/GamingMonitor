#include <libssh/libssh.h>
#include <algorithm>
#include <iostream>

std::string send_command(ssh_session session, std::string command){
    ssh_channel channel;
    int rc;
    channel = ssh_channel_new(session);
    rc = ssh_channel_open_session(channel);
    if(rc!=SSH_OK){
        throw rc;
    }

    rc = ssh_channel_request_exec(channel, command.c_str());
    if(rc!=SSH_OK){
        throw rc;
    }

    char buffer[2048];
    int nbytes;
    nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    while (nbytes > 0) {
        //fwrite(buffer, 1, nbytes, stdout);
        nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    }
    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    return std::string(buffer);
}

int free_session(ssh_session session){
    ssh_disconnect(session);
    ssh_free(session);
    return 0;
}


ssh_session establish_session(std::string username, std::string password, std::string ip, int port=22){
    ssh_session ssh_session;
    int rc;
    ssh_session = ssh_new();

    int verbosity = SSH_LOG_PROTOCOL;
    ssh_options_set(ssh_session, SSH_OPTIONS_HOST, ip.c_str());
    ssh_options_set(ssh_session, SSH_OPTIONS_USER, username.c_str());
    ssh_options_set(ssh_session, SSH_OPTIONS_PORT, &port);
    ssh_options_set(ssh_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);

    rc = ssh_connect(ssh_session);
    if(rc!=SSH_OK){
        throw rc;
    }
    rc = ssh_userauth_password(ssh_session, nullptr, password.c_str());
    if(rc!=SSH_OK){
        throw rc;
    }
    std::cout << rc << std::endl;

    return ssh_session;
}

int get_ram_usage(ssh_session session){
    std::string str = send_command(session, "vmstat -s | egrep 'used memory' | cut -d 'K' -f 1");
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    return std::stoi(str);
}
int get_ram_total(ssh_session session){
    std::string str = send_command(session, "vmstat -s | egrep 'total memory' | cut -d 'K' -f 1");
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    return std::stoi(str);
}
