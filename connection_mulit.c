/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** connection_mulit
*/

#include "navy.h"

char *get_ip()
{
    int fd;
    struct ifreq ifr;
    struct ifconf ifc;
    char buffer[1024];
    int success = 0;

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    ifc.ifc_len = sizeof(buffer);
    ifc.ifc_buf = buffer;
    if (ioctl(fd, SIOCGIFCONF, &ifc) == 0) {
        struct ifreq* it = ifc.ifc_req;
        const struct ifreq* const end = it + (ifc.ifc_len / sizeof(struct ifreq));

        for (; it != end; ++it) {
            strcpy(ifr.ifr_name, it->ifr_name);
            if (ioctl(fd, SIOCGIFFLAGS, &ifr) == 0) {
                if (!(ifr.ifr_flags & IFF_LOOPBACK)) {
                    if (strncmp(ifr.ifr_name, "wl", 2) == 0) {
                        if (ioctl(fd, SIOCGIFADDR, &ifr) == 0) {
                            success = 1;
                            break;
                        }
                    }
                }
            }
            else {
            }
        }
    }
    else {
     }
    close(fd);
    if (success) {
        return inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
    } else {
        return ("No IP found, use ifconfig in a terminal or connect to the internet");
    }
    return 0;
}

