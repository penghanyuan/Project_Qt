#ifndef APPOINTMENTCONTROLLER_H
#define APPOINTMENTCONTROLLER_H

#include "dao/appointmentdao.h"
class AppointmentController
{
private:
    AppointmentDAO appointmentDAO;
public:
    AppointmentController();
    bool addAppointment(int client_id, int res_id);
};

#endif // APPOINTMENTCONTROLLER_H
