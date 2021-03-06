#ifndef APPOINTMENTDAO_H
#define APPOINTMENTDAO_H
#include "connectionsql.h"
#include "models/client.h"
#include "models/resource.h"
#include "models/appointment.h"


#include <QSqlQuery>
#include <QSqlDatabase>

class AppointmentDAO
{
private:
    QSqlDatabase db;
public:
    AppointmentDAO();
    bool insertAppointment(Client &client, Resource &resource);
    void selectAppointmentByClientID(int id, vector<Appointment>&v_app);
    void selectAppointmentByResourceID(int id, vector<Appointment>&v_app);
    bool deleteAppointmentByClientId(int cli_id);
    bool deleteAppointmentByResourceId(int cli_id);

};

#endif // APPOINTMENTDAO_H
