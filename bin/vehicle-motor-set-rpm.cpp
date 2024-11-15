#include <ipc/vehicle-protocol.h>

#include <mqueue.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>
#include <iostream>


int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << argv[0] << " <RPM>\n";
        return 1;
    }
    int rpm = std::stoi(argv[1]);

    mqd_t message_queue = mq_open("/crazy-car", O_WRONLY);
    if (message_queue == -1) {
        perror("mq_open");
        return 1;
    }

    VehicleMessage msg = {
        .command = MOTOR_SET_RPM,
        .value = rpm
    };
    unsigned int priority = 0;

    ssize_t n_bytes_written = mq_send(message_queue, (char*)&msg, sizeof(msg), priority);
    if (n_bytes_written == -1) {
        perror("mq_send");
        return 1;
    }
    assert(n_bytes_written == 0);

    return 0;
}
