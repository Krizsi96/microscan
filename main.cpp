#include <iostream>
#include <sick_safetyscanners_base/SickSafetyscanners.h>
#include <sick_safetyscanners_base/Exceptions.h>
#include <sick_safetyscanners_base/Types.h>
#include <sick_safetyscanners_base/datastructure/CommSettings.h>

int main() {
    // Sensor IP and Port
    std::string sensor_ip_str = "192.168.1.3";
    sick::types::ip_address_t sensor_ip = boost::asio::ip::address_v4::from_string(sensor_ip_str);
    sick::types::port_t tcp_port {2122};

    // Prepare the CommSettings for Sensor streaming data
    sick::datastructure::CommSettings comm_settings;
    std::string host_ip_str = "192.168.1.15";
    comm_settings.host_ip = boost::asio::ip::address_v4::from_string(host_ip_str);
    comm_settings.host_udp_port = 0;

    // Create a sensor instance
    auto safety_scanner = std::make_unique<sick::SyncSickSafetyScanner>(sensor_ip, tcp_port, comm_settings);

    // Receive one sensor data packet
    auto timeout = boost::posix_time::seconds(5);
    sick::datastructure::Data data = safety_scanner->receive(timeout);

    bool is_run_mode_active = data.getGeneralSystemStatePtr()->getRunModeActive();
    std::cout << "is_run_mode_active: " << is_run_mode_active << std::endl;

    auto scan_points = data.getMeasurementDataPtr()->getScanPointsVector();

    for (const auto &scan_point: scan_points) {
        float angle = scan_point.getAngle();
        float distance = scan_point.getDistance();
        std::cout << "angle: " << angle << " distance: " << distance << std::endl;
    }

    return 0;
}
