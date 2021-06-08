#include<stdio.h>
#include<QtDBus/QtDBus>

int main(void)
{
    if (!QDBusConnection::sessionBus().isConnected()) {
        fprintf(stderr, "Cannot connect to the D-Bus session bus.\n"
                "To start it, run:\n"
                "\teval `dbus-launch --auto-syntax`\n");
        return 1;
    }
    else
    {
        fprintf(stdout, "Connected to Bus\n");
    }
    return 0;
}
