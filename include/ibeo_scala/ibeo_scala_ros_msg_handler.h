#ifndef IBEO_SCALA_ROS_MSG_HANDLER_H
#define IBEO_SCALA_ROS_MSG_HANDLER_H

#include <ibeo_core/utils.h>
#include <ibeo_scala_common.h>

using namespace AS::Drivers::Ibeo;

namespace AS
{
namespace Drivers
{
namespace IbeoScala
{
  class IbeoScalaRosMsgHandler
  {
    public:
      void fillAndPublish(const unsigned short& type_id,
                          std::string frame_id,
                          ros::Publisher& pub,
                          std::shared_ptr<IbeoTxMessage>& parser_class);
      void fillPointcloud(std::vector<Point3DL>& points, pcl::PointCloud<pcl::PointXYZL>& new_msg);
      void fillContourPoints(std::vector<Point3D>& points, visualization_msgs::Marker& new_msg, std::string frame_id);
      void fillMarkerArray(std::vector<IbeoObject>& objects, visualization_msgs::MarkerArray& new_msg, std::string frame_id);

    private:
      ros::Time ntp_to_ros_time(NTPTime time);

      void fillIbeoHeader(IbeoDataHeader& class_header, ibeo_msgs::IbeoDataHeader& msg_header);

      void fill2202(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ScanData2202& new_msg, std::string frame_id);
      void fill2205(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ScanData2205& new_msg, std::string frame_id);
      void fill2208(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ScanData2208& new_msg, std::string frame_id);
      void fill2225(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ObjectData2225& new_msg, std::string frame_id);
      void fill2270(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ObjectData2270& new_msg, std::string frame_id);
      void fill2271(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ObjectData2271& new_msg, std::string frame_id);
      void fill2280(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ObjectData2280& new_msg, std::string frame_id);
      void fill2403(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::CameraImage& new_msg, std::string frame_id);
      void fill2805(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::HostVehicleState2805& new_msg, std::string frame_id);
      void fill2806(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::HostVehicleState2806& new_msg, std::string frame_id);
      void fill2807(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::HostVehicleState2807& new_msg, std::string frame_id);
      void fill6301(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::DeviceStatus& new_msg, std::string frame_id);
      visualization_msgs::Marker createWireframeMarker(const float& center_x,
                                                       const float& center_y,
                                                       float size_x,
                                                       float size_y,
                                                       const float& size_z);
  };
}
}
}

#endif
